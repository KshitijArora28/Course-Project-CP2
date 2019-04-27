Display.o: display.cpp
	g++ -c -o Display.o Display.cpp

alerts.o: alerts.cpp
	g++ -c -o alerts.o alerts.cpp

Change.o: Change.cpp
	g++ -c -o Change.o Change.cpp

delete_commodity.o: delete_commodity.cpp
	g++ -c -o delete_commodity.o delete_commodity.cpp

economic_statistics.o: economic_statistics.cpp
	g++ -c -o economic_statistics.o economic_statistics.cpp

insert_item.o: insert_item.cpp
		g++ -c -o insert_item.o insert_item.cpp

mainprogram.o: mainprogram.cpp
	g++ -c -o mainprogram.o mainprogram.cpp

product_code.o: product_code.cpp
	g++ -c -o product_code.o product_code.cpp

search.o: search.cpp
	g++ -c -o product_code.o product_code.cpp

sort.o: sort.cpp
	g++ -c -o sort.o sort.cpp

stock.o: stock.cpp
	g++ -c -o stock.o stock.cpp

Inventory_System: Display.o alerts.o Change.o delete_commodity.o economic_statistics.o insert_item.o mainprogram.o product_code.o search.o sort.o stock.o
	g++ -o Inventory_System Display.o alerts.o Change.o delete_commodity.o economic_statistics.o insert_item.o mainprogram.o product_code.o search.o sort.o stock.o
