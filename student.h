#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"computerRoom.h"
#include"globalFile.h"
#include<string>
#include<fstream>
#include<vector>
#include"orderFile.h"

class Student : public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//��������
	~Student();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom>vCom;
};