#include<iostream>
#include<fstream>//Stream class to both read and write from/to files.
#include <cstdlib>//searching
#include<string.h>
using namespace std;
namespace temp2
{
    void dis()//function to display all details of csv file
    {
        ifstream a;//reading for a file
        a.open("Order.csv");//to open the file order
        while(a.good())//to check whether the previous file operation has been successful
        {
            string data;
            getline(a,data,',');//to read an alphanumeric character from a file and store it in data.
            cout<<data<<"\t";
        }
        a.close();//close the file
    }

    void writeinfo(string nam,string email, string add, string phno)//function to write customer details into the csv
    {
        ofstream fs1;//writing to a file
        fs1.open("Order.csv",ios::app);//append new data into the file
        fs1<<nam<<","<<phno<<","<<email<<","<<add<<",";//',' is used to shift to the next column of the csv
        fs1.close();
    }

    void writeitem(string item2, int i,int no)//function to write customer order into the csv
    {
        ofstream fs;
        fs.open("Order.csv",ios::app);
        fs<<i<<"."<<item2<<"  Quantity:"<<no<<" ";
        fs.close();
    }

    void writebill(float cost)//function to write customer final bill into the csv
    {
        ofstream fs;
        fs.open("Order.csv",ios::app);
        fs<<","<<"Final Bill:"<<cost;
        cout<<endl;
        fs.close();
    }

    void searching()//function to find the order details for the given order number
    {
        ifstream b;//– reading for a file
        string val;
        b.open("Order.csv");
        int a=0;
        int num;
        cout<<"\nEnter order number: ";
        cin>>num;
        cout<<"____________________________________________________________"<<endl;
        cout<<"Order deatils of order no "<<num<<" are"<<endl;
        cout<<endl;
        while(b.peek()!=EOF)//eof is used to check the end of file character
        {
            a++;
            getline(b,val);
            if(a==(num+1))
            {
                cout<<val<<"\t";
            }
        }
        cout<<endl;
        cout<<"____________________________________________________________"<<endl;
    }
    int counte()//function to get order number
    {

        ifstream b;
        string val;
        b.open("Order.csv");
        int a=0;
        while(b.peek()!=EOF)//peek-reads the next character from the input stream without extracting it.
        {
            a++;
            getline(b,val);
        }
        b.close();
        return a;
    }
}
