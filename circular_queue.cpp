#include<iostream>
using namespace std;

#define MAX 5
int q[MAX];
int front = -1;
int rear = -1;

void enqueue(int value){
	//Queue is full
	if((rear+1)%MAX == front){
		cout << "Queue is full..." << endl;
	}
	else{
		//First element
		if(front == -1){
			front = rear = 0;
		}
		//General Case
		else{
			rear = (rear+1) % MAX;
		}
		q[rear] = value;
		cout << "Value entered successfully!" << endl;
	}
}

void dequeue(){
	//Queue is empty
	if(front == -1){
		cout << "Queue is empty..." << endl;
		return;
	}
	else{
		//Only 1 element was there
		if(front == rear){
			front = rear = -1;
		}
		//General Case
		else{
			front = (front+1) % MAX;
		}
		cout << "Value deleted successfully!" << endl;
	}
}

void disp(){
	int i = front;
	while(true){
		if(front == -1){
			cout << "Queue is empty..." << endl;
			return;
		}
		else{
			cout << q[i] << " ";

			if(i == rear){
				break;
			}

			else{
				i = (i+1) % MAX;
			}
		}
		cout << endl;
	}
}

int main(){
	int value;
	int choice;	
	do{
		cout << "----------Circular Queue----------" << endl;
		cout << "1. Enqueue" << endl << "2. Dequeue" << endl << "3. Display" << endl << "4. Exit" << endl << "Enter your choice: ";
		cin >> choice;

		switch(choice){
		case 1:
			cout << "Enter the value: ";
			cin >> value;
			enqueue(value);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			disp();
			break;

		case 4:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice..." << endl;
		}
	}while(choice != 4);

	return 0;
}