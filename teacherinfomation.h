#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<windows.h>


using namespace std;

class teacherinfo;

class management {
	vector<teacherinfo> m_teachers_list;
	public:
	void t_editchoice(string str, const vector<teacherinfo>& a);
	void t_editchoice(int str, const vector<teacherinfo>& a);
	vector<teacherinfo> t_find();
	void t_add();
	void t_delete(const vector<teacherinfo> &a);
	void t_edit(const vector<teacherinfo>& a);
	
	/*void t_salaryAnalyzeofUnit(string& unit);//���а�����ƽ�����ʵĺ���
	void t_sort();
	void t_file();*/
};

class teacherinfo {
	string t_id, t_name, t_unit, t_number;
	int t_basic_salary, t_bonus, t_tax, t_fund, t_sum_should, t_sum_minus, t_sum_exact;
public:
	teacherinfo()
		:t_id(""), t_name(""), t_unit(""), t_number(""), t_basic_salary(0), t_bonus(0), t_tax(0), t_fund(0), t_sum_should(0), t_sum_minus(0), t_sum_exact(0) {
		cout << "please enter the info of the teacher\n"
			 << "---------------------------------------------------------------------------" << endl
			 << "|    id    |" << " name |" << " unit |" << "    number    |" << "basic salary|" << " bonus |" << " tax |" << " fund |" << endl
			 << "---------------------------------------------------------------------------" << endl;
		cin >> t_id >> t_name >> t_unit >> t_number >> t_basic_salary >> t_bonus >> t_tax >> t_fund;
		t_sum_should = t_basic_salary + t_bonus, t_sum_minus = t_tax + t_fund, t_sum_exact = t_basic_salary + t_bonus - t_tax - t_fund;
	}
	teacherinfo(const teacherinfo& input):t_id(input.t_id), t_name(input.t_name), t_unit(input.t_unit), t_number(input.t_number),
		t_basic_salary(input.t_basic_salary), t_bonus(input.t_bonus), t_tax(input.t_tax), t_fund(input.t_fund),
		t_sum_should(input.t_sum_should), t_sum_minus(input.t_sum_minus), t_sum_exact(input.t_sum_exact) {}

	friend class management;
	friend ostream& operator<<(ostream& os, const teacherinfo& a);
	friend bool operator==(teacherinfo& a, const teacherinfo& b);
};