#include"teacherinfomation.h"
/*system("cls");*/
//void continueapproaching(void a())
int main() 
{
	management System;
	System.t_filein("teacherdata.txt",0);
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
		cout << "++++++++++++++++++++++++++ menu ++++++++++++++++++++++++++ \n\t1.Add one information\n\t2.Find information from the system\n\t3.Find and delete information that you type\n\t4.Find and edit information\n\t5.Analyze information that you choose\n\t6.Sort the information\n\t7. show the information in system file \n\t0.Quit\n"
			<<"============================================================\n"<<"Type the number to choose a function:" << endl;
		int funcChoice;
		cin >> funcChoice;
		system("cls");//清除页面显示
		switch (funcChoice) 
		{   //每一个case中断后都会进入while循环
		case 1://add 
			cout<< "============================================================\n"
				<<"\t1 add by typing\n\t2 add by scan a file\n\t3 Cancel\n" 
				<< "============================================================\n"
				<< "Which way you area gonna to choose to add information?" << endl;
			char anwser;
			cin >> anwser;
			if (anwser != '1' && anwser != '2')break;
			if (anwser == '1')loop(1, System);
			if (anwser == '2') 
			{	
				cout << "============================================================\n"
					<<"Type the name of your file:";
				string a;
				cin >> a;
				System.t_filein(a,1);
			}
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
			System.t_filein("teacherdata.txt", 1);
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

