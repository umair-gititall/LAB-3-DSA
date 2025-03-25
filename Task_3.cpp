#include <iostream>
using namespace std;

class CustomList {
    int* arr;
    int size;
public:
    CustomList(int* elements, int s) : size(s) {
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = elements[i];
    }
    ~CustomList() { delete[] arr; }

    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int sum_ofPrime() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (isPrime(arr[i])) sum += arr[i];
        }
        return sum;
    }

    void printDuplicates() {
        cout << "Duplicate elements: ";
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    cout << arr[i] << " ";
                    break;
                }
            }
        }
        cout << endl;
    }

    void rotateClockwise(int r) {
        int mid = size / 2;
        r = r % mid;
        for (int i = 0; i < r; i++) {
            int temp = arr[mid - 1];
            for (int j = mid - 1; j > 0; j--) arr[j] = arr[j - 1];
            arr[0] = temp;
            temp = arr[size - 1];
            for (int j = size - 1; j > mid; j--) arr[j] = arr[j - 1];
            arr[mid] = temp;
        }
    }

    void rotateAntiClockwise(int r) {
        int mid = size / 2;
        r = r % mid;
        for (int i = 0; i < r; i++) {
            int temp = arr[0];
            for (int j = 0; j < mid - 1; j++) arr[j] = arr[j + 1];
            arr[mid - 1] = temp;
            temp = arr[mid];
            for (int j = mid; j < size - 1; j++) arr[j] = arr[j + 1];
            arr[size - 1] = temp;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    int elements[] = { 3, 5, 7, 10, 10, 2, 8, 15, 17, 19 };
    int size = sizeof(elements) / sizeof(elements[0]);
    CustomList cl(elements, size);
    int choice, r;

    do {
        cout << "\nMenu:\n";
        cout << "1. Sum of prime numbers\n";
        cout << "2. Print duplicate elements\n";
        cout << "3. Rotate clockwise\n";
        cout << "4. Rotate anti-clockwise\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Sum of prime numbers: " << cl.sum_ofPrime() << endl;
            break;
        case 2:
            cl.printDuplicates();
            break;
        case 3:
            cout << "Enter rotations: ";
            cin >> r;
            cl.rotateClockwise(r);
            cout << "List rotated clockwise." << endl;
            break;
        case 4:
            cout << "Enter rotations: ";
            cin >> r;
            cl.rotateAntiClockwise(r);
            cout << "List rotated anti-clockwise." << endl;
            break;
        case 5:
            cl.display();
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);

    return 0;
}