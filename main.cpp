#include"teacherinfomation.h"
#include <stdlib.h>
/*system("cls");*/
//void continueapproaching(void a())
int main() 
{
	management System;
	int Operating_parameter = 1;
	while (Operating_parameter == 1) 
	{
		system("cls");//清除页面显示（改
		cout << " __________________________________________________________" << endl
			<< "|                                                          |" << endl
			<< "|    _/_ _ _ / _ _  _  _   _ _ _ _  _  _/   _    __/_ _    |" << endl
			<< "|    /(-(/( /)(-/  //)(//)(/(/(-//)(-/)/  _) (/_) /(-//)   |" << endl
			<< "|                          _/                /             |" << endl
			<< "|__________________________________________________________|" << endl << endl;
		cout << "menu:\n1.Add one information\n2.Find information from the system\n3.Find and delete information that you type\n4.Find and edit information\n5.Analyze information that you choose\n6.Sort the information\n7.Operating file\n0.Quit\nType the number to choose a function:" << endl;
		int funcChoice;
		cin >> funcChoice;
		system("cls");//清除页面显示（改
		switch (funcChoice) 
		{   //每一个case中断后都会进入while循环
		case 1://add 
		{
			loop(1, System);
			break;
		}
		case 2://find
		{
			loop(2, System);
			break;
		}
		case 3://delete
		{	
			loop(3, System);
			break; 
		}
		case 4://edit
		{
			loop(4, System);
			break; 
		}
		case 5://analyze
			loop(5, System);
			break;
		case 6://sort
			System.t_sort();
			break;
		case 7://file manufacture
			//System.t_file();
			break;
		case 0:
			Operating_parameter = 0;     //通过将该参数置0退出该程序
			system("cls");
			cout << "-------Quit management system successfully-------" << endl;
			Sleep(300);
		}
	}
	return 0;
}
