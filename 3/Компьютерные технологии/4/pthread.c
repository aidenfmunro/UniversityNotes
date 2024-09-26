#include <pthread.h>
#include <stdio.h>

const int NUM_LOOPS = 10000;

long long sum = 0;

void* cnt_func (void* args)
{
    int offset = *(int*) args;


    for (int i = 0; i < NUM_LOOPS; i++)
    {
        sum += offset;
    }

    return NULL;
}

int main()
{
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
