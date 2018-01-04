
// An interactive test program for the new BST class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "BST.h"
using namespace std;


// PROTOTYPES for functions used by this test program:
void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters),
// and this character has been returned.

void show_list(BST& display);
// Postcondition: The items on display have been printed to cout (one per line).

int get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

int main()
{
	BST test; // A sequence that we�ll perform tests on
	char choice;   // A command character entered by the user

	cout << "I have initialized an empty sequence of real numbers." << endl;

	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{

			//  case 'P': show_sequence(test);
			//          break;
		case 'S': cout << "Size is " << test.size() << '.' << endl;
			break;
		case 'I': test.insert(get_number());
			break;
		case 'E': test.erase(get_number());
			break;
		case 'P': test.print();
			break;
		case 'R': test.preOrder();
			break;
		case 'N': test.inOrder();
			break;
		case 'O': test.postOrder();
			break;
		case 'Q': cout << "Have a good day!" << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	} while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu()
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " S   Print the result from the size( ) function" << endl;//
	cout << " I   Insert a new number with the insert( ) function" << endl;//
	cout << " E   Activate the erase(...) function" << endl;//
	cout << " P   Print a copy of the entire BST" << endl;//
	cout << " R   Print a preOrder traversal" << endl;
	cout << " N   Print a inOrder traversal" << endl;
	cout << " O   Print a postOrder traversal" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

int get_number()
// Library facilities used: iostream
{
	int result;

	cout << "Please enter an integer: ";
	cin >> result;
	cout << result << " has been read." << endl;
	return result;
}
