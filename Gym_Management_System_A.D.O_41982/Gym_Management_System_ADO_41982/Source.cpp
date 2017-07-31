#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip> /*this library was included for the setw() function, which helps with
					designing a limited UI-like interface for the console application
					by setting the width from the left edge of the console screen*/

using namespace std;

/*structure of Customers created
to store customers and their details.*/
struct Customers
{
	int customerID;
	string customer_fName;
	string customer_sName;
	string customer_address;
	string customer_postCode;
	int customer_age;

}Customer;
int customerCount = 0; //a counter variable used to count each new entry.
int customerID = 100; // declared it here for incrementing on each new customer.

//declaring all functions that will be used
void switchBoard(struct Customers *customer);
Customers newCustomer(struct Customers *customer);
void showCustomers(struct Customers *customer);
void searchCustomersByID(struct Customers *customer);
Customers changeCustomerDetails(struct Customers *customer);
Customers deleteCustomer(struct Customers *customer);

int main()
{
	//declared an array of struct of maximum 30 members for the gym;
	struct Customers customer[30];
	cout << setw(50) << "\u2022 Welcome to the Gym Management System! \u2022 \n" << endl;
	switchBoard(customer);
}

//Function to add a new Customer.
Customers newCustomer(struct Customers *customer)
{	
	//clearing the input buffer
	cin.sync();
	cin.clear();
	int i = customerCount;
	//checks to see if customer IDs already allocated are within range of array length.
	if (customerID >= 100 && customerID < 131) {
		cout << "Please enter the Customer's details." << endl;
		/*the customer's ID is equal to customerID, which
		autoincrements by 1 when a new customer is added.*/
		customer[i].customerID = customerID;
		getchar();
		/* used getchar(); to catch the whitespace
		or character left in the buffer as it was
		affecting the getline() function and
		skipped the input */
		cout << "\n Please enter the Customer's first name: ";
		getline(cin, customer[i].customer_fName);

		cout << "\n Please enter the Customer's surname: ";
		getline(cin, customer[i].customer_sName);

		cout << "\n Please enter the Customer's address: ";
		getline(cin, customer[i].customer_address);

		cin.clear();
		cout << "\n Please enter the Customer's postcode: ";
		getline(cin, customer[i].customer_postCode);
		cin.clear();

		cout << "\n Please enter the Customer's age: ";
		cin >> customer[i].customer_age;

		//if the user enters anything but an integer or an integer below 18 or above age of 65
		if(cin.fail() || customer[i].customer_age <= 18 || customer[i].customer_age >= 65) 
		{
			cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << "!!!   Invalid entry. Please enter the age of the customer as an integer.   !!! " << endl;
			cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
			cin.clear();
			cin.ignore();
			cin.get(); //makes the program wait for input.
			cout << "\n Please enter the Customer's age: "; cin >> customer[i].customer_age;			
		}
		
		customerCount++;//increment customerCount by 1 with the new customer addition.
		cout << "Customer Count: " << customerCount << endl;
		customerID++; //increment customerID by 1 on successful addition.
		//go back to control switch function switchBoard.
		switchBoard(customer);
		return customer[i];
	}
	else 
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!! Database is full! Please contact your administrator for remediation  !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		//go back to control switch function switchBoard.
		switchBoard(customer);
	}

}

//function that acts as a switchboard to transit and choose between functions of the application
void switchBoard(struct Customers *customer)
{
	int c;
	/*using setw to set the width of the text for a better visual representation of a menu
	and " \u2022 " encoding for a bullet point */
	cout << setw(47) << "\u2022 What would you like to do next? \u2022 \n" << endl;
	cout << setw(45) << "\u2022 To add a new customer, press and enter 1." << endl;
	cout << setw(55) << "\u2022 To print all existing customers, press and enter 2." << endl;
	cout << setw(59) << "\u2022 To search a customer by Customer ID, press and enter 3." << endl;
	cout << setw(54) << "\u2022 To change a customer's details, press and enter 4." << endl;
	cout << setw(60) << "\u2022 To delete a customer from the system, press and enter 5." << endl;
	cout << "\n  -->"; cin >> c;
	//if the input is NOT an integer, give this warning message.
	if (cin.fail())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!! Invalid entry. Please press and enter any of the menu options given!!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear(); //cin.clear() and cin.ignore() is used to clear and bypass anything left in
		cin.ignore();//the cin input buffer.
		switchBoard(customer);
	}
	//else if the input is an integer outside the boundaries of the menu, give this warning message.
	else if (c > 5 || c < 1)
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!! Invalid entry. Please press and enter any of the menu options given !!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear();
		cin.ignore();
		switchBoard(customer);
	}
 //a switch to handle the various menu options and redirect accordingly.
	switch(c)
	{		
	case 1:
		newCustomer(customer);
		break;
	case 2:
		showCustomers(customer);
		break;
	case 3:
		searchCustomersByID(customer);
		break;
	case 4:
		changeCustomerDetails(customer);
		break;
	case 5:
		deleteCustomer(customer);
		break;
	case NULL:
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!! Invalid entry. Please press and enter any of the menu options given !!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear();
		cin.ignore();
		switchBoard(customer);
		break;
	}
	
	_getch();
}

