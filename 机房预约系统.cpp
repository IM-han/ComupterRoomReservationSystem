#include<iostream>
using namespace std;

#include "globalFile.h"
#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#include<fstream>
#include<string>

void Login(string fileName, int type);
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);

//��¼����
void Login(string fileName, int type) {
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	
	//�ļ����������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		ifs.close();
		return ;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		//ѧ����¼
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		//��ʦ��¼
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//��¼��֤
	if (type == 1) {
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (id == fId && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "��֤��¼�ɹ�" << endl;
				//��¼�ɹ��󣬰�������������Ա����
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��½ʧ��" << endl;

	system("pause");
	system("cls");
	return;
}

//����Ա�Ӳ˵�
void managerMenu(Identity*& manager) {
	while (true) {
		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1) {
			//����˺�
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else if (select == 0){
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity*& student) {
	while (true) {
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;
		if (select == 1) {
			//����ԤԼ
			stu->applyOrder();
		}
		else if (select == 2) {
			//�鿴����ԤԼ
			stu->showMyOrder();
		}
		else if (select == 3) {
			//�鿴����ԤԼ
			stu->showAllOrder();
		}
		else if (select == 4) {
			//ȡ������ԤԼ
			stu->cancelOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
}

//��ʦ�˵�
void teacherMenu(Identity*& teacher) {
	while (true) {
		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1) {
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2) {
			//���ԤԼ
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

int main() {

	int select = 0;

	while (true) {

		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�û�ѡ��

		switch (select) {
		case 1: //ѧ��
			Login(STUDENT_FILE, 1);
			break;
		case 2: //��ʦ
			Login(TEACHER_FILE, 2);
			break;
		case 3: //����Ա
			Login(ADMIN_FILE, 3);
			break;
		case 0: //�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");

			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}