#include "teacherinfomation.h"

using namespace std;

void management::t_add() 
{
	
		teacherinfo new_t;  //通过构造函数来输入数据
		m_teachers_list.push_back(new_t); //将构造的一个teacherinfo对象放入m_teachers_list中
};

vector<teacherinfo> management::t_find() 
{    //这里还需解决find容器复用的问题，是否每次都自动清除或消亡？
	vector<teacherinfo> rightinformation;
	cout << "Select the information you want to use as the search criteria:\n"
		<< "1.Name or ID\n2.Range of payable wages, actual wages and provident fund\n3.Fuzzy search\n4.Back\nType the number to choose a function:" << endl;
	int secchoice, k = 0;
	cin >> secchoice;
	switch (secchoice) 
	{
	case 1: 
	{
		cout << "Type the Name or ID:" << endl;
		string info;
		cin >> info;
		cout << "---------------------------------------------------------------------------------------" << endl
			<< "|    id    |" << " name |" << " unit |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
			<< "---------------------------------------------------------------------------------------" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
		{
			if ((*it).t_id == info || (*it).t_name == info) 
			{
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;   //k用于判断是否有匹配项，相当于输出容器是否为空的判断
			}
		}
		if (k == 0) 
		{
			cout << "No compliant information in the system" << endl;
			return rightinformation; 
		}
		break;
	}
	case 2: 
	{
		cout << "Tpye The Range of payable wages, actual wages and provident fund: " << endl;
		int a, b, c, d, e, f;
		cout << "( "; cin >> a; cout << " , "; cin >> b; cout << " )\n";
		cout << "( "; cin >> c; cout << " , "; cin >> d; cout << " )\n";
		cout << "( "; cin >> e; cout << " , "; cin >> f; cout << " )\n";//可再尝试用退格符改善排版
		cout << "---------------------------------------------------------------------------------------" << endl
			<< "|    id    |" << " name |" << " unit |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
			<< "---------------------------------------------------------------------------------------" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
		{
			if ((((*it).t_sum_should <= b) && ((*it).t_sum_should >= a)) && (((*it).t_sum_exact <= d) && ((*it).t_sum_exact >= c)) && (((*it).t_fund <= f) && ((*it).t_fund >= e))) 
			{
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;
			}
		}
		if (k == 0)cout << "No compliant information in the system" << endl;
		break;
	}
	/*case 3: 
	{
		cout << "Type your Information:" << endl;
		string info2;
		cin >> info2;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
		{
			if (strstr((*it).t_name, info2) != NULL || strstr((*it).t_number, info2) != NULL || strstr((*it).t_unit, info2) != NULL) 
			{ //需要自定义一个与strstr()功能相同的函数以实现模糊查找
				int i = 1;
				cout << i << "." << *it << endl;
				rightinformation.push_back(*it);
				++i;
				k = 1;
			}
		}
		if (k == 0)cout << "No compliant information in the system" << endl;
		else 
		{
			cout << "chose your destination info(type the number before the info)" << endl;
			int x;
			cin >> x;                                //模糊查找时二次选择信息
			cout << rightinformation.at(x) << endl;
			vector<teacherinfo> rightinformation1 = { rightinformation.at(x) };
			return rightinformation1;
		}
		break;
	}*/
		  
	}
	return rightinformation;
}

void management::t_delete(const vector<teacherinfo>& a) 
{
	if(a.empty()==0)
	{
		cout << "Are you sure to delete these infomation?(Y?N)\a" << endl;
		char judge = 'N';
		cin >> judge;
		if (judge == 'Y') 
		{
			for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
			{
				for (auto it1 = a.begin(); it1 != a.end(); ++it1) 
				{
					if (*it == *it1) 
					{
						m_teachers_list.erase(it);  //这里可能要调用其他函数释放删除了之后容器的空间
					}
				}
				if (m_teachers_list.empty())break;//通过判断容器是否为空决定是否继续遍历老师名单容器
			}//删除两个容器重合的部分，通过两个迭代器分别遍历两个容器中的元素，找出相同的项，通过m_teachers_list.erase(it)
			cout << "Complete!\a" << endl;
		}
	}
	else { cout << "There is no information that can be deleted" << endl; }
	
}

void management::t_edit(const vector<teacherinfo>& a) 
{
	if (a.empty() == 0)
	{
		cout << "Choose which info you are going to edit:\n(1.id\n2.name\n3.unit\n4.number\n5.basicsalary\n6.bonus\n7.tax\n8.fund)" << endl;
		int judge;
		cin >> judge;
		switch (judge) 
		{
		case 1:
			t_editchoice("id", a); break;
		case 2:
			t_editchoice("name", a); break;
		case 3:
			t_editchoice("unit", a); break;
		case 4:
			t_editchoice("number", a); break;
		case 5:
			t_editchoice(5, a); break;
		case 6:
			t_editchoice(6, a); break;
		case 7:
			t_editchoice(7, a); break;
		case 8:
			t_editchoice(8, a); break;
		}
		cout << "Info has been changed!\a" << endl;	
	}
	else 
	{
		cout << "There is no information that can be edited\a" << endl;
	}
}
	


void management::t_editchoice(string str, const vector<teacherinfo>& a) 
{
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
	{
		for (auto it1 = a.begin(); it1 != a.end(); ++it1) 
		{
			if (*it == *it1) 
			{
				cout << "the last info is : "<<*it;
				cout << "type the new info!:" << endl;
				if (str == "id")cin >> (*it).t_id;
				else if (str == "name")cin >> (*it).t_name;
				else if (str == "unit")cin >> (*it).t_unit;
				else if (str == "number")cin >> (*it).t_number;
			}
		}

	}
}

