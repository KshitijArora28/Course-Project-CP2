# Commodity Inventory System

The objective of this project is to build an inventory system that will enable the organisation using it to manage their stock effectively and efficiently, so as to run the business well.

## Functions for Inventory Management

These functions will help a user to control, optimise, and manage the ordering and storage of data in the inventory :-

1. Management optimisation process: -Optimisation of inventory model for easy access to product info.
2. Filters for searching commodities: -Filtering process to search for particular products based on particular requirements.
3. Adding new commodities with basic information: -Increasing inventory list and adding info for new products.
4. Delete obsolete commodity and basic information: -Delete products which have sales below minimum required sales.
5. Change commodity info when stock changes,price changes, etc: -Change inventory details if details of product change.
6. Automatic change of inventory status according to commodity amount that is currently available: -Inventory status update.
7. Deliver alerts when commodity is put of stock: -Alert system for low/out of stock conditions.
8. Automatic reordering of products: -Reordering system to order product units when stock is low.
9. Max and min sales: -Calculate quanity of units sold for product and give products with max and min sales.

## 3-D Representation of the Inventory Concept

![3-D Array](https://user-images.githubusercontent.com/47135656/55143584-03048a80-517a-11e9-9a43-40ebdd990ab9.png)

As the above figure suggests, the inventory model will be stocking products in terms of x,y and z positions.
### Significance of x
Products of similar category will be under the same value of x (Vegetables in grocery store, Electrical components in automobile manufacturing unit etc.)
### Significance of y
Different Products under the same category will be under the same value of y (Carrots and Potatoes under Vegetables,Transistors and Capacitors under Electrical components etc.)
### Significance of z
Any sub variety under the same Product will appear as different products under z (Australian Carrots and Chinese Carrots under Carrots,10mF and 20mF Capacitors under Capacitors etc.)

## Our method for an Optimised Inventory Model

Our optimised inventory model will use the above mentioned functions in conjunction with sorting(Multiple varieties based on Alphabetical order, Quantity remaining, fastest moving etc.) to ensure a user friendly assess to the inventory.

A very clear list of the products is necessary for a comprehensive inventory system. This sort of a clear tabular output will be an important part of our program.

![Project](https://user-images.githubusercontent.com/47174028/55222789-b25b6300-5247-11e9-9ed9-92667633fca8.jpg)

To achieve these objectives, we will be making use of structures, linked lists, dynamic variables and a number of libraries and C++ resources.
#

## Header Files to be used
iostream
#
fstream
#
sstream
#
cstdlib
#
string
#
iomanip
#
stdlib.h
#
cmath
#
cstring
#
