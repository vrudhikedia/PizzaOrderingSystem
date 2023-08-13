#include<iostream>
#include <cstdlib>
using namespace std;
#include "filehandle.h"
using namespace temp2;  //made a namespace for file handling

struct lists   //structure made for linked lists
{
    string item;
    int no;
    float price;
    lists* next;
};
lists*head=NULL;   //head of the linked listed initialized as null at start

class Info
{
public:
    int order_no=counte();
    string name,address,del,num;

    void info()   //function to get user details
    {
        cout<<"Please login to further proceed with the order:"<<endl;
        cout<<"Enter name : "<<endl;
        cin>>name;
        cout<<"Enter phone number : "<<endl;
        cin>>num;
        while(num.length()!=10)   //to make sure the phone number is exactly 10 digits
        {
            cout<<endl;
            cout<<"Wrong Entry"<<endl;
            cout<<"Re-enter phone number : "<<endl;
            cin>>num;
        }
        cout<<"Enter email address : "<<endl;
        cin>>address;
        cout<<"Enter Delivery Address : "<<endl;
        cin>>del;
        cout<<"Your order number is:"<<order_no<<endl;
        writeinfo(name,address,del,num);   //to write user details into file
        cout<<"Check out our Menu!"<<endl;
    }
};

class Menu
{
public:
    float fresh_pan_base=75;
    float wheat_base=fresh_pan_base+30;
    float thin_crust_base=fresh_pan_base+40;
    float sauce=75;
    float cheese=35;
    float small=10;
    float medium=small+10;
    float large=small+20;
    float Margherita=fresh_pan_base+sauce+cheese;
    float paneer=55,mush=33,corn=44,cap=54;
    float Phenomenal_paneer=Margherita+paneer;
    float Majestic_Mushroom=Margherita+mush;
    float Vegie_Paradise=Margherita+paneer+mush+corn;
    float Veg_Extravaganza=Vegie_Paradise+cap;
    float pep=99,pbc=100,cs=101,chick=110;
    float Pepperoni=Margherita+pep;
    float Pepper_Barbecue_Chicken=Margherita+pbc;
    float Chicken_Sausage=Margherita+cs;
    float Chicken_Dominator=Margherita+chick;
    float Garlic_Bread=60;
    float Cheese_Garlic_Bread=Garlic_Bread+30;
    float French_Fries=77;
    float red=150;
    float white=200;
    float pink=250;
    float Coca_Cola=40,Sprite=40,Fanta=40,Ice_Tea=40;
    float choco=88,brown=99,velvet=99;

    void menu()  //function to display the menu to user
    {
        cout<<" ____________________________________________________________"<<endl;
        cout<<" | ________________________________________________________  |"<<endl;
        cout<<" | |                          ~MENU~                       | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | |                      WOOD FIRE PIZZA*                 | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | Vegetarian:                                           | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | 1.Margherita                                       "<<Margherita<<"| |"<<endl;
        cout<<" | | 2.Phenomenal paneer                                "<<Phenomenal_paneer<<"| |"<<endl;
        cout<<" | | 3.Majestic Mushroom                                "<<Majestic_Mushroom<<"| |"<<endl;
        cout<<" | | 4.Vegie Paradise                                   "<<Vegie_Paradise<<"| |"<<endl;
        cout<<" | | 5.Veg Extravaganza                                 "<<Veg_Extravaganza<<"| |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | Non-Vegetarian:                                       | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | 6.Pepperoni                                        "<<Pepperoni<<"| |"<<endl;
        cout<<" | | 7.Pepper Barbecue Chicken                          "<<Pepper_Barbecue_Chicken<<"| |"<<endl;
        cout<<" | | 8.Chicken Sausage                                  "<< Chicken_Sausage<<"| |"<<endl;
        cout<<" | | 9.Chicken Dominator                                "<<Chicken_Dominator<<"| |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | |                           SIDES                       | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | 10.Garlic Bread                                     "<<Garlic_Bread<<"| |"<<endl;
        cout<<" | | 11.Cheese Garlic Bread                              "<<Cheese_Garlic_Bread<<"| |"<<endl;
        cout<<" | | 12.French Fries                                     "<<French_Fries<<"| |"<<endl;
        cout<<" | | 13.Pasta in red sauce                              "<<red<<"| |"<<endl;
        cout<<" | | 14.Pasta in white sauce                            "<<white<<"| |"<<endl;
        cout<<" | | 15.Pasta in pink sauce                             "<<pink<<"| |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | |                         DRINKS                        | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | 16.Coca-Cola                                        "<<Coca_Cola<<"| |"<<endl;
        cout<<" | | 17.Sprite                                           "<<Sprite<<"| |"<<endl;
        cout<<" | | 18.Fanta                                            "<<Fanta<<"| |"<<endl;
        cout<<" | | 19.Ice-Tea                                          "<<Ice_Tea<<"| |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | |                       DESSERTS                        | |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | | 20.Choco Lava Cake                                  "<<choco<<"| |"<<endl;
        cout<<" | | 21.Brownie                                          "<<brown<<"| |"<<endl;
        cout<<" | | 22.Red-Velvet Cake                                  "<<velvet<<"| |"<<endl;
        cout<<" | |                                                       | |"<<endl;
        cout<<" | |                  *Pizza size:Small Base:fresh pan base| |"<<endl;
        cout<<" | ________________________________________________________  |"<<endl;
        cout<<" ____________________________________________________________"<<endl;
}
};

