#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
    
int AddStudent();   
void DisplayAll();
void DisplayByroom_no();
int SearchByStud_no(); 
void DeleteStudent(); 
int ModifyStudent(); 
int addroom();
void displayroom();
int deleteroom();
void change_cur_accom(int,int);  
int check(int);

class Student{
    int stud_no;
    char name[25];
    char mobile[15];
    int room_no;
    public:
    int getstud_no() {return stud_no;}
    int getroom_no() { return room_no;}
    void storeData()
    {
        cout<<"\n............... NEW  RECORD...............\n";
        cout<<"Enter Student ID : "; cin>>stud_no; cin.ignore();
        cout<<"Enter Name   : "; cin.getline(name,25);
        cout<<"Enter Mobile Number : "; cin.getline(mobile,15);
        cout<<"Enter Room No to be alloctaed : "; cin>>room_no; cin.ignore();
        cout<<endl;
    }
    void showData()
    {
        cout<<"\n............... RECORD...............\n";
        cout<<"Student ID	: "<<stud_no<<endl;
        cout<<"Name	   : "<<name<<endl;
        cout<<"Mobile No	: "<<mobile<<endl;
        cout<<"Room No 	 : "<<room_no<<endl;
    }
}b;

class room
{
	int room;
	int max_accom;
	int cur_accom;
public:
	int getroom_no(){return room;}
	int getcur_accom(){return cur_accom;}
	int getmax_accom(){return max_accom;}
	void inrcur_accom(){ cur_accom=cur_accom+1;}
	void deccur_accom(){ cur_accom=cur_accom-1;}
	void storeData()
    {
        cout<<"\n...............ROOM RECORD...............\n";
        cout<<"Enter Room No : "; cin>>room; cin.ignore();
        cout<<"Enter Maximaum Accomodation  : "; cin>>max_accom; cin.ignore();
        cout<<"Enter Current Accomodation : ";cin>>cur_accom; cin.ignore();
    }
    void showData()
    {
        cout<<"\n...............ROOM RECORD...............\n";
        cout<<"Room No   : "<<room<<endl;
        cout<<"Maximaum Accomodation : "<<max_accom<<endl;
        cout<<"Current Accomodation : "<<cur_accom<<endl;
    }
}r;

int AddStudent()
{
	int rm;
    ofstream fout;
    int flag_add;
    fout.open("HOSTEL.dat",ios::out|ios::binary|ios::app);
    b.storeData();
    rm=b.getroom_no();
    flag_add=check(b.getroom_no());
    if(flag_add==0)
	{
		fout.write((char*)&b,sizeof(b));
	    fout.close();
	    cout<<"\nRecord Saved to File......\n";
	    change_cur_accom(rm,0);
	}	
	else
	{
		cout<<"\nRoom full choose another room.\n";
		fout.close();
	}
	
	return 0;		
}

void DisplayAll()
{
    ifstream fin;
    fin.open("HOSTEL.dat",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&b,sizeof(b)))
    {
        b.showData();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}
void DisplayByroom_no()
{
	int x;
    ifstream fin;
    fin.open("HOSTEL.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter room_no to be displayed"<<endl;
    cin>>x;
    while(fin.read((char*)&b,sizeof(b)))
    {
    	if(b.getroom_no()==x)
    	{
        	b.showData();
		}
		
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

int SearchByStud_no()
{
    ifstream fin;
    int n, flag=0;
    fin.open("HOSTEL.dat",ios::out|ios::binary|ios::app);
    cout<<"Enter Student ID To Display: ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getstud_no())
        {
            b.showData();
            flag=1;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    return flag;
}

void DeleteStudent()
{
    ifstream fin;
    ofstream fout;
    int n,rm, flag=0;
    fin.open("HOSTEL.dat",ios::out|ios::binary|ios::app);
    fout.open("temp.dat",ios::out|ios::binary);
    cout<<"Enter Student ID To Delete : ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getstud_no())
        {
        	rm=b.getroom_no();
            cout<<"\nThe Following student ID is deleted....\n";
            b.showData();
            change_cur_accom(rm,1);
        }
        else
        {
            fout.write((char*)&b,sizeof(b));
        }
    }
    fin.close();
    fout.close();
    remove("HOSTEL.dat");
    rename("temp.dat","HOSTEL.dat");

}
int ModifyStudent()
{
	int temproom;
    fstream fio;
    int n, graphic_modify_student=0, pos;
    fio.open("HOSTEL.dat",ios::out|ios::binary|ios::in);

    cout<<"Enter Student ID To Modify : ";
    cin>>n;

    while(fio.read((char*)&b,sizeof(b)))
    {
        pos=fio.tellg();
        if(n==b.getstud_no())
        {
            cout<<"\nThe Following student record will be modified....\n";
            b.showData();
            temproom=b.getroom_no();
            cout<<"\nEnter New Details.....\n";
            b.storeData();
            if(temproom!=b.getroom_no())
            {
            	change_cur_accom(0,b.getroom_no());
            	change_cur_accom(1,temproom);
            	
			}
            fio.seekg(pos-sizeof(b));
            fio.write((char*)&b,sizeof(b));
            cout<<"\n Record is modified....\n";
            
        }
    }
    fio.close();
    cout<<"\n Cannot find particular student....\n";
    return 0;
}

int addroom()
{
    ofstream fout;
    fout.open("room.dat",ios::out|ios::binary|ios::app);
    r.storeData();
    fout.write((char*)&r,sizeof(r));
    fout.close();
	cout<<"Room added succesfully..."<<endl;
}

void displayroom()
{
    ifstream fin;
    fin.open("room.dat",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&r,sizeof(r)))
    {
        r.showData();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

int deleteroom()
{	
    ifstream fin;
    ofstream fout;
    int n, flag=0;
    fin.open("room.dat",ios::out|ios::binary|ios::app);
    fout.open("temp.dat",ios::out|ios::binary);
    cout<<"Enter Room Number To Delete Room Record : ";
    cin>>n;

    while(fin.read((char*)&r,sizeof(r)))
    {
        if(n==r.getroom_no())
        {
            cout<<"\nThe Following record is deleted....\n";
            r.showData();
        }
        else
        {
            fout.write((char*)&r,sizeof(r));
        }
    }
    fin.close();
    fout.close();
    remove("room.dat");
    rename("temp.dat","room.dat");
    cout<<"Cannot find room"<<endl;
    return 0;
}

int check(int x)
{
    ifstream fin;
    int n, flag;
    fin.open("room.dat",ios::out|ios::binary|ios::app);
	n=x;

    while(fin.read((char*)&r,sizeof(r)))
    {
        if(n==r.getroom_no())
        {
           if(r.getcur_accom()==r.getmax_accom())
           {
           	flag=1;
		   }
		   else if(r.getcur_accom()>r.getmax_accom())
		   {
		   	flag=1;
		   }
        }
        else
        {
        	flag=0;
		}
    }
    fin.close();
    return flag;
}

void change_cur_accom(int x,int y)
{
	fstream fio;
    int n, flag=0,pos;
    fio.open("room.dat",ios::out|ios::binary|ios::in);
	n=x;

    while(fio.read((char*)&r,sizeof(r)))
    {
        pos=fio.tellg();
        if(n==r.getroom_no())
        {
        	if(y==0)
            {
				r.inrcur_accom();
            	fio.seekg(pos-sizeof(r));
            	fio.write((char*)&r,sizeof(r));
            }
            else if(y==1)
            {
            	r.deccur_accom();
            	fio.seekg(pos-sizeof(r));
            	fio.write((char*)&r,sizeof(r));
			}
        }
    }
    fio.close();
}

