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
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//析构函数
	~Student();

	//学生学号
	int m_Id;

	//机房容量
	vector<ComputerRoom>vCom;
};