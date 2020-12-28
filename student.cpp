#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "Student.h"
using namespace std;
studentDB::studentDB()
{
	firstname="";
	lastname="";
	id="";
	midterm1=0;
	midterm2=0;
	current_grade='\0';
	cur_grade =0;
}
studentnode::studentnode()
{
	next=NULL;
	prev=NULL;
}
linkedlist::linkedlist()
{
	head=NULL;
	tail=NULL;
}
linkedlist::~linkedlist()
{
	studentnode *garbage;
	while(head != NULL)
	{
	garbage = head;
	head = head->next;
	delete garbage;
	}
	delete head;
	delete tail;
}
void linkedlist::createlist(string first, string last,string stid, double mid1, double mid2)
{
	studentnode *newnode= new studentnode();
	newnode->firstname = first;
	newnode->lastname = last;
	newnode->id= stid;
	newnode->midterm1= mid1;
	newnode->midterm2=mid2;
	newnode->cur_grade = (newnode->midterm1+newnode->midterm2)/2;
	if(newnode->cur_grade < 60 )
	{
		newnode->current_grade = 'D';
	}
	else if(newnode->cur_grade > 60 && newnode->cur_grade < 70)
	{
		newnode->current_grade = 'C';
	}
	else if(newnode->cur_grade > 70 && newnode->cur_grade < 85)
	{
		newnode->current_grade = 'B';
	}
	else if(newnode->cur_grade > 85)
	{
		newnode->current_grade = 'A';
	}
	if(head==NULL)
			{
				head = newnode;
				tail = newnode;
				head->prev=NULL;
				head->next=NULL;
			}
			else if(head != NULL)
			{
				tail->next=newnode;
				newnode->prev=tail;
				tail=tail->next;
			}
}
void linkedlist::printlist(int size)
{
	int space=16;
	int space_bar = 17;
	int from_id_to_mid=12;
	if(size==0)
	{
	cout<<"The list has no element."<<endl;
	}
		else if(size>0)
	{
		studentnode *temp=head;
		cout<<"First name"<<setw(space)<<"Last name"<<setw(space-6)<<"ID"<<setw(space-2)<<"Mid1"<<setw(space-7)<<"Mid 2"<<"   Grade"<<endl;
	for(int i=0; i< size ; i++)
	{
	     cout<<temp->firstname;
	     int f_size = temp->firstname.size();
        for(int i = 0; i < space_bar - f_size; i++ )
	    {
	     cout<<" ";
	     }
          cout<<temp->lastname;
          int l_name = temp->lastname.size();
         for(int i = 0; i < space_bar - l_name; i++ )
	     {
	     cout<<" ";
	      }
          cout<<temp->id;
          int id_size = temp->id.size();
          for(int i = 0; i < from_id_to_mid - id_size; i++ )
	      {
	      cout<<" ";
	      }
          cout<<temp->midterm1<<setw(9)<<temp->midterm2<<setw(5)<<temp->current_grade<<endl;
          temp=temp->next;
	      }
     }
}
bool linkedlist::professor_access(string pass)
{
	string access="yesiam";
	if(pass == access)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void linkedlist::adjust_first_last_name(string &first,string &last)
{
	int f_size = first.size();
	for(int i=0; i < f_size; i++)
	{
		if(i==0)
		{
		first[i]= toupper(first[i]);
		}
		else
		{
		first[i]= tolower(first[i]);
		}
	}
	int l_size = last.size();
	for(int i=0; i < l_size; i++)
		{
			if(i==0)
			{
			last[i]= toupper(last[i]);
			}
			else
			{
		     last[i]= tolower(last[i]);
			}
		}
}
void linkedlist::find_student(string f, string l,int &pos)
{
	studentnode *temp=head;
	pos=0;
	while(temp->next != NULL)
	{
		if (temp->firstname == f && temp->lastname == l)
		{
			break;
		}
		else
		{
			temp=temp->next;
			pos += 1;
		}
	}
	if (temp->firstname != f && temp->lastname != l)
	{
		cout<<"Your name is not in the list"<<endl;
		pos = -1;
	}
}
void linkedlist::print_student_info(int size,int pos)
{

	studentnode *temp= head;
	for(int i =0; i < size; i++)
	{
		if(i==pos)
		{
			cout<<"First and last name: "<<temp->firstname<<" "<<temp->lastname<<endl;
			cout<<"Student ID: "<<temp->id<<endl;
			cout<<"Midterm 1 and Midterm2 scores: "<<temp->midterm1<<" | "<<temp->midterm2<<endl;
			cout<<"Current grade is "<<temp->current_grade<<endl;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
}
void linkedlist::testing_final(int size,int pos)
{
	studentnode *temp= head;
		for(int i =0; i < size; i++)
		{
			if(i==pos)
			{
				char grade;
				double final_exam;
				cout<<"Enter grade you want for the class. ";
				cin>>grade;
				grade = toupper(grade);
				while (temp->current_grade -2 == grade || temp->current_grade +2 ==grade)
				{
					cout<<"Your grade can change up to 1 letter grade(for example: from C to B, not C to A)."<<endl;
					cout<<"Please re-enter grade you want for the class based on your current grade."<<endl;
					cin>>grade;
				}
				if (grade == 'A'|| grade =='a')
				{
					final_exam= (85 - ((1- 0.5) * temp->cur_grade))/0.5;
				}
				else if(grade == 'B'|| grade =='b')
				{
					final_exam= (70 - ((1- 0.5) * temp->cur_grade))/0.5;
				}
				else if(grade == 'C'|| grade =='c')
				{
					final_exam= (60 - ((1- 0.5) * temp->cur_grade))/0.5;
				}
				cout<<"In order to get a(n) "<<grade<<" for this course, ";
				cout<<"Your final exam score must be "<<final_exam<<" "<<endl;
			}
			else
			{
				temp=temp->next;
			}
		}
}

void linkedlist::operator+(linkedlist &obj1)
{
	studentnode *temp=obj1.head;
	while (temp!=NULL)
	{
		studentnode *newnode= new studentnode();
		newnode->firstname= temp->firstname;
		newnode->lastname = temp->lastname;
		newnode->id= temp->id;
		newnode->midterm1= temp->midterm1;
		newnode->midterm2=temp->midterm2;
		newnode->cur_grade=(newnode->midterm1 + newnode->midterm2)/2;
		if(newnode->cur_grade < 60 )
			{
				newnode->current_grade = 'D';
			}
			else if(newnode->cur_grade > 60 && newnode->cur_grade < 70)
			{
				newnode->current_grade = 'C';
			}
			else if(newnode->cur_grade > 70 && newnode->cur_grade < 85)
			{
				newnode->current_grade = 'B';
			}
			else if(newnode->cur_grade > 85)
			{
				newnode->current_grade = 'A';
			}
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
		tail->next=NULL;
		temp=temp->next;
	}
}
void linkedlist::add_student_by_name()
{
	studentnode *newnode = new studentnode();
	cout<<"What is your first name? ";
	cin>>newnode->firstname;
	cout<<"What is your last name? ";
	cin>>newnode->lastname;
	adjust_first_last_name(newnode->firstname,newnode->lastname);
	cout<<"What is your id ?(ID should contain 9 digits starting with 0)";
	cin>>newnode->id;
	newnode->midterm1 = (rand() %100)+ 0.5;
	newnode->midterm2 = rand() %100+0.5;
	newnode->cur_grade = (newnode->midterm1+newnode->midterm2)/2;
		if(newnode->cur_grade < 60 )
		{
			newnode->current_grade = 'D';
		}
		else if(newnode->cur_grade > 60 && newnode->cur_grade < 70)
		{
			newnode->current_grade = 'C';
		}
		else if(newnode->cur_grade > 70 && newnode->cur_grade < 85)
		{
			newnode->current_grade = 'B';
		}
		else if(newnode->cur_grade > 85)
		{
			newnode->current_grade = 'A';
		}
		tail->next=newnode;
		newnode->prev=tail;
		newnode->next =NULL;
		tail=newnode;
}
void linkedlist::drop_a_student(int pos,int &size)
{
	if(pos == 0) // if the position at head
	{
		studentnode *temp=head;
		head= temp->next;
		head->prev=NULL;
		temp->next=NULL;
		delete temp;
		size--;
	}
	else if(pos== size-1) // if the position at tail
	{
		studentnode *temp=tail;
		tail=temp->prev;
		tail->next=NULL;
		temp->prev=NULL;
		delete temp;
		size--;
	}
	else
	{
		int counter=0;
		studentnode *temp=head;
		while(temp!=NULL)
		{
			if(counter == pos)
			{
			studentnode *front_temp=temp->prev;
			studentnode *after_temp= temp->next;
			front_temp->next = after_temp;
			after_temp->prev=front_temp;
			temp->next=NULL;
			temp->prev=NULL;
			delete temp;
			break;
			}
			else
			{
			counter++;
			temp=temp->next;
			}
		}
		size--;
	}
}
void linkedlist::reverse_the_list(int size)
{
	if(size==0)
	{
		cout<<"The list has no element, so there is nothing to reverse."<<endl;
	}
	else if(size>0)
	{
	studentnode *temp = NULL;
	head=tail;
	while (tail != NULL)
	{
		temp= tail->next;
		tail->next= tail->prev;
		tail->prev=temp;
		if(tail->next == NULL)
		{
			cout<<"The list is already reversed."<<endl;
			break;
		}
		tail= tail->next;
	}
	}
}
void linkedlist::save_to_a_file()
{
	ofstream outfile;
	outfile.open("src/OUTPUT.txt");
	if(outfile.fail())
	{
		exit(1);
	}
	studentnode *temp=head;
	while (temp!=NULL)
	{
		if(temp->next==NULL)
		{
	    outfile << temp->firstname <<"  "<<temp->lastname<<"  "<<temp->id<<"  "<<temp->midterm1<<"  "<<temp->midterm2;
	    break;
		}
		outfile<<temp->firstname<<"  "<<temp->lastname<<"  "<<temp->id<<"  "<<temp->midterm1<<"  "<<temp->midterm2<<endl;
		temp=temp->next;
	}
}
void linkedlist::swap_data(studentnode *left,studentnode *right)
{
	string temp_f,temp_l,temp_id;
	double mid1,mid2,cur_grade;
	char curr_grade;
	temp_f=right->firstname;
	temp_l=right->lastname;
	temp_id=right->id;
	mid1=right->midterm1;
	mid2=right->midterm2;
	cur_grade=right->cur_grade;
	curr_grade=right->current_grade;


	right->firstname=left->firstname;
	right->lastname=left->lastname;
	right->id=left->id;
	right->midterm1=left->midterm1;
	right->midterm2=left->midterm2;
	right->cur_grade=left->cur_grade;
	right->current_grade=left->current_grade;

	left->firstname=temp_f;
	left->lastname=temp_l;
	left->id=temp_id;
	left->midterm1=mid1;
	left->midterm2=mid2;
	left->cur_grade=cur_grade;
	left->current_grade=curr_grade;
}
void linkedlist::sort_student_by_name()
{
	studentnode *first;
	bool swap;
	do{
	first=head;
	swap=false;
	while(first->next != NULL)
	{
			if((first->next->firstname[0] < first->firstname[0])||
			((first->next->firstname[0] == first->firstname[0]) && (first->next->lastname[0] < first->lastname[0])))
			{
				swap_data(first,first->next);
				swap=true;
			}
			first=first->next;
	}
	}while(swap);
}
void linkedlist::sort_student_by_grade()
{
	studentnode *first;
	bool swap;
	do{
	first=head;
	swap=false;
	while(first->next != NULL)
	{
			if(first->next->cur_grade < first->cur_grade)
			{
				swap_data(first,first->next);
				swap=true;
			}
			first=first->next;
	}
	}while(swap);
}
int linkedlist::find_largest(studentnode *current, double n)
{
	if(current->next == NULL) {
		cout<<n<<endl;
		return n;}
	else{
		double val= current->cur_grade;
		double max = current->next->cur_grade;
		if(val>max && val>=n)
		{
			n=val;
		}
		else if (val<max && n <= max )
		{
			n = max;
		}
		return find_largest(current->next,n);

	}


}
void linkedlist::find_best_student_basedon_the_score(int &pos, double best)
{
  studentnode *temp=head;
  while(temp->next != NULL)
  {
	  if(temp->cur_grade == best)
	  {
		  break;
	  }
	  else
	  {
		  temp=temp->next;
		  pos++;
	  }
  }
}
