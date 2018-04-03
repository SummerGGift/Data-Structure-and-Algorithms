#include<stdio.h>
#include<stdlib.h>

struct DataNode {
	int addr;
	int data;
	int nextaddr;
	struct DataNode *link;
};
typedef struct DataNode *DataList;

// ϵ�� ָ�� ��Ҫ���ڵ���������β��ָ��
static void Attach(int addr, int data, int nextaddr, DataList *pRear) {
	DataList P;

	P = (DataList) malloc(sizeof(struct DataNode));
	P->addr = addr;
	P->data = data;
	P->nextaddr = nextaddr;
	P->link = NULL;
	(*pRear)->link = P; //��β�ڵ��ָ��ָ���µĽڵ�
	*pRear = P;         //����βָ��ָ���λ��
}

int first_addr, data_num, k;

//1�������ݶ���һ��������
DataList DataNode_read() {

	int addr, data, nextaddr , datanumber;
	DataList P, Rear, t;

	scanf("%d %d %d", &first_addr, &data_num, &k);
	datanumber = data_num;

	P = (DataList) malloc(sizeof(struct DataNode));
	P->link = NULL;
	Rear = P;

	while (datanumber--) {
		scanf("%d %d %d", &addr, &data, &nextaddr);
		Attach(addr, data, nextaddr, &Rear);
	}

	t = P;
	P = P->link;
	free(t);

	return P;
}

//2������������������򣬲���֮ǰ���ɵ������е�һ����ַ�Ľڵ���룬
//Ȼ�������һ����ַ���Һ����

DataList DataNode_rearrangement(DataList List, int firstaddr, int data_num) {
    DataList P, Rear, t;
    P = (DataList) malloc(sizeof(struct DataNode));
    P->link = NULL;
    Rear = P;
    DataList List_t = List;

    while (data_num--) {
        while (List_t) {
            if (List_t->addr == firstaddr) {
                Attach(List_t->addr, List_t->data, List_t->nextaddr, &Rear);
                firstaddr = List_t->nextaddr;
                break;
            } else {
                List_t = List_t->link;
            }
        }
        List_t = List;
    }

    t = P;
    P = P->link;
    free(t);

    return P;
}

DataList DataListReversing(DataList List, int data_num, int k) {
	int z,remainder;
	z = data_num / k;
	remainder = data_num % k;
	printf("z = %d,remainder = %d \n", z, remainder);

	//����պ�����Ϊ0����ôҪÿ�ν�ȡ  K ������ת����ȡ z ��
    DataList P, Rear, t;
    P = (DataList) malloc(sizeof(struct DataNode));
    P->link = NULL;
    Rear = P;
    DataList List_t = List;
    int i = 1;
    int times, times_inter;

	while(i <= z)
	{
		times = i * k;
		times_inter = times;
		while(k--)
		{
			while(--times_inter)
			{
				List_t = List_t->link;
			}

			Rear->link = List_t;   //��Ԫ�ع������� P��
			Rear = List_t;

			List_t = List;
			times_inter = --times;
		}
       i++;
	}

	Rear->link = NULL;

    t = P;
    P = P->link;
    free(t);

	return P;
}

void DataListprint(DataList List) {
	while (List) {
		printf("%d %d %d\n", List->addr, List->data, List->nextaddr);
		List = List->link;
	}
}

int main() {
	DataList p, p_rearrangement, p_output;
	//1����������
	p = DataNode_read();
	//DataListprint(p);
	p_rearrangement = DataNode_rearrangement(p, first_addr, data_num);
	DataListprint(p_rearrangement);

	//2����ת����
	p_output = DataListReversing(p_rearrangement, data_num, k);
	//3���������
	DataListprint(p_output);
	return 0;
}
