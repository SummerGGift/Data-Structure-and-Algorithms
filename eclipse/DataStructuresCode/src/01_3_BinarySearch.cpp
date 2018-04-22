/*
 * BinarySearch.cpp
 *
 *  Created on: 2018��4��7��
 *      Author: Summer
 */


/*
 * 01-���Ӷ�3 ���ֲ��ң�20 �֣�
 ����Ҫ��ʵ�ֶ��ֲ����㷨��

 �����ӿڶ��壺

 Position BinarySearch( List L, ElementType X );
 ����List�ṹ�������£�

 typedef int Position;
 typedef struct LNode *List;
 struct LNode {
	 ElementType Data[MAXSIZE];
	 Position Last;
 };

 L���û������һ�����Ա�����ElementTypeԪ�ؿ���ͨ��>��==��<���бȽϣ�
 ������Ŀ��֤����������ǵ�������ġ�����BinarySearchҪ����X��Data�е�λ�ã�
 �������±꣨ע�⣺Ԫ�ش��±�1��ʼ�洢����
 �ҵ��򷵻��±꣬���򷵻�һ�������ʧ�ܱ��NotFound��

 ���в��Գ���������

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

List ReadInput(); //
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

// ��Ĵ��뽫��Ƕ������

��������1��

5
12 31 55 89 101
31
�������1��

2
��������2��

3
26 78 233
31
�������2��

0

*/

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

Position BinarySearch( List L, ElementType X )
{
  int low, mid, high;
  low = 1;
  high = L->Last;
  while( low <= high  )
  {
    mid = (low + high)/2;
    if ( L->Data[mid] < X )
        low = mid + 1;
    else if( L->Data[mid] > X )
    {
        high = mid - 1;
    }else{
        return mid;
    }
   }
  return NotFound;
}

