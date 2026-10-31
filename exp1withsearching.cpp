```cpp
#include<iostream>
#include<string>
using namespace std;

class student{
    private:
    int roll;
    string name;
    float cg;

    public:
    void set(int r, string n, float c){
        roll = r;
        name = n;
        cg = c;
    }

    void disp(){
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cg << endl;
        cout << "-------------------------------------\n\n";
    }

    string getn(){
        return name;
    }

    float getc(){
        return cg;
    }
};

void disp_all(student db[], int n){
    for(int i = 0; i < n; i++){
        db[i].disp();
    }
}

void BS_C(student db[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(db[j].getc() > db[j+1].getc()){
                student temp;
                temp = db[j];
                db[j] = db[j+1];
                db[j+1] = temp;
            }
        }
    }
}

void BS_N(student db[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(db[j].getn() > db[j+1].getn()){
                student temp;
                temp = db[j];
                db[j] = db[j+1];
                db[j+1] = temp;
            }
        }
    }
}

void IS_C(student db[], int n){
    int i = 0;

    while(i != n){
        int j = i;

        while(j != 0){
            if(db[j].getc() < db[j-1].getc()){
                student temp;
                temp = db[j];
                db[j] = db[j-1];
                db[j-1] = temp;
                j--;
            }
            else{
                break;
            }
        }
        i++;
    }
}

// Linear Search by CGPA
void LS_C(student db[], int n, float key){
    for(int i = 0; i < n; i++){
        if(db[i].getc() == key){
            cout << "Student Found:\n";
            db[i].disp();
            return;
        }
    }

    cout << "Student not found!\n";
}

// Binary Search by CGPA
void BS_Search_C(student db[], int n, float key){
    int low = 0, high = n - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(db[mid].getc() == key){
            cout << "Student Found:\n";
            db[mid].disp();
            return;
        }
        else if(db[mid].getc() < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    cout << "Student not found!\n";
}

int main(){
    student db[6];

    db[0].set(8239, "Rishi Kundalia", 8.93);
    db[1].set(8224, "Krishan Kumar Singh", 8.98);
    db[2].set(8222, "Khushdeep Singh", 8.73);
    db[3].set(8240, "Rishikesh Satyawan Shedge", 8.87);
    db[4].set(8241, "Rohit Sharad Pimpale", 8.78);
    db[5].set(8230, "Nilesh Kumar Rai", 8.68);

    cout << "-------------------------------------\n";
    cout << "Before Sorting:\n";
    cout << "-------------------------------------\n";
    disp_all(db, 6);

    cout << "\n\n\n-------------------------------------\n";
    cout << "Sorting by Name:\n";
    cout << "-------------------------------------\n";
    BS_N(db, 6);
    disp_all(db, 6);

    cout << "\n\n\n-------------------------------------\n";
    cout << "Sorting by CGPA:\n";
    cout << "-------------------------------------\n";
    IS_C(db, 6);
    disp_all(db, 6);

    // Searching
    float key;

    cout << "\nEnter CGPA to search: ";
    cin >> key;

    cout << "\nLinear Search:\n";
    LS_C(db, 6, key);

    cout << "\nBinary Search:\n";
    BS_Search_C(db, 6, key);
}

// Compile: g++ <prog_name>.cpp -o a.exe
// Run: ./a.exe
```
