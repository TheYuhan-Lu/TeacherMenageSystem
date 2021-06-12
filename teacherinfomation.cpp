#include "teacherinfomation.h"
#include<iomanip>
using namespace std;

void management::t_add() {
	
		teacherinfo new_t;  //通过构造函数来输入数据
		m_teachers_list.push_back(new_t); //将构造的一个teacherinfo对象放入m_teachers_list中
};

vector<teacherinfo> management::t_find() {    //这里还需解决find容器复用的问题，是否每次都自动清除或消亡？
	vector<teacherinfo> rightinformation;
	cout << "Select the information you want to use as the search criteria:\n"
		<< "1.Name or ID\n2.Range of payable wages, actual wages and provident fund\n3.Fuzzy search\n4.Back\nType the number to choose a function:" << endl;
	int secchoice, k = 0;
	cin >> secchoice;
	switch (secchoice) {
	case 1: {
		cout << "Type the Name or ID:" << endl;
		string info;
		cin >> info;
		cout << "|--------------------------------------------------------------------------|" << endl
			<< "|     id    | name |  unit  |   number   |basic salary| bonus | tax | fund |" << endl
			<< "|--------------------------------------------------------------------------|" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
			if ((*it).t_id == info || (*it).t_name == info) {
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;
			}
		}
		if (k == 0) {
			cout << "No compliant information in the system" << endl;
			return rightinformation; }
		break;
	}
	case 2: {
		cout << "Tpye The Range of payable wages, actual wages and provident fund: " << endl;
		int a, b, c, d, e, f;
		cout << "( "; cin >> a; cout << " , "; cin >> b; cout << " )\n";
		cout << "( "; cin >> c; cout << " , "; cin >> d; cout << " )\n";
		cout << "( "; cin >> e; cout << " , "; cin >> f; cout << " )\n";//可再尝试用退格符改善排版
		cout << "|--------------------------------------------------------------------------|" << endl
			<< "|     id    | name |  unit  |   number   |basic salary| bonus | tax | fund |" << endl
			<< "|--------------------------------------------------------------------------|" << endl;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
			if ((((*it).t_sum_should <= b) && ((*it).t_sum_should >= a)) && (((*it).t_sum_exact <= d) && ((*it).t_sum_exact >= c)) && (((*it).t_fund <= f) && ((*it).t_fund >= e))) {
				cout << *it << endl;
				rightinformation.push_back(*it);
				k = 1;
			}
		}
		if (k == 0)cout << "No compliant information in the system" << endl;
		break;
	}
	/*case 3: {
		cout << "Type your Information:" << endl;
		string info2;
		cin >> info2;
		for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
			if (strstr((*it).t_name, info2) != NULL || strstr((*it).t_number, info2) != NULL || strstr((*it).t_unit, info2) != NULL) { //需要自定义一个与strstr()功能相同的函数以实现模糊查找
				int i = 1;
				cout << i << "." << *it << endl;
				rightinformation.push_back(*it);
				++i;
				k = 1;
			}
		}
		if (k == 0)cout << "No compliant information in the system" << endl;
		else {
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

void management::t_delete(const vector<teacherinfo>& a) {
	if(a.empty()==0){
		cout << "Are you sure to delete these infomation?(Y?N)\a" << endl;
		char judge = 'N';
		cin >> judge;
		if (judge == 'Y') {
			for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
				for (auto it1 = a.begin(); it1 != a.end(); ++it1) {
					if (*it == *it1) {
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

void management::t_edit(const vector<teacherinfo>& a) {
	if (a.empty() == 0){
		cout << "Choose which info you are going to edit:\n(1.id\n2.name\n3.unit\n4.number\n5.basicsalary\n6.bonus\n7.tax\n8.fund)" << endl;
		int judge;
		cin >> judge;
		switch (judge) {
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
	else {
		cout << "There is no information that can be edited\a" << endl;
	}
}
	


void management::t_editchoice(string str, const vector<teacherinfo>& a) {
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
		for (auto it1 = a.begin(); it1 != a.end(); ++it1) {
			if (*it == *it1) {
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

void management::t_editchoice(int n, const vector<teacherinfo>& a) {
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
		for (auto it1 = a.begin(); it1 != a.end(); ++it1) {
			if (*it == *it1) {
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

	
/*void management::t_salaryAnalyzeofUnit(string& unit) {
	cout << "Type the Unit you are going to analyze:" << endl;
	string info;
	cin >> info;
	double sum = 0, i = 0, k;
	for (auto it = m_teachers_list.begin(); it != m_teachers_list.end(); ++it) {
		if ((*it).t_unit == info) {
			cout << *it << endl;
			sum += (*it).t_sum_exact;
			k = 1;
		}
	}
}
void management::t_sort() {
//
}
void management::t_file() {}*/

ostream& operator<<(ostream& os, const teacherinfo& a) {
	os << setw(12) << a.t_id << setw(7) << a.t_name << setw(9) << a.t_unit << setw(12) << a.t_number 
		<< setw(14) << a.t_basic_salary << setw(8) << a.t_bonus << setw(6) << a.t_tax << setw(7) << a.t_fund << endl;
	return os;
}

bool operator==(teacherinfo& a, const teacherinfo& b) {
	return (a.t_name == b.t_name) && (a.t_id == b.t_id) && (a.t_number == b.t_number) && (a.t_unit == b.t_unit); //由于使用删除功能时，用到了一个const teacherinfo对象（不使用const类型会报错）和teacherinfo对象的比较，故重载==
}