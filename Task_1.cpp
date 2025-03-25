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
        for(int i = 0;i<currentSize;i++)
            if
    }


	~MyList() { delete[] arr; }
};

int main()
{
	MyList <int> obj(3);
	obj.addElementAtFirstIndex(10);
	obj.display();
	obj.addElementAtLastIndex(11);
	obj.display();
	obj.addElementAtLastIndex(12);
	obj.display();
	obj.addElementAtFirstIndex(13);
	obj.display();
	int el = obj.removeElementFromEnd();
	obj.display();
	obj.removeElementFromStart();
	obj.display();
	obj.addElementAtFirstIndex(11);
	obj.display();
	obj.removeElementFromStart();
	obj.display();

	return 0;
}