#include"teacherinfomation.h"
#include <stdlib.h>
/*system("cls");*/
//void continueapproaching(void a())
int main() {
	management System;
	int Operating_parameter = 1;
	while (Operating_parameter == 1) {
		system("cls");//���ҳ����ʾ����
		cout << " __________________________________________________________" << endl
			<< "|                                                          |" << endl
			<< "|    _/_ _ _ / _ _  _  _   _ _ _ _  _  _/   _    __/_ _    |" << endl
			<< "|    /(-(/( /)(-/  //)(//)(/(/(-//)(-/)/  _) (/_) /(-//)   |" << endl
			<< "|                          _/                /             |" << endl
			<< "|__________________________________________________________|" << endl << endl;
		cout << "menu:\n1.Add one information\n2.Find information from the system\n3.Find and delete information that you type\n4.Find and edit information\n5.Analyze information that you choose\n6.Sort the information\n7.Operating file\n0.Quit\nType the number to choose a function:" << endl;
		int funcChoice;
		cin >> funcChoice;
		system("cls");//���ҳ����ʾ����
		switch (funcChoice) {   //ÿһ��case�жϺ󶼻����whileѭ��
		case 1://add 
		{char judge = 'N';
		do {
			System.t_add();
			cout << "Continue ?(Y/N):" << endl;
			cin >> judge;
		} while (judge == 'Y');
		cout << "Backing to the main menu...";
		Sleep(200);//���һ����ʦ��
		break; }
		case 2://find
		{char answer;
		do {
			System.t_find();
			cout << "Continue ?(Y/N):" << endl;        //�Ƿ������������
			cin >> answer;
		} while (answer == 'Y');
		cout << "Back to the main menu...\a";
		Sleep(300);
		break; }
		case 3://delete
		{char answer;
		do {
			System.t_delete(System.t_find());
			cout << "Continue ?(Y/N):" << endl;        //�Ƿ������������
			cin >> answer;
		} while (answer == 'Y');
		cout << "Back to the main menu...\a";
		Sleep(300);
		break; }
		case 4://edit
		{char judge1;
		do {
			System.t_edit(System.t_find());
			cout << endl << "Continue editting?(Y/N):" << endl;
			cin >> judge1;
		} while (judge1 == 'Y');
		cout << "Back to the main menu...\a";
		Sleep(300);
		break; }
		case 5://analyze
			//System.t_salaryAnalyzeofUnit();
			break;
		case 6://sort
			//System.t_sort();
			break;
		case 7://file manufacture
			//System.t_file();
			break;
		case 0:
			Operating_parameter = 0;     //ͨ�����ò�����0�˳��ó���
			system("cls");
			cout << "-------Quit management system successfully-------" << endl;
			Sleep(300);
		}
	}
	return 0;
}