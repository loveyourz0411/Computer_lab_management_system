#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"orderFile.h"
#include<vector>

class Teacher :public Identity {
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����ţ����������룩
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��������
	~Teacher();

	int m_EmpId; //��ʦ���

};