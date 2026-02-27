#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int nCommand, nAccessLevel = 0;
string sUsername, sPassword;

void GuestMainMenu();
void MainMenu();
void Login();
void BuyTicket();
void UpdateMovies();
void UpdateMovieOption(int i);
void UpdateMovieActual(int i);
void DeleteMovie(int i);
void UpdatePassword();
char CheckSeat(int CinemaNumber, int MovieNumber, int ShowNumber, int SeatNumber);
void ReserveSeat(int CinemaNumber, int MovieNumber, int ShowNumber, int SeatNumber);
void ReserveSeat(int nCinema, int nMovie, int nShowing);
void SeatSelectionSystem(int nCinema, int nMovie, int nShowing);
void TicketReservation(int nCinema, int nMovie, int nShow, int nSeat);
void DisplayHeader();

///////////////////////////////////////////////////////
// Main Function
///////////////////////////////////////////////////////
int main()
{
Start:
	DisplayHeader();
	cout << "  [1] Log In" << endl;
	cout << "  [2] Exit Application" << endl;
	cout << endl;
	cout << " Please select your comamnd: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			Login();
			goto Start;
		case 2:
	return 0;
		default:
			goto Start;
	}
}



////////////////////////////////////////////////////////
// Login Function
////////////////////////////////////////////////////////
void Login()
{
	DisplayHeader();
	cout << "  Enter your login details."<<endl;
	cout << "  If logging in as a guest, type Guest as the username."<<endl<<endl;
	cout << "  Username: ";
	cin >> sUsername;

	// If username is Guest then log in as a guest
	if (sUsername == "Guest")
	{
		cout << " Logging in as a guest..." <<endl;
		cout << " ";
		system("pause");
		GuestMainMenu();
	}
	else if (sUsername == "Admin") // If username is Admin
	{
		bool bAccessAllowed = false;
		nAccessLevel = 2;
		fstream FileHandler;
		cout << "  Password: ";
		cin >> sPassword;
		FileHandler.open("UserPass\\admin.pw");
		string pw;
		getline(FileHandler,pw); // Get one line and store it for password.
		if (sPassword == pw)
			bAccessAllowed = true;
		FileHandler.close();
		if (bAccessAllowed == true)
		{
			cout << " Login successful." << endl;
			MainMenu();
		}
		else
		{
			cout << " Invalid username and/or password." << endl;
			cout << "  "; system("pause");
		}
		
	}
	else // If an ordinary user
	{
		fstream FileHandler;
		// If username is not Guest then ask for password
		bool bAccessAllowed = false;
		cout << " Password: ";
		cin >> sPassword;
		cout << endl;
		// Open the userlist.upl file
		FileHandler.open("UserPass\\accounts.upl");
		// While the file still has unread lines
		while ( FileHandler.good() )
		{
			string user;
			string pw;
			getline(FileHandler,user); // Get one line and store it for username.
			getline(FileHandler,pw); // Get one line and store it for password.
			if ((sUsername == user) && (sPassword == pw))
			{
				bAccessAllowed = true;
				break;
			}
		}
		// Closes the userlist.upl file
		FileHandler.close();
		if (bAccessAllowed == true)
		{
			cout << " Login successful." << endl;
			system("pause");
			MainMenu();
		}
		else
			cout << " Invalid username and/or password." << endl;
		cout << " ";
	}
}

void GuestMainMenu()
{
Start:
	DisplayHeader();
	cout << "  [1] Buy ticket" << endl;			
	cout << "  [2] Verify reservation (Not done)" << endl;
	if (nAccessLevel == 0)
		cout << "  [3] Log out" << endl;
	else
		cout << "  [3] Back" <<endl;
	cout << endl;
	cout << "  Enter your command: ";
	cin >> nCommand;
	switch (nCommand)
	{
		case 1:
			BuyTicket();
			break;
		case 3:
			return;
		default:
			break;
	}
	goto Start;
}

void MainMenu()
{
Start:
	DisplayHeader();
	cout << "  [1] Ticket Reservation"<<endl;
	cout << "  [2] Update Movies"<<endl;
	cout << "  [3] Change Password"<<endl;
	cout << "  [4] Log Out"<<endl;
	cout << endl << "  Please select your comamnd: ";
	cin >> nCommand;
	switch (nCommand)
	{
	case 1:
		GuestMainMenu();
		break;
	case 2:
		UpdateMovies();
		break;
	case 3:
		UpdatePassword();
	case 4:
		return;
	default:
		goto Start;
	}
	goto Start;
}