//Function to show all customers, one by one.
void showCustomers(struct Customers *customer)
{
	//loop through each customer and print out their details one by one.
	for (int i = 0; i < customerCount; i++)
	{
		cout << "-----------------------------" << endl;
		cout << "\u2022| Customer ID: " << customer[i].customerID << endl;
		cout << "\u2022| Customer first name: " << customer[i].customer_fName << endl;
		cout << "\u2022| Customer surname: " << customer[i].customer_sName << endl;
		cout << "\u2022| Customer address: " << customer[i].customer_address << endl;
		cout << "\u2022| Customer postcode: " << customer[i].customer_postCode << endl;
		cout << "\u2022| Customer age: " << customer[i].customer_age << endl;
		cout << "-----------------------------" << endl;
		cout << "\n" << endl;
		
		
	}
	//display the total number of customers currently in the system.
	cout << "-----------------------------------" << endl;
	cout << "\u2022 There are: " << customerCount << " customers in the system.\n" << endl;
	cout << "-----------------------------------" << endl;
	switchBoard(customer);
}

//Function to search for a specific customer based on ID
void searchCustomersByID(struct Customers *customer)
{
	int id, i;
	cout << "-----------------------------------------" << endl;
	cout << "| In order to search for a specific customer, an ID is needed.";
	cout << "| Please enter the Customer ID: " << endl; cin >> id;
	if (cin.fail())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!   Invalid entry. Please enter the ID of the customer as an integer.   !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear();
		cin.ignore();
		cin.get(); //makes the program wait for input.
		cout << "\n Please enter the ID of the customer you want to delete: "; cin >> id;
	}
	//searching the array of structs for a specific ID, with length of 30 as max, as declared
	for (i = 0; i < customerCount; i++)
	{
		if (customer[i].customerID == id)
		{
			cout << "-----------------------------" << endl;
			cout << "\u2022| The customer with the id " << id << " is listed below: " << endl;
			cout << "\u2022| Customer first name: " << customer[i].customer_fName << endl;
			cout << "\u2022| Customer surname: " << customer[i].customer_sName << endl;
			cout << "\u2022| Customer address: " << customer[i].customer_address << endl;
			cout << "\u2022| Customer postcode: " << customer[i].customer_postCode << endl;
			cout << "\u2022| Customer age: " << customer[i].customer_age << endl;
			cout << "----------------------------" << endl;
			cout << "\n" << endl;
		}
	}
	switchBoard(customer);
}

