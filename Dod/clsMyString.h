#pragma once
#include<iostream>
#include<string>
#include"clsMyStackArr.h"
using namespace std;

class clsMyString
{
private:

	string _Value = "";
	clsMyStackArr<string>_Undo, _Redo;

public:

	void SetValue(string value)
	{
		_Undo.push(_Value);
		_Value = value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;
	
	void Undo()
	{
		if (!_Undo.IsEmpty())
		{
			_Redo.push(_Value);
			_Value = _Undo.Top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.IsEmpty())
		{
			_Undo.push(_Value);
			_Value = _Redo.Top();
			_Redo.pop();
		}
	}
};

