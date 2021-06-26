#include "teacherinfomation.h"

using namespace std;

void management::t_add()
{
	teacherinfo new_t;
	cout <<"please enter the info of the teacher\n"
		 << "---------------------------------------------------------------------------" << endl
		 << "|    id    |" << " name |" << " unit |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |" << endl
		 << "---------------------------------------------------------------------------" << endl;
	cin >> new_t.t_id >> new_t.t_name >> new_t.t_unit >> new_t.t_number >> new_t.t_basic_salary >> new_t.t_bonus >> new_t.t_tax >> new_t.t_fund;//ͨ�����캯������������
	new_t.t_sum_should = new_t.t_basic_salary + new_t.t_bonus, new_t.t_sum_minus = new_t.t_tax + new_t.t_fund, new_t.t_sum_exact = new_t.t_basic_salary + new_t.t_bonus - new_t.t_tax - new_t.t_fund;
	m_teachers_list.push_back(new_t); //�������һ��teacherinfo�������m_teachers_list��

};

vector<teacherinfo> management::t_find()
{
	vector<teacherinfo> rightinformation;
	cout << "Select the information you want to use as the search criteria:\n"
		<< "============================================================\n"
		<< "\t1.Name or ID\n\t2.Range of payable wages, actual wages and provident fund\n\t3.Fuzzy search(with id,name,number,unit)\n\t4.Cancel\n"
		<< "============================================================\n"
		<<"Type the number to choose a function:" << endl;
	int secchoice, k = 0;
	cin >> secchoice;
	switch (secchoice)
	{
	case 1:
	{

		cout << "Type the Name or ID:" << endl;
		string info;
		cin >> info;
		cout << "-------------------------------------------------------------------------------------------" << endl
			<< "|    id    |" << "  name  |" << "  unit  |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
			<< "-------------------------------------------------------------------------------------------" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
		{
			if ((*it).t_id == info || (*it).t_name == info)//��������������Ϣ�ȶ�
			{
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;   //k�����ж��Ƿ���ƥ����൱����������Ƿ�Ϊ�յ��ж�
			}
		}
		if (k == 0)
		{
			cout << "==========  No compliant information in the system  ========" << endl;
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
		cout << "( "; cin >> e; cout << " , "; cin >> f; cout << " )\n";
		system("cls");
		cout << "-------------------------------------------------------------------------------------------" << endl
			<< "|    id    |" << "  name  |" << "  unit  |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
			<< "-------------------------------------------------------------------------------------------" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
		{
			if ((((*it).t_sum_should <= b) && ((*it).t_sum_should >= a)) && (((*it).t_sum_exact <= d) && ((*it).t_sum_exact >= c)) && (((*it).t_fund <= f) && ((*it).t_fund >= e)))
			{
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;
			}
		}
		if (k == 0)cout << "\nNo compliant information in the system" << endl;
		break;
	}
	case 3:
	{
		cout << "Type your Information:" << endl;
		string info2;
		cin >> info2;
		int i = 1;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
		{
			if ((search((*it).t_name,info2) ) ||( search((*it).t_number, info2) ) || (search((*it).t_unit, info2) )||search((*it).t_id,info2))//����ģ����Ϣƥ��
			{ 
				
				cout << i << "." << *it << endl;
				rightinformation.push_back(*it);
				++i;
				k = 1;
			}
		}
		if (k == 0)cout << "\nNo compliant information in the system" << endl;
		else
		{
			cout << "\nchose your destination info(type the number before the info)" << endl;
			int x;
			cin >> x;                                //ģ������ʱ����ѡ����Ϣ
			cout << rightinformation.at(x-1) << endl;
			vector<teacherinfo> rightinformation1 = { rightinformation.at(x-1) };
			return rightinformation1;
		}
		break;
	}
	}
	return rightinformation;
}

void management::t_delete(const vector<teacherinfo>& a)
{
	if (a.empty() == 0)
	{
		cout << "Are you sure to delete these infomation?(Y/N)\a" << endl;
		char judge = 'N';
		cin >> judge;
		if (judge == 'Y')
		{
			char k = 0;//ͨ����ֵ�ĸ������������ɾ�������е�Ԫ�ض����µĴ���Ұָ�������
			for (auto it = m_teachers_list.begin(); it != m_teachers_list.end();)
			{
				for (auto it1 = a.begin(); it1 != a.end(); ++it1)
				{
					if (*it == *it1) {
						it = m_teachers_list.erase(it);//�������Ҫ�������������ͷ�ɾ����֮�������Ŀռ�
						k = 1;
						break;
					}
					else k = 0;
				}
				if (k == 0)it++; //��û����ɾ������ʱ���������������½�һλ
			}//ɾ�����������غϵĲ��֣�ͨ�������������ֱ�������������е�Ԫ�أ��ҳ���ͬ���ͨ��m_teachers_list.erase(it)
			cout << "\n============================Complete!=======================\a" << endl;
		}
	}
	else { cout  << "\n\nThere is no information that can be deleted" << endl; }
}

void management::t_edit(const vector<teacherinfo>& a)
{
	if (a.empty() == 0)
	{
		cout << "============================================================\n"
			<<"\t1.id\n\t2.name\n\t3.unit\n\t4.number\n\t5.basicsalary\n\t6.bonus\n\t7.tax\n\t8.fund\n\t9.cancel"
			<< "============================================================\n"
			<<"Choose which info you are going to edit:" << endl;
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
				cout << "the last info is : " << *it;
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
	cout << "Type the Unit you are going to analyze:��\"all\" to analyze all unit)" << endl;
	string info;
	cin >> info;
	cout <<"============================================================\n"
		 << "\t1 Final Paying Amount\n\t2 Total Pay Amount\n\t3 Provident Fund\n\t4 all of above\n\t5 Cancel\n" 
		 << "============================================================\n"
		 <<"Which information you would like to analyze?\n" << endl;
	int anwser = 0, k = 0;
	cin >> anwser;
	vector<teacherinfo> rightinformation;
	if (info == "all")rightinformation = m_teachers_list;
	else
	{
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
		{
			if ((*it).t_unit == info)   //ɸѡ��ĳ����λ��������Ϣ
			{
				rightinformation.push_back(*it);
				k = 1;
			}
		}
	}
	if (anwser == 1 || anwser == 2 || anwser == 3)
	{
		cout << "============================================================\n"
			 << "The average salary is:" << averaging(rightinformation, anwser) << "\n\n"
			 << "Standard deviation is:" << Standard_deviation(rightinformation, anwser) << "\n\n";
	}
	else if(anwser==4)
	{
		cout<<"============================================================\n"
			<< "Average Final Paying Amount: " << averaging(rightinformation, 1) << "\n\n"
			<< "Standard deviation is:" << Standard_deviation(rightinformation, 1) << "\n\n"
			<< "Average Total Pay Amount: " << averaging(rightinformation, 2) << "\n\n"
			<< "Standard deviation is: " << Standard_deviation(rightinformation, 2) << "\n\n"
			<< "Average Provident Fund: " << averaging(rightinformation, 3) << "\n\n"
			<< "Standard deviation is: " << Standard_deviation(rightinformation, 3) << "\n\n";
	}

}
void management::t_sort()
{
	int n = m_teachers_list.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (m_teachers_list[j] < m_teachers_list[j + 1])
				swap(m_teachers_list[j], m_teachers_list[j + 1]);//ð������
		}
	}

	cout << "-------------------------------------------------------------------------------------------" << endl
		 << "|    id    |" << "  name  |" << "  unit  |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |Final Salary|" << endl
		 << "-------------------------------------------------------------------------------------------" << endl;
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
	{
		cout << *it ;
	}

	cout << "\tBack to the main menu...\a\n";
	Sleep(5000);
}