/*This function provides the option to search a customer based on their ID
and choose to change any individual detail of chosen customer*/
Customers changeCustomerDetails(struct Customers *customer)
{
	int id, i;
	char answer;
	cout << "-------------------------------------------------------------------------" << endl;
	cout << setw(47) << "\n [] Please provide the ID of the Customer whose details you'd like to change: " << endl; cin >> id;
	cout << "-------------------------------------------------------------------------\n" << endl;
	if (cin.fail())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!   Invalid entry. Please enter the ID of the customer as an integer.   !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear();
		cin.ignore();
		cin.get(); //makes the program wait for input.
		cout << "\n Please enter the ID of the customer you want to delete: "; cin >> id;
	}
	/*loop through each of the details for the chosen customer and change each detail, if required.*/
	for (i = 0; i < customerCount; i++)
	{
		if (customer[i].customerID == id)
		{
			cout << "---------------------------------------------------" << endl;
			cout << "|The customer with the id of '" << id << "' is listed below: \n" << endl;
			cout << "---------------------------------------------------" << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "|Customer's current first name: " << customer[i].customer_fName << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "\n [] Would you like to change their first name? Enter 'y' for Yes, 'n' for No." << endl;
			cin >> answer;

			if (answer == 'y')
			{
				getchar();
				cout << "---------------------------------------------------" << endl;
				cout << "\u2022|Please enter the Customer's first name: "; getline(cin, customer[i].customer_fName);
				cout << "\n-------------------------------------------------" << endl;
				
			}
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "|Customer's current surname: " << customer[i].customer_sName << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "\n [] Would you like to change their surname? Enter 'y' for Yes, 'n' for No." << endl;
			cin >> answer;

			if (answer == 'y')
			{
				getchar();
				cout << "---------------------------------------------------" << endl;
				cout << "\u2022|Please enter the Customer's surname: "; getline(cin, customer[i].customer_sName);
				cout << "\n-------------------------------------------------" << endl;
				
			}
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "|Customer's current address: " << customer[i].customer_address << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "\n [] Would you like to change their address? Press 'y' for Yes, 'n' for No." << endl;
			cin >> answer;

			if (answer == 'y')
			{
				getchar();
				cout << "---------------------------------------------------" << endl;
				cout << "\u2022|Please enter the Customer's address: "; getline(cin, customer[i].customer_address);
				cout << "\n-------------------------------------------------" << endl;
				
				
			}
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "|Customer's current postcode: " << customer[i].customer_postCode << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "\n [] Would you like to change their postcode? Press 'y' for Yes, 'n' for No." << endl;
			cin >> answer;

			if (answer == 'y')
			{
				getchar();
				cout << "---------------------------------------------------" << endl;
				cout << "\u2022|Please enter the Customer's postcode: "; getline(cin, customer[i].customer_postCode);
				cout << "---------------------------------------------------" << endl;
				
			}
			cin.clear();
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "|Customer's current age: " << customer[i].customer_age << endl;
			cout << "--- --- --- --- --- --- ---" << endl;
			cout << "\n [] Would you like to change their age? Press 'y' for Yes, 'n' for No." << endl;
			cin >> answer;

			if (answer == 'y')
			{
				cout << "---------------------------------------------------" << endl;
				cout << "\u2022|Please enter the Customer's age: "; cin >> customer[i].customer_age;
				cout << "---------------------------------------------------" << endl;
				//if the user input is not between legal age of 18 or max age of 65 or if not an integer
				if (cin.fail() || customer[i].customer_age <= 18 || customer[i].customer_age >= 65)
				{
					cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
					cout << "!!!   Invalid entry. Please enter the age of the customer as an integer.   !!! " << endl;
					cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
					cin.clear();
					cin.ignore();
					cin.get(); //makes the program wait for input.
					cout << "\n Please enter the Customer's age: "; cin >> customer[i].customer_age;
					
				}
			}
			cout << "-------------------------------------------------------------------------" << endl;
			
			//after the change, this prints out the updated customer details.
			cout << "---------------------------------------------------" << endl;
			cout << "\n[] The updated customer details are below: ";
			cout << "The customer with the id " << id << "is listed below: " << endl;
			cout << "Customer first name: " << customer[i].customer_fName << endl;
			cout << "Customer surname: " << customer[i].customer_sName << endl;
			cout << "Customer address: " << customer[i].customer_address << endl;
			cout << "Customer postcode: " << customer[i].customer_postCode << endl;
			cout << "Customer age: " << customer[i].customer_age << endl;
			cout << "---------------------------------------------------" << endl;
		}
	}
	switchBoard(customer);
	return customer[i];
}

//function to delete a customer based on their ID;
Customers deleteCustomer(struct Customers *customer)
{
	int id, i, j;
	cout << "\n Please enter the ID of the customer you want to delete: "; cin >> id;
	/*nested for loops to loop through all customers and
	replace the "deleted" customer with the one after it
	and moving each of the ones after it back one element*/
	if (cin.fail())
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!!   Invalid entry. Please enter the ID of the customer as an integer.   !!! " << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		cin.clear();
		cin.ignore();
		cin.get(); //makes the program wait for input.
		cout << "\n Please enter the ID of the customer you want to delete: "; cin >> id;
	}
	else if (id >= 100 && id <= 130)
	{
		for (i = 0; i < customerCount; i++)
		{
			if (customer[i].customerID == id)
			{
				for (j = i; j < customerCount - 1; j++)
				{
					if (customer[j + 1].customerID != NULL)
					{
						customer[j].customerID = customer[j + 1].customerID - 1;
						customer[j].customer_fName = customer[j + 1].customer_fName;
						customer[j].customer_sName = customer[j + 1].customer_sName;
						customer[j].customer_address = customer[j + 1].customer_address;
						customer[j].customer_postCode = customer[j + 1].customer_postCode;
						customer[j].customer_age = customer[j + 1].customer_age;
					}
				}
			}
		}
		//modify the number of customers (customerCount).
		customerCount -= 1;
		cout << "\u2022 There are now " << customerCount << " customers in the system." << endl;
		switchBoard(customer);
		return customer[i];
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		cout << "!!! Invalid entry. You will be taken back to the main menu  !!!" << endl;
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" << endl;
		switchBoard(customer);
	}
}


