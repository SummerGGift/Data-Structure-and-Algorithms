/*
 * Maxsubsequencesum_1.cpp
 *
 *  Created on: 2018��4��7��
 *      Author: Summer
 */

/*
01-���Ӷ�1 ������к����⣨20 �֣�

����K��������ɵ�����{ N1, N2, ..., NK }�����������С�������Ϊ{ Ni, Ni+1, ..., Nj }��
���� 1 <= i <= j <= K����������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ�
�����������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20��
��Ҫ�����д���򣬼�������������е�������к͡�

����ּ�ڲ��Ը��ֲ�ͬ���㷨�ڸ�����������µı��֡�������������ص����£�

����1���������ȼۣ����Ի�����ȷ�ԣ�
����2��102�����������
����3��103�����������
����4��104�����������
����5��105�����������
�����ʽ:

�����1�и���������K (��100000)����2�и���K������������Կո�ָ���

�����ʽ:

��һ�������������к͡��������������������Ϊ�����������0��

��������:

6
-2 11 -4 13 -5 -2
�������:

20

 */

#include <stdio.h>

static int MaxSubseqSum1( int A[], int N )
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) {
          ThisSum += A[i]; /* �����ۼ� */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* ���ָ��������µ�ǰ��� */
          else if( ThisSum < 0 ) /* �����ǰ���к�Ϊ�� */
                  ThisSum = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
    }
    return MaxSum;
}

//int main()
//{
//    int i, *a;
//    int arraycount;
//    int result;
//    scanf("%d",&arraycount);
//
//    a = malloc(sizeof(int) * arraycount); /*�����ڴ�*/
//
//    for(i = 0; i < arraycount; i++)
//        scanf("%d", a + i);
//
//    result = MaxSubseqSum1(a, arraycount);
//    printf("%d",result);
//
//  return 0;
//}



