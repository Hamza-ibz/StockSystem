
/*
 store2.cpp
 Student ID: M00737296
 Created: 10/1/2021
 Updated: 15/1/2021
*/

#include "store.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

Stock_system:: Stock_system()
    { 
      // b=10;s=20; last = 3;
      //   const char *dflt_items[3] = { "cd", "dvd", "book"};
      // for( k=0;k<last;k++)
      // { 
      // nam[k]=dflt_items[k];
      // amount[k]=b;
      // price[k]=s;
      // b++;
      // s++;
      
      // }
      
     }

   void Stock_system::restock(){ 
      int k = 0;
      bool included = false;

      cout<< "\nEnter item name: ";
      cin.ignore();
      getline(std::cin,name); // reads the line in which user entered (not just one word)

// for loop that goes through the names in the system and checks if the name entered by the user matches
      for( k=0; k<last; k++){ 
        if(name == nam[k]){
          included = true;
          break;
          } 
      else{
        included = false;
       }
      }
      if(included == false){
        cout<< "\nSorry..This item is not available.\n";
        return;
      }

      cout<< "\nEnter the number you want to increase stock by: ";
      cin>> stock;

      if(stock < 1){
        cout<< "\nEnter a positive number.incorrect input.\n";
    return;
      }
      if(cin.fail() || cin.get() != '\n'){  // validation of user input (if it matches the type int )
    cin.clear(); // reset cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip bad input
    cout<< "\nEnter a positive whole number.incorrect input.\n";
    return;
    }

     for( k=0; k<last; k++)
       { if(name == nam[k])
      { 
        amount[k] = amount[k] + stock; // adds correct product to correct stock
        break;
      }
       }

     cout<< "The item has been added";
      }
      
   void Stock_system::add_new(){
    cout<< "\nEnter item name: ";
    cin.ignore();
    getline(std::cin,name); // reads the line in which user entered (not just one word)

    if(name == ""){ 
      cout<< "\nEnter name for the item.\n";
        return;
    }

     for( k=0; k<last; k++){ 
         if(name == nam[k]){ 
        cout<< "\nItem already exist. choose another.\n";
        return;
      }
       }

    cout<< "\nEnter amount of that item: ";
    cin>> quantity;

     if(quantity < 1){
        cout<< "\nEnter a positive number.incorrect input.\n";
    return;
      }

      if(cin.fail() || cin.get() != '\n'){ // validation of user input (if it matches the type int )
    cin.clear(); // reset cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    cout<< "\nEnter a positive whole number.incorrect input.\n";
    return;
    }

    cout<< "\nEnter item price: £";
    cin>> price;

      if(!cin || price < 1) { // validation of price 
    cin.clear(); // reset cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    cout<< "\nEnter a positive number.incorrect input.\n";
    return;
    }
// arrays with "last" records new items. includeing new items in the array
    nam[last] = name;
    amount[last] = quantity;
    pris[last] = price;
    last++; 
     }

    void Stock_system::show(){

       string input;

       for( k=0; k<last; k++){ // for loop listing all stock
      cout<< "\n------------------------------------------";
      cout<< "\nNAME: "<< nam[k] << "\t";
      cout<< "\nAMOUNT: "<< amount[k] << "\t";
      cout<< "\nPRICE: £"<< pris[k];
      cout<< "\n------------------------------------------";
      }
      cout<< "\nEnter any character to return to menu\n";
      cin.ignore(); 
    getline(std::cin,input); // reads the line in which user entered (not just one word)
    }

  void Stock_system::sell(){
     string items_sold;
     bool included = false;

      cout<< "\nEnter item name: ";
      cin.ignore();
      getline(std::cin,items_sold); // reads the line in which user entered (not just one word)

      for( k=0; k<last; k++){
        if(items_sold == nam[k]){
          included = true;
          break;
          }
      else{
        included = false;
      }
      }

      if(included == false){
        cout<< "\nSorry..This item is not available.\n";
        return;
      }

      cout<< "\nEnter the number of stock you want to sell: ";
      cin>> stock;

     if(stock<1 || stock > amount[k]){
        cout<< "\nEnter a valid number.incorrect input.\n";
    return;
      }
      
      if(cin.fail() || cin.get() != '\n'){ // validation of user input (if it matches the type int )
    // user didn't input a number
    cin.clear(); // reset failbit
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    cout<< "\nincorrect input.Enter a valid number\n";
    return;
    // next, request user reinput
        }

     for( k=0; k<last; k++){ // for loop to check user input matches the name of stock 
      if(items_sold == nam[k]){ 
        amount[k] = amount[k]-stock; // reduce stock number
        itm_sold[itms_sold] = items_sold; 
        amount_sold[itms_sold] = stock; // amount sold is recorded for report of sales
        price_sold[itms_sold] = amount_sold[itms_sold] * pris[k]; // revenue of item is recorded for report of sales
        itms_sold++; 
      }
      }
      cout<< "\nItem Sold\n";
    }

  void Stock_system::update_stock(){ 
      bool included = false;

      cout<< "\nEnter item name: ";
      cin.ignore();
      getline(std::cin,name); // reads the line in which user entered (not just one word)

      for( k=0; k<last; k++){
        if(name == nam[k]){
          included = true;
          break;
          }
      else{
        included = false;
      }
      }

      if(included == false){
        cout<< "\nSorry..This item is not available.\n";
        return;
      }

      cout<< "\nChange number of stock for item: ";
      cin>> stock;

      if(stock < 1){
        cout<< "\nEnter a positive number.incorrect input.\n";
    return;
      }

      if(cin.fail()|| cin.get() != '\n'){ // validation of user input (if it matches the type int )
    // user didn't input a number
    cin.clear(); // reset cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    cout<< "\nEnter a positive number.incorrect input.\n";
    return;
    }
      cout<< "\nChange product price: £";
      cin>> price;

      if(!cin || price<1){ // validation of price. (check if its float)
    cin.clear(); // reset cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    cout<< "\nEnter a positive number.incorrect input.\n";
    return;
    }

     for( k=0; k<last; k++){ // for loop to ensure system updates correct stock amount and price
      if(name == nam[k]){ 
        amount[k] = stock;
        pris[k] = price;
      }
       }
      }

  void Stock_system::total_sold(){
     string input;

     for( int i=0; i < itms_sold; i++){ // report on all stocks that has sold
      cout<<"-----------------------------------------";
      cout<< "\nITEM NAME: "<< itm_sold[i] <<"\t";
      cout<< "\nAMOUNT SOLD: "<< amount_sold[i] <<"\t";
      cout<< "\nREVENUE FROM ITEM: £"<< price_sold[i] <<endl;
      revenue = revenue + price_sold[i]; // calculate revenue
      }

      if(itms_sold == 0){
         cout<< "\n0 ITEMS SOLD";
         revenue = 0;
       }

      cout<< "\n-----------------------------------------";
      cout<< "\nTOTAL REVENUE FROM ALL ITEMS: " << revenue <<endl;
      revenue = 0;

      cout<<"\nEnter any character to return to menu\n";
      cin.ignore();
    getline(std::cin,input); // reads the line in which user entered (not just one word)

   }

   void Stock_system::save_file(){

     ofstream outFile;

     outFile.open("Items.txt");
     for( k=0; k<last; k++){ // prints the stock (that are in the for loop) to text file (Items.txt)
     outFile << "ITEM NAME:" << nam[k] <<"| ";
     outFile << "AMOUNT SOLD:"<< amount[k] <<"| ";
     outFile << "REVENUE FROM ITEM (£):"<< pris[k] <<"|\n";

     }
     outFile.close();
   }

     void Stock_system::read_file(){
       string name_, amount_string, price_string, temp_string;
       string line;
       int amount_;
       float price_;
       k = 0;

     ifstream inFile("Items.txt"); // file to read from

     if(!inFile.is_open()){
       cout<< "File Fail to open"<<endl;
       exit(0);
       }

       while(getline(inFile, line)){ // while loop which reads line by line of text file
         stringstream ss(line); 
         getline(ss, temp_string, ':'); // reads anyting after ":" and stores it in "temp_string"
         getline(ss, name_, '|'); // reads anyting after "|" and stores it in "name_"
         getline(ss, temp_string, ':');
         getline(ss, amount_string, '|'); // reads anyting after "|" and stores it in "amount_string"
         amount_ = stoi(amount_string); // converts amount_string into an int
         getline(ss, temp_string, ':'); 
         getline(ss, price_string, '|'); // reads anyting after "|" and stores it in "price_string"
         price_ = stof(price_string); // converts price_string into an float

        // stores text file into an array allows system to have stocks within the text file.
         nam[k] = name_;
         amount[k] = amount_;
         pris[k] = price_;
         k++;
         last++;
       }
       inFile.close();
   }
