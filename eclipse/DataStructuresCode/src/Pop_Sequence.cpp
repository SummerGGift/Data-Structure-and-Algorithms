/*
 * Pop_Sequence.cpp
 *
 *  Created on: 2018��4��6��
 *      Author: Administrator
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