void BuyTicket()
{
SelectCinema:
	fstream Handler[2];
	int nCinema, nMovie, nShowing;
	DisplayHeader();
	cout << "  Enter 0 to cancel." << endl;
	cout << "  Enter cinema number [1-3]: ";
	cin >> nCinema;
	switch (nCinema)
	{
		case 1:
		case 2:
		case 3:
			break;
		case 0:
			return;
		default:
			goto SelectCinema;
	}
SelectMovie:
	string sPrefix = "C*";
	char temp[2];
	itoa(nCinema,temp,10);
	sPrefix[1] = temp[0];
	string sFilename;
	char cFilename[18];
	int i;
	DisplayHeader();
	cout << "  Enter 0 to cancel." << endl;
	// Movie 1
	sFilename = sPrefix + "\\M1\\Movie.props";
	for (i = 0; i < 18; i++)
	{
		cFilename[i] = sFilename[i];
	}
	Handler[0].open(cFilename);
	if (!Handler[0].fail())
	{
		string sTitle;
		getline(Handler[0],sTitle);
		cout << "  [1] " << sTitle << endl;
	}
	Handler[0].close();

	// Movie 2
	sFilename = sPrefix + "\\M2\\Movie.props";
	for (i = 0; i < 18; i++)
	{
		cFilename[i] = sFilename[i];
	}
	Handler[1].open(cFilename);
	if (!Handler[1].fail())
	{
		string sTitle;
		getline(Handler[1],sTitle);
		cout << "  [2] " << sTitle << endl;
	}
	Handler[1].close();

	cout << endl;
	cout << "  Enter movie number: ";
	cin >> nMovie;

	switch (nMovie)
	{
	case 1:
		sFilename = sPrefix + "\\M1\\Movie.props";
		for (i = 0; i < 18; i++)
		{
			cFilename[i] = sFilename[i];
		}
		Handler[0].open(cFilename);
		if (!Handler[0].fail())
		{
			Handler[0].close();
			break;
		}
		else
		{
			Handler[0].close();
			goto SelectMovie;
		}
	case 2:
		sFilename = sPrefix + "\\M2\\Movie.props";
		for (i = 0; i < 18; i++)
		{
			cFilename[i] = sFilename[i];
		}
		Handler[1].open(cFilename);
		if (Handler[1].good())
		{
			Handler[1].close();
			break;
		}
		else
		{
			Handler[1].close();
			goto SelectMovie;
		}
		break;
	case 0:
		return;
	default:
		goto SelectMovie;
	}
SelectShowing:
	DisplayHeader();
	cout << "  Enter 0 to cancel." << endl;
	cout << "  Enter showing number [1-2]: ";
	cin >> nShowing;

	switch (nShowing)
	{
	case 1:
	case 2:
		ReserveSeat(nCinema,nMovie,nShowing);
		break;
	case 0:
		return;
	default:
		goto SelectShowing;
	}
}

