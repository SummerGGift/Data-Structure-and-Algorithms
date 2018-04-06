/*
 * list_mult_add.cpp
 *
 *  Created on: 2018��4��1��
 *      Author: Summer
 */

/*
02-���Խṹ2 һԪ����ʽ�ĳ˷���ӷ�����

��ƺ����ֱ�������һԪ����ʽ�ĳ˻���͡�

�����ʽ:

�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000����������
���ּ��Կո�ָ���

�����ʽ:

�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո�
�����ʽӦ���0 0��

��������:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
�������:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

#include<stdio.h>
#include<stdlib.h>

struct PolyNode {
	int coef;                   // ϵ��
	int expon;                  // ָ��
	struct PolyNode *link;      // ָ����һ���ڵ��ָ��
};
typedef struct PolyNode *Polynomial;
Polynomial P1, P2;

// ϵ�� ָ�� ��Ҫ���ڵ���������β��ָ��
void Attach(int c, int e, Polynomial *pRear) {
	Polynomial P;

	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P; //��β�ڵ��ָ��ָ���µĽڵ�
	*pRear = P;         //����βָ��ָ���λ��
}

Polynomial ReadPoly() {
	int c, e, N;
	Polynomial P,Rear,t;

	scanf("%d", &N);
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;

	while (N--) {
		scanf("%d %d", &c, &e);
		Attach(c, e, &Rear);
	}

	t = P;
	P = P->link;
	free(t);

	return P;
}

Polynomial Add(Polynomial P1, Polynomial P2) {
	Polynomial Rear, t1, t2, P;
	t1 = P1;
	t2 = P2;
	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;

	while (t1 && t2) {
		//���ָ����ͬ����ô��ϵ����ӣ�Ȼ����뵽P��
		if (t1->expon == t2->expon) {
			//���ϵ���Ͳ�Ϊ0
			if(t1->coef + t2->coef)
			{
				Attach((t1->coef + t2->coef), t1->expon, &Rear);
				t1 = t1->link;
				t2 = t2->link;
			}else{
			//ϵ����Ϊ0
				t1 = t1->link;
				t2 = t2->link;
			}
		} else if (t1->expon > t2->expon) {
			//���t1��ָ������t2��ָ������ô��t1����P,��t1ָ����һ��Ԫ��
			Attach(t1->coef, t1->expon, &Rear);
			t1 = t1->link;

		} else {
			//t2��ָ������t1����ô��t2����P,��t2ָ����һ��Ԫ��
			Attach(t2->coef, t2->expon, &Rear);
			t2 = t2->link;
		}
	}

	//t1��Ϊ�գ���t1�����Ԫ�����β��뵽P��
	while (t1) {
		Attach(t1->coef, t1->expon, &Rear);
		t1 = t1->link;
	}

	//t2��Ϊ�գ���t2�����Ԫ�����β��뵽P��
	while (t2) {
		Attach(t2->coef, t2->expon, &Rear);
		t2 = t2->link;
	}

	//��������
	t2 = P;
	P = P->link;
	free(t2);

	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial Rear, t1, t2, P, t;
	t1 = P1;
	t2 = P2;
	int c, e;

	if(!P1 || !P2) return NULL;

	P = (Polynomial) malloc(sizeof(struct PolyNode));
	P->link = NULL;
	Rear = P;

	while(t2)   //��t1�ĵ�һ�����P2���õ���һ����P
	{
		Attach(t1->coef * t2->coef,t1->expon + t2->expon, &Rear);
		t2 = t2->link;
	}

	t1 = t1->link;

	while(t1)   //��������ѭ��������������뵽������
	{
		t2 = P2;
		Rear = P;
		while(t2){
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;

		    //���ҵ�ϵ������e���λ�ú�ͣ����
			while(Rear->link && (Rear->link->expon > e))
				Rear = Rear->link;

			//���Rear��ǰ�ڵ����һ��������ָ�������Ҫ���������ͬ����ô��Ҫ�ϲ�
			if(Rear->link && (Rear->link->expon == e))
			{
				if((Rear->link->coef + c) != 0) //����Ͳ�Ϊ0����ô����ϵ��
					Rear->link->coef += c;
				else{
					t = Rear->link;
					Rear->link = t->link;
					free(t);
				}
			}else{
			//����ͬ������һ���½ڵ�ֱ�Ӳ���
				t = (Polynomial) malloc(sizeof(struct PolyNode));
				t->coef = c;
				t->expon = e;

				t->link = Rear->link;  //�����µĽڵ�
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}

	//��������
	t2 = P;
	P = P->link;
	free(t2);

	return P;
}

void PrintPoly(Polynomial P) {
	int flag = 0;

	if (!P) {
		printf("0 0\n");
		return;
	}

	while (P) {
		if (!flag) {
			flag = 1;
		} else {
			printf(" ");
		}

		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}

	printf("\n");
}

//int main() {
//	Polynomial P1, P2, PP, PS;
//	P1 = ReadPoly();
//	P2 = ReadPoly();
//	PP = Mult(P1, P2);
//	PrintPoly(PP);
//	PS = Add(P1, P2);
//	PrintPoly(PS);
//	return 0;
//}
