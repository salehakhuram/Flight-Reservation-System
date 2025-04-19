#include<iostream>
#include<fstream>
#include<cstdlib>//for rand() function
#include<ctime>//for adding time(0) functionality and to show current time
using namespace std;
void adminlogin()
{ //this will allow the admin to login and access the admin funtions if they are registered
    string pass, user, pass1, user1;
while(true)
{  cout<<fixed<<setprecision(3);
	cout << "\n=========================================" << endl;
    cout << "             Admin Login Page             " << endl;
    cout << "=========================================" << endl; 
    cout<<"Enter your username: ";
    cin>>user;
    cout<<"Enter your Password: ";
    cin>>pass;
    ifstream read;
	read.open("admin username password.txt");
    while(read>>user1>>pass1)
	{
    if(user==user1&&pass==pass1)
	{
    cout<<"Login Successful!\n";
    return;
  }
  
 }
    read.close();
    cout<<"Incorrect Credentials. Please enter correct username and password!"<<endl;
}
}

void passlogin()
{ //this will allow the user to register and login the passenger.
    string pass, user, pass1, user1;
while(true)
{
	int usersign;
	cout<<"Enter 0 if you are a first time user and enter 1 if you are not: \n";
	cin>>usersign;
	if(usersign==0)
	{
	cout << "\n =========================================" << endl;
    cout << "               SignUp Page                "<< endl;
    cout << "=======================================" << endl; 
    cout<<"Set your Username: ";
    cin>>user;
    cout<<"Set your Password: ";
    cin>>pass;
    ofstream write_data;
    write_data.open("passenger.txt",ios::app);
    write_data<<user<<" "<<pass<<endl;
    write_data.close();
    cout<<"Sign up Successful! PLease login now.\n";
     }
     
cout << "\n========================================" << endl;
cout << "             Passenger Login Page             " << endl;
cout << "========================================" << endl; 
cout<<"Enter your username: ";
cin>>user;
cout<<"Enter your Password: ";
cin>>pass;
ifstream read;
read.open("passenger.txt");
while(read>>user1>>pass1)
{
if(user==user1&&pass==pass1)
{
    cout<<"Login Successful!\n";
    return;
}
}
    read.close();
    cout<<"Incorrect Credentials. Please enter correct username and password!"<<endl;
}
}
void adminmenu(int* choice)
{ // this function will show the
// list of functions that admin can perform.
cout<<"\n---------Menu---------\n";
cout<<"1. Add Flight\n";
cout<<"2. Update Flight\n";
cout<<"3. Delete Flight\n";
cout<<"4. Manage Seat Availibilty\n";
cout<<"5. Send Confirmation Email\n";
cout<<"6. Exit\n";
cout<<"Make a choice by entering corresponding number from the given Menu: \n";
cin>>*choice;
}
void passmenu(int* choice)
{ //this will allow the user to access the passenger funtions from the menu after login process.
cout<<"\n---------Menu---------\n";
cout<<"1. Search Flights and Flight Details\n";
cout<<"2. Book Ticket\n";
cout<<"3. Check Flight status\n";
cout<<"4. Generate Boarding Pass\n";
cout<<"5. Cancel Booking\n";
cout<<"6. Exit\n";
cout<<"Make a choice by entering corresponding number from the given Menu: \n";
cin>>*choice;
}