void UpdateMovies()
{
Start:
	DisplayHeader();
	string title;
	ifstream Reader[6];
	cout << "  [0] -Cancel-" << endl;

	Reader[0].open("C1\\M1\\Movie.props");
	if (Reader[0])
	{
		getline(Reader[0],title);
		cout << "  [1] Cinema 1: " << title << endl;
	}
	else
		cout << "  [1] Cinema 1: NO MOVIE" << endl;
	Reader[0].close();

	Reader[1].open("C1\\M2\\Movie.props");
	if (Reader[1])
	{
		getline(Reader[1],title);
		cout << "  [2] Cinema 1: " << title << endl;
	}
	else
		cout << "  [2] Cinema 1: NO MOVIE" << endl;
	Reader[1].close();

	Reader[2].open("C2\\M1\\Movie.props");
	if (Reader[2])
	{
		getline(Reader[2],title);
		cout << "  [3] Cinema 2: " << title << endl;
	}
	else
		cout << "  [3] Cinema 2: NO MOVIE" << endl;
	Reader[2].close();

	Reader[3].open("C2\\M2\\Movie.props");
	if (Reader[3])
	{
		getline(Reader[3],title);
		cout << "  [4] Cinema 2: " << title << endl;
	}
	else
		cout << "  [4] Cinema 2: NO MOVIE" << endl;
	Reader[3].close();

	Reader[4].open("C3\\M1\\Movie.props");
	if (Reader[4])
	{
		getline(Reader[4],title);
		cout << "  [5] Cinema 3: " << title << endl;
	}
	else
		cout << "  [5] Cinema 3: NO MOVIE" << endl;
	Reader[4].close();

	Reader[5].open("C3\\M2\\Movie.props");
	if (Reader[5])
	{
		getline(Reader[5],title);
		cout << "  [6] Cinema 3: " << title << endl;
	}
	else
		cout << "  [6] Cinema 3: NO MOVIE" << endl;
	Reader[5].close();
	cout << "  Select which movie you will update: ";
	cin >> nCommand;
	switch (nCommand)
	{
	case 1:
		UpdateMovieOption(nCommand);
		break;
	case 2:
		UpdateMovieOption(nCommand);
		break;
	case 3:
		UpdateMovieOption(nCommand);
		break;
	case 4:
		UpdateMovieOption(nCommand);
		break;
	case 5:
		UpdateMovieOption(nCommand);
		break;
	case 6:
		UpdateMovieOption(nCommand);
		break;
	case 0:
		return;
	default:
		goto Start;
	}
	goto Start;
}
void UpdateMovieOption(int i)
{
Start:
	ifstream Reader;
	switch (i)
	{
	case 1:
		Reader.open("C1\\M1\\Movie.props");
		break;
	case 2:
		Reader.open("C1\\M2\\Movie.props");
		break;
	case 3:
		Reader.open("C2\\M1\\Movie.props");
		break;
	case 4:
		Reader.open("C2\\M2\\Movie.props");
		break;
	case 5:
		Reader.open("C3\\M1\\Movie.props");
		break;
	case 6:
		Reader.open("C3\\M2\\Movie.props");
		break;
	}
	DisplayHeader();
	if (Reader)
	{
		string title;
		getline(Reader,title);
		Reader.close();
		cout << "  Movie title: " << title << endl;
		cout << "  [1] Update Movie" << endl;
		cout << "  [2] Delete Movie (Admin Only)" << endl;
		cout << "  [3] Back" << endl;
		cout << endl << "  Please enter your command: ";
		int j;
		cin >> j;
		switch (j)
		{
		case 1:
			UpdateMovieActual(i);
			return;
		case 2:
			if (nAccessLevel==2)
			{
				cout << "Movie has been successfully deleted." << endl;
				DeleteMovie(i);
				return;
			}
			else
			{
				DisplayHeader();
				cout << "  Function is only for admin."<< endl;
				cout << "  ";
				system("pause");
				goto Start;
			}
		case 3:
			return;
		}
		goto Start;
	}
	else
	{
		cout << "  [1] Add Movie" << endl;
		cout << "  [2] Back" << endl;
		cout << endl;
		cout << "  Please enter your command: ";
		int j;
		cin >> j;
		switch (j)
		{
		case 1:
			UpdateMovieActual(i);
			return;
		case 2:
			return;
		default:
			goto Start;
		}
		goto Start;
	}
}
void UpdateMovieActual(int i)
{
	ofstream Writer;
	switch (i)
	{
	case 1:
		Writer.open("C1\\M1\\Movie.props");
		break;
	case 2:
		Writer.open("C1\\M2\\Movie.props");
		break;
	case 3:
		Writer.open("C2\\M1\\Movie.props");
		break;
	case 4:
		Writer.open("C2\\M2\\Movie.props");
		break;
	case 5:
		Writer.open("C3\\M1\\Movie.props");
		break;
	case 6:
		Writer.open("C3\\M2\\Movie.props");
		break;
	default:
		cout << "  ERROR: Invalid movie number." << endl;
		cout << "  "; system("pause");
	}
	string Input;
	DisplayHeader();
	cout << "  Enter movie title: ";
	getline(cin, Input); //Reset the cin; 
	Writer << Input << endl;
	DisplayHeader();
	cout << "  Enter synopsis: ";
	getline(cin,Input);
	Writer << Input << endl;
	DisplayHeader();
	cout << "  Enter price: ";
	getline(cin,Input);
	Writer << Input << endl;
	DisplayHeader();
	cout << "  Enter date of showing [Month Day Year], ex.(Apr 01 2012): ";
	getline(cin,Input);
	Writer << Input << endl;
	Writer.close();
	DisplayHeader();
	cout << "  Movie successfully updated!" << endl;
	cout << "  ";
	system("pause");
}
void DeleteMovie(int i)
{
	char moviefile[]="C*\\M*\\Movie.props";
	char seatsfile[]="C*\\M*\\S*_***";
	switch (i)
	{
	case 1:
		moviefile[1]='1';
		seatsfile[1]='1';
		moviefile[4]='1';
		seatsfile[4]='1';
		break;
	case 2:
		moviefile[1]='1';
		seatsfile[1]='1';
		moviefile[4]='2';
		seatsfile[4]='2';
		break;
	case 3:
		moviefile[1]='2';
		seatsfile[1]='2';
		moviefile[4]='1';
		seatsfile[4]='1';
		break;
	case 4:
		moviefile[1]='2';
		seatsfile[1]='2';
		moviefile[4]='2';
		seatsfile[4]='2';
		break;
	case 5:
		moviefile[1]='3';
		seatsfile[1]='3';
		moviefile[4]='1';
		seatsfile[4]='1';
		break;
	case 6:
		moviefile[1]='3';
		seatsfile[1]='3';
		moviefile[4]='2';
		seatsfile[4]='2';
		break;
	}
	int res = remove(moviefile);
	for (i = 1; i <= 2; i++)
	{
		char temp[4];
		itoa(i,temp,10);
		seatsfile[7]=temp[0];
		for (int j = 1; j <= 250; j++)
		{
			if (j > 99)
			{			
				itoa(j, temp, 10);
				seatsfile[9]=temp[0];
				seatsfile[10]=temp[1];
				seatsfile[11]=temp[2];
			}
			else if (j > 9)
			{				
				itoa(j, temp, 10);
				seatsfile[9]='0';
				seatsfile[10]=temp[0];
				seatsfile[11]=temp[1];
			}
			else
			{				
				itoa(j, temp, 10);
				seatsfile[9]='0';
				seatsfile[10]='0';
				seatsfile[11]=temp[0];
			}
			res = remove(seatsfile);
			
		}
	}
	system("pause");
}

