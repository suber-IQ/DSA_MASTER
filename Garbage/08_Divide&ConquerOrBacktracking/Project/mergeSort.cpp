// 👉 Sorted student records by grade:

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Definitions for Student struct and merge sort functions

struct Student {
    string name;
    int grade;

    // Default constructor
    Student() : name(""),grade(0){}

    Student(string n, int g) : name(n), grade(g) {}
};

// Merge function
void merge(vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Student> L(n1);
    vector<Student> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].grade <= R[j].grade) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(vector<Student>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print the array
void printArray(const vector<Student>& arr) {
    for (const auto& student : arr)
        cout << "Name: " << student.name << ", Grade: " << student.grade << "\n";
}

// Main function to test merge sort
int main() {
    // Sample student data
        vector<Student> students = {
        Student("Alice", 85),
        Student("Bob", 95),
        Student("Charlie", 80),
        Student("Dave", 90),
        Student("Eve", 70)
    };

    cout << "Given student records:\n";
    printArray(students);

    mergeSort(students, 0, students.size() - 1);

    cout << "\nSorted student records by grade:\n";
    printArray(students);


   // 🎉 output:- 
          // 👉 Given student records:
          // Name: Alice, Grade: 85
          // Name: Bob, Grade: 95
          // Name: Charlie, Grade: 80
          // Name: Dave, Grade: 90
          // Name: Eve, Grade: 70

          // 👉 Sorted student records by grade:
          // Name: Eve, Grade: 70
          // Name: Charlie, Grade: 80
          // Name: Alice, Grade: 85
          // Name: Dave, Grade: 90
          // Name: Bob, Grade: 95


    return 0;
}
