#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include <iostream>

namespace SGLib
{

template <typename T>
class SmartPointer
{

protected:
	T* m_pointer;

public:
    SmartPointer(T* p = NULL)
    {
		m_pointer = p;
    }

    //�������캯�����������ָ�븳ֵ����ô��ֵ֮����ԭ����ָ��ָ��NULL
    SmartPointer(const SmartPointer<T>& obj)
    {
    	m_pointer = obj.m_pointer;
    	//const_castǿ������ת����ȥ��һ�������const����
    	const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    }

   //���� = ������
    SmartPointer<T>& operator= (const SmartPointer<T>& obj)
    {
    	if (this != &obj)
    	{
    		//�ŵ� m_pointer ������ָ����ڴ�
    		delete m_pointer;
    		//ָ������ֵ�Ŀռ䣬Ȼ����ԭָ��ָ��NULL
    		m_pointer = obj.m_pointer;
    		const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
    	}

    	return *this;
    }

	T* operator-> ()
	{
		return m_pointer;
	}

	T& operator* ()
	{
		return *m_pointer;
	}

	bool isNull()
	{
		return (m_pointer == NULL);
	}

	T* get()
	{
		return m_pointer;
	}

	~SmartPointer()
	{
		delete m_pointer;
	}

};

}

#endif /* SMARTPOINTER_H_ */
