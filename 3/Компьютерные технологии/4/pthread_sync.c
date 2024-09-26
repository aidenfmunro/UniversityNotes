#include <pthread.h>
#include <stdio.h>

const int NUM_LOOPS = 100000000;

long long sum = 0;

pthread_mutex_t mutex;

void* cnt_func (void* args)
{
    int offset = *(int*) args;


    for (int i = 0; i < NUM_LOOPS; i++)
    {
        pthread_mutex_lock(&mutex);
        sum += offset;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);

    pthread_t id1, id2;

    int offset1 = 1;
    int offset2 = -1;

    pthread_create(&id1, NULL, cnt_func, &offset1);
    pthread_create(&id2, NULL, cnt_func, &offset2);

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    printf("sum: %d\n", sum);
    return 0;
}
