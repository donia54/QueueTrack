#include <iostream>
#include<vector>
#include<string>
#include<cctype>
#include<fstream> 
#include<iomanip>
#include"clsDblLinkedList.h"
#include"clsMyQueue.h"
#include"clsMyStack.h"
#include"clsDynamicArray.h"
#include"clsMyQueueArr.h"
#include"clsMyStackArr.h"
#include"clsMyString.h"
#include"clsQueueLine.h"
using namespace std;

int main()
{
    clsQueueLine p("A0", 10);

    p.IssueTicket();
    p.IssueTicket();
    p.IssueTicket();
    p.IssueTicket();
    p.IssueTicket();

    p.PrintInfo();

    p.PrintTicketsLineLTR();
    p.PrintTicketsLineRTL();

    p.PrintAllTickets();

    cout << "After________________________________________________\n";
    p.ServeNextClient();
    p.PrintInfo();
    cout << "_____________________________________________________________\n";
    p.IssueTicket();
    p.PrintInfo();



    system("pause>0");
}