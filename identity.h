#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class Identity {
public:

	//显示操作菜单纯虚函数
	virtual void openMenu() = 0;

	string m_Name;
	string m_Pwd;
};