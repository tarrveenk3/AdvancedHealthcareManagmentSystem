//Hospital Management System
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;
void login();

int main()
{
char fname[20];
time_t rawtime;
struct tm * timeinfo;

time ( &rawtime );
timeinfo = localtime ( &rawtime );




//printing the welcome note
re:
cout<<"\n\t\t\t\t\t\t\t\t\t  WELCOME TO\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM\n";




int i;
login();




//giving option to the user for their choice
b:
cout<<"\n\n\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM \n\n";
cout<<"\n\n\t\t\tPlease,  Choose from the following Options: \n\n";
cout<<"\t\t\t\t\t1  >> Add New Patient Record\n";
cout<<"\t\t\t\t\t2  >> Our Doctors\n";
cout<<"\t\t\t\t\t3  >> Full History of the Patient\n";
cout<<"\t\t\t\t\t4  >> About the Hospital\n";
cout<<"\t\t\t\t\t5  >> Exit the Program \n";

a:
cout<<"\n\t\t\t\t\t\tEnter your choice: ";cin>>i;cout<<"\n\n\n";




//if inputed choice is other than given choice
if(i>5||i<1)
{
	cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";
	cout<<"\t\t\t\t\t\tTry again...........\n\n";
	goto b;
}




//Adding the record of the new patient..................option 3
if(i==1)
{
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  cout<<"\n\n\t\t\t\t\t\t\t\t"<< asctime (timeinfo);
  ofstream pat_file;
  char fname[20];
  cout<<"\n\n\n\nEnter the patient's file name : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
            struct patient_info
            {
                char name[20];
                char address[100];
                char contact[10];
                char age[5];
                char sex[8];
                char blood_gp[5];
                char disease_past[50];
                char id[15];
			};
			struct app
			{
				char symptom[500];
                char diagnosis[500];
                char medicine[500];
				char admission[30];
                char ward[15];
            };
			char temp;
			int roomNo;
			app add;
            patient_info ak;
            cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";//fn1353 st
            cout<<"\nName : ";pat_file<<"Name : ";gets(ak.name);pat_file<<ak.name<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";gets(ak.address);pat_file<<ak.address<<"\n";
            cout<<"\nContact Number : ";pat_file<<"Contact Number : ";gets(ak.contact);pat_file<<ak.contact<<"\n";
            cout<<"\nAge : ";pat_file<<"Age : ";gets(ak.age);pat_file<<ak.age<<"\n";
            cout<<"\nSex : ";pat_file<<"Sex : ";gets(ak.sex);pat_file<<ak.sex<<"\n";
            cout<<"\nBlood Group : ";pat_file<<"Blood Group : ";gets(ak.blood_gp);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";gets(ak.disease_past);pat_file<<ak.disease_past<<"\n";
            cout<<"\nPatient ID : ";pat_file<<"Patient ID : ";gets(ak.id);pat_file<<ak.id<<"\n";
            cout<<"\nSymptoms : "; pat_file<<"Symptoms : ";gets(add.symptom); pat_file<<add.symptom<<"\n";
            cout<<"\nDiagnosis : "; pat_file<<"Diagnosis : ";gets(add.diagnosis); pat_file<<add.diagnosis<<"\n";
            cout<<"\nAdmission Required?: Y or N ? ";
cin>>temp;
if(temp=='Y')
{
	cout<<"\nRoom No : ";
cin>>roomNo;
pat_file<<"Room No : ";
pat_file<<roomNo<<"\n";pat_file<<"\n*************************************************************************\n";
			}
			cout<<"\nInformation Saved Successfully\n";
			cout<<"\n********************************************************************\n";pat_file<<"\n********************************************************************\n\n";
            fstream filep;
  filep.open("patients.txt");
  if(!filep)
  {
	  cout<<"\nError while entering the file name\n";goto b;
  }
  else
  {
	  filep.close();
	  filep.open("patients.txt", ios::out | ios::app);
	  filep<<ak.name;
	  filep<<"\n";
	  filep.close();
  }
			}
  system("pause");
  system("cls");
  goto b;

}




//displaying the List of Doctors working in the hospital........option 2
if(i==2)
{
	ifstream file;
	file.open("doctors.txt");
		if(!file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\n\t\t\t\t\t   ...........................Our Doctors.............................\n\n";
		    string line;
			while(file.good())
			{
			getline(file,line);
			cout<<line<<"\n\t\t";
			}
			cout<<"\n\n\t\t";
			goto b;
		}
}




//For displaying the full medical history of patient in that hospital............option 3
if(i==3)
{
    fstream pat_file;

	cout<<"\n\n\t\t\t\t\t   ...........................Patients List.............................\n\n";
	ifstream file;
	file.open("patients.txt");
	if(!file)
	{
	cout<<"\nError while opening the file\n";goto b;
	}
	else
	{
	    string line;
		while(file.good())
		{
		getline(file,line);
		cout<<line<<"\n\t\t";
		}
		cout<<"\n\n\t\t";
	}

    cout<<"\n\nEnter the patient's file name to be opened : ";
    cin.ignore();
    gets(fname);
    system("cls");
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\n\n\n\t\t\t\t........................................ Full Medical History of "<<fname<<" ........................................\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        system("pause");
        system("cls");
        goto b;
}




//displaying the information about the hospital........option 4
if(i==4)
{
	ifstream file;
	file.open("hos.txt");
		if(!file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\n\n\t\t\t\t\t   ...........................Information about the Hospital.............................\n\n";
		    string line;
			while(file.good())
			{
			getline(file,line);
			cout<<line<<"\n\t\t";
			}
			cout<<"\n\n\t\t";
			goto b;
		}
}



//Exiting Through the system with a Thank You note........................option 5
if(i==5)
{
	cout<<"\t\t\t\t\t                               THANK YOU FOR USING                                     \n";
	cout<<"\t\t\t\t\t                                                                                       \n";
	cout<<"\t\t\t\t\t                            HOSPITAL MANAGEMENT SYSTEM                                 \n";
}


cout<<"\n";

}

void login(){
   string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13)
   {
	  //character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass")
   {
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
   }
   else
   {
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      login();
   }
}

