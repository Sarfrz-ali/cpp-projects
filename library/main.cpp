#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;



// user defined files //
#include "style.cpp";
#include "intro.cpp";
//....................//
//  global variables  //

int total_books = 0;
int books_limit = 5;

// ............... Books meterr ......................... //


void books_meter(){
	cout << "Total Books: " << '\t';
	
	for(int i=0;i< total_books;i++){
		cout << char(219);
	}
	for(int i=books_limit;i>total_books;i--){
		cout << '.';
	}
	
	cout << "  ";
	cout << total_books;
}
// ......................................... //


// ......... Structure information ......... //
struct book{
	string title;
	string author;
	string ISBN;
	
	void input(){
		system("cls");
		blankline();
		m();
		animation("Add Book");blankline();
		m(5);
		cout << "Enter Book Title: ";
		getline(cin,title);
		m(5);
		cout << "Enter Book Author: ";
		getline(cin,author);
		m(5);
		cout << "Enter Book ISBN: ";
		getline(cin,ISBN);
		blankline();
		m(5);
		animation("Book added successfully.");
		blankline();
		m(5);
		animation("Press any key to continue... ");
		getch();
		system("cls");
	}
};
// ......................................... //

// ........................ Add book ....................... //
void addBook(book *b){
	if(total_books < books_limit){
		cin.ignore();
		b[total_books].input();
		total_books++;
	}else{
		blankline();
		m();
		animation("Sorry! You cannot add more than 2 books.");
		blankline();
	}
}
// ......................................................... //



// ...................... books output ..................... //

void outputBooks(book *b){
	system("cls");
	blankline();
	if(total_books > 0){
	m();line();
	m();cout << left << setw(3) <<      '|' << setw(5) <<  "NO." << setw(3) << '|' << setw(20) << "Title"    << setw(3) << '|' << setw(20) << "Author"      << setw(3) << '|' << setw(20)<<  "ISBN"   << setw(3) << '|';    cout << endl;
	m();line();
		m();cout << left << setw(3) <<      '|' << setw(5) <<  ""    << setw(3) << '|' << setw(20) << ""         << setw(3) << '|' << setw(20) << ""            << setw(3) << '|' << setw(20)<<    ""     << setw(3) << '|';    cout << endl;		
		//dynamic result loop
		for(int i=0;i<total_books;i++){
			m();cout << left << setw(3) <<  '|' << setw(5) <<  i+1   << setw(3) << '|' << setw(20) << b[i].title << setw(3) << '|' << setw(20) << b[i].author   << setw(3) << '|' << setw(20)<< b[i].ISBN << setw(3) << '|';    cout << endl;
		}	
			m();line();	
			blankline();
		m(5);
		animation("Press any key to continue... ");
		getch();
		system("cls");
	}else{
		system("cls");
		blankline();
		m(15);
		animation("There is no book found.");
//		blankline();
	}
}
// ........................................................ //


//...................... compare function ...................//



bool cmpr(string value1, string value2){
	bool equal = true;
	int j=0;
//	value1 = strlwr(value1);

	while(value1[j]!= '\0'){
	strlwr(&value1[j]); // convert value1 to lowercase
    strlwr(&value2[j]); // convert value2 to lowercase
		if(value1[j]!=value2[j]){
			equal = false;
			break;
		}
		j++;
	}
	
	return equal;
}
//...........................................................//

//...................... search function ...................//
void search(book *b){
	system("cls");
	blankline();
	m(5);
	cout << "Enter the book Title or ISBN: ";
    string searchQuery;
    cin.ignore();
    getline(cin, searchQuery);
    	blankline();
		m();line();
		m();cout << left << setw(3) <<      '|' << setw(5) <<  "NO." << setw(3) << '|' << setw(20) << "Title"    << setw(3) << '|' << setw(20) << "Author"      << setw(3) << '|' << setw(20)<<  "ISBN"   << setw(3) << '|';    cout << endl;
		m();line();
		m();cout << left << setw(3) <<      '|' << setw(5) <<  ""    << setw(3) << '|' << setw(20) << ""         << setw(3) << '|' << setw(20) << ""            << setw(3) << '|' << setw(20)<<    ""     << setw(3) << '|';    cout << endl;		
		//dynamic result loop
		
		for(int i=0;i<total_books;i++){
		if(cmpr(searchQuery,b[i].title) || cmpr(searchQuery,b[i].ISBN)){
			m();cout << left << setw(3) <<  '|' << setw(5) <<  i+1   << setw(3) << '|' << setw(20) << b[i].title << setw(3) << '|' << setw(20) << b[i].author   << setw(3) << '|' << setw(20)<< b[i].ISBN << setw(3) << '|';    cout << endl;
		}	

	}		m();line();	
				blankline();
		m(5);
		animation("Press any key to continue... ");
		getch();
		system("cls");
}
//..........................................................//


//........................ Delete Function ..................................//
void deleteBook(book *b) {
	system("cls");
    // Prompt the user to enter the title or ISBN of the book to delete
    
    blankline();
    m();
    cout << "Enter the title or ISBN of the book to delete: ";
    string deleteQuery;
    cin.ignore();
    getline(cin, deleteQuery);
    
    
    bool action = false;
    // Search for the book in the array and delete it
    int i;
    for(i=0;i<total_books;i++){
    if(cmpr(b[i].title,deleteQuery) || cmpr(b[i].ISBN,deleteQuery)){
    	action = true;
    	break;
	}
	}
	if(action){
        for(int j = i; j < total_books-1; j++) {
            b[j] = b[j + 1];
        }
        total_books--;
        blankline();
        m();
        animation("Book deleted successfully.");
        cout << endl;
    } else {
    	blankline();m();
        animation("No book matching the query found.");
        cout << endl;
    }
    				blankline();
		m();
		animation("Press any key to continue... ");
		getch();
		system("cls");
	}
//...........................................................................//

//................................. Menu ..........................................//
void menu(){
		cout << endl;
        m();cout << "=====================================" << endl;
        m();cout << "|           LIBRARY SYSTEM          |" << endl;
        m();cout << "=====================================" << endl;
        m();cout << "|      1. Display all books         |" << endl;
        m();cout << "|      2. Add a book                |" << endl;
        m();cout << "|      3. Search book               |" << endl;
        m();cout << "|      4. Delete a book             |" << endl;
        m();cout << "|      0. Exit                      |" << endl;
        m();cout << "=====================================" << endl;
        cout << endl;
}
//.................................................................................//


int main (){
	intro();
				blankline();
	book library[books_limit];
	
	string cmd;
	while(true){

		blankline();
		m();
		books_meter();cout << endl;
		menu();
		m();
		cout << "Enter command: ";
		cin >> cmd;
		if(cmd[0] == '0'){
			exit(0);
		}
		else if(cmd == "1"){
			outputBooks(library);

		}
		else if(cmd == "2"){
			addBook(library);
		}
		else if(cmd == "3"){
			search(library);
		}
		else if(cmd == "4"){
			deleteBook(library);
		}
		else{
			system("cls");
			cout << "Invalid";
		}
	}
	
	return 0;
}