class Cart:public Info, public Menu
{
public:
    int choice,choice2=25,position,quantity;
    string item_name;

    void order()  // function to select the desired order from menu
    {
        choice = 50;
        while(choice!=0)
        {
            cout<<"Hello "<<name<<"!"<<" Please proceed with your order"<<endl;
            cout<<"Please check the menu and enter your choice (0 to exit):";
            cin>>choice;
            cout<<endl;
            if(choice==1)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Margherita";
                insert_end(item_name,Margherita,quantity);  //inserting the items,price and quantity in cart
            }
            else if(choice==2)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Phenomenal paneer";
                insert_end(item_name,Phenomenal_paneer,quantity);
            }
            else if(choice==3)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Majestic Mushroom";
                insert_end(item_name,Majestic_Mushroom,quantity);
            }
            else if(choice==4)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Vegie Paradise";
                insert_end(item_name,Vegie_Paradise,quantity);
            }
            else if(choice==5)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Veg Extravaganza";
                insert_end(item_name,Veg_Extravaganza,quantity);
            }
            else if(choice==6)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Pepperoni";
                insert_end(item_name,Pepperoni,quantity);
            }
            else if(choice==7)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Pepper Barbecue Chicken";
                insert_end(item_name,Pepper_Barbecue_Chicken,quantity);
            }
            else if(choice==8)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Chicken Sausage";
                insert_end(item_name,Chicken_Sausage,quantity);
            }
            else if(choice==9)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;;
                item_name="Chicken Dominator";
                insert_end(item_name,Chicken_Dominator,quantity);
            }
            else if(choice==10)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Garlic Bread";
                insert_end(item_name,Garlic_Bread,quantity);
            }
            else if(choice==11)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Cheese Garlic Bread";
                insert_end(item_name,Cheese_Garlic_Bread,quantity);
            }
            else if(choice==12)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="French Fries";
                insert_end(item_name,French_Fries,quantity);
            }
            else if(choice==13)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Pasta in red sauce";
                insert_end(item_name,red,quantity);
            }
            else if(choice==14)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Pasta in white sauce";
                insert_end(item_name,white,quantity);
            }
            else if(choice==15)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Pasta in pink sauce";
                insert_end(item_name,pink,quantity);
            }
            else if(choice==16)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Coca Cola";
                insert_end(item_name,Coca_Cola,quantity);
            }
            else if(choice==17)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Sprite";
                insert_end(item_name,Sprite,quantity);
            }
            else if(choice==18)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Fanta";
                insert_end(item_name,Fanta,quantity);
            }
            else if(choice==19)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Ice Tea";
                insert_end(item_name,Ice_Tea,quantity);
            }
            else if(choice==20)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Choco lava cake";
                insert_end(item_name,choco,quantity);
            }
            else if(choice==21)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Brownie";
                insert_end(item_name,brown,quantity);
            }
            else if(choice==22)
            {
                cout<<"How much quantity you would like to order : ";
                cin>>quantity;
                cout<<endl;
                item_name="Red-velvet Cake";
                insert_end(item_name,velvet,quantity);
            }
            else
            {
                cout<<"Please enter a choice between 0 to 22"<<endl;
            }
        }
        cout<<"____________________________________________________________"<<endl;
        cout<<"The items in your cart are:"<<endl;
        display();
        cout<<"____________________________________________________________"<<endl;
    }

    void display()  //function to display the items in cart
         {
             lists*current=head;
             if(current==NULL)   //if there is no items
             {
                 cout<<"Cart is empty"<<endl;
             }
             else
             {
                 int y=1;
                 while(current!=NULL)  //to stop displaying if it reaches the end of list
                 {
                     cout<<y<<"\t"<<current->item<<"\t"<<current->price<<"\t"<<current->no<<endl;
                     y++;
                     current=current->next;  //to print the next item
                 }
             }
         }

    void insert_end(string food,float cost,int number)  //function to add items, price and quantity
        {
            lists*last;
            last=new lists;
            last->item=food;
            last->price=cost;
            last->no=number;
            last->next=NULL;
            if(head==NULL)    //if only one item entered
            {
                head=last;
            }
            else
            {
                lists*temp=head;
                while(temp->next!=NULL)  //takes input until its the end of list
                {
                    temp=temp->next;
                }
                temp->next=last;
            }
         }

    void delete_cart(int pos)  //function to delete an item from cart
        {
            lists* curr = head;
            if (position == 1)
            {
                head=curr->next;
                delete curr;
                return;
            }
            for(int i=1; i<(pos-1); i++)
            {

                if(curr == NULL)
                {
                    cout << "invalid position" << endl;
                    return;
                }
                curr = curr->next;
            }

            lists* temp = curr->next;
            if(temp == NULL)
            {
                cout << "invalid position" << endl;
                return;
            }
            else
            {
                curr->next = temp->next;
                delete temp;
                return;
            }
        }
};