void UpdatePassword()
{
	DisplayHeader();
	string Input;
	string pw;
	cout << "  Enter current password (Max 20 chars): ";
	getline(cin,Input);
	getline(cin,Input);
	pw = Input;
	if (!(pw==sPassword))
	{
		cout << "  Wrong password!" << endl;
		return;
	}
	cout << "  Enter new password (Max 20 chars): ";
	getline(cin,Input);
	pw = Input;
	string filename = "UserPass\\"+sUsername+".pw";
	const char* cFilename = filename.c_str();
	ofstream Writer;
	Writer.open(cFilename);
	Writer << pw;
	DisplayHeader();
	cout << "  Password successfully changed." << endl;
	cout << "  "; system("pause");
}

char CheckSeat(int CinemaNumber, int MovieNumber, int ShowNumber, int SeatNumber)
{
	ifstream Reader;
	char temp[4];
	char filename[]="C*\\M*\\S*_***";
	itoa(CinemaNumber,temp,10);
	filename[1]=temp[0];
	itoa(MovieNumber,temp,10);
	filename[4]=temp[0];
	itoa(ShowNumber,temp,10);
	filename[7]=temp[0];
	itoa(SeatNumber,temp,10);
	if (SeatNumber>99)
	{
		filename[9]=temp[0];
		filename[10]=temp[1];
		filename[11]=temp[2];
	}
	else if (SeatNumber>9)
	{
		filename[9]='0';
		filename[10]=temp[0];
		filename[11]=temp[1];
	}
	else
	{
		filename[9]='0';
		filename[10]='0';
		filename[11]=temp[0];
	}
	Reader.open(filename);
	if (!Reader)
		return 'O';
	else
		return 'X';
}

