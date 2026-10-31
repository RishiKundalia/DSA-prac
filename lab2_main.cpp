#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;//left side first index
    int n2 = right - mid;//right side first index
    int L[n1], R[n2];//left and right side temp arrays

    for(int i = 0; i < n1; i++){//left side ke liye temp arr
        L[i] = arr[left + i];
    }

    for(int j = 0; j < n2; j++){//right side ke liye temp arr
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){//check which side's element is smaller then input that into arr
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1){//if L[] has elements left so just input them in arr[]
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){//if R[] has elements left so just input them in arr[]
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Dividing(int arr[], int left, int right) {
    if(left < right){
        int mid = (left + right) / 2;

        Dividing(arr, left, mid);//dividing for left side recursively
        Dividing(arr, mid + 1, right);// dividing for right side recursively
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    Dividing(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}