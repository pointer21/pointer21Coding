#pragma once
//ģ�廯�����Խ�����������
//���췽������ֵһ��ָ��
//�����������ͷ�ָ��

//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ��
//reset �ͷ�֮ǰ�ģ�����µ�ָ��
//release �ͷſ���Ȩ������ָ��
//operator *() ģ��ָ����ʷ���
//operator ->() ģ��ָ���ͷʽ���ʷ���
//get()  ���ָ��ָ��ָ���ָ��
template<class T>
class r_autoPtr
{
	T* ptr=nullptr;
public:
	r_autoPtr(T* tem) :ptr(tem)
	{
	}
	r_autoPtr() = default;
	~r_autoPtr()
	{
		delete ptr;
	}
	r_autoPtr(r_autoPtr<T>& tem)
	{
		ptr = tem.ptr;
		tem.ptr = nullptr;
	}
	r_autoPtr<T>& operator= (r_autoPtr<T>& tem)
	{
		delete ptr;
		ptr = tem.ptr;
		tem.ptr = nullptr;
		return *this;
	}
	void reset(T* tem)
	{
		delete ptr;
		ptr = tem.ptr;
	}
	T* release()
	{
		auto tem = ptr;
		delete ptr;
		return tem;
	}
	T& operator*()
	{
		return *ptr;
	}
	T* operator->()
	{
		return ptr;
	}
	T* get()
	{
		return ptr;
	}
};