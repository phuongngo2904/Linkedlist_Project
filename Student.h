#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdlib>
#include <iomanip>
class studentDB
{
public:
studentDB();
string firstname, lastname,id;
double midterm1, midterm2;
double cur_grade;
char current_grade;
};

class studentnode : public studentDB
{
public:
    studentnode();
    studentnode *next;
    studentnode *prev;

};

class linkedlist
{
public:
	linkedlist();
	~linkedlist();
	studentnode *head;
	studentnode *tail;
	void createlist(string first, string last,string stid, double mid1, double mi2);
	void printlist(int size);
	bool professor_access(string pass);
	void find_student(string f,string l,int &pos);
	void print_student_info(int size,int pos);
	void testing_final(int size,int pos);
	void operator+(linkedlist &obj1);
	void drop_a_student(int pos,int &size);
	void save_to_a_file();
	void sort_student_by_grade();
	void sort_student_by_name();
	void reverse_the_list(int size);
	void adjust_first_last_name(string &first,string &last);
	void add_student_by_name();
	void swap_data(studentnode *left,studentnode *right);
	int find_largest(studentnode *current, double n);
	void find_best_student_basedon_the_score(int &pos,double best);

};


#endif /* STUDENT_H_ */
