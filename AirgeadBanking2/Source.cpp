/*
*
* Kiersten Grove
* Airgead Banking Application
* 1 February 2023
*
*/

#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void printColumn(string value, int width)
{
	cout << setw(width) << value;
}

void printRow(string columnOne, string columnTwo, string columnThree)
{
	printColumn(columnOne, 6);
	printColumn(columnTwo, 25);
	printColumn(columnThree, 30);
	cout << endl;
}

string formatMoney(double amount)
{
	stringstream ss;
	ss << "$" << fixed << setprecision(2) << amount;
	return ss.str();
}

int main()
{
	float initInv, monDep, anuInt, months, years; // variables to store input
	float totalAmount, intAmount, yearTotInt; // variables to store end year amounts

	cout << "********************************" << endl; // get data input from user
	cout << "********** Data Input **********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initInv;
	cout << "Monthly Deposit: $";
	cin >> monDep;
	cout << "Annual Interest: %";
	cin >> anuInt;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	system("PAUSE"); // waits for input from user

	totalAmount = initInv; // sets total amount to be updated

	cout << endl;
	cout << "     Balance and Interest Without Additional Monthly Deposits" << endl; // displays year data without additional monthly deposits
	cout << "==================================================================" << endl;
	printRow("Year", "Year End Balance", "Year End Earned Interest");
	cout << "------------------------------------------------------------------" << endl;

	for (int i = 0; i < years; i++)
	{
		intAmount = (totalAmount) * (anuInt / 100); // calculates yearly interest

		totalAmount = totalAmount + intAmount; // calculates year end total

		printRow(to_string(i + 1), formatMoney(totalAmount), formatMoney(intAmount)); // outputs results with only two decimal places
	}

	totalAmount = initInv; // sets total amount to initial investment to be updated

	cout << endl;
	cout << "      Balance and Interest With Additional Monthly Deposits" << endl; // displays year data with additional monthly deposits
	cout << "================================================================" << endl;
	printRow("Year", "Year End Balance", "Year End Earned Interest");
	cout << "----------------------------------------------------------------" << endl;

	for (int i = 0; i < years; i++)
	{
		yearTotInt = 0; // sets yearly interest to zero 
		for (int j = 0; j < 12; j++)
		{
			intAmount = (totalAmount + monDep) * ((anuInt / 100) / 12); // calculates monthly interest

			yearTotInt = yearTotInt + intAmount; // calculates month end interest

			totalAmount = totalAmount + monDep + intAmount; // calculates month end total
		}

		printRow(to_string(i + 1), formatMoney(totalAmount), formatMoney(yearTotInt)); // outputs results with only two decimal places
	}
}