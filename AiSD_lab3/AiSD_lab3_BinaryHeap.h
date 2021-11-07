#pragma once
#include <iostream>
#include <exception>

using namespace std;

// class Vector for BinaryHeap storage
class Vector {
private:
	size_t Size;
	int Capasity;
	int* Array;
public:
	// Consrtructor of Vector
	Vector()
		:Size(0), 
		Capasity(100), 
		Array(new int[Capasity]){}

	// Desrtructor of Vector
	~Vector() {
		delete[] Array; 
		Size = 0;
	};

	// Add element to the end of Vector
	void emplace_back(int value) {
		Array[Size] = value;
		++Size;
	}

	// Get the Vector size
	int size() {
		return Size;
	}

	// Get the Vector element at user's index
	int at(size_t index) {
		if (index >= Size) {
			throw out_of_range("There is not element with that index");
		}
		else
		return Array[index];
	}

	// Reducing Vector size
	void pop_back() {
		if (Size == 0) {
			throw out_of_range("Vector is empty");
		}
		else
		Size--;
	}
	
	// Swap value of two Vector elements
	void swap(size_t first_position, size_t second_position) {
		if (first_position >= Size || second_position >= Size) {
			throw out_of_range("There is not element with that index");
		}
		int temp = Array[first_position];
		Array[first_position] = Array[second_position];
		Array[second_position] = temp;
	}
};

// class stack for depth-first traverse in BinaryHeap
class stack
{
private:
	// class Node for stack element storage
    class Node
    {
	public:
        int value;
        Node* prev;
        Node(const int element) :value(element), prev(0) {}
    };
    Node* current;
	size_t size_stack;
public:
	// Consrtructor of stack
    stack() :current(0), size_stack(0) {}

	// Desrtructor of stack
    ~stack()
    {
        while (current)
            pop();
    }

	// Add element to the stack
    void push(const int element)
    {
        Node* temp = current;
        current = new Node(element);
        current->prev = temp;
		size_stack++;
    }

	// Remove top element from the stack
    void pop()
    {
		if (size_stack) {
			Node* temp = current->prev;
			delete current;
			current = temp;
			size_stack--;
		}
		else {
			throw out_of_range("stack is empty");
		}
    }

	// Get the element on the top of the stack
    int top()
    {
			return current->value;
    }

	// Check the stack's empty
	bool empty()
	{
		return !size_stack;
	}

	// Get the size of the stack
    size_t size()
    {
        return size_stack;
    }
};

// class queue for breadth-first traverse in BinaryHeap
class queue
{
private:
	// class Node for queue element storage
	class Node
	{
	public:
		int value;
		Node* next;
		Node() :value(), next(0) {}
	};
	int size_queue;
	Node* first;
	Node* last;
public:
	// Consrtructor of queue
	queue(){
		first = new Node;
		first->next = NULL;
		last = first;
		size_queue = 0;
	}

	// Desrtructor of queue
	~queue() {
		while (first != last) {
			Remove();
		}
	}

	// Add element to the queue
	void insert(int element) {
		last->next = new Node;
		last = last->next;
		last->value = element;
		last->next = NULL;
		size_queue++;
	}

	// Get the first element of the queue
	int peakFirst() {
		if (size_queue)
		return first->next->value;
		else {
			throw out_of_range("queue is empty");
		}
	}

	// Remove element from the queue
	void Remove() {
		first = first->next;
		size_queue--;
	}

	// Check the queue's empty
	bool isEmpty() {
		return (first == last);
	}
};

// class Iterator for bfs_iterator and dfs_iterator
class Iterator {
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};

// class BinaryHeap
class BinaryHeap {
private:
	size_t Size_heap; // size of BinaryHeap
public:
	Vector BinaryHeap_Array; // vector for BinaryHeap storage

	Iterator* create_bft_iterator();

	Iterator* create_dft_iterator();

	// class for bft_iterator
	class BFT_Iterator : public Iterator {
	public:
		BFT_Iterator(Vector& BinaryHeap_Array);
		~BFT_Iterator();
		int next() override;
		bool has_next() override;
	private:
		queue* current;
		size_t Size_iterator_heap;
		int node_index = 0;
		Vector Iterator_Array;
	};

	// class for dft_iterator
	class DFT_Iterator : public Iterator {
	public:
		DFT_Iterator(Vector& BinaryHeap_Array);
		~DFT_Iterator();
		int next() override;
		bool has_next() override;
	private:
		stack* current;
		size_t Size_iterator_heap;
		int node_index = 0;
		Vector Iterator_Array;
		int count_out;
	};

	// Constructor of BinaryHeap
	BinaryHeap() {
		BinaryHeap_Array;
	}

	// Destructor of BinaryHeap
	~BinaryHeap() {
		BinaryHeap_Array.~Vector();
	}

