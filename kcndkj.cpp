#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
int choice;
string filename, data;

do {
    cout << "\n--- FILE HANDLING OPERATIONS ---\n";
    cout << "1. Create File\n";
    cout << "2. Write to File\n";
    cout << "3. Read File\n";
    cout << "4. Delete File\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            cout << "Enter filename: ";
            cin >> filename;

            ofstream file(filename);

            if (file) {
                cout << "File created successfully!\n";
                file.close();
            } else {
                cout << "Error creating file!\n";
            }
            break;
        }

        case 2: {
            cout << "Enter filename: ";
            cin >> filename;

            ofstream file(filename, ios::app);

            if (file) {
                cout << "Enter data to write: ";
                cin.ignore();
                getline(cin, data);

                file << data << endl;
                file.close();

                cout << "Data written successfully!\n";
            } else {
                cout << "Error opening file!\n";
            }
            break;
        }

        case 3: {
            cout << "Enter filename: ";
            cin >> filename;

            ifstream file(filename);

            if (file) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "File not found!\n";
            }
            break;
        }

        case 4: {
            cout << "Enter filename: ";
            cin >> filename;

            if (remove(filename.c_str()) == 0)
                cout << "File deleted successfully!\n";
            else
                cout << "Error deleting file!\n";

            break;
        }

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
    }

} while (choice != 5);

return 0;
}