void management::t_editchoice(int n, const vector<teacherinfo>& a) 
{
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
	{
		for (auto it1 = a.begin(); it1 != a.end(); ++it1) 
		{
			if (*it == *it1) 
			{
				cout << "the last info is : " << *it;
				cout << "type the new info!:" << endl;
				if (n == 5)cin >> (*it).t_basic_salary;
				else if (n == 6)cin >> (*it).t_bonus;
				else if (n == 7)cin >> (*it).t_tax;
				else if (n == 8)cin >> (*it).t_fund;
			}
		}

	}
}

	
void management::t_salaryAnalyzeofUnit() 
{
	cout << "Type the Unit you are going to analyze:" << endl;
	string info;
	cin >> info;
	cout << "Which information you would like to analyze?\n" << "1 Final Paying Amount\n2 Total Pay Amount\n3 Provident Fund\n4 all of above"<<endl;
	int anwser = 0,k = 0;
	cin >> anwser;
	vector<teacherinfo> rightinformation;
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) 
	{
		if ((*it).t_unit == info) 
		{
			rightinformation.push_back(*it);
			k = 1;
		}
	}
	if (anwser == 1 || anwser == 2 || anwser == 3)
	{
		cout << "The average salary is:" << averaging(rightinformation, anwser) << endl;
		cout << "Standard deviation is:" << Standard_deviation(rightinformation, anwser) << endl;
	}
	else 
	{
		cout << "Average Final Paying Amount:"<<averaging(rightinformation, 1)<<endl;
		cout << "Standard deviation is:" << Standard_deviation(rightinformation, 1) << endl;
		cout << "Average Total Pay Amount:" << averaging(rightinformation, 2) << endl;
		cout << "Standard deviation is:" << Standard_deviation(rightinformation, 2) << endl;
		cout << "Average Provident Fund:" << averaging(rightinformation, 3) << endl;
		cout << "Standard deviation is:" << Standard_deviation(rightinformation, 3) << endl;
	}

}
void management::t_sort() 
{
	int n = m_teachers_list.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (m_teachers_list[j] < m_teachers_list[j+1])
				swap(m_teachers_list[j], m_teachers_list[j+1]);
		}
	}
	cout << "---------------------------------------------------------------------------------------" << endl
		 << "|    id    |" << " name |" << " unit |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
		 << "---------------------------------------------------------------------------------------" << endl;
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << "Back to the main menu...\a";
	Sleep(3000);
}

/*void management::t_file() {}*/

ostream& operator<<(ostream& os, const teacherinfo& a) 
{
	os << setw(12) << a.t_id << setw(7) << a.t_name << setw(9) << a.t_unit << setw(12) << a.t_number
		<< setw(14) << a.t_basic_salary << setw(8) << a.t_bonus << setw(6) << a.t_tax << setw(7) << a.t_fund << setw(8) << a.t_sum_exact << endl;
	return os;
}

bool operator==(teacherinfo& a, const teacherinfo& b) 
{
	return (a.t_name == b.t_name) && (a.t_id == b.t_id) && (a.t_number == b.t_number) && (a.t_unit == b.t_unit); //由于使用删除功能时，用到了一个const teacherinfo对象（不使用const类型会报错）和teacherinfo对象的比较，故重载==
}

bool operator<(teacherinfo& a, const teacherinfo& b)
{
	if (a.t_sum_exact < b.t_sum_exact)return 1;
	else {
		if (a.t_sum_exact == b.t_sum_exact)
		{
			if (a.t_fund < b.t_fund)return 1;
			else 
			{
				if (a.t_fund == b.t_fund)
				{
					if (a.t_id < b.t_id)return 1;
					else return 0;
				}
				else return 0;
			}
		}
		else return 0;
	}
}

void loop(int x, management& a) //主程序中的循环函数
{
	char answer;
	do {
		if (x == 1)a.t_add();
		if (x == 2)a.t_find();
		if (x == 3)a.t_delete(a.t_find());
		if (x == 4)a.t_edit(a.t_find());
		if (x == 5)a.t_salaryAnalyzeofUnit();
		cout << "Continue ?(Y/N):" << endl;        //是否继续查找数据
		cin >> answer;
	} while (answer == 'Y');
	cout << "Back to the main menu...\a";
	Sleep(300);
}

double averaging(const vector<teacherinfo>& a, int b)
{
	double sum = 0;
	for (auto it = a.begin(); it != a.end(); ++it)
	{
		if (b == 1)sum += (*it).t_sum_exact;
		if (b == 2)sum += (*it).t_sum_should;
		if (b == 3)sum += (*it).t_fund;
	}
	return sum / a.size();
}

double Standard_deviation(const vector<teacherinfo>& a, int b)
{
	double sum = 0;
	for (auto it = a.begin(); it != a.end(); ++it)
	{
		if (b == 1)sum += ((*it).t_sum_exact - averaging(a, 1)) * ((*it).t_sum_exact - averaging(a, 1));
		if (b == 2)sum += ((*it).t_sum_should - averaging(a, 2)) * ((*it).t_sum_should - averaging(a, 2));
		if (b == 3)sum += ((*it).t_fund - averaging(a, 3)) * ((*it).t_fund - averaging(a, 3));
	}
	return sqrt(sum / a.size());
}
