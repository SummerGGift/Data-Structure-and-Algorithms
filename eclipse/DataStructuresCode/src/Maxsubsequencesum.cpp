/*
 * Maxsubsequencesum.cpp
 *
 *  Created on: 2018��3��8��
 *      Author: Administrator
 */


int MaxSubsequenceSum(const int A[], int n) {
    int thissum, maxsum, i, j, k;

    maxsum = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++) {
            thissum = 0;
            for (k = i; k <= j; k++) {
                thissum += A[k];
            }

            if (thissum > maxsum)
                maxsum = thissum;
        }

    return maxsum;
}


