#include "Account.cpp"
/* Main Function start*/
int main() {
	float balance;
	int choice = 0, i = 0, testNumber;
	Account account[TOTAL_ACCOUNTS];
	while (true) {
		/*Maximum 10 account should be created as length of array*/
		if (i == 10) {
			break;
		}
		account[i].setUserData();
		account[i].displayAccountInfo();
		cout << "Do u wana create Another account 1/0: ";
		cin >> choice;
		if (choice == 0) {
			break;
		}
		i++;
	}

	cout << "Please Enter Account number to be details displayed: " << endl;
	cin >> testNumber;
	for (i = 0; i<TOTAL_ACCOUNTS; i++) {
		if (account[i].getAccountNumber() == testNumber) {

			/* prompt for depositing money in account*/
			cout << "Enter the amount to be deposited: " << endl;
			cin >> balance;
			account[i].deposit(balance);
			/* prompt for withdraw money from account*/
			int flag = 1;
			while (flag) {
				cout << "Enter the amount to be withdraw: " << endl;
				cin >> balance;
				/* withdraw function calling*/
				account[i].withdraw(balance);
				cout << "Do u wana withdraw again 1/0: " << endl;
				cin >> flag;
			}
		}
	}
	return 0;
	getchar();
}