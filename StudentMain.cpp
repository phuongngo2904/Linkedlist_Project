#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "Student.h"
using namespace std;
int size_of_class = 20;
int main() {
	fstream infile,waitlist;
	int size=0;
	string first,last,id;
	double mid1,mid2;
	int wait_list=0;
	linkedlist cmp126,wlist;
	infile.open("studentlist.txt");
	waitlist.open("waitlist.txt");

	if(waitlist.fail())
	{
		cout<<"The File does not exist."<<endl;
		exit(1);
	}
	if(infile.fail())
	{
		cout<<"The File does not exist."<<endl;
		exit(1);
	}
	while(!infile.eof())
	{
		infile>>first>>last>>id>>mid1>>mid2;
		cmp126.createlist(first,last,id,mid1,mid2);
		size++;
    }
	while(!waitlist.eof())
	{
		waitlist>>first>>last>>id>>mid1>>mid2;
		wlist.createlist(first,last,id,mid1,mid2);
		wait_list++;
    }
	int stu_or_prof;
	cout<<"This is compe 126. Are you a student or professor of this course ?"<<endl;
	cout<<"1. Professor Frank Lin."<<endl;
	cout<<"2. Student."<<endl;
	cin>>stu_or_prof;
	while(stu_or_prof <0 || stu_or_prof >2)
	{
		cout<<"Invalid  input. Please re-enter:  ";
		cin>>stu_or_prof;
	}
	switch(stu_or_prof)
{
	// option 1: prof access
	case 1:
	{
		string pw="yesiam";
		int attemp=3;
		cout<<"Please enter your password to access:";
//        cin>>pw;
		cout<<"---------------------------------------------"<<endl;
		if(!(cmp126.professor_access(pw)))
		{
			for(int i=0; i < attemp; i++)
			{
				int test= attemp-1-i;
				cout<<"You still have "<<test<<" attemp(s)."<<endl;
				if(test==0)
				{
					cout<<"Too many attemps. Aborting the program."<<endl;
					exit(1);
				}
				cout<<"Wrong password.Please re-enter. ";
				cin>>pw;

				if(cmp126.professor_access(pw))
				{
					break;
				}
			}
		}
		if(cmp126.professor_access(pw))
		{
			cout<<"I am Frank Lin. I want to:"<<endl;
			int opt;
     do{
    	 	cout<<"0. Exit the program."<<endl;
			cout<<"1. See the list."<<endl;
			cout<<"2. Check the waiting list."<<endl;
			cout<<"3. Add students to the course"<<endl;
			cout<<"4. Drop a student from the course."<<endl;
			cout<<"5. Reverse the list."<<endl;
			cout<<"6. Save eveything I just did to a file."<<endl;
			cout<<"7. Sort students in ascending order."<<endl;
			cout<<"8. Find the student who has the best score."<<endl;
			cin>>opt;
	switch (opt)
	{
		case 0:
		{
			exit(1);
		}
		case 1:
		{
			cmp126.printlist(size);
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 2:
		{
			if(wait_list == 0 )
			{
				cout<<"The waiting list is empty."<<endl;
			}
			else if(wait_list <= size_of_class)
			{
			wlist.printlist(wait_list);
			cout<<"--------------------------------------------------------------"<<endl;
			}
			break;
		}
		case 3:
		{
			int w_list_or_by_name;
			cout<<"Do you want to add "<<endl;
			cout<<"1. The whole waiting list"<<endl;
			cout<<"2. By a student name"<<endl;
			cin>>w_list_or_by_name;
			switch(w_list_or_by_name)
			{
			case 1:
				{
					if(wait_list != 0 && (size + wait_list)<= size_of_class)
					{
					size += wait_list;
					wait_list =0;
					cmp126 + wlist;
					}
					else if ((size + wait_list) > size_of_class)
					{
						cout << "The size is " << size << ". If you add entire waiting list(which has "<<wait_list<<" students) ";
						cout<<"the size becomes " << size + wait_list;
						cout << " which is greater than the actual size of the class(20)." << endl;
					}
					else
					{
						cout<<"The waitlist is empty. There's nothing to add."<<endl;
					}
					break;
				}
			case 2:
				{
					if(size < size_of_class)
					{
						cmp126.add_student_by_name();
						size++;
					}
					else if( size >= size_of_class )
					{
						cout<<"The class is full"<<endl;
					}
					break;
				}
			}

			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 4:
		{
			string first, last;
			cout<<"Please enter student's name that you want to drop."<<endl;
			cout<<"First name: ";
			cin>>first;
			cout<<"Last name: ";
			cin>>last;
			cmp126.adjust_first_last_name(first,last);
			int pos=0;
			cmp126.find_student(first,last,pos);
			while (pos == -1)
			{
				cout<<"Please check the file studentlist.txt or waitlist.txt to see if you are in the list."<<endl;
				cout<<"What is your first name ? ";
				cin>>first;
				cout<<"What is your last name ? ";
				cin>>last;
				cmp126.adjust_first_last_name(first,last);
				cmp126.find_student(first,last,pos);
			}
			cmp126.drop_a_student(pos,size);
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 5:
		{
			cmp126.reverse_the_list(size);
			cout<<"The list has been reversed."<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 6:
		{
			cmp126.save_to_a_file();
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 7:
		{
			int grade_or_name;
			cout<<"Do you want to sort by "<<endl;
			cout<<"1. Grade."<<endl;
			cout<<"2. Name."<<endl;
			cin>>grade_or_name;
			switch(grade_or_name)
			{
				case 1:
					{
						cmp126.sort_student_by_grade();
						break;
					}
				case 2:
					{
						cmp126.sort_student_by_name();
						break;
					}
			}

			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
		case 8:
		{
			double best=0;
			int position=0;
			best = cmp126.find_largest(cmp126.head,best);
			cmp126.find_best_student_basedon_the_score(position, best);
			cout<<"The student who has the best score is: "<<endl;
			cmp126.print_student_info(size, position);
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
	}
	}while (opt !=0);
		}
		break;
	}

// option 2 ( student access) below

	case 2:
	{
		string f_name,l_name;
		cout<<"What is your first name ? ";
		cin>>f_name;
		cout<<"What is your last name ? ";
		cin>>l_name;
		cmp126.adjust_first_last_name(f_name,l_name);
		int pos=0;
		cmp126.find_student(f_name,l_name,pos);
		while (pos == -1)
		{
			cout<<"Please check the file studentlist.txt or waitlist.txt to see if you are in the list."<<endl;
			cout<<"What is your first name ? ";
			cin>>f_name;
			cout<<"What is your last name ? ";
			cin>>l_name;
			cmp126.adjust_first_last_name(f_name,l_name);
			cmp126.find_student(f_name,l_name,pos);
		}
		int option;
do{
			cout<<"Pick an optipon below."<<endl;
			cout<<"0. Exit the program."<<endl;
			cout<<"1. Print your information."<<endl;
			cout<<"2. Testing the final scores and see your final grade."<<endl;

			cin>>option;
	switch(option)
	{
	case 1:
	{
		cmp126.print_student_info(size,pos);
		cout<<"--------------------------------------------"<<endl;
		break;
	}
	case 2:
	  {
		cmp126.testing_final(size,pos);
		cout<<"--------------------------------------------"<<endl;
		break;
	  }
	case 0:
	  {
		exit(1);
		break;
	  }
	}
}while (option!=0);
		cin.ignore();
		break;
	}
}
	return 0;
}
