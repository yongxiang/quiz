#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

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

int maxSubArray(int A[], int n)
{
    assert(A&&n);
    int max =0, cur_sum=0;
    int i;
    for(i=0; i<n; i++) {
        cur_sum += A[i];

        if(cur_sum < 0)
            cur_sum = 0;

        if(max<cur_sum)
            max=cur_sum;
    }

    return max;
}

int main()
{
    int arr[9] = { -2,1,-3,4,-1,2,1,-5,4 };
    struct timespec start, end;
    int ans;

    clock_gettime(CLOCK_REALTIME, &start);
    ans = maxSubArray(arr,9);
    clock_gettime(CLOCK_REALTIME, &end);

    printf("ans = %d execution time = %lf nsec\n", ans,diff(start,end));
    return 0;
}
