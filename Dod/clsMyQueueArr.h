#pragma once
#include<iostream>
#include"clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T>_MyList;

public:

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}

	void pop()
	{
		_MyList.DeleteFirstItem();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size()-1);
	}

	T GetItem(int idx)
	{
		return _MyList.GetItem(idx);
	}

	void Reverse()
	{

		_MyList.Reverse();

	}

	void UpdateItem(int idx, T Newvalue)
	{
		_MyList.SetItem(idx, Newvalue);

	}

	void InsertAfter(int idx, T value)
	{
		_MyList.InsertAfter(idx, value);
	}

	void InsertAtFront(T value)
	{
		_MyList.InsertAtBeginning(value);

	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);


	}

	void Clear()
	{
		_MyList.Clear();
	}

	void Print()
	{
		_MyList.PrintList();
	}
};

