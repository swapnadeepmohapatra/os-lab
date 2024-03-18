// Write a menu driven program to implement producer consumer problem using Semaphore.

#include <stdio.h>
#include <semaphore.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int *s)
{
    // printf("Wait S:%d", *s);
    while (s <= 0)
        ;
    (*s)--;
}

int signal(int *s)
{
    // printf("Signal S:%d", *s);
    (*s)++;
}

void producer()
{
    wait(&empty);
    wait(&mutex);
    x++;
    printf("\nProducer produces the item %d", x);
    signal(&mutex);
    signal(&full);
}

void consumer()
{
    wait(&full);
    wait(&mutex);
    printf("\nConsumer consumes item %d", x);
    x--;
    signal(&mutex);
    signal(&empty);
}

int main()
{
    int n;
    while (1)
    {
        // printf("\n\nFull:%d\nEmpty:%d", full, empty);
        // printf("\n\nmutex:%d x:%d", mutex, x);
        printf("\n\n1.Producer\n2.Consumer\n3.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if (empty != 0)
            {
                producer();
            }
            else
            {
                printf("!!Buffer is full!!");
            }
            break;
        case 2:
            if (full != 0)
            {
                consumer();
            }
            else
            {
                printf("!!Buffer is empty!!");
            }
            break;
        case 3:
            return 0;
            break;
        }
    }
    return 0;
}