void arr(string flightID[],string flightName[],string destination[],string source[],string schedule[],int i){
	//this will pass the details from the files to arrays.
	string c,d,e,f,g;
		ifstream read;
		read.open("total flights.txt");
	for(int a=0;a<i;a++)
	{
		read>>c;
		flightID[a]=c;
		}
		read.close();
		ifstream extract;
		extract.open("flight name.txt");
	for(int a=0;a<i;a++)
	{
		getline(extract,d);
		flightName[a]=d;
		}
        extract.close();
    ifstream fileread;
		fileread.open("destination.txt");
	for(int a=0;a<i;a++)
	{
		getline(fileread,e);
		destination[a]=e;
		}
        fileread.close();
    ifstream readin;
		readin.open("source.txt");
	for(int a=0;a<i;a++)
	{
		getline(readin,f);
		source[a]=f;
		}
        readin.close();
        ifstream readout;
		readout.open("schedule.txt");
	for(int a=0;a<i;a++)
	{
		getline(readout,g);
		schedule[a]=g;
		}
        readout.close();
}
   void FlightNames()
   {
   cout<<" Emirates\n Jeddah Airport\n United Airlines\n American Airlines\n Qatar Airways";
   }
   void Destinations()
   {
   cout<<" Paris\n Multan\n Jeddah\n Seoul\n Turkey";
   }
   void  Sources(){
   cout<<" Tokyo\n Bangkok\n Islamabad\n Delhi\n London";
   }
   
 void availableFlights()
 {
    cout<<"Available Flights:\n";
    cout<<"1. (A2B00)\n";
    cout<<"2. (2MN67)\n";
    cout<<"3. (S245H)\n";
    cout<<"4. (SA53A)\n";
    cout<<"5. (E47H2)\n";
 } 
 
void addflight(int i)
{
	//this will add flights if the admin wants to
	string idflight, name, destin, sourc;
	ofstream writes;
	cout << "\n=========================================" << endl;
    cout << "             Add a flight!             " << endl;
    cout << "==========================================" << endl; 
	cout<<"Enter the flight id for new flight:";
	writes.open("total flights.txt", ios::app);
	cin.ignore();
	getline(cin,idflight);
	writes<<endl<<idflight;
	writes.close();
	cout<<"Enter the flight name for new flight:";
			ofstream writein;
	writein.open("flight name.txt", ios::app);
	getline(cin,name);
	writein<<endl<<name;
	writein.close(); 
		cout<<"Enter the flight destination for new flight:";
			ofstream writefile;
	writefile.open("destination.txt", ios::app);
	getline(cin,destin);
	writefile<<endl<<destin;
	writefile.close(); 
	ofstream writesource;
		cout<<"Enter the flight source for new flight:";
	writesource.open("source.txt", ios::app);
	getline(cin,sourc);
	writesource<<endl<<sourc;
	writesource.close();     
	cout<<"New flight details have been successfully added!\n";  
	i=i+1;     
}

