#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// ENQUEUE
void enqueue(int value){
    // Queue is full
    if ((rear + 1) % MAX == front){
        cout << "Queue is Full!\n";
        return;
    }

    // First element
    if (front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;

    cout << value << " inserted into queue.\n";
}

// DEQUEUE
void dequeue(){
    // Queue is empty
    if (front == -1){
        cout << "Queue is Empty!\n";
        return;
    }

    cout << queue[front] << " deleted from queue.\n";

    // Only one element
    if (front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }
}

// DISPLAY
void display(){
    if (front == -1){
        cout << "Queue is Empty!\n";
        return;
    }

    cout << "Circular Queue: ";

    int i = front;

    while (true){
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    cout << endl;
}

int main(){
    int choice, value;

    do{
        cout << "\n----- CIRCULAR QUEUE -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}