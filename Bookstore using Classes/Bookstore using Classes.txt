#include<iostream>
#include<string>

using namespace std;

class memberType {
public:
	memberType();
	memberType(const string& nm, const string& id, int bk, double am);
	memberType(const memberType& pass);
	int getMembers();
	void increaseBy(int x);

	string memberID;
	int booksBought;
	double amountSpent;
	int membersTotal;

private:
	string name;												// name should be private
};

memberType::memberType() {										//default constructor
	name = "no name";
	memberID = "no ID";
	booksBought = 0;
	amountSpent = 0.0;
	membersTotal = 0;
}

memberType::memberType(const string& nm, const string& id, int bk, double am) {		//constructor given values
	name = nm;
	memberID = id;
	booksBought = bk;
	amountSpent = am;
	membersTotal = membersTotal + bk;
}

memberType::memberType(const memberType& pass) {					// copy constructor
	name = pass.name;
	memberID = pass.memberID;
	booksBought = pass.booksBought;
	amountSpent = pass.amountSpent;
	membersTotal = pass.membersTotal;
}

int memberType::getMembers() {
	return membersTotal;
}

void memberType::increaseBy(int x) {
	membersTotal += x;
}


int main() {
	memberType();
	memberType Holdstotal;
	memberType Blank;

	memberType guy1;
	Holdstotal.increaseBy(1);

	memberType guy2("James_Bond", "0007", 5, 25.00);
	Holdstotal.increaseBy(1);

	memberType girl1("Jessica_Solo", "1234", 2, 10.00);
	Holdstotal.increaseBy(1);

	memberType guy3(guy2);


	cout << "Test that guy 2 is saved correctly " << endl;
	cout << "User ID :" << guy2.memberID << endl;
	cout << "Books Bought :" << guy2.booksBought << endl;
	cout << "Amount Spent : $ " << guy2.amountSpent << endl;

	cout << "Book store has " << Holdstotal.getMembers() << " members " << endl;

	int answer;
	string answer1, answer2;
	int answer3;
	double answer4 = 0.0;

	cout << "Welcome to the invite only bookstore, are you a member or a guest? enter 0 for member, 1 to copy, anything else for guest: " << endl;
	cin >> answer;

	if (answer == 0) {
		cout << "Please input your name " << endl;
		cin >> answer1;
		cout << "Please input your ID " << endl;
		cin >> answer2;
		cout << "How many books did you buy? ";
		cin >> answer3;
		answer4 = answer3 * 5;
		cout << "Your total is: " << answer4 << endl << endl;

		memberType guy4(answer1, answer2, answer3, answer4);

		cout << "Please verify your infomation " << endl;

		cout << "User ID :" << guy4.memberID << endl;
		cout << "Books Bought :" << guy4.booksBought << endl;
		cout << "Amount Spent : " << guy4.amountSpent << endl;
		Holdstotal.increaseBy(1);
		cout << "You are member: " << Holdstotal.getMembers() << " of our store " << endl << endl;

	}

	else if (answer = 1) {
		cout << "WARNING This is to COPY infomation of the last user. press any key to copy" << endl;
		cin >> answer;
		memberType guy4(guy2);
		cout << "User ID :" << guy4.memberID << endl;
		cout << "Books Bought :" << guy4.booksBought << endl;
		cout << "Amount Spent : " << guy4.amountSpent << endl;
		cout << "You are member: " << Holdstotal.getMembers() << " of our store " << endl << endl;


	}
	else {
		cout << "How many books did you buy ?";
		cin >> answer3;
		answer4 = answer3 * 5;
		cout << "Your total is: " << answer4 << endl << endl;
	}

	cout << "End of Program " << endl << endl << endl;

	system("pause");
	return 0;

}
