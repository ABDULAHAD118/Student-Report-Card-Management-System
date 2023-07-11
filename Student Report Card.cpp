#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class student
{
protected:
	int rollno;
	char name[50];
	double p_marks, c_marks, m_marks, e_marks, cs_marks;
	double per;
	char grade;
private:
	void calculate();//THIS IS PRIVATE FUNCTION WHICH IS USED TO CALCULATE GARDE
public:
	void getdata();		
	void showdata() const;	
	int retrollno() const;
}; 

void student::calculate()
{
	per = (p_marks + c_marks + m_marks + e_marks + cs_marks) / 500 *100;
	if (per >= 90)
		grade = 'A';
	else if (per >= 80)
		grade = 'B';
	else if (per >= 80)
		grade = 'C';
	else if (per >= 50)
		grade = 'D';
	else
		grade = 'F';
}

void student::getdata()
{
	cout<<"\nEnter The roll number of student : ";
	cin>>rollno;
	cout<<"\n\nEnter The Name of student : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The marks in physics out of 100 : ";
	cin>>p_marks;
	cout<<"\nEnter The marks in chemistry out of 100 : ";
	cin>>c_marks;
	cout<<"\nEnter The marks in maths out of 100 : ";
	cin>>m_marks;
	cout<<"\nEnter The marks in english out of 100 : ";
	cin>>e_marks;
	cout<<"\nEnter The marks in computer science out of 100 : ";
	cin>>cs_marks;
	calculate();
}

void student::showdata() const
{
	cout<<"\n\tRoll number of student : "<<rollno;
	cout<<"\n\tName of student : "<<name;
	cout<<"\n\tMarks in Physics : "<<p_marks;
	cout<<"\n\tMarks in Chemistry : "<<c_marks;
	cout<<"\n\tMarks in Maths : "<<m_marks;
	cout<<"\n\tMarks in English : "<<e_marks;
	cout<<"\n\tMarks in Computer Science :"<<cs_marks;
	cout<<"\n\tPercentage of student is  :"<<per<<"%";
	cout<<"\n\tGrade of student is :"<<grade;
	cout << "\n\n\t=================================\n";
}

int  student::retrollno() const
{
	return rollno;
}		

class result:public student
{
	public:
		void intro();			
		void result1();			
		void class_result();	
		void display_sp(int);	
		void entry_menu();
		void write_student_data();			
		void modify_student(int);
		void delete_student(int);
		void end();
};

int main()
{
	result res;
	char ch;
	res.intro();
	bool flag = true;
	while(flag)
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. RESULT MENU";
		cout<<"\n\n\t02. ENTRY/EDIT MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) ";
		cin>>ch;
		switch(ch)
		{
			case '1': res.result1();
				break;
			case '2': res.entry_menu();
				break;
			case '3':
				flag = false;
				break;
			default :cout<<"\a";
		}
    }
    system("cls");
    res.end();
	return 0;
}

void result::intro()
{
	cout<<"\n\n\n\n";
	cout<<"\t  #####  ####### #     # ######  ####### #     # #######    ######  ####### ######  ####### ######  #######     #####     #    ######  ######  "<<endl;
	cout<<"\t #     #    #    #     # #     # #       ##    #    #       #     # #       #     # #     # #     #    #       #     #   # #   #     # #     # "<<endl;
	cout<<"\t #          #    #     # #     # #       # #   #    #       #     # #       #     # #     # #     #    #       #        #   #  #     # #     # "<<endl;
	cout<<"\t  #####     #    #     # #     # #####   #  #  #    #       ######  #####   ######  #     # ######     #       #       #     # ######  #     # "<<endl;
	cout<<"\t       #    #    #     # #     # #       #   # #    #       #   #   #       #       #     # #   #      #       #       ####### #   #   #     # "<<endl;
	cout<<"\t #     #    #    #     # #     # #       #    ##    #       #    #  #       #       #     # #    #     #       #     # #     # #    #  #     # "<<endl;
	cout<<"\t  #####     #     #####  ######  ####### #     #    #       #     # ####### #       ####### #     #    #        #####  #     # #     # ######  "<<endl;
	cout<<"\n\n";
	cout<<"\t  #####  ######  #######    #    ####### ####### ######     ######  #     #    "<<endl;  
	cout<<"\t #     # #     # #         # #      #    #       #     #    #     #  #   #     "<<endl;
	cout<<"\t #       #     # #        #   #     #    #       #     #    #     #   # #      "<<endl;
	cout<<"\t #       ######  #####   #     #    #    #####   #     #    ######     #       "<<endl;
	cout<<"\t #       #   #   #       #######    #    #       #     #    #     #    #       "<<endl;
	cout<<"\t #     # #    #  #       #     #    #    #       #     #    #     #    #       "<<endl;
	cout<<"\t  #####  #     # ####### #     #    #    ####### ######     ######     #       "<<endl;
    cout<<"\n\n";       
	cout<<"\t\t\t\t\t\t\t\t\t\t  #####  ######  ####### #     # ######          ###    #####  "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t #     # #     # #     # #     # #     #        #   #  #     # "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t #       #     # #     # #     # #     #       #     #       # "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t #  #### ######  #     # #     # ######  ##### #     #  #####  "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t #     # #   #   #     # #     # #             #     # #       "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t #     # #    #  #     # #     # #              #   #  #       "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t\t  #####  #     # #######  #####  #               ###   ####### "<<endl;
                                                                                                                                  
	cin.get();
}