void ReserveSeat(int CinemaNumber, int MovieNumber, int ShowNumber, int SeatNumber)
{
	ofstream Writer;
	ifstream Reader;
	char temp[4];
	char filename[]="C*\\M*\\S*_***";
	char fileopen[]="C*\\M*\\Movie.props";
	itoa(CinemaNumber,temp,10);
	filename[1]=temp[0];
	fileopen[1]=temp[0];
	itoa(MovieNumber,temp,10);
	filename[4]=temp[0];
	fileopen[4]=temp[0];
	itoa(ShowNumber,temp,10);
	filename[7]=temp[0];
	itoa(SeatNumber,temp,10);
	if (SeatNumber>99)
	{
		filename[9]=temp[0];
		filename[10]=temp[1];
		filename[11]=temp[2];
	}
	else if (SeatNumber>9)
	{
		filename[9]='0';
		filename[10]=temp[0];
		filename[11]=temp[1];
	}
	else
	{
		filename[9]='0';
		filename[10]='0';
		filename[11]=temp[0];
	}
	Writer.open(filename);
	// First * - Random Letter
	// Next 2 * - Reservation Day
	// Next * - Random Letter
	// Next 2 * - Reservation Month
	// Next * - Random Letter
	// Next 2 * - Reservation Year
	// Next * - Cinema Number
	// Next * - Movie Number
	// Next 2 * - Showing (AM/PM)
	// Next 3 * - SeatNumber
	char ticketn[]="*********C*M***S***";
	char rletters[3];
	char date[9];
	int n;
	srand(time(NULL));
	n = rand() % 26;
	rletters[0] = (char)(n+65);
	n = rand() % 26;
	rletters[1] = (char)(n+65);
	n = rand() % 26;
	rletters[2] = (char)(n+65);
	_strdate(date);
	ticketn[0] = rletters[0];
	ticketn[1] = date[0];
	ticketn[2] = date[1];
	ticketn[3] = rletters[1];
	ticketn[4] = date[3];
	ticketn[5] = date[4];
	ticketn[6] = rletters[2];
	ticketn[7] = date[6];
	ticketn[8] = date[7];
	itoa(CinemaNumber,temp,10);
	ticketn[10] = temp[0];
	itoa(MovieNumber,temp,10);
	ticketn[12] = temp[0];
	if (ShowNumber==1)
		ticketn[13]='A';
	else
		ticketn[13]='P';
	ticketn[14]='M';
	itoa(SeatNumber,temp,10);
	if (SeatNumber>99)
	{
		ticketn[16]=temp[0];
		ticketn[17]=temp[1];
		ticketn[18]=temp[2];
	}
	else if (SeatNumber>9)
	{
		ticketn[16]='0';
		ticketn[17]=temp[0];
		ticketn[18]=temp[1];
	}
	else
	{
		ticketn[16]='0';
		ticketn[17]='0';
		ticketn[18]=temp[0];
	}
	DisplayHeader();
	Reader.open(fileopen);
	string sTitle;
	getline(Reader,sTitle);
	time_t curr = time(0);
	cout <<"\tMovie Title: " << sTitle << endl;
	cout <<"\tCinema: " << CinemaNumber << "\t\t\tShowing: ";
	if (ShowNumber==1)
		cout <<"AM";
	else
		cout <<"PM";
	cout<<endl;
	cout <<"\tTime of Purchase:\t\t" << ctime(&curr) <<endl;
	cout << "   Ticket ID: ";
	for (int i = 0; i < sizeof(ticketn) - 1; i++)
	{
		cout << ticketn[i];
		Writer << ticketn[i];
	}
	Writer << "\n" << ctime(&curr);
	Writer.close();
	cout << "\tBe sure to write down your ticket ID!"<<endl;
	system("pause");
}

void ReserveSeat(int nCinema, int nMovie, int nShowing)
{
	ofstream FileWriter;
	ifstream FileChecker;
	char cFilename[15];
	char temp[2];
	string sFilename = "C*\\M*\\S*.seats";
	itoa(nCinema,temp,10);
	sFilename[1] = temp[0];
	itoa(nMovie,temp,10);
	sFilename[4] = temp[0];
	itoa(nShowing,temp,10);
	sFilename[7] = temp[0];
	for (int j = 0; j < 15; j++)
	{
		cFilename[j] = sFilename[j];
	}
	FileChecker.open(cFilename);
	FileChecker.close();
	SeatSelectionSystem(nCinema, nMovie, nShowing);
}