void update()
 { //this function will give the admin to update any flight if he/she wants it
    string flightID, flightname, flightdestination, flightsource, flightschedule;
    string tempID, tempname, tempdesti, tempsource, tempschedule;
    cout << "\n========================================" << endl;
    cout << "             Update Flight                 " << endl;
    cout << "==========================================" << endl;
	availableFlights(); 
    cout << "Enter the Flight ID you want to update: ";
    cin >> flightID;

    ifstream readID;
    ifstream readName;
    ifstream readDestination;
    ifstream readSource;
    ifstream readSchedule;

    ofstream tempIDFile;
    ofstream tempNameFile;
    ofstream tempDestFile;
    ofstream tempSourceFile;
    ofstream tempScheduleFile;

    readID.open("total flights.txt");
    readName.open("flight name.txt");
    readDestination.open("destination.txt");
    readSource.open("source.txt");
    readSchedule.open("schedule.txt");

    tempIDFile.open("temp_flights.txt", ios::app);
    tempNameFile.open("temp_flight_names.txt", ios::app);
    tempDestFile.open("temp_destinations.txt", ios::app);
    tempSourceFile.open("temp_sources.txt", ios::app);
    tempScheduleFile.open("temp_schedules.txt", ios::app);

    bool flightFound;

    while (getline(readID, tempID) && getline(readName, tempname) && 
           getline(readDestination, tempdesti) && getline(readSource, tempsource) && 
           getline(readSchedule, tempschedule))
		    {

        if (tempID == flightID)
		 {
            flightFound = true;
            cout << "Flight found! Enter the new details for the flight: \n";

            cout << "Enter the new flight name: ";
            cin.ignore();
            getline(cin, flightname);

            cout << "Enter the new destination for the flight: ";
            getline(cin, flightdestination);

            cout << "Enter the new source for the flight: ";
            getline(cin, flightsource);

            cout << "Enter the new schedule for the flight: ";
            getline(cin, flightschedule);

            tempname = flightname;
            tempdesti = flightdestination;
            tempsource = flightsource;
            tempschedule = flightschedule;
        }

        tempIDFile << tempID << endl;
        tempNameFile << tempname << endl;
        tempDestFile << tempdesti << endl;
        tempSourceFile << tempsource << endl;
        tempScheduleFile << tempschedule << endl;
    }

    if (!flightFound) 
	{
        cout << "Flight ID not found." << endl;
    } else {
        cout << "Flight details updated successfully!" << endl;
    }

    readID.close();
    readName.close();
    readDestination.close();
    readSource.close();
    readSchedule.close();

    tempIDFile.close();
    tempNameFile.close();
    tempDestFile.close();
    tempSourceFile.close();
    tempScheduleFile.close();

    remove("total flights.txt");
    remove("flight name.txt");
    remove("destination.txt");
    remove("source.txt");
    remove("schedule.txt");

    rename("temp_flights.txt", "total flights.txt");
    rename("temp_flight_names.txt", "flight name.txt");
    rename("temp_destinations.txt", "destination.txt");
    rename("temp_sources.txt", "source.txt");
    rename("temp_schedules.txt", "schedule.txt");
}
void deleteFlight()
{
	//this function will allow the admin to delete any delete any flight
    string flightID, tempID, tempname, tempdestination, tempsource, tempschedule;
    cout << "\n========================================" << endl;
    cout << "            Delete Flight                 " << endl;
    cout << "==========================================" << endl; 
    cout<<"Enter the flight ID you want to delete: ";
    availableFlights();
    cin>>flightID;
    ifstream readID;
    ifstream readName;
    ifstream readDestination;
    ifstream readSource;
    ifstream readSchedule;

    ofstream tempIDFile;
    ofstream tempNameFile;
    ofstream tempDestFile;
    ofstream tempSourceFile;
    ofstream tempScheduleFile;

    readID.open("total flights.txt");
    readName.open("flight name.txt");
    readDestination.open("destination.txt");
    readSource.open("source.txt");
    readSchedule.open("schedule.txt");

    tempIDFile.open("temp_flights.txt", ios::app);
    tempNameFile.open("temp_flight_names.txt", ios::app);
    tempDestFile.open("temp_destinations.txt", ios::app);
    tempSourceFile.open("temp_sources.txt", ios::app);
    tempScheduleFile.open("temp_schedules.txt", ios::app);

    bool flightFound;
    while (getline(readID, tempID) && getline(readName, tempname) && 
           getline(readDestination, tempdestination) && getline(readSource, tempsource) && 
           getline(readSchedule, tempschedule))
		    {

        if (tempID == flightID) 
		{
            flightFound = true;
            cout << "Flight found!";
            continue;
        }
        tempIDFile << tempID << endl;
        tempNameFile << tempname << endl;
        tempDestFile << tempdestination << endl;
        tempSourceFile << tempsource << endl;
        tempScheduleFile << tempschedule << endl;
    }
        if (!flightFound)
		 {
        cout << "Flight ID not found." << endl;
    } 
	else 
	{
        cout << "Flight details deleted successfully!" << endl;
    }
    readID.close();
    readName.close();
    readDestination.close();
    readSource.close();
    readSchedule.close();

    tempIDFile.close();
    tempNameFile.close();
    tempDestFile.close();
    tempSourceFile.close();
    tempScheduleFile.close();

    remove("total flights.txt");
    remove("flight name.txt");
    remove("destination.txt");
    remove("source.txt");
    remove("schedule.txt");

    rename("temp_flights.txt", "total flights.txt");
    rename("temp_flight_names.txt", "flight name.txt");
    rename("temp_destinations.txt", "destination.txt");
    rename("temp_sources.txt", "source.txt");
    rename("temp_schedules.txt", "schedule.txt");
    
}
//this function will allow the admin to manage seat availibility
void avail(string flightID[],int i, int availableSeats)
{
	string checkflight;
	 bool flightFound;
	time_t now =time(0);
	availableFlights();
	cout<<"Enter flight ID you want to check: ";
	cin>>checkflight;
	for(int a=0;a<i;a++)
	{
			if(flightID[a]==checkflight)
			{
				flightFound=true;
				cout<<"Flight "<<checkflight<<" has "<<availableSeats<<" seats at time "<<ctime(&now)<<endl;
			}
	}
	if(!flightFound)
	{
		cout<<"No flight of this ID has been found! ";
	}
}