	// Add the element to the BinaryHeap
	void Insert(int element) {
		Size_heap = BinaryHeap_Array.size();
		BinaryHeap_Array.emplace_back(element); // put the element to the end of BinaryHeap_Array
		if (Size_heap != 0) { // if BinaryHeap isn't empty
			size_t currentIndex = Size_heap;
			size_t parentIndex = (currentIndex - 1) / 2;
			// put the new element on its place in BinaryHeap
			while ((currentIndex > 0) && (BinaryHeap_Array.at(parentIndex) < BinaryHeap_Array.at(currentIndex))) {
				BinaryHeap_Array.swap(currentIndex, parentIndex);
				currentIndex = parentIndex;
				parentIndex = (currentIndex - 1) / 2;
			}
		}
	}

	// Check that BinaryHeap contains user's element
	bool Contains(int looking_for) {
		Size_heap = BinaryHeap_Array.size();
		if (Size_heap != 0) { // if BinaryHeap isn't empty
			bool isFound = false;
			// run the BFS to find the looking for element
			Iterator* hello_iterator = create_bft_iterator();
			while (hello_iterator->has_next()) {
				if (hello_iterator->next() == looking_for) isFound = true;
			}
			// return the result
			return isFound;
		}
		else {
			throw invalid_argument("BinaryHeap is empty");
		}
	}

	//Remove the user's element from BinaryHeap
	void Remove(int Remove) {
		Size_heap = BinaryHeap_Array.size();
		if (Size_heap != 0) { // if BinaryHeap isn't empty
			for (size_t i = 0; i < Size_heap; i++) {
				if (BinaryHeap_Array.at(i) == Remove) { // if needs to delete the last elemet
					if (i == (Size_heap - 1)) {
						BinaryHeap_Array.pop_back();
					}
					else {
						BinaryHeap_Array.swap(i, (Size_heap - 1));
						BinaryHeap_Array.pop_back();
						Size_heap--;
						Heapify(i);
					}
				}
			}
		}
		else {
			throw invalid_argument("BinaryHeap is empty");
		}
	}

	// Restoring BinaryHeap properties after element deleting
	void Heapify(int currentIndex) {
		int maxIndex = currentIndex;;
		int leftIndex;
		int rightIndex;

		while (currentIndex < Size_heap) {
			leftIndex = 2 * currentIndex + 1;
			rightIndex = 2 * currentIndex + 2;

			if (BinaryHeap_Array.at(leftIndex) > BinaryHeap_Array.at(maxIndex))
				maxIndex = leftIndex;

			if (BinaryHeap_Array.at(rightIndex) > BinaryHeap_Array.at(maxIndex))
				maxIndex = rightIndex;

			if (maxIndex == currentIndex) break;
			BinaryHeap_Array.swap(currentIndex, maxIndex);
			currentIndex = maxIndex;
		}
	}

};

// BFS_Iterator methods
Iterator* BinaryHeap::create_bft_iterator() {
	return new BFT_Iterator(BinaryHeap_Array);
}

BinaryHeap::BFT_Iterator::BFT_Iterator(Vector& BinaryHeap_Array) {
	const size_t Size_heap = BinaryHeap_Array.size();
	current = new queue;
	Size_iterator_heap = Size_heap;
	Iterator_Array = BinaryHeap_Array;
	current->insert(Iterator_Array.at(node_index));
}

BinaryHeap::BFT_Iterator::~BFT_Iterator() {
	delete[] current;
}

bool BinaryHeap::BFT_Iterator::has_next() {
	return !current->isEmpty();
}

int BinaryHeap::BFT_Iterator::next() {
	if (current->isEmpty()) {
		throw out_of_range("No more elements");
	}
	if ((2 * node_index + 1) <= Size_iterator_heap - 1) current->insert(Iterator_Array.at(2 * node_index + 1));
	if ((2 * node_index + 2) <= Size_iterator_heap - 1) current->insert(Iterator_Array.at(2 * node_index + 2));
	node_index++;
	int temp = current->peakFirst();
	current->Remove();
	return temp;
}

// DFS_Iterator methods
Iterator* BinaryHeap::create_dft_iterator() {
	return new DFT_Iterator(BinaryHeap_Array);
}

BinaryHeap::DFT_Iterator::DFT_Iterator(Vector& BinaryHeap_Array) {
	const size_t Size_heap = BinaryHeap_Array.size();
	current = new stack;
	Size_iterator_heap = Size_heap;
	Iterator_Array = BinaryHeap_Array;
	int count_visited = 0;
}

BinaryHeap::DFT_Iterator::~DFT_Iterator() {
	delete[] current;
}

bool BinaryHeap::DFT_Iterator::has_next() {
	if (node_index > Size_iterator_heap - 1 && count_out < Size_iterator_heap) {
		node_index = current->top();
		current->pop();
		return BinaryHeap::DFT_Iterator::has_next();
	}
	return (!current->empty() || node_index <= Size_iterator_heap - 1 && count_out < Size_iterator_heap);
}

int BinaryHeap::DFT_Iterator::next() {
	int temp;
	if (node_index <= Size_iterator_heap - 1) {
		temp = Iterator_Array.at(node_index);
		if (2 * node_index + 2 <= Size_iterator_heap - 1) {
			current->push(2 * node_index + 2);
		}
		node_index = 2 * node_index + 1;
	}
	else {
		node_index = current->top();
		current->pop();
		temp = Iterator_Array.at(node_index);
	}
	count_out++;
	return temp;
}