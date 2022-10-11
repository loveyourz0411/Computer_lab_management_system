#pragma once
#include<iostream>
using namespace std;
#include"student.h"
#include"teacher.h"
#include"computerRoom.h"
#include"identity.h"
#include<string>
#include"globalFile.h"
#include<fstream>
#include<vector>
#include<algorithm>

class Manager : public Identity {
public:	
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�
	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	//��������
	vector<ComputerRoom>vCom;

	//��������
	~Manager();
};