void book(string flightID[],int i, int availableSeats)
{ //this function will let admin to book a flight
	string checkflight;
	bool flightFound;
	time_t now =time(0);
			availableFlights();
	cout<<"Enter flight ID you want to book your seat in: ";
	cin>>checkflight;
	srand(time(0));
	int bookedSeat=rand()%availableSeats+1; //we added plus 1 because it could completely divide and give 0 without it
	for(int a=0;a<i;a++)
	{
			if(flightID[a]==checkflight)
			{
				flightFound=true;
				cout<<"In flight "<<checkflight<<" seat no "<<bookedSeat<<" has been reserved for you at time: "<<ctime(&now)<<endl;
			}
	}
	availableSeats=availableSeats-1;
}
void del(string flightID[],int i, int availableSeats)
{ //this function will let admin delete a flight
	string checkflight;
	bool flightFound;
	int seatnum;
	time_t now =time(0);
			availableFlights();
	cout<<"Enter flight ID you want to cancel your seat in: ";
	cin>>checkflight;
	cout<<"Enter your seat number: ";
	cin>>seatnum;
	srand(time(0));
	for(int a=0;a<i;a++)
	{
			if(flightID[a]==checkflight)
			{
				flightFound=true;
				cout<<"In flight "<<checkflight<<" your booking at seat no "<<seatnum<<" has been cancelled at time: "<<ctime(&now)<<endl;
			}
	}
		if(!flightFound)
		{
		cout<<"No flight of this ID has been found! ";
	}
	availableSeats= availableSeats+1;
}
void search(string flightID[],string schedule[], int i, int availableSeats)
{
	string checkflight;
	 bool flightFound;
	time_t now =time(0);
			availableFlights();
	cout<<"Enter flight ID you want to check: ";
	cin>>checkflight;
	int bookedSeat=rand()%availableSeats+1; //we added plus 1 because it could completely divide and give 0 without it
	for(int a=0;a<i;a++)
	{
			if(flightID[a]==checkflight)
			{
				flightFound=true;
				cout<<"Flight ("<<checkflight<<") having details "<<schedule[a]<<" has "<<bookedSeat<<" seats at time "<<ctime(&now)<<endl;
			}
	}
	if(!flightFound)
	{
		cout<<"No flight of this ID has been found! ";
	}
	return;
}