void result::result1()
{
	char ch;
	int rno;
	system("cls");
	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Result";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\t3. Back to Main Menu";
	cout<<"\n\n\n\tEnter Choice (1-3) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1' :	class_result(); break;
	case '2' :	cout<<"\n\n\tEnter Roll Number Of Student : "; cin>>rno;
				display_sp(rno); break;
	case '3' :	break;
	default:	cout<<"\a";
	}
}

void result::class_result()
{
	result res;
	ifstream inFile;
	inFile.open("student.txt",ios::app|ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\t\tALL STUDENTS RESULT \n\n";
	while(inFile.read((char *) &res, sizeof(result)))
	{
		res.showdata();
	}
	cin.ignore();
	cin.get();
	inFile.close();
}

void result::display_sp(int n)
{
	result res;
	ifstream inFile;
	inFile.open("student.txt",ios::app|ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read((char *)&res, sizeof(result)))
	{
		if(res.retrollno()==n)
		{
	  		 res.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nrecord not exist";
	cin.ignore();
	cin.get();
}

void result::entry_menu()
{
	char ch;
	int num;
	system("cls");
	bool flag =true;
	while(flag){
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.MODIFY STUDENT RECORD";
	cout<<"\n\n\t3.DELETE STUDENT RECORD";
	cout<<"\n\n\t4.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-4) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student_data(); break;
	case '2':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			modify_student(num);break;
	case '3':	cout<<"\n\n\tPlease Enter The roll number "; cin>>num;
			delete_student(num);break;
	case '4':	flag=false; break;
	default:	cout<<"\a";
	}
}
}

void result::write_student_data()
{
	result res;
	ofstream outFile;
	outFile.open("student.txt",ios::app|ios::binary);
	res.getdata();
	outFile.write((char *)&res, sizeof(result));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
	system("cls");
}

void result::modify_student(int n){   
	result res;
	ifstream inFile;
	inFile.open("student.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt");
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &res, sizeof(result)))
	{
		if(res.retrollno()!=n)
		{
			outFile.write((char *) &res, sizeof(result));
			cout << "Record Not Exist ..";
			break;

		}
		else{
			res.getdata();
			outFile.write((char *) &res, sizeof(result));
			cout<<"\n\n\tRecord Updated ..";
		}
	}
	outFile.close();
	inFile.close();
	remove("student.txt");
	rename("Temp.txt","student.txt");
	cin.ignore();
	cin.get();
	system("cls");
}

void result::delete_student(int n)
{
	result res;
	ifstream inFile;
	inFile.open("student.txt");
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.txt");
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &res, sizeof(result)))
	{
		if(res.retrollno()!=n)
		{
			outFile.write((char *) &res, sizeof(result));
			cout << "Record Not Exist ..";
			break;
		}
		else
		{
			cout<<"\n\n\tRecord Deleted ..";
		}
	}
	outFile.close();
	inFile.close();
	remove("student.txt");
	rename("Temp.txt","student.txt");
	cin.ignore();
	cin.get();
	system("cls");
}

void result::end(){
	cout<<"\n\n\n";
	cout<<"\t #######  #     #     #     #     #  #    #      #     #  #######  #     # "<<endl;
	cout<<"\t    #     #     #    # #    ##    #  #   #        #   #   #     #  #     # "<<endl;
	cout<<"\t    #     #     #   #   #   # #   #  #  #          # #    #     #  #     # "<<endl;
	cout<<"\t    #     #######  #     #  #  #  #  ###            #     #     #  #     # "<<endl;
	cout<<"\t    #     #     #  #######  #   # #  #  #           #     #     #  #     # "<<endl;
	cout<<"\t    #     #     #  #     #  #    ##  #   #          #     #     #  #     # "<<endl;
	cout<<"\t    #     #     #  #     #  #     #  #    #         #     #######   #####  "<<endl;
	cin.ignore();
	cin.get();                                                                
}