void management::t_filein(string a,int b)//��ȡ�ļ���д�뵽ϵͳ��,b������Ϊ��ӡ�ļ���Ϣ�Ŀ���
{
	const teacherinfo x;
	char line[256];
	ifstream in(a);
	if (!in.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	while (!in.eof())
	{
		in.getline(line, 100);//���ж���
		teacherinfo new_t;
		new_t = line;
		if (new_t == x)continue;//���������Ϣ���ڸ�teacherinfo����ֵ
		if (b == 1)cout << new_t;
		m_teachers_list.push_back(new_t);
	}
}

void management::t_fileout()
{
	char anwser;
	cout << "\n\nDo you want to write the sorted information to a file?(Y/N)" << endl;
	cin >> anwser;
	if (anwser == 'Y')
	{
		ofstream out("teacherdata.txt");
		if (out.is_open() && !(m_teachers_list.empty()))//���ļ�����������Ϊ��ʱ����д�����
		{
			for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it)
			{
				out << *it;
			}
			out.close();
		}
	}
};

ostream& operator<<(ostream& os, const teacherinfo& a)
{
	os << setw(12) << a.t_id << setw(7) << a.t_name << setw(9) << a.t_unit << setw(14) << a.t_number
		<< setw(12) << a.t_basic_salary << setw(9) << a.t_bonus << setw(7) << a.t_tax << setw(7) << a.t_fund << setw(8) << a.t_sum_exact << endl;
	return os;
}

