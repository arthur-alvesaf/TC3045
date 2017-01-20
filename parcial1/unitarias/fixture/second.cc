#include "warehouse.h"

int main() {
	Warehouse w(10);
	w.addFront(1);
	w.print();
	w.deleteElement(0);
	w.print();

	return 0;
}