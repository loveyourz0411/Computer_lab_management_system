#pragma once
#include<iostream>
using namespace std;

//��ݳ�����
class Identity {
public:

	//��ʾ�����˵����麯��
	virtual void openMenu() = 0;

	string m_Name;
	string m_Pwd;
};