class Bill:public Cart
{
public:
    void cal()   //to calculate the final amount of the bill
    {
        float amount = 0;
        float tax = 0;
        int i=1;
            lists *temp = head;
            while(temp!=NULL)
            {
                amount = amount + temp->price;
                writeitem(temp->item ,i,temp->no);  //to write items in file
                i++;
                temp=temp->next;
            }
            tax = 0.05 * amount;
            cout<<"__________________________________________________________"<<endl;
            cout<<"                         ~BILL~"<<endl;
            cout<<"Customer Name : "<<name<<endl;
            cout<<"Phone number : "<<num<<endl;
            cout<<"Email address : "<<address<<endl;
            cout<<"Delivery address : "<<del<<endl;
            cout<<endl;
            cout<<"Order number : "<<order_no<<endl;
            cout<<"__________________________________________________________"<<endl;
            display();
            cout<<"__________________________________________________________"<<endl;
            cout<<"The tax is: Rs."<<tax<<endl;
            amount +=tax;
            cout<<" The total amount to be paid is: Rs."<<amount<<endl;
            cout<<"__________________________________________________________"<<endl;
            writebill(amount);    //to write the bill amount in the file
    }

    void bill()
    {
        order();
        do
        {
            cout<<"Select 1.Proceed with payment"<<endl;
            cout<<"Select 2.Add item"<<endl;
            cout<<"Select 3.Delete item"<<endl;
            cin>>choice2;
            if(choice2 == 2)
            {
                order();   //to add item in the cart
            }
            else if(choice2==3)
            {
                cout<<"Which item do you want to remove from cart enter the position:"<<endl;
                cin>>position;
                delete_cart(position);   //to delete item from cart
                cout<<"____________________________________________________________"<<endl;
                cout<<"The items in your cart are:"<<endl;
                display();
                cout<<"____________________________________________________________"<<endl;
            }
        }while(choice2!=1);
        cal();

    }
};

int main()
{
    int choice=1;
    cout<<"____________________________________________________________"<<endl;
        cout<<"Welcome to SLICE OF HEAVEN!"<<endl;
        cout<<endl;
        cout<<"____ _    _ ____ ____    ____ ____    _  _ ____ ____ _  _ ____ _  _ "<<endl;
        cout<<"[__  |    | |    |___    |  | |___    |__| |___ |__| |  | |___ |\\ | "<<endl;
        cout<<"___] |___ | |___ |___    |__| |       |  | |___ |  |  \\/  |___ | \\| "<<endl;
        cout<<endl;
        cout<<"// ""--.._"<<endl;
        cout<<"||  (_)  _ ""-._"""<<endl;
        cout<<"||    _ (_)    '-."<<endl;
        cout<<"||   (_)   __..-'"<<endl;
        cout<<" \\__..--"<<endl;
        cout<<endl;
    while(choice!=0)
    {
        cout<<"Enter 1. To place order"<<endl;
        cout<<"Enter 2. To check order status"<<endl;
        cout<<"Enter 0. Exit"<<endl;
        cin>>choice;
        switch(choice)
            {
            case 1:
                {
                    Bill obj;   //object of the derived class initialized
                    obj.info();
                    obj.menu();
                    obj.bill();
                    choice = 0;   //exit from program to update the file
                    break;
                }
            case 2:
                {
                    searching();  //to search order from the file
                    break;
                }
            }
    }
    return 0;
}
