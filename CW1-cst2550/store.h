/*
 store.h
 Student ID: M00737296
 Created: 10/1/2021
 Updated: 15/1/2021
*/

#ifndef _STORE_H_INCLUDED_
#define _STORE_H_INCLUDED_

#include <iostream>
#include <unistd.h>
#include <string.h>
using namespace std;

const int MAX=20;

  class Stock_system
  { 
    private:  
      int amount[MAX], amount_sold[MAX];
      int k, itms_sold, quantity, stock, last; // "k" is used in most for loops
      string name;
      string nam[MAX], itm_sold[MAX]; 
      float price, revenue;
      float pris[MAX], price_sold[MAX];

    public:
       Stock_system();
       void sell();
       void total_sold();
       void restock();
       void add_new();
       void show();
       void update_stock();
       void save_file();
       void read_file();
     };

#endif
