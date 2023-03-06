#include<iostream>
#include<fstream>
#include<iomanip> //setw()
#include<string.h> //strcmp
using namespace std;
void Update() {
	char ID[10], Name[25], Cost[10], Shelf_no[10], Date[11], Perioty[10]
		, ID_R[10], Name_R[25], OP[2], X[2], A[2];
	bool found;
	fstream f, t;
	do
	{
		found = false;
		f.open("Super Market.txt", ios::in);
		t.open("T.txt", ios::app);
		cout << "################################\n";
		cout << "#To Delete by ID      :1 #\n" << "#To Delete by Name     :2 #\n";
		cout << "################################\n";
		do
		{
			cout << "Enter Option :"; cin.getline(OP, 2);
			if (!(OP[0] == '1' || OP[0] == '2'))
				cout << "\a";
		} while (!(OP[0] == '1' || OP[0] == '2'));
		switch (OP[0])
		{
		case '1':
			cout << "Enter Product's ID :"; cin.getline(ID, 10);
			break;
		case '2':
			cout << "Enter Product's Name :"; cin.getline(Name, 25);
			break;
		}
		while (!f.eof())
		{
			f.getline(ID_R, 10, '|');
			f.getline(Name_R, 25, '|');
			f.getline(Cost, 10, '|');
			f.getline(Shelf_no, 10, '|');
			f.getline(Date, 11, '|');
			f.getline(Perioty, 10);
			if (int(ID_R[0]) == 0) {
				continue;
			}
			else if ((strcmp(ID, ID_R) == 0 && OP[0] == '1') || (strcmp(Name, Name_R) == 0 && OP[0] == '2'))
			{
				found = true;
				cout << "##########################\n";
				cout << "To update Name        :1 #\n"
					<< "To update Cost        :2 #\n"
					<< "To update Shelf_no    :3 #\n"
					<< "To update Date        :4 #\n"
					<< "To update Perioty     :5 #\n"
					<< "To update ALL         :6 #\n";
				cout << "##########################\n";
				do
				{
					cout << "Enter option :"; cin.getline(A, 2);
					if (!(A[0] == '1' || A[0] == '2' || A[0] == '3' || A[0] == '4' || A[0] == '5' || A[6] == '6'))						cout << "\a";
				} while (!(A[0] == '1' || A[0] == '2' || A[0] == '3' || A[0] == '4' || A[0] == '5' || A[6] == '6'));
				switch (A[0])
				{
				case '1':
					cout << "Enter Product's Name       :"; cin.getline(Name, 25);
					break;
				case '2':
					cout << "Enter Product's Cost       :"; cin.getline(Cost, 10);
				case '3':
					cout << "Enter Product's Shelf_no   :"; cin.getline(Shelf_no, 10);
					break;
				case '4':
					cout << "Enter Product's Date       :"; cin.getline(Date, 11);
					break;
				case '5':
					cout << "Enter Product's Perioty    :"; cin.getline(Perioty, 10);
					break;
				case '6':
					cout << "Enter your product Name                      :"; cin.getline(Name, 25);
					cout << "Enter your product Cost                      :"; cin.getline(Cost, 10);
					cout << "Enter your product Shelf_no                  :"; cin.getline(Shelf_no, 10);
					cout << "Enter your product Date (DD-MM-YYYY)         :"; cin.getline(Date, 11);
					cout << "Enter your product Perioty (In Days)         :"; cin.getline(Perioty, 10);
					break;
				}
				t << ID_R << "|" << Name_R << "|" << Cost << "|" << Shelf_no << "|" << Date << "|" << Perioty << '\n';
			}
			else
			{
				t << ID_R << "|" << Name_R << "|" << Cost << "|" << Shelf_no << "|" << Date << "|" << Perioty << '\n';
			}
		}
		if (!found) {
			cout << "Product Not Found !\n";
		}
		else
		{
			cout << "Product successfully Updated !\n";
		}
		cout << "Do you want Update another product(y) ?\n";cin.getline(X, 2);
		f.close();
		t.close();
		remove("Super Market.txt");
		rename("T.txt", "Super Market.txt");

	} while (X[0] == 'Y' || X[0] == 'y');
}
void Delete() {
	char ID[10], Name[25], Cost[10], Shelf_no[10], Date[11], Perioty[10]
		, ID_R[10], Name_R[25], OP[2], X[2];
	bool found;
	fstream f, t;
	do
	{
		found = false;
		f.open("Super Market.txt", ios::in);
		t.open("T.txt", ios::app);
		cout << "################################\n";
		cout << "#To Delete by ID      :1 #\n" << "#To Delete by Name     :2 #\n";
		cout << "################################\n";
		do
		{
			cout << "Enter Option :"; cin.getline(OP, 2);
			if (!(OP[0] == '1' || OP[0] == '2'))
				cout << "\a";
		} while (!OP[0] == '1' || OP[0] == '2');
		switch (OP[0])
		{
		case '1':
			cout << "Enter Product's ID :";cin.getline(ID, 10);
			break;
		case '2':
			cout << "Enter Product's Name :"; cin.getline(Name, 25);
			break;
		}
		while (!f.eof())
		{
			f.getline(ID_R, 10, '|');
			f.getline(Name_R, 25, '|');
			f.getline(Cost, 10, '|');
			f.getline(Shelf_no, 10, '|');
			f.getline(Date, 11, '|');
			f.getline(Perioty, 10);
			if (int(ID_R[0]) == 0) {
				continue;
			}
			if ((strcmp(ID, ID_R) == 0 && OP[0] == '1') || (strcmp(Name, Name_R) == 0 && OP[0] == '2'))
			{
				found = true;
				continue;
			}
			t << ID_R << "|" << Name_R << "|" << Cost << "|" << Shelf_no << "|" << Date << "|" << Perioty << '\n';
		}
		if (!found) {
			cout << "Product Not Found !\n";
		}
		else
		{
			cout << "Product successfully Deleted !\n";
		}
		cout << "Do you want to Delete another product(y) ?\n";cin.getline(X, 2);
		f.close();
		t.close();
		remove("Super Market.txt");
		rename("T.txt", "Super Market.txt");
	} while (X[0] == 'Y' || X[0] == 'y');

}
void Search() {
	char ID[10], Name[25], Cost[10], Shelf_no[10], Date[11], Perioty[10]
		, ID_R[10], Name_R[25], OP[2], X[2];
	bool found;
	fstream f;
	do
	{
		found = false;
		f.open("Super Market.txt", ios::in);
		cout << "################################\n";
		cout << "#To Search by ID      :1 #\n" << "#To Search by Name     :2 #\n";
		cout << "################################\n";
		do
		{
			cout << "Enter Option :"; cin.getline(OP, 2);
			if (!(OP[0] == '1' || OP[0] == '2'))
				cout << "\a";
		} while (!(OP[0] == '1' || OP[0] == '2'));
		switch (OP[0])
		{
		case '1':
			cout << "Enter Product's ID :"; cin.getline(ID, 10);
			break;
		case '2':
			cout << "Enter Product's Name :"; cin.getline(Name, 25);
			break;
		}
		while (!f.eof())
		{
			f.getline(ID_R, 10, '|');
			f.getline(Name_R, 25, '|');
			f.getline(Cost, 10, '|');
			f.getline(Shelf_no, 10, '|');
			f.getline(Date, 11, '|');
			f.getline(Perioty, 10);
			if ((strcmp(ID, ID_R) == 0 && OP[0] == '1') || (strcmp(Name, Name_R) == 0 && OP[0] == '2'))
			{
				cout << "#######################################################################################\n";
				cout << left << setw(11) << "#ID  " << setw(25) << "#Name" << setw(11) << "#Cost" <<
					setw(11) << "#Shelf_no" << setw(11) << "#Date" << setw(11) << "#Periot0y  \n";
				cout << "#######################################################################################\n";
				cout << "#" << left << setw(11) << ID_R << "#" << setw(25) << Name_R << "#" << setw(11) << Cost << "#" <<
					setw(11) << Shelf_no << "#" << setw(11) << Date << "#" << setw(11) << Perioty << "#      \n";
				cout << "#######################################################################################\n";
				found = true;
				break;
			}

		}
		if (!found) {
			cout << "Product Not Found !\n";
		}
		cout << "Do you want to search another product(y) ?\n";cin.getline(X, 2);
		f.close();
	} while (X[0] == 'Y' || X[0] == 'y');
}
void Display() {
	fstream f;
	char ID[10], Name[25], Cost[10], Shelf_no[10], Date[11], Perioty[10];
	f.open("Super Market.txt", ios::in);
	cout << "########################################################################################\n";
	cout << "#                                     My Store                                         #\n";
	cout << "########################################################################################\n";
	cout << left << setw(11) << "#ID  " << setw(25) << " #Name" << setw(11) << "  #Cost" <<
		setw(11) << "   #Shelf_no" << setw(11) << "   #Date" << setw(11) << "     #Perioty    # \n";
	cout << "########################################################################################\n";
	while (!f.eof())
	{
		f.getline(ID, 10, '|');
		f.getline(Name, 25, '|');
		f.getline(Cost, 10, '|');
		f.getline(Shelf_no, 10, '|');
		f.getline(Date, 11, '|');
		f.getline(Perioty, 10);
		if (int(ID[0] != 0))
		{
			cout << "#" << left << setw(11) << ID << "#" << setw(25) << Name << "#" << setw(11) << Cost << "#" <<
				setw(11) << Shelf_no << "#" << setw(11) << Date << " #" << setw(11) << Perioty << "#\n";
			cout << "########################################################################################\n";
		}
	}
	f.close();
}
void Insert() {
	fstream f;
	char ID[10], Name[25], Cost[10], Shelf_no[10], Date[11], Perioty[10], ch[2];
	f.open("Super Market.txt", ios::app);
	do
	{
		cout << "Enter your product ID                        :"; cin.getline(ID, 10);
		cout << "Enter your product Name                      :"; cin.getline(Name, 25);
		cout << "Enter your product Cost                      :"; cin.getline(Cost, 10);
		cout << "Enter your product Shelf_no                  :"; cin.getline(Shelf_no, 10);
		cout << "Enter your product Date (DD-MM-YYYY)         :"; cin.getline(Date, 11);
		cout << "Enter your product Perioty (In Days)         :"; cin.getline(Perioty, 10);
		f << ID << "|" << Name << "|" << Cost << "|" << Shelf_no << "|" << Date << "|" << Perioty << '\n';
		cout << "The Product is successfully inserted \n ";
		cout << "Do you want add more products (y/Y)\n";
		cin.getline(ch, 2);
	} while (ch[0] == 'y' || ch[0] == 'Y');
	f.close();
}
int main() {
	char c[2];
	bool flag = true;
	fstream f;
	f.open("Super Market.txt", ios::app);
	f.close();
	do {
		cout <<"#################################\n"
			<< "#Welcome To Super Market program#\n"
			<< "#################################\n"
			<< "#To Insert             Enter : 1#\n"
			<< "#To Display_All        Enter : 2#\n"
			<< "#To Search             Enter : 3#\n"
			<< "#To Delete             Enter : 4#\n"
			<< "#To Update             Enter : 5#\n"
			<< "#To Exit               Enter : 6#\n"
			<< "#################################\n";
		cout << "Enter your Choice : ";cin.getline(c, 2);
		switch (c[0]) {
		case '1':
			Insert();
			break;
		case '2':
			Display();
			break;
		case '3':
			Search();
			break;
		case '4':
			Delete();
			break;
		case '5':
			Update();
			break;
		case '6':
			flag = false;
			cout << "Thanks to use our program";
			break;
		default:
			cout << "\a choose number between (1-6)\n";
		}

	} while (flag);



	return 0;
}
