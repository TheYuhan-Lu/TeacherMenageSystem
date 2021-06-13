#include"teacherinfomation.h"
/*system("cls");*/
//void continueapproaching(void a())
int main() 
{
	management System;
	int Operating_parameter = 1;
	while (Operating_parameter == 1) 
	{
		system("cls");//清除页面显示
		cout << " __________________________________________________________" << endl
			<< "|                                                          |" << endl
			<< "|    _/_ _ _ / _ _  _  _   _ _ _ _  _  _/   _    __/_ _    |" << endl
			<< "|    /(-(/( /)(-/  //)(//)(/(/(-//)(-/)/  _) (/_) /(-//)   |" << endl
			<< "|                          _/                /             |" << endl
			<< "|__________________________________________________________|" << endl << endl;
		cout << "menu:\n1.Add one information\n2.Find information from the system\n3.Find and delete information that you type\n4.Find and edit information\n5.Analyze information that you choose\n6.Sort the information\n0.Quit\nType the number to choose a function:" << endl;
		int funcChoice;
		cin >> funcChoice;
		system("cls");//清除页面显示
		switch (funcChoice) 
		{   //每一个case中断后都会进入while循环
		case 1://add 
			cout << "Which way you area gonna to choose to add information?\n1 add by typing\n2 add by scan a file" << endl;
			char anwser;
			cin >> anwser;
			if (anwser == '1')loop(1, System);
			if (anwser == '2')System.t_filein();
			System.t_fileout(); //将添加的信息存入文件中
			break;
		case 2://find
			loop(2, System);
			break;
		case 3://delete	
			loop(3, System);
			System.t_fileout();//将删除后的整体信息存入文件中
			break; 
		case 4://edit
			loop(4, System);
			System.t_fileout();
			break; 
		case 5://analyze
			loop(5, System);
			break;
		case 6://sort
			System.t_sort();
			System.t_fileout();
			break;
		case 7:

		case 0:
			Operating_parameter = 0;     //通过将该参数置0退出该程序
			system("cls");
			cout << "-------Quit management system successfully-------" << endl;
			Sleep(300);
		}
	}
	return 0;
}