void bookseat(string flightID[],string FlightName,string Source, string Destination, int i, int availableSeats){
	string name;
	string checkflight;
	bool flightFound;
	time_t now =time(0);
	cout<<"Enter your name: ";
	cin>>name;
	availableFlights();
	cout<<"Enter flight ID you want to book your seat in: ";
	cin>>checkflight;
	srand(time(0));
	int bookedSeat=rand()%availableSeats+1; //we added plus 1 because it could completely divide and give 0 without it
	ofstream write;
	write.open("reservations.txt", ios::app);
	for(int a=0;a<i;a++)
	{
			if(flightID[a]==checkflight)
			{
				flightFound=true;
				cout<<"In flight "<<checkflight<<" seat no "<<bookedSeat<<" has been reserved for Mr./Ms. "<<name<<" at time: "<<ctime(&now)<<endl;
				write<<"In flight "<<checkflight<<" seat no "<<bookedSeat<<" has been reserved for Mr./Ms. "<<name<<" at time: "<<ctime(&now)<<endl;
				cout << "\n========================================" << endl;
                cout << "                Your Ticket                   " << endl;
                cout << "=========================================" << endl;
                cout<<"Your seat number is :"<<bookedSeat<<endl;
                availableSeats=availableSeats-1;
                cout << "Booking successful! You have reserved a seat on " << FlightName<<" (" <<checkflight<< ")"<<"from"<<Source<<"to"<<Destination<<endl;
			}
	}
		if(!flightFound){
		cout<<"No flight of this ID has been found! ";
	}
	availableSeats=availableSeats-1;
    cout << "Remaining Seats: " << availableSeats<< endl;

	return;
}

