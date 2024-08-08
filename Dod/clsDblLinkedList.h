#pragma once
#include<iostream>
using namespace std;
template <class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;

public:

    class Node
    { 
       public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
		}
		else
		{
			Node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newNode;
			newNode->prev = temp;
		}
		_Size++;
	}

	void InsertAfter(Node* current, T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != NULL) {
			current->next->prev = newNode;
		}
		current->next = newNode;
		_Size++;
	}

	bool InserAfter(int idx, T value)
	{
		Node* temp = GetNode(idx);
		if (temp != NULL)
		{
			InsertAfter(temp, value);
			return true;
		}
		return false;

	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
		{
			return;
		}
		if (head == NodeToDelete)
		{
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL) {
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete temp;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL)
		{
			return;
		}
		if (head->next == NULL) //one node
		{
			delete head;
			head = NULL;
			_Size--;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;
	}

	Node* Find(T val)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->value== val)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	int  Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0? true:false);

	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* curr = head;
		Node* temp = NULL;
		while (curr != NULL)
		{
			temp = curr->prev;
			curr->prev = curr->next;
			curr->next = temp;
			curr = curr->prev;
		}
		if (temp != NULL)
			head = temp->prev;
	}

	Node *GetNode(int idx)
	{
		if (idx > _Size - 1 || idx < 0)
			return NULL;

		Node* temp = head;
		int cnt = 0;
		while (temp != NULL&&temp->next!=NULL)
		{
			if (cnt == idx)
			{
				break;
			}
			temp = temp->next;
			cnt++;
		}
		return temp;
	}

	T GetItem(int idx)
	{
		Node* temp = GetNode(idx);
		if (temp == NULL)
			return NULL;
		return temp->value;
	}

	bool UpdateItem(int idx, T newvalue)
	{
		Node* temp = GetNode(idx);
		if (temp != NULL)
		{
			temp->value = newvalue;
			return true;
		}
		return false;
	}

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
		cout << endl;
	}


	


};

