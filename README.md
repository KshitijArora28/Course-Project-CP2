# Commodity Inventory System

#####################![SharedScreenshot](https://user-images.githubusercontent.com/47135656/56851199-d1304080-693e-11e9-9e7b-0401c7bfbdde.jpg)####################


The objective of this project is to build an inventory system that will enable the organisation using it to manage their stock effectively and efficiently, so as to run the business well.

## Functions for Inventory Management

These functions will help a user to control, optimise, and manage the ordering and storage of data in the inventory :-

1. Management optimisation process: -Optimisation of inventory model for easy access to product info.
2. Filters for searching commodities: -Filtering process to search for particular products based on particular requirements.
3. Adding new commodities with basic information: -Increasing inventory list and adding info for new products.
4. Delete commodity and basic information by user demand: -Delete products which have sales below minimum required sales.
5. Change commodity info when stock changes, price changes, etc: -Change inventory details if details of product change.
6. Automatic change of inventory status according to commodity amount that is currently available: -Inventory status update.
7. Deliver alerts when commodity is out of stock: -Alert system for low/out of stock conditions.
8. Economic suggestions for products using the sales info.
9. Max and min sales: -Calculate quantity of units sold for product and give products with max and min sales.

## Run through of the code

The code is designed to be easy to understand and user-friendly.

The program welcomes you with a list of options to choose from-
I->Insert new commodities
C->Change commodity info
R->Remove commodity
S->Search item
O->Sort items alpahbetically
Q->Sell and check stock
E->Economic advise based on stock data
D->Display inventory
T->Terminate code

### Insert:- The user will typically first use this function, where he or she has to enter the quantity of items to be added to the inventory followed by details about the product, such as, name,expiry date, buying cost, selling cost and quantity to be added.


### Change:- The user can then choose to change the above details of the product using the change function.


### Remove:- The user can remove any item from the list at will using this function.


### Search:- They may also search for any item on the list. Once selected, the search function prompts the user to search by name,product code,inventory status (all in-stock products or all out-of-stock products).


### Sort:- For more convenient product management, the user can rely on the sort function. This function allows a user to sort a product alphabetically by the name or by product code. Then they can also choose to reverse whatever order their current inventory is sorted in. This function is especially time saving, as products can be entered in any order and the computer will order it for the user just through a single function.


### Sell and check stock:- The currently available stock (quantity) of a product maybe sold or removed, this function tracks the sales and automatically modifies the Inventory data accordingly.


### Economic advise based on stock data:- This function is a very helpful digital assistant to any establishment. Upon running this function, and indicating the number of days the current sales data is based on, the user can get to know a variety of information, including quantity sold, net profit (for the whole period) and simple prediction of the requirement for the product in the next month. This function also displays one product that sold the most,one product that sold the least, one product that was most profitable and one product that was least profitable.


### Display:- The display function displays a detailed table of the Inventory. All the changes from the sort function will be reflected in this function. In addition, this function also creates a new file with the same tabular representation of the inventory which is a useful feature for users who wish to printout these details.


### Terminate Code:-Terminate code will close the program. It will recheck with the user if he or she wants to terminate the program(to avoid accidental closure of the Inventory System). 


## Testing of our code

###![ss1](https://user-images.githubusercontent.com/47174028/56850537-9aeec300-6936-11e9-8d99-7bdbe709cbb7.png)


###![ss2](https://user-images.githubusercontent.com/47174028/56850554-c5408080-6936-11e9-9a5b-6e15d05656f7.png###)


###![ss3](https://user-images.githubusercontent.com/47174028/56850565-ebfeb700-6936-11e9-84df-bce6338ef4e0.png)


###![ss4](https://user-images.githubusercontent.com/47174028/56850569-0a64b280-6937-11e9-8075-e7d5c635a73d.png)

## Our method for an Optimised Inventory Model

Our optimised inventory model will use the above mentioned functions in conjunction with sorting(Multiple varieties based on Alphabetical order, Quantity remaining, fastest moving etc.) to ensure a user friendly assess to the inventory.

A very clear list of the products is necessary for a comprehensive inventory system. This sort of a clear tabular output will be an important part of our program.For reference: -


![Project](https://user-images.githubusercontent.com/47174028/55222789-b25b6300-5247-11e9-9ed9-92667633fca8.jpg)

To achieve these objectives, we have made use of structures, dynamic variables and a number of libraries and C++ resources.
