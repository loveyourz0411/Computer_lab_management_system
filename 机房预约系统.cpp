#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
using namespace std;

//进入管理员的子菜单界面
void managerMenu(Identity*& manager) {
	while (true) {
		//调用管理员子菜单
		manager->openMenu();

		//将父类指针转为子类指针 调用子类其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) { //添加账号
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if(select == 2){ //查看账号
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) { //查看机房
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager; //清空堆区数据
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student) {
	while (true) {
		//调用管理员子菜单
		student->openMenu();

		//将父类指针转为子类指针 调用子类其他接口
		Student* stu = (Student*)student;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) { //申请预约
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) { //查看自身预约
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) { //查看所有预约
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else {
			delete student; //清空堆区数据
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity*& teacher) {
	while (true) {
		//调用管理员子菜单
		teacher->openMenu();

		//将父类指针转为子类指针 调用子类其他接口
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) { //查看所有预约
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) { //审核预约
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else {
			delete teacher; //清空堆区数据
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能 参数1 操作文件名 参数2 操作身份类型
void LoginIn(string fileName, int type) {
	//父类指针，用于指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户传进的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1) { //学生身份
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {  //教师身份
		cout << "请输入您的职工号： " << endl;
		cin >> id;
	}

	cout << "请输入用户名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId; //从文件中获取的Id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师身份验证
		int fId; //从文件中获取的Id号
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "教师验证登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员身份验证
		string fName; //从文件中获取的姓名
		string fPwd; //从文件中获取的密码

		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "管理员登陆成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登陆失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main() {
	
	while (true) {
		int select = 0; //用于接收用户的选择
		cout << "=========================  欢迎来到佰泽机房预约系统  ========================"
			<< endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t -------------------------------------------- \n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               1. 学 生 代 表                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               2. 老       师                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               3. 管  理   员                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               0. 退       出                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t -------------------------------------------- \n";
		cout << "请输入您的选择：";

		cin >> select;

		switch (select) {
		case 1: //学生身份进入系统
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师身份进入
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //管理员身份进入
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！ " << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}