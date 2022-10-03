/*
 mainstore.cpp
 Student ID: M00737296
 Created: 10/1/2021
 Updated: 15/1/2021
*/

#include "store.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(){

    system("clear"); 

     Stock_system s_system;
     string choice; 
     string input;
     int val_choice;

     s_system.read_file();
     
    do{
        system("clear"); // clears system for every user choice so terminal is clean.
       
       // prints user menu
      cout<<"--------------------------------------\n";
      cout<<"WELCOME TO THE STOCK MANAGEMENT SYSTEM\n";
      cout<<"--------------------------------------\n";
      cout<<"ENTER YOUR CHOICE:\n";
      cout<<"\n1. Show all stored items:\n";
      cout<<"\n2. restock item:\n";
      cout<<"\n3. Add a new item:\n";
      cout<<"\n4. Sell an item:\n";
      cout<<"\n5. Update stock:\n";
      cout<<"\n6. Show total items sold:\n";
      cout<<"\n7. Save File \n";
      cout<<"\n8. Quit \n";
      cout<<"--------------------------------------\n";
      cout<<"INPUT: ";
      cin>>choice;
      cout<<"-*************************************-\n";

      // validates user choice
      if(!(choice == "1" || choice == "2"|| choice == "3"|| choice == "4"|| choice == "5"|| choice == "6"|| choice == "7"|| choice == "8")){ 
      cout<<"Choose options from menu.\n";
      cin>> choice;
      continue;
      }

      val_choice = stoi(choice); // change string to int

    switch(val_choice){

      case 1: {
        cout<<"\nSHOW ALL STOCKS:\n";
        s_system.show();
        break;
    }

      case 2: {
        cout<<"\nRESTOCK ITEMS:\n";
        s_system.restock();
        s_system.show();
        break;
        }

      case 3: {
        cout<<"\nADD NEW ITEMS:\n";
        s_system.add_new();
        s_system.show();
        break;
        }

      case 4: {
        cout<<"\nSELL ITEMS:\n";
        s_system.sell();
        s_system.show();
        break;
        }

      case 5:{ 
        cout<<"\nUpdate stock:\n";
        s_system.update_stock();
        s_system.show();
        break;
        }

      case 6: {
        cout<<"\nTOTAL ITEMS SOLD:\n";
               s_system.total_sold();
              break;
        }

      case 7: {
        cout<<"\nReport has been saved\n";
               s_system.save_file();
               cout<<"\nEnter any character to return to menu\n";
              cin.ignore();
              getline(std::cin,input); // gets user input as a line rather then words.
              break;
        }

      case 8: {
        cout<<"SYSTEM IS CLOSED\n";
        break;
        }

        default:{
            cout<<"choose from menu."; // validation of user choice
            break;
        }

         }

         } while(val_choice != 8); // system (loop) runs until user inputs "8"

    return 0;
    }
