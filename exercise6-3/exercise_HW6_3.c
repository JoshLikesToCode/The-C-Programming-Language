/**************************************************************
* Write a cross-referencer that prints a list of all words in a
* document, and, for each word, a list of the line numbers on
* which it occurs.
**************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
/* For word list */
#define CHUNK_SIZE 512
/* Looking for words /w minimum six characters */
#define SIX_CHARS 6
/* For sorting the top 10 */
#define TOP_TEN 10



/* I may find this useful */
char * delim = "\"\'.“”‘’?:;-,—*($%)! \t\x0A\r";

/* mutex lock */
pthread_mutex_t lock;

/* for words */
typedef struct word_struct
{
	char* word;
	int* line_numbers;
} word_struct, *word_struct_ptr;

/* Struct to contain file information */
typedef struct file_info
{
        char* file_name;
        int pos;
        int offset;
} file_info, *file_info_ptr;

/* We use volatile because the below are global variables accessed
*  by multiple tasks within a multi-threaded application */
volatile word_struct_ptr words_container = NULL; 	/* to hold words */
volatile int container_count = 0;		/* number of 6+ char words currently in words_container */
int container_size = 0;			/* the size of word_entry array */

int count = 0;

/* provided for less code reuse */
void add(char* word)
{
	words_container[container_count].word = malloc(strlen(word) +2);
	strcpy(words_container[container_count].word, word);
	words_container[container_count].line_numbers[0] = count;
	container_count++;
}

void add_to_container(char* word)
{
	/* initial add */
	if(container_size == 0)
	{
		pthread_mutex_lock(&lock);
		container_size = container_size + CHUNK_SIZE;
		words_container = malloc(sizeof(word_struct) * container_size);
		/* Testing for failure in malloc() */
		if(words_container == NULL)
		{
			printf("The initial malloc() failed.\n");
			exit(-1);
		}
		add(word);
		pthread_mutex_unlock(&lock);
		return;
	}

	/* Check for duplicates, if one is found, increment its count */
	for(int i = 0; i < container_count; i++)
	{
		if(strcmp(words_container[i].word, word) == 0)
		{
			pthread_mutex_lock(&lock);
			words_container[i].line_numbers[i] = count;
			words_container[i].line_numbers[i+1] = -1;
			pthread_mutex_unlock(&lock);
			return;
		}
	}

	/* Make memory in words container if needed */
	pthread_mutex_lock(&lock);
	if(container_count >= container_size)
	{
		container_size += CHUNK_SIZE;
		word_struct_ptr realloc_words_container = realloc(words_container, sizeof(word_struct) * container_size);
		/* check for realloc() failure */
		if(realloc_words_container == NULL)
		{
			printf("Failure of realloc() occured.\n");
			exit(-1);
		}
		words_container = realloc_words_container;
	}
	add(word);
	pthread_mutex_unlock(&lock);
	//add(word);
}

void* threads_process(void* ptr)
{
	file_info_ptr data = (file_info_ptr) ptr;
	char *buffer, *word, *save;	/* save is for thread safe strtok_r() */
	int fd;

	buffer = malloc(data -> offset);
	/* check for failure to allocate buffer */
	if(buffer == NULL)
	{
		printf("Failure to allocate buffer in thread.\n");
		return NULL;
	}

	fd = open(data -> file_name, O_RDONLY);
	/* check for failure of open() */
	if(fd == 0)
	{
		printf("Failure to open file with threading.\n");
		return NULL;
	}
	lseek(fd, data -> pos, SEEK_SET);
	int bytes_read = read(fd, buffer, data -> offset);
	close(fd);
	/* null terminate buffer */
	int buffer_size = data -> offset;
	buffer[buffer_size + 1] = '\0';

	int k = 0;
	while(buffer[k] != '\0')
	{
		if(buffer[k++] == '\n')
		{
			count++;
		}
	}

	word = strtok_r(buffer, delim, &save);
	while(word != NULL)
	{
		if(strlen(word) >= SIX_CHARS)
		{
			add_to_container(word);
		}
		/* for the rest */
		word = strtok_r(NULL, delim, &save);
	}

	free(buffer);
	return NULL;
}



int main (int argc, char *argv[])
    {

    // ***TO DO***  Look at arguments, open file, divide by threads
    //             Allocate and Initialize and storage structures
	int fd, i = 0, proc_count = atoi(argv[2]);
	file_info* data;
	pthread_t* threads;
	char* file = argv[1];

	//printf("argv[0] = %s\n", argv[0]);
	//printf("argv[1] = %s\n", argv[1]);
	//printf("argv[2] = %s\n", argv[2]);

	fd = open(file, O_RDONLY);
	if(fd == 0)
	{
		printf("Failure to open file in main\n");
		return -1;
	}

	lseek(fd, 0, SEEK_END);
	int file_size = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	close(fd);


    // **************************************************************
    // DO NOT CHANGE THIS BLOCK
    //Time stamp start
    struct timespec startTime;
    struct timespec endTime;

    clock_gettime(CLOCK_REALTIME, &startTime);
    // **************************************************************
    // *** TO DO ***  start your thread processing
    //                wait for the threads to finish
	data = malloc(sizeof(file_info) * proc_count);
	if(data == NULL)
	{
		printf("Failure to malloc() data in main\n");
		return -1;
	}
	threads = malloc(sizeof(pthread_t) * proc_count);
	if(threads == NULL)
	{
		printf("Failure to malloc() threads in main\n");
		return -1;
	}


	while(i < proc_count)
	{
		data[i].file_name = file;
		data[i].pos = (file_size / proc_count) * i;
		if(i == proc_count - 1)
		{
			/* for last */
			data[i].offset = file_size - data[i].pos;
		}
		else
		{
			data[i].pos = (file_size / proc_count);
		}
		/* create threads */
		pthread_create(&(threads[i]), NULL, threads_process, &(data[i]));
		i++;
	}
	i = 0;

	/* wait on threads */
	while(i < proc_count)
	{
		pthread_join(threads[i++], NULL);
	}

    // ***TO DO *** Process TOP 10 and display
	for(int i = 0; i < container_count; i++)
	{
		printf("%s appeared on line numbers: ", words_container[i].word);
		int j = 0;
		while(j != -1)
			printf("%d ", words_container[i].line_numbers[j++]*8);
	}

	printf("count = %d\n", 8*count);

    //**************************************************************
    // DO NOT CHANGE THIS BLOCK
    //Clock output
    clock_gettime(CLOCK_REALTIME, &endTime);
    time_t sec = endTime.tv_sec - startTime.tv_sec;
    long n_sec = endTime.tv_nsec - startTime.tv_nsec;
    if (endTime.tv_nsec < startTime.tv_nsec)
        {
        --sec;
        n_sec = n_sec + 1000000000L;
        }

    printf("Total Time was %ld.%09ld seconds\n", sec, n_sec);
    //**************************************************************


    // ***TO DO *** cleanup
	i = 0;
	while(i < container_count)
	{
		free(words_container[i].word);
		words_container[i++].word = NULL;
	}
	free(words_container);
	words_container = NULL;
	pthread_mutex_destroy(&lock);

	return 0;
}

