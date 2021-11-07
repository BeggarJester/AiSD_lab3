#include "AiSD_lab3_BinaryHeap.h"

int main()
{
	int array[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	BinaryHeap MyBinaryHeap;
	cout << "We have set of numbers:\n";
	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << '\n';
	cout << "\nCreate empty MyBinaryHeap\n";
	cout << "\nTry to check that MyBinaryHeap contains '17': ";
	try {
		MyBinaryHeap.Contains(17);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << '\n';
	cout << "\nStep by step insert elements to the MyBinaryHeap:\n\n";
	for (int i = 0; i < 10; i++) {
		MyBinaryHeap.Insert(array[i]);
		if (i > 6) {
			cout << "BFT:";
			Iterator* MyBinaryHeapBft_iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeapBft_iterator->has_next()) {
				cout << MyBinaryHeapBft_iterator->next() << " ";
			}
			cout << '\n';
			cout << "DFT:";
			Iterator* MyBinaryHeapDft_iterator = MyBinaryHeap.create_dft_iterator();
			while (MyBinaryHeapDft_iterator->has_next()) {
				cout << MyBinaryHeapDft_iterator->next() << " ";
			}
			cout << "\n\n";
		}
	}
	cout << "\nTry to check that MyBinaryHeap contains '17': ";
	try {
		cout << MyBinaryHeap.Contains(17);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << '\n';
	cout << "\nDelete '16' from the MyBinaryHeap:\n\n";
	MyBinaryHeap.Remove(16);
	cout << "BFT:";
	Iterator* MyBinaryHeapBft_iterator = MyBinaryHeap.create_bft_iterator();
	while (MyBinaryHeapBft_iterator->has_next()) {
		cout << MyBinaryHeapBft_iterator->next() << " ";
	}
	cout << '\n';
	cout << "DFT:";
	Iterator* MyBinaryHeapDft_iterator = MyBinaryHeap.create_dft_iterator();
	while (MyBinaryHeapDft_iterator->has_next()) {
		cout << MyBinaryHeapDft_iterator->next() << " ";
	}
	cout << "\n\n";
	cout << "\nInsert '17' to the MyBinaryHeap:\n\n";
	MyBinaryHeap.Insert(17);
	cout << "BFT:";
	MyBinaryHeapBft_iterator = MyBinaryHeap.create_bft_iterator();
	while (MyBinaryHeapBft_iterator->has_next()) {
		cout << MyBinaryHeapBft_iterator->next() << " ";
	}
	cout << '\n';
	cout << "DFT:";
	MyBinaryHeapDft_iterator = MyBinaryHeap.create_dft_iterator();
	while (MyBinaryHeapDft_iterator->has_next()) {
		cout << MyBinaryHeapDft_iterator->next() << " ";
	}
	cout << "\n\n";
	cout << "\nTry to check that MyBinaryHeap contains '17': ";
	try {
		cout << MyBinaryHeap.Contains(17);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << '\n';
	cout << "\nDelete '5' from the MyBinaryHeap:\n\n";
	MyBinaryHeap.Remove(5);
	cout << "BFT:";
	MyBinaryHeapBft_iterator = MyBinaryHeap.create_bft_iterator();
	while (MyBinaryHeapBft_iterator->has_next()) {
		cout << MyBinaryHeapBft_iterator->next() << " ";
	}
	cout << '\n';
	cout << "DFT:";
	MyBinaryHeapDft_iterator = MyBinaryHeap.create_dft_iterator();
	while (MyBinaryHeapDft_iterator->has_next()) {
		cout << MyBinaryHeapDft_iterator->next() << " ";
	}
}