#include<iostream>
#include<string>
using namespace std;

#define SIZE 10

struct Node{
	string name, phone;
	Node* next;
};

Node* table[SIZE] = {NULL};

int hf(string phone){
	int sum = 0;
	for(int i = 0; i < phone.length(); i++){
		sum += phone[i];
	}
	return (sum % SIZE);
}

void insert(string name, string phone){
	int index = hf(phone);
	Node* newNode = new Node;

	newNode->name = name;
	newNode->phone = phone;
	newNode->next = table[index];
	table[index] = newNode;
}

void search(string phone){
	int index = hf(phone);
	Node* temp = table[index];

	while(temp != NULL){
		if(temp->phone == phone){
			cout << "Contact found!" << endl << "-------------------------------" << endl;
			cout << "Name: " << temp->name << endl;
			cout << "Phone Number: " << temp->phone << endl << "-------------------------------" << endl;
			return;
		}
		else{
			temp = temp->next;
		}
	}
	cout << "Contact not found..." << endl;
}

void del(string phone){
	int index = hf(phone);
	Node* temp = table[index];
	Node* prev = NULL;

	while(temp != NULL){
		if(temp->phone == phone){
			//First element to be deleted
			if(prev == NULL){
				table[index] = temp->next;
			}
			else{
				prev->next = temp->next;
			}
			delete temp;
			cout << "Contact deleted successfully!" << endl;
			return;
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
	cout << "Contact not found..." << endl;
}

int main(){
	string name, phone;
	int choice;

	do{
		cout << "----------Telephone Directory Management System----------" << endl;
		cout << "1. Insert a contact" << endl << "2. Search for a contact" << endl << "3. Delete a contact" << endl << "4. Exit" << endl << "Enter your choice: ";
		cin >> choice;

		switch(choice){
			case 1:
				cout << "Enter name: ";
				getline(cin >> ws, name);
				cout << "Enter phone number: ";
				cin >> phone;
				insert(name, phone);
				break;

			case 2:
				cout << "Enter phone number: ";
				cin >> phone;
				search(phone);
				break;

			case 3:
				cout << "Enter phone number: ";
				cin >> phone;
				del(phone);
				break;

			case 4:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice" << endl;
		}
	}while(choice != 4);

	return 0;
}