#pragma once
//ģ�廯�����Խ�����������
//���췽������ֵһ��ָ��
//�����������ͷ�һ��ָ��
//����׼�ĸ��ƹ��죨ת���ڲ�ָ�����Ȩ��
//����׼�ĸ��Ƹ�ֵ��ת���ڲ�ָ�����Ȩ��
//reset �ͷ�֮ǰ�ģ�����µ�ָ��
//release() �ͷſ���Ȩ������ָ��
//operator*()ģ��ָ����ʷ���
//operator->() ģ��ָ���ͷ���ʷ���
//get() ���ָ��ָ���ָ��
template<class T>
class S_autoPtr{
	T* obj = nullptr;
public:
	S_autoPtr(T* ptr) : obj(ptr){
	}
	S_autoPtr() = default;
	~S_autoPtr(){
		delete obj;
	}
	S_autoPtr(S_autoPtr<T>& ptr){
		obj = ptr.obj;
		ptr.obj = nullptr;
	}
	S_autoPtr& opertor = (S_autoPtr<T>& ptr){
		delete obj;
		obj = ptr.obj;
		ptr.obj = nullptr;
		return *this;
	}
	void reset(T* newPtr){
		delete obj;
		obj = newPtr;
	}
	T* release(){
		auto temP = obj;
		obj = nullptr;
		return temP;
	}
	T& operator*(){
		return *obj;
	}
	T& operator->(){
		return obj;
	}
	T* get(){
		return obj;
	}
};