void SeatSelectionSystem(int Cinema, int Movie, int Show)
{
	int nCursorX = 1, nCursorY = 0;
Start:
	system("cls");
	cout << endl << endl;
	if ((nCursorX>=1)&&(nCursorX<=10))
	{
		cout << "    Area 1:" << endl;
		for (int i = 0; i <= 200; i+=50)
		{
			cout << "    ";
			for (int j = 1; j <= 10; j++)
				{
					if (nCursorX+(nCursorY*50)==i+j)
						cout << " <<" << CheckSeat(Cinema, Movie, Show, i+j) << ">> ";
					else
						cout << "  [" << CheckSeat(Cinema, Movie, Show, i+j) << "]  ";
				}
			cout << endl << endl;
		}
	}
	else if ((nCursorX>=11)&&(nCursorX<=20))
	{
		cout << "    Area 2:" << endl;
		for (int i = 0; i <= 200; i+=50)
		{
			cout << "    ";
			for (int j = 11; j <= 20; j++)
				{
					if (nCursorX+(nCursorY*50)==i+j)
						cout << " <<" << CheckSeat(Cinema, Movie, Show, i+j) << ">> ";
					else
						cout << "  [" << CheckSeat(Cinema, Movie, Show, i+j) << "]  ";
				}
			cout << endl << endl;
		}
	}
	else if ((nCursorX>=21)&&(nCursorX<=30))
	{
		cout << "    Area 3:" << endl;
		for (int i = 0; i <= 200; i+=50)
		{
			cout << "    ";
			for (int j = 21; j <= 30; j++)
				{
					if (nCursorX+(nCursorY*50)==i+j)
						cout << " <<" << CheckSeat(Cinema, Movie, Show, i+j) << ">> ";
					else
						cout << "  [" << CheckSeat(Cinema, Movie, Show, i+j) << "]  ";
				}
			cout << endl << endl;
		}
	}
	else if ((nCursorX>=31)&&(nCursorX<=40))
	{
		cout << "    Area 4:" << endl;
		for (int i = 0; i <= 200; i+=50)
		{
			cout << "    ";
			for (int j = 31; j <= 40; j++)
				{
					if (nCursorX+(nCursorY*50)==i+j)
						cout << " <<" << CheckSeat(Cinema, Movie, Show, i+j) << ">> ";
					else
						cout << "  [" << CheckSeat(Cinema, Movie, Show, i+j) << "]  ";
				}
			cout << endl << endl;
		}
	}
	else
	{
		cout << "    Area 5:" << endl;
		for (int i = 0; i <= 200; i+=50)
		{
			cout << "    ";
			for (int j = 41; j <= 50; j++)
				{
					if (nCursorX+(nCursorY*50)==i+j)
						cout << " <<" << CheckSeat(Cinema, Movie, Show, i+j) << ">> ";
					else
						cout << "  [" << CheckSeat(Cinema, Movie, Show, i+j) << "]  ";
				}
			cout << endl << endl;
		}
	}
	cout << "     Legend:"<<endl;
	cout << "     O -> Available" << endl;
	cout << "     X -> Unavailable" << endl << endl;
	cout << "\tUse the Arrow Keys to move, Space to select and Esc for cancel.";
	int z = getch();
	switch (z)
	{
	case 80:
		if (nCursorY<4)
			nCursorY++;
		break;
	case 72:
		if (nCursorY>0)
			nCursorY--;
		break;
	case 75:
		if (nCursorX>1)
			nCursorX--;
		break;
	case 77:
		if (nCursorX<50)
			nCursorX++;
		break;
	case 32:
		char cCheck;
		cCheck = CheckSeat(Cinema, Movie, Show, nCursorX+(nCursorY*50));
		if (cCheck=='O')
			TicketReservation(Cinema, Movie, Show, nCursorX+(nCursorY*50));
		goto Start;
	case 27:
		return;
	default:
		break;
	}
	goto Start;
}

void TicketReservation(int nCinema, int nMovie, int nShow, int nSeat)
{
	char x;
	cout << "\t\t\t\t\tReserve this seat[Y/N]? ";
	cin >> x;
	if (tolower(x)=='y')
		ReserveSeat(nCinema,nMovie,nShow,nSeat);
}

void DisplayHeader()
{
	system("cls");
	cout << endl;
	
	// Upper Border
	cout << " \xC9";
	for (int i = 0; i < 76; i++)
		cout << "\xCD";
	cout << "\xBB";
	cout << endl;

	// Middle Border
	cout << " \xBA";
	//      [FROM_HERE                                                            TO_HERE]
	cout << "                          Movie Reservation System                          ";
	cout << "\xBA";
	cout << endl;

// Upper Border
	cout << " \xC8";
	for (int i = 0; i < 76; i++)
		cout << "\xCD";
	cout << "\xBC";
	cout << endl;
	cout << endl;
}
