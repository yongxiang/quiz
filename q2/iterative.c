#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

char smallest_character(char str[], char c)
{
    int i = 0;
    while( str[i] != '\0' ) {
        if( str[i]>c ) {
            return str[i];
        }
        i++;
    }
    return str[0];
}

static double diff(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec *1000000000.0+ diff.tv_nsec );
}


int main()
{
    char out;
    struct timespec start, end;
    /* test case */
    /* input */
    char input[] = {'c', 'f', 'g', 'h', 'i', 'j','k', 'l','m','n','o', 'p', 'v'};
    out = smallest_character(input,'z');

    assert( out == 'c' );

    clock_gettime(CLOCK_REALTIME, &start);
    out = smallest_character(input, 'z');
    clock_gettime(CLOCK_REALTIME, &end);

    printf("answer is %c, execution time is %lf nsec\n",out ,diff(start,end));
    return 0;
}
