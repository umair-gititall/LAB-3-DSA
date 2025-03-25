#include <iostream>
using namespace std;

template <class T>
class MyList {
	T* arr;
	int maxSize;
	int currentSize;
public:
	MyList(int c) :currentSize(c), maxSize(10)
	{
		if (currentSize < maxSize)
			arr = new T[currentSize]{};
		else
		{
			arr = new T[10]{};
			currentSize = maxSize;
		}
	}
	MyList(MyList* obj)
	{
		currentSize = obj->currentSize;
		maxSize = obj->maxSize;
		arr = new T[currentSize];

		for (int i = 0; i < currentSize; i++)
			arr[i] = obj->arr[i];
	}

	void addElementAtFirstIndex(T t)
	{
		arr[0] = t;
	}
	// Should add the element at the first position of the MyList 
	void addElementAtLastIndex(T t)
	{
		arr[currentSize - 1] = t;
	}
	// Should add the element at the last position of the MyList 
	T removeElementFromEnd()
	{
		int temp = arr[currentSize - 1];
		arr[currentSize - 1] = 0;
		currentSize--;
		return temp;
	}
	// Should remove the element from the last position of the MyList
	void removeElementFromStart()
	{
		for (int i = 0; i < currentSize - 1; i++)
			arr[i] = arr[i + 1];
		currentSize--;
	}
	//Should remove the element from the first position of the 
	void display()
	{
		for (int i = 0; i < currentSize; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

	bool empty()
	{
		for (int i = 0; i < currentSize; i++)
			if (arr[i] != 0)
				return false;
		return true;
	}
	
	bool full()
	{
		for (int i = 0; i < currentSize; i++)
			if (arr[i] == 0)
				return false;
		return true;
	}
	int size()
	{
		return currentSize;
	}
	bool insertAt(int index, T value)
	{
		if (index < currentSize && index >= 0)
		{
			arr[index] = value;
			return true;
		}
		return false;
	}
	T last()
	{
		return arr[currentSize - 1];
	}

	bool search(T t)
	{
		for (int i = 0; i < currentSize; i++)
			if (arr[i] == t)
				return true;
		return false;
	}
	~MyList() { delete[] arr; }
};

int main()
{
	MyList<int> MyList(5); // Assuming MyList is a templated class
	int choice, index, value;

	do {
		cout << "\nMenu:";
		cout << "\n1. Check if list is empty";
		cout << "\n2. Check if list is full";
		cout << "\n3. Get size of list";
		cout << "\n4. Insert at index";
		cout << "\n5. Get last element";
		cout << "\n6. Search for a value";
		cout << "\n7. Exit";
		cout << "\nEnter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << (MyList.empty() ? "List is empty." : "List is not empty.") << endl;
			break;
		case 2:
			cout << (MyList.full() ? "List is full." : "List is not full.") << endl;
			break;
		case 3:
			cout << "Current size: " << MyList.size() << endl;
			break;
		case 4:
			cout << "Enter index and value: ";
			cin >> index >> value;
			if (MyList.insertAt(index, value))
				cout << "Value inserted successfully." << endl;
			else
				cout << "Failed to insert value." << endl;
			break;
		case 5:
			cout << "Last element: " << MyList.last() << endl;
			break;
		case 6:
			cout << "Enter value to search: ";
			cin >> value;
			cout << (MyList.search(value) ? "Value found." : "Value not found.") << endl;
			break;
		case 7:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	} while (choice != 7);

	return 0;
}