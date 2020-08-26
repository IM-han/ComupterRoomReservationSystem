#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "computerRoom.h"
#include<vector>
#include<fstream>
#include "globalFile.h"
#include "orderFile.h"

/*ѧ�������Ҫ����
* ��ʾѧ�������Ĳ˵�����
* ����ԤԼ
* �鿴����ԤԼ
* �鿴����ԤԼ
* ȡ��ԤԼ
*/

class Student : public Identity {
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�ţ����������룩
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};