void cancelBooking(string FlightID)
 {
    string username;
    bool flightFound = false;
    cin.ignore();
    cout << "Enter flight reservation details you want to cancel your booking in: ";
    getline(cin, FlightID); //In flight A2B00 seat no 40 has been reserved for Mr./Ms. Soha at time: Tue Jan 07 09:10:28 2025
    cout << "Enter your username: ";
    cin >> username;
    ifstream readFile;
    readFile.open("reservations.txt");
    ofstream tempFile;
	tempFile.open("temp_res.txt");
    string flight;
    while (getline(readFile, flight))
	 {
        if (flight == FlightID) 
		{
            flightFound = true;
            cout << "Your booking for flight " << FlightID << " has been canceled." << endl;
            continue;
        }
        tempFile << flight << endl;
    }
    readFile.close();
    tempFile.close();

    if (flightFound) {
        remove("reservations.txt");
        rename("temp_res.txt", "reservations.txt");
    } else {
        cout << "No booking found for the specified flight ID." << endl;
        remove("temp_res.txt");
    }
}
void checkstat(string flightID[],int i)
{
	string checkflight;
	int present;
	srand(time(0));
	time_t now=(time(0));
	present= rand()%100+1;
	bool flightFound;
	availableFlights();
		cout<<"Enter flight ID you want to track: ";
	cin>>checkflight;
		for(int a=0;a<i;a++){
			if(flightID[a]==checkflight)
			{
				flightFound=true;
					cout<<"Flight have ID "<<checkflight<<" is "<<present<<" mins late at present time "<<ctime(&now);

			}
	}
	if(!flightFound)
	{
		cout<<"No flight of this ID has been found! ";
	}
}
void boarding( string Name,string FlightID,string FlightName, string Source,string Destination, int seatnumber){
    cout <<"\n===========================================" << endl;
    cout <<"                 Boarding Pass           " << endl;
    cout <<"==============================================" << endl; 
    cout<<"       Passenger Name: "<<Name<<endl;
    cout<<"       Flight ID: "<<FlightID<<endl;
    cout<<"       Flight Name: "<<FlightName<<endl;
    cout<<"       Source: "<<Source<<endl;
    cout<<"       Destination: "<<Destination<<endl;
    cout<<"       Seat Number: "<<seatnumber<<endl;
    cout<<"----------------------------------------------------------\n";
    cout<<"Please arrive 2 hours before departure!\n";
    cout<<"Have a safe journey!\n";
    cout<<"----------------------------------------------------------\n";
}
int main(){
	 int availableSeats=60;
     int numFlights;  
	int i=20;                                                     
    int numDestinations;
    string flightID[i];
    string flightName[i];
    string destination[i];
    string source[i];
    string schedule[i];
    cout <<"\n                         ========================================" << endl;
    cout << "                                 Flight Management System!             " << endl;
    cout <<"                         ========================================" << endl; 
    cout<<"\nHello! Welcome to SER Flying Company.\n";
    string cat;
    int choice;
    cout<<"Please select your category from the given menu to login. "<<endl;
        cout<<"1. Admin\n";
        cout<<"2. Passenger\n";
        cin>>cat;
        //admin functionalities
         if (cat=="Admin"||cat=="admin"||cat=="1")
		 {
            cout<<"Welcome to the Login page! \n";
            adminlogin();
            arr(flightID,flightName,destination,source,schedule,i);
          do{ there:
		    adminmenu(&choice);
            switch(choice)
			{
            	case 1:
            		cout<<"We are going to add a flight. Get ready!\n";
                   addflight(i);
			break;
			case 2:
				cout<<"We are going to update a flight. Get ready!\n";
				update();
				break;
				case 3:
						cout<<"We are going to delete a flight. Get ready!\n";
					deleteFlight();
					break;
				    case 4:
						int choose;
						do{
							cout<<"1. Check availibilty\n2.Book Seat.\n3.Cancel Booking\n4.Exit\n";
							cout<<"Choose the option number from the given menu: \n";
							cin>>choose;
							switch(choose)
							{
							case 1:
						avail(flightID, i, availableSeats);
						break;
						case 2:
							book(flightID, i, availableSeats);
							break;
							case 3:
								del(flightID, i, availableSeats);
								break;
								case 4:
									cout<<"Exiting from Manage Seats Function! \n";
								goto there;
							}
                       if(choice>4||choice<1)
					   {
                    	cout<<"Please make a valid choice! \n";
                    }
						}
						while(choice<4||choice>1);
						case 5:
							cout<<"Confirmation email has been sent to the Passenger";
							break;
							case 6:
								cout<<"Exiting the program!";
								return 0;
								break;
								default:
									cout<<"Invalid choice ! Try again\n";
							}
                    }while(choice!=6);
    }
        else if(cat=="Passenger"||cat=="passenger"||cat=="2")
		{
             cout<<"Welcome to the Login page! ";
               arr(flightID,flightName,destination,source,schedule,i);
            passlogin();
            string Name,FlightID,FlightName, Source,Destination;
            int seatnumber;
            cin.ignore();
            ofstream write;
            write.open("details.txt", ios::app);
            cout<<"Enter name: ";
            getline(cin,Name);
            FlightNames();
            cout<<"\nEnter Flight name: ";
            getline(cin,FlightName);
            availableFlights();
            cout<<"\nEnter FlightID: ";
            getline(cin,FlightID);
            Sources();
            cout<<"\nEnter your Flight Source: ";
            getline(cin,Source);
            Destinations();
            cout<<"\nEnter your Flight Destination : ";
            getline(cin,Destination);
            cout<<"Enter your seat number: ";
            cin>>seatnumber;
            write<<"Name: \n"<<Name<<" Flight ID: \n"<<FlightID<<" Flight name: \n"
			<<FlightName<<" Source: \n"<<Source<<" Destination:\n"<<Destination<<
			" Seat number "<<seatnumber<<endl;
            write.close();
           do{
		   passmenu(&choice);
            switch(choice)
			{
            case 1:
            		search(flightID,schedule,i,availableSeats);
            break;
            case 2: 
                   bookseat(flightID,FlightName,Source,Destination,i,availableSeats);
            break;
            case 3:
                    checkstat(flightID, i);
            	break;
            case 4:
            	    boarding(Name,FlightID, FlightName,Source,Destination,seatnumber);
            		break;
        	case 5:
                    cancelBooking(FlightID);
            	    break;
            case 6:
            		cout<<"Thanks For Choosing us!\n Exiting the program";
            		return 0;
            		default:
            			cout<<"Please make a valid choice\n";
        }
        }while(choice!=6);
    }
        else
		{
            cout<<"Invalid choice. Please choose a valid option.";
        }
    return 0;
}
