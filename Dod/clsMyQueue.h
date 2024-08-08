#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T> _MyList;
public:

	void push(T value)
	{
		_MyList.InsertAtEnd(value);
	}


	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	void Print()
	{
		_MyList.PrintList();
	}

	int Size()
	{
		return _MyList.Size();
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
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
		_MyList.UpdateItem(idx, Newvalue);

	}

	void InsertAfter(int idx, T Newvalue)
	{
		_MyList.InsertAfter(idx, Newvalue);
	}


	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);

	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);


	}


	void Clear()
	{
		_MyList.Clear();
	}



};

