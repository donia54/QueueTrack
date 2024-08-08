#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include"clsDate.h"
using namespace std;

class clsQueueLine
{
private:

	class clsTickets
	{
	private:
		string _Prefix = "";
        string _TicketTime;
		int _Num = 0;
		int _WatingClients = 0;
		int _ServeTime = 0;
		int _ExpectedServeTime = 0;
	public:

        clsTickets(string prefix, int num, int waitingclients, int servetime)
        {
            _Num = num;
            _Prefix = prefix;
            _WatingClients = waitingclients;
            _ServeTime = servetime;
            _TicketTime = clsDate::GetSystemDateTimeString();
        }

        string Prefix()
        {
            return _Prefix;

        }

        short Number()
        {
            return _Num;
        }

        string FullNumber()
        {
            return _Prefix + to_string(_Num);
        }

        short WaitingClients()
        {
            return _WatingClients;
        }

        short ExpectedServeTime()
        {
            return _ServeTime * _WatingClients;
        }

        string TicketTime()
        {
            return _TicketTime;
        }

        void Print()
        {
            cout << "\n\t\t\t  _______________________\n";
            cout << "\n\t\t\t\t    " << FullNumber();
            cout << "\n\n\t\t\t    " << _TicketTime;
            cout << "\n\t\t\t    Waiting Clients = " << _WatingClients;
            cout << "\n\t\t\t      Serve Time In";
            cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
            cout << "\n\t\t\t  _______________________\n";


        }

	};

    string _Prefix = "";
    int _ServeTime = 0;
    int _TotalTickets = 0;
   // int _WaitingClients = 0;
   // int _ServedClients = 0;

public:

    queue<clsTickets> QueueLine;

    clsQueueLine(string prefix, int servetime)
    {
        _Prefix = prefix;
        _ServeTime = servetime;
    }

    int WaitingClients()
    {
        return QueueLine.size();
    }

    int ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    void IssueTicket()
    {
        _TotalTickets++;
        clsTickets T(_Prefix, _TotalTickets, WaitingClients(), _ServeTime);
        QueueLine.push(T);
    }

    bool ServeNextClient()
    {
        if (QueueLine.empty())
            return false;
       // _ServedClients++;
        QueueLine.pop();
        return true;
    }

    string WhoIsNext()
    {
        if (QueueLine.empty())
        {
            return "Queue is Empty\n";
        }
        return QueueLine.front().FullNumber();

    }

    void PrintTicketsLineRTL()
    {
        if (QueueLine.empty())
        {
            cout << "Queue is Empty \n";
            return;
        }
        cout << "\n\t\tTickets: ";
        queue<clsTickets>temp = QueueLine;
        while (!temp.empty())
        {
            clsTickets ticket = temp.front();
            cout << " " << ticket.FullNumber() << " <-- ";
            temp.pop();
        }
        cout << endl;
    }

    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
        {
            cout << "Queue is Empty \n";
            return;
        }
        cout << "\n\t\tTickets: ";
        queue<clsTickets>temp = QueueLine;
        vector<clsTickets>vTemp;
        while (!temp.empty())
        {
            vTemp.push_back(temp.front());
            temp.pop();
        }

        for (int i = vTemp.size() - 1; i >= 0; i--)
        {
            cout << " " << vTemp[i].FullNumber() << " --> ";
        }
        cout << endl;
        

    }

    void PrintInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _Prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        cout << "\n\t\t\t    Wating Clients  = " << WaitingClients();
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";

    }

    void PrintAllTickets()
    {
        queue<clsTickets>temp = QueueLine;
        while (!temp.empty())
        {
            clsTickets T = temp.front();
            T.Print();
            temp.pop();
            cout << endl;
        }
    }

};

