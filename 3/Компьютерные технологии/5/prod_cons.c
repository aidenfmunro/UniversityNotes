#include <pthread.h>
#include <stdio.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];

int add = 0;
int rem = 0;
int num = 0;

pthread_mutex_t mutex     = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_consumer = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_producer = PTHREAD_COND_INITIALIZER;

void* producer()
{
    for (int i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mutex);

        if (num == BUFFER_SIZE)
        {
            pthread_cond_wait(&c_producer, &mutex);
        }

        buffer[add] = i + 1;

        printf("Producer: %d produced\n", buffer[add]);
        fflush(stdout);

        add = (add + 1) % BUFFER_SIZE;
        num++;

        pthread_cond_signal(&c_consumer);

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void* consumer()
{
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (num == 0)
        {
            pthread_cond_wait(&c_consumer, &mutex);
        }

        int val = buffer[rem];
        printf("Consumer: %d consumed\n", buffer[val]);
        fflush(stdout);

        rem = (rem + 1) % BUFFER_SIZE;

        num--;

        pthread_cond_signal(&c_producer);

        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int i = 0;

    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t1, NULL, consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

