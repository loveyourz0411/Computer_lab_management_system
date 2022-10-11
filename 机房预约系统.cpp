#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
using namespace std;

//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->openMenu();

		//������ָ��תΪ����ָ�� �������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) { //����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if(select == 2){ //�鿴�˺�
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) { //�鿴����
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager; //��ն�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(Identity*& student) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		student->openMenu();

		//������ָ��תΪ����ָ�� �������������ӿ�
		Student* stu = (Student*)student;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) { //����ԤԼ
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) { //�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) { //�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else {
			delete student; //��ն�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(Identity*& teacher) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		teacher->openMenu();

		//������ָ��תΪ����ָ�� �������������ӿ�
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) { //�鿴����ԤԼ
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) { //���ԤԼ
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else {
			delete teacher; //��ն�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼���� ����1 �����ļ��� ����2 �����������
void LoginIn(string fileName, int type) {
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���������Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) { //ѧ�����
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {  //��ʦ���
		cout << "����������ְ���ţ� " << endl;
		cin >> id;
	}

	cout << "�������û����� " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ�������֤
		int fId; //���ļ��л�ȡ��Id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ�����֤
		int fId; //���ļ��л�ȡ��Id��
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ����Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա�����֤
		string fName; //���ļ��л�ȡ������
		string fPwd; //���ļ��л�ȡ������

		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "����Ա��½�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}

int main() {
	
	while (true) {
		int select = 0; //���ڽ����û���ѡ��
		cout << "=========================  ��ӭ�����������ԤԼϵͳ  ========================"
			<< endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t -------------------------------------------- \n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               1. ѧ �� �� ��                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               2. ��       ʦ                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               3. ��  ��   Ա                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t|               0. ��       ��                |\n";
		cout << "\t\t|                                             |\n";
		cout << "\t\t -------------------------------------------- \n";
		cout << "����������ѡ��";

		cin >> select;

		switch (select) {
		case 1: //ѧ����ݽ���ϵͳ
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ��ݽ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3: //����Ա��ݽ���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ�� " << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}