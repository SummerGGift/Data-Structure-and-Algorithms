/*
 * Pop_Sequence.cpp
 *
 *  Created on: 2018��4��6��
 *      Author: Administrator
 */

/*
02-���Խṹ4 Pop Sequence��25 �֣�

Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly.
You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.
For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.

Input Specification:

Each input file contains one test case.
For each case, the first line contains 3 numbers (all no more than 1000):
M (the maximum capacity of the stack), N (the length of push sequence), and K (the number of pop sequences to be checked).
Then K lines follow, each contains a pop sequence of N numbers. All the numbers in a line are separated by a space.

Output Specification:

For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.

Sample Input:

5 7 5

1 2 3 4 5 6 7

3 2 1 7 5 6 4

7 6 5 4 3 2 1

5 6 4 3 7 2 1

1 7 6 5 4 3 2

Sample Output:

YES

NO

NO

YES

NO

*/


#include<cstdio>
#include<stack>
using namespace std;

//���� 1-(i-1) ��������ջ��i ��û�н���ջ��
//һ��һ��Ԫ�ؿ��ǳ�ջ���е�Ԫ��x��
//1. i>x
//    ��ʱX�Ѿ����ջ�ˡ�
//1.1 ���������ջ����ô���޷�pop��x��
//1.2 ���x��ջ����ֱ�ӴӶ�ջpop�Ϳ����ˣ�������һ����ջԪ��
//
//2. i<=x
//2.1 ��ʱ��X��û����ջ��Ҫ��Ҫ��X��ջ�����Ǳ���Ѵ�i��x��push��ջ����ʱ��x��ջ����Pop���ɡ�
//ע�⣺ѹ��Ԫ��Ҫ��֤ջ�����Ԫ�ظ���������������ջ����������Ҳ�����ܽ�x������

int pop_seqence_test() {
    stack<int> st;
    int stack_cap, test_seq_len, k;
    scanf("%d%d%d", &stack_cap, &test_seq_len, &k);    //��������ջ������������������еĳ��ȣ��������е�������
    while (k--) {                                   //��ÿһ��������зֱ���в���
        int t = test_seq_len;
        int num = 1;                                //ÿ��push��ջ�е����ִ�С�ļ�¼
        bool flag = true;
        while (t--) {                               //�Բ������е�ÿһ���������ݽ��в���
            int x;
            scanf("%d", &x);                        //����һ����������x
            while (num <= x)                        //x�ȵ�ǰջ���±�Ҫ��
                st.push(num++);                     //һֱpushԪ��ֱ����ջ�����ִ�С��x���
            int last = st.top();                    //�鿴ջ��Ԫ��
            if (last != x || st.size() > stack_cap)    //���ջ��Ԫ�ز�����x,����ջ�Ĵ�С�Ѿ�����ջ������ʧ��
                flag = false;
            st.pop();                               //ջ��Ԫ�غ�x��ȣ��Ҳ���������ջ
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

