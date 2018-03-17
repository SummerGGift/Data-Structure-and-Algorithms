/*
 * Maxsubsequencesum.cpp
 *
 *  Created on: 2018��3��8��
 *      Author: Administrator
 */
#include <stdio.h>

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


int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i,array_end;
    ThisSum = MaxSum = 0;
    array_end = 0;
    int array_begin = 0;
    int allnative = 1;
    int zero_count = 1;
    int save_array_begin = 0;

    for( i = 0; i < N; i++ )
    {
        ThisSum += A[i]; /* �����ۼ� */

        if( A[i] >= 0 )
            allnative = 0;

        if( ThisSum > MaxSum )
        {
            MaxSum = ThisSum; /* ���ָ��������µ�ǰ��� */
            zero_count++;
            array_end = i;
            save_array_begin = array_begin;
        }else
        if( ThisSum < 0 ) /* �����ǰ���к�Ϊ�� */
        {
            ThisSum = 0 ; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
            array_begin = i + 1;
        }
    }

    if ( allnative )
    {
        printf("0 %d %d",A[0], A[ N - 1 ]);
        return 0;
    }

    if( MaxSum == 0 )
    {
        printf("0 0 0");
    }else
    {
        printf("%d %d %d",MaxSum,A[save_array_begin],A[array_end]);
    }

    return 0;
}


//int main()
//{
//    int i, *a;
//    int arraycount;
//    scanf("%d",&arraycount);
//
//    a = (int *)malloc(sizeof(int) * arraycount); /*�����ڴ�*/
//
//    for(i = 0; i < arraycount; i++)
//        scanf("%d", a + i);
//
//    MaxSubseqSum4(a, arraycount);
//    free(a);
//    return 0;
//}
