//Assignment 4.................................................................................................
//CS291 AddressBookProgram Copyright (c) 2015 Barindra Narinesingh. All rights reserved.

#include <iostream>
#include<string>
#include<deque>					//I found the deque library after I couldn't get my code to work
								//after troubleshooting for a while I got my code to work but left the deque
								//library to check my code.

using namespace std;
using std::deque;			

class LinkedDequeException		// After a lot of research I found a method that used the throw that worked
{								// You need a seperate class for the throw to go to to catch
public:
	LinkedDequeException()
	{
		cout << "LinkedDeque empty" << endl;
	}
};


class DNode
{
public:
	int elem;
	DNode* next;
	DNode* prev;
};

class LinkedDeque
{
private:
	DNode* front;
	DNode* back;
	int n;

public:
	LinkedDeque()
	{
		front = NULL;
		back = NULL;
		n = 0;
	}
	
	int Size() { return n; }
	bool empty() {
		if (n == 0)
			return true;
		else
			return false;
	}

	int Front(){
		if (empty())
			throw new LinkedDequeException();

		return front->elem;		//point to front element
	}

	int Back(){
		if (empty())
			throw new LinkedDequeException();

		return back->elem;		//point to back element
	}
	
	void insertFront(int e){
	
		DNode* temp = new DNode();			//make the new node 
		temp->elem = e;
		temp->next = NULL;
		temp->prev = NULL;

		if (empty()) {
			front = temp;
			front = back;
			}
		else {
			temp->next = front;
			front->prev = temp;
			front = temp;
			}
		n++;
	}

	int removeFront(){
		if (empty()) {
			throw new LinkedDequeException();
		}

		//  elem in the front DNode
		int temp2 = front->elem;

		DNode* temp = front;
		if (front->next != NULL){
			front = front->next;
			front->prev = NULL;
		}
		else {
			front = NULL;
		}
		n--;
		delete temp;

		return temp2;  //removes element but returns it so you can use it, more useful than void.
	}

	void insertBack(int e){

		DNode* temp = new DNode();
		temp->elem = e;
		temp->next = NULL;
		temp->prev = NULL;

		if (empty()) {
			front = back = temp;
		}
		else {
			back->next = temp;
			temp->prev = back;
			back = temp;
		}

		n++;
	}

	int removeBack(){
		if (empty()) {
			throw new LinkedDequeException();
		}
		int temp2;
		
		temp2=back->elem;
		DNode* temp = back;
		if (back->prev != NULL){
			back = back->prev;
			back->next = NULL;
		}
		else {
			back = NULL;
		}

		n--;
		delete temp;

		return temp2;
	}

};


void printDeque(LinkedDeque& bDeque) {

	int s = bDeque.Size();
	
	for (int x = 0; x < s; x++) {

		cout << bDeque.Front() << " ";
		bDeque.insertBack(bDeque.removeFront()); //advantage of int is i save a line here 
												//since i can get the elem removed.
	}
	cout << endl;
}

void printDeque2(deque<int> aDeque) {

	int s = aDeque.size();

	for (int x = 0; x < s; x++) {

		cout << aDeque.front() << " ";
		aDeque.push_back(aDeque.front());
		aDeque.pop_front();

	}

}




int main() {

	//Testing, by comparing to the built in deque library........................................................................

	deque<int> LinkedDeque2;
	LinkedDeque LinkedDeque1;

	for (int x = 1; x <= 5; x++) {
		LinkedDeque2.push_back(x);		//built in libray insert
		LinkedDeque1.insertBack(x);		//created insert
	}
	 
	 cout << " Printing elements in LinkedDeque: "<<endl;
	 	
	printDeque2(LinkedDeque2);
	cout << " : should be the same as : ";
	printDeque(LinkedDeque1);

	cout << "\nPrinting elements LinkedDeque again to verify:";

	printDeque2(LinkedDeque2);
	cout << " : should be the same as : ";
	printDeque(LinkedDeque1);

	//...................................................................................
	char answer; int anumber; 
	
	LinkedDeque LinkedDeque3;

	cout << "\nDo you want to make your own dequeue? y/n ";
	cin >> answer;

	if (answer == 'y') {
		cout << "What number do you want to put in? ";
		cin >> anumber;
		LinkedDeque3.insertBack(anumber);

		do {
			cout << "\nDo you want to add another number? if so what is it? type 0 to quit: ";
			cin >> anumber;
			if (anumber != 0) {

				cout << "Do you want to put it in the front or the back of the deque? f/b ";
				cin >> answer;

				if (answer == 'f')
					LinkedDeque3.insertFront(anumber);

				else if (answer == 'b')
					LinkedDeque3.insertBack(anumber);
			}

		} while (anumber != 0);

		cout << "Your deque stack contains the numbers ";
		printDeque(LinkedDeque3);

	}
	else
		cout << "Good day ";




	cout << "\nEnd of Program " << endl << endl;
	system("pause");
	return 0;

}

