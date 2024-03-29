


#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int account = 1000000;														//Customer account
int rnd = rand();															//For trasaction code

int withdraw(int wdamt) {													//Withdraw function

	int total = account - wdamt;
	return total;
}

int deposit(int dpst) {														//Deposit Function

	int total = account + dpst;
	return total;
}

double credit(int loan, int months, int cdt) {								//Credit score function

	double payment;															//Monthly payment for loan
	if (cdt <= 500) {
		payment = pow(((loan)*(1.05)), (months/12.0)) / months;				//5% interest rate
	}
	else if (501 <= cdt && cdt <= 700) {
		payment = pow(((loan)*(1.02)), (months/12.0)) / months;				//2% interest rate
	}
	else {
		payment = pow(((loan)*(1.01)), (months/12.0)) / months;				//1% interest rate
	}
	return payment;
}  

void main() {

	int opt;
	bool flag = true;
	do{
		cout << "Select an action:" << endl;
		cout << "1. Withdraw the Amount" << endl;
		cout << "2. Deposit the Amount" << endl;
		cout << "3. Take a Loan" << endl;
		cout << "4. Quit" << endl;

		cin >> opt;

		int amt;
		int month;
		int cdt;
		int loan;

		switch (opt)
		{
		case 1 :
		{
			cout << "How much amount do you want to withdraw?" << endl;
			cin >> amt;
			if (amt > 1000000) {
				cout << "You cannot withdraw more than you have." << endl;
				break;
			}
			account = withdraw(amt);
			cout << "Remaining amount is: " << account << endl;
			break;
		}
		case 2 :
		{
			cout << "How much amount do you want to deposit?" << endl;
			cin >> amt;
			account = deposit(amt);
			cout << "Transaction is complete." << endl;
			cout << "Transaction code is: " << rnd << endl;
			cout <<	"Current available balance is: " << account << endl;
			break;
		}
		case 3 :
		{
			cout << "Enter your credit score" << endl;
			cin >> cdt;
			cout << "In how many months will you pay off the loan?" << endl;
			cin >> month;
			cout << "How much loan do you want?" << endl;
			cin >> loan;
			double payment = credit(loan, month, cdt);
			cout << "Your monthly payment will be:" << payment << endl;
			break;
		}
		default :
		{
			
			flag = false;
			exit(1);
		}
		}
	} while (flag);
}

