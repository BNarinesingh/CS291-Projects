#include <vector>
#include "CreditCard.h"

using namespace std;

void testCard(int NumC){
	vector<CreditCard*> wallet(11);
    
    wallet[0] = new CreditCard("5391 0375 9387 5309", "John Bowman", 2500);
    wallet[1] = new CreditCard("3485 0399 3395 1954", "John Bowman", 3500);
    wallet[2] = new CreditCard("6011 4902 3294 2994", "John Bowman", 4500);
	wallet[3] = new CreditCard("4564 4377 4543 3432", "John Bowman", 5000);
	wallet[4] = new CreditCard("2344 5656 5653 2345", "John Bowman", 5500);
	wallet[5] = new CreditCard("3455 3455 3453 2343", "John Bowman", 6000);
	wallet[6] = new CreditCard("5675 5756 5675 6666", "John Bowman", 7500);
	wallet[7] = new CreditCard("5575 5675 5675 5675", "John Bowman", 8000);
	wallet[8] = new CreditCard("3434 4545 4545 5675", "John Bowman", 85000);
	wallet[9] = new CreditCard("4545 4545 6564 2994", "John Bowman", 9000);
	wallet[10] = new CreditCard("3333 4545 4545 2222", "John Bowman", 10000);

    for(int j=1; j<=16; j++){
        wallet[0]->chargeit(double(j));
        wallet[1]->chargeit(2*j);
        wallet[2]->chargeit(3*j);
    }
    
    cout <<"Card payments: \n ";
    for (int i=0; i<NumC; i++){
        cout<<*wallet[i];

    while(wallet[i]->getBalance()>100.0){
        wallet[i]->makePayment(100.0);
        cout<<"New balance = " <<wallet[i]->getBalance() << "\n";
    }
    cout<<"\n";
    delete wallet[i];
}
}
int main(){
	int NumC;

	cout << "Enter number of cards to check ";
	cin >> NumC;

	testCard(NumC);
	system("pause");
    return 0;
	
}
        
