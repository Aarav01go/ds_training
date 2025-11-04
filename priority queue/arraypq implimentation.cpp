#include <iostream>
using namespace std;
void ascEnqueue(int arr[], int* size, int element, int capacity){
    if(*size >= capacity){
        cout << "Array is full!" << endl;
        return;
    }
    int i = *size - 1;
    while(i >= 0 && arr[i] > element){
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
    (*size)++;
}

void ascDequeue(int arr[], int* size){
    if(*size == 0){
        cout << "Array is empty!" << endl;
        return;
    }
    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*size)--;
}
void desEnqueue(int arr[], int* size, int element, int capacity){
    if(*size >= capacity){
        cout << "Array is full!" << endl;
        return;
    }
    int i = *size - 1;
    while(i >= 0 && arr[i] > element){
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
    (*size)++;
}

void desDequeue(int arr[], int* size){
    if(*size == 0){
        cout << "Array is empty!" << endl;
        return;
    }
    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*size)--;
}


int main(){
    int capacity = 100, arr[100], n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter element to insert: ";
    cin >> k;
    ascEnqueue(arr, &n, k, capacity);
    cout << "After Enqueue (insert): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    ascDequeue(arr, &n);
    cout << "After Dequeue (delete front): ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}