teacherinfo& teacherinfo::operator=(char a[])//���ء�="�ű����ڽ����ļ���ȡʱ���ļ��е����ݰ��е��뵽�����е�Ԫ����
{
	vector<string> b;
	char* c[100] = { 0 };
	char* tokenPtr = strtok_s(a, " ", c);//ͨ��strtok_s���ַ������зָ�
	while (tokenPtr != NULL)
	{
		b.push_back(tokenPtr);
		tokenPtr = strtok_s(NULL, " ", c);
	}
	if (b.size() != 0)
	{
		t_id = b.at(0);
		t_name = b.at(1);
		t_unit = b.at(2);
		t_number = b.at(3);
		t_basic_salary = atoi(b.at(4).c_str());
		t_bonus = atoi(b.at(5).c_str());
		t_tax = atoi(b.at(6).c_str());
		t_fund = atoi(b.at(7).c_str());
		t_sum_should = t_basic_salary + t_bonus;
		t_sum_minus = t_tax + t_fund;
		t_sum_exact = t_basic_salary + t_bonus - t_tax - t_fund;
	}
	return *this;
}

bool operator==(teacherinfo& a, const teacherinfo& b)
{
	return (a.t_name == b.t_name) && (a.t_id == b.t_id) && (a.t_number == b.t_number) && (a.t_unit == b.t_unit); //����ʹ��ɾ������ʱ���õ���һ��const teacherinfo���󣨲�ʹ��const���ͻᱨ����teacherinfo����ıȽϣ�������==
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

void loop(int x, management& a) //�������е�ѭ������
{
	char anwser;
	do {
		if (x == 1)a.t_add();
		if (x == 2)a.t_find();
		if (x == 3)a.t_delete(a.t_find());
		if (x == 4)a.t_edit(a.t_find());
		if (x == 5)a.t_salaryAnalyzeofUnit();
		cout << "\nContinue ?(Y/N):" << endl;        //�Ƿ������������
		cin >> anwser;
	} while (anwser == 'Y');
	cout << "\tBack to the main menu...\a\n";
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

bool search(string a, string b) //ģ������
{
	int e=0;
	for (int i = 0; i < a.size();++i)
	{
		if ((a.at(i) == b.at(0)) && ((a.size() - i) >= b.size()))
		{
			int j = i + 1;
			for (int x = 1; x < b.size(); ++j, ++x)
			{
				if (a.at(j) == b.at(x)) e = 1;
				else
				{
					e = 0; break;
				}
				if ((x == b.size() - 1) && (e == 1))return 1;
			}
		}
	}
	return 0; 
}