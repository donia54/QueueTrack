#pragma once
#include<iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;

	T* _TempArray;

public:

	T* MyArray;

	clsDynamicArray(int size=0)
	{
		if (size < 0)
		{
			size = 0;
		}
		_Size = size;
		MyArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] MyArray;
	}

	bool SetItem(int idx, T value)
	{
		if (idx >= _Size || idx < 0)
		{
			return false;
		}
		MyArray[idx] = value;
		return true;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void Resize(int newsize)
	{
		if (newsize < 0)
		{
			newsize = 0;
		}
		_TempArray = new T[newsize];
		if (newsize < _Size)
			_Size = newsize;
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = MyArray[i];
		}

		_Size = newsize;

		delete[] MyArray;
		MyArray = _TempArray;
	}

	T GetItem(int idx)
	{
		return MyArray[idx];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];
		int temp_idx = 0;
		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[temp_idx] = MyArray[i];
			temp_idx++;
		}
		delete[] MyArray;
		MyArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] MyArray;
		MyArray = _TempArray;
	}

	bool DeleteItemAt(int idx)
	{
		if (idx >= _Size || idx < 0)
		{
			return false;
		}
		_TempArray = new T[_Size-1];
		int temp_idx = 0;
		for (int i = 0; i < _Size; i++)
		{
			if (i!=idx)
			{
				_TempArray[temp_idx] = MyArray[i];
				temp_idx++;
			}
		}
		_Size--;
		delete[] MyArray;
		MyArray = _TempArray;
		return true;
	}

	void DeleteFirstItem()
	{
	    DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		 DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (MyArray[i] == value)
			{
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T value)
	{
		int idxOfValue = Find(value);
		if (idxOfValue == -1)
		{
			return false;
		}
		DeleteItemAt(idxOfValue);
		return true;
	}

	bool InsertAt(int idx, T value)
	{
		if (idx > _Size || idx < 0)
		{
			return false;
		}
		_Size++;
		_TempArray = new T[_Size];
		int temp_idx = 0;
		for (int i = 0; i < idx; i++)
		{
			_TempArray[i] = MyArray[i];
		}
		_TempArray[idx] = value;
		for (int i = idx; i < _Size-1; i++)
		{
			_TempArray[i + 1] = MyArray[i];
		}
		delete[] MyArray;
		MyArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value);
	}

	void InsertBeforTo(int idx, T value)
	{
		if (idx < 1)
		{
			InsertAt(0, value);
		}
		else
		InsertAt(idx - 1, value);
	}

	void InsertAfter(int idx, T value)
	{
		if (idx >= _Size)
		{
			InsertAt(_Size, value);
		}
		else
		  InsertAt(idx + 1, value);
	}

	void InsertAtEnd( T value)
	{
		InsertAt(_Size, value);
	}



	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << MyArray[i] << " ";
		}
		cout << endl;
	}


};

