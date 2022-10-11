#include"manager.h"


//Ĭ�Ϲ���
Manager::Manager() {

}

//�вι���
Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;

	ifs.close();
} 

//ѡ��˵�
void Manager::openMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -------------------------------------- \n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|            1. �� �� �� ��            |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|            2. �� �� �� ��            |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|            3. �� �� �� ��            |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|            4. �� �� Ԥ Լ            |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t|            0. ע �� �� ¼            |\n";
	cout << "\t\t|                                      |\n";
	cout << "\t\t -------------------------------------- \n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�����˺�
void Manager::addPerson() {
	cout << "�����������˺ŵ�����" << endl;
	cout << "1. ����ѧ��" << endl;
	cout << "2. ������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;

	ofstream ofs;

	int select = 0;
	while(true){
		cin >> select;
		if (select == 1) {
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ� ";
			errorTip = "ѧ���ظ������������룡";
			break;
		}
		else if (select == 2) {
			fileName = TEACHER_FILE;
			tip = "������ְ����ţ� ";
			errorTip = "ְ�����ظ������������룡";
			break;
		}
		else {
			cout << "�����������������룡" << endl;
		}
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}

	
	

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	this->initVector();
	cout << "���ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

void printStudent(Student& s) {
	cout << "ѧ�ţ� " << s.m_Id << "\t������ " << s.m_Name << "\t���룺 " << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "ְ���ţ� " << t.m_EmpId << "\t������ " << t.m_Name << "\t���룺 " << t.m_Pwd << endl;
}

void printComputerRoom(ComputerRoom& c) {
	cout << "������ţ� " << c.m_ComId << "\t������������� " << c.m_MaxNum << endl;
}

//�鿴�˺�
void Manager::showPerson() {
	cout << "��ѡ��鿴�����ݣ� " << endl;
	cout << "1���鿴���е�ѧ��" << endl;
	cout << "2���鿴���е���ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//�鿴ѧ��
		cout << "���е�ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		//�鿴��ʦ
		cout << "���е���ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer() {
	cout << "������Ϣ���£� " << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile() {
	int select;
	while (true) {
		cout << "ȷ�����ԤԼ������" << endl;
		cout << "1��ȷ��" << endl;
		cout << "2��ȡ��" << endl;
		cin >> select;
		if (select == 1) {
			ofstream ofs(ORDER_FILE, ios::trunc);
			ofs.close();
			cout << "��ճɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		else if (select == 2) {
			cout << "��ȡ����գ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		else {
			cout << "�����������������" << endl;
		}
	}
}

//��ʼ������
void Manager::initVector() {
	//���ļ�
	//��ȡѧ������Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ� " << endl;
		return;
	}

	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;

	ifs.close();
}

//����ظ�
bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin();it != vStu.end();it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin();it != vTea.end();it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}
	}
	return false;
}

//��������
Manager::~Manager() {

}