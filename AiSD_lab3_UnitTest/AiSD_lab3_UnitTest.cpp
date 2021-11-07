#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_lab3/AiSD_lab3_BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSDlab3UnitTest
{
	TEST_CLASS(AiSDlab3UnitTest)
	{
	public:
		TEST_METHOD(ConsrtructorStackTest)
		{
			stack MyStack;
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(DesrtructorStackTest)
		{
			stack MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.~stack();
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(PushStackTest)
		{
			stack MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);
			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
		}
		TEST_METHOD(PopStackTest)
		{
			stack MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(TopStackTest)
		{
			stack MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);
			
			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
			MyStack.pop();
			Assert::IsTrue(MyStack.top() == 3);
		}
		TEST_METHOD(SizeStackTest)
		{
			stack MyStack;
			Assert::IsTrue(MyStack.size() == 0);
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(EmptyStackTest) {
			stack MyStack;
			Assert::IsTrue(MyStack.empty() == 1);
			MyStack.push(3);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.push(7);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.pop();
			Assert::IsTrue(MyStack.empty() == 0);
		}
		TEST_METHOD(RemoveStackTest)
		{
			stack MyStack;
			Assert::IsTrue(MyStack.size() == 0);
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(ConsrtructorQueueTest)
		{
			queue MyQue;
			Assert::IsTrue(MyQue.isEmpty() == 1);
		}
		TEST_METHOD(DesrtructorQueueTest)
		{
			queue MyQue;
			Assert::IsTrue(MyQue.isEmpty() == 1);
			MyQue.insert(3);
			Assert::IsTrue(MyQue.isEmpty() == 0);
			MyQue.~queue();
			Assert::IsTrue(MyQue.isEmpty() == 1);
		}
		TEST_METHOD(InsertQueueTest)
		{
			queue MyQue;
			MyQue.insert(3);
			Assert::IsTrue(MyQue.peakFirst() == 3);
			MyQue.insert(7);
			Assert::IsTrue(MyQue.peakFirst() == 3);
		}
		TEST_METHOD(PeakFirstQueueTest)
		{
			queue MyQue;
			try {
				MyQue.peakFirst();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("queue is empty", error.what());
			}
			MyQue.insert(3);
			try {
				MyQue.peakFirst();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("queue is empty", error.what());
			}
			Assert::IsTrue(MyQue.peakFirst() == 3);
			MyQue.insert(7);
			try {
				MyQue.peakFirst();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("queue is empty", error.what());
			}
			Assert::IsTrue(MyQue.peakFirst() == 3);
			MyQue.Remove();
			try {
				MyQue.peakFirst();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("queue is empty", error.what());
			}
			Assert::IsTrue(MyQue.peakFirst() == 7);
		}
		TEST_METHOD(IsEmptyQueueTest)
		{
			queue MyQue;
			Assert::IsTrue(MyQue.isEmpty() == 1);
			MyQue.insert(3);
			Assert::IsTrue(MyQue.isEmpty() == 0);
			MyQue.Remove();
			Assert::IsTrue(MyQue.isEmpty() == 1);
		}
		TEST_METHOD(ConstructorBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			try {
				MyBinaryHeap.Contains(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
		}
		TEST_METHOD(DestructorBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			MyBinaryHeap.Insert(3);
			try {
				MyBinaryHeap.Contains(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			Assert::IsTrue(MyBinaryHeap.Contains(3) == 1);
			MyBinaryHeap.~BinaryHeap();
			try {
				MyBinaryHeap.Contains(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
		}
		TEST_METHOD(InsertBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			stringstream output1;
			stringstream output2;
			stringstream output3;
			MyBinaryHeap.Insert(3);
			Iterator* MyBinaryHeap_1iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_1iterator->has_next()) {
				output1 << MyBinaryHeap_1iterator->next() << " ";
			}
			Assert::IsTrue(output1.str() == "3 ");
			MyBinaryHeap.Insert(4);
			Iterator* MyBinaryHeap_2iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_2iterator->has_next()) {
				output2 << MyBinaryHeap_2iterator->next() << " ";
			}
			Assert::IsTrue(output2.str() == "4 3 ");
			MyBinaryHeap.Insert(16);
			Iterator* MyBinaryHeap_3iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_3iterator->has_next()) {
				output3 << MyBinaryHeap_3iterator->next() << " ";
			}
			Assert::IsTrue(output3.str() == "16 3 4 ");
		}
		TEST_METHOD(ContainsBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			try {
				MyBinaryHeap.Contains(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyBinaryHeap.Insert(3);
			try {
				MyBinaryHeap.Contains(3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			Assert::IsTrue(MyBinaryHeap.Contains(3) == 1);
			try {
				MyBinaryHeap.Contains(7);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			Assert::IsTrue(MyBinaryHeap.Contains(7) == 0);
		}
		TEST_METHOD(RemoveBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			stringstream output1;
			stringstream output2;
			stringstream output3;
			stringstream output4;
			try {
				MyBinaryHeap.Remove(1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyBinaryHeap.Insert(3);
			MyBinaryHeap.Insert(4);
			MyBinaryHeap.Insert(16);
			MyBinaryHeap.Insert(1);
			Iterator* MyBinaryHeap_1iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_1iterator->has_next()) {
				output1 << MyBinaryHeap_1iterator->next() << " ";
			}
			Assert::IsTrue(output1.str() == "16 3 4 1 ");
			try {
				MyBinaryHeap.Remove(1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyBinaryHeap.Remove(1);
			Iterator* MyBinaryHeap_2iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_2iterator->has_next()) {
				output2 << MyBinaryHeap_2iterator->next() << " ";
			}
			Assert::IsTrue(output2.str() == "16 3 4 ");
			int array1[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			BinaryHeap MyBinaryHeap1;
			for (int i = 0; i < 10; i++)
				MyBinaryHeap1.Insert(array1[i]);
			Iterator* MyBinaryHeap_3iterator = MyBinaryHeap1.create_bft_iterator();
			while (MyBinaryHeap_3iterator->has_next()) {
				output3 << MyBinaryHeap_3iterator->next() << " ";
			}
			Assert::IsTrue(output3.str() == "16 11 9 10 5 6 8 1 2 4 ");
			try {
				MyBinaryHeap1.Remove(16);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyBinaryHeap1.Remove(16);
			Iterator* MyBinaryHeap_4iterator = MyBinaryHeap1.create_bft_iterator();
			while (MyBinaryHeap_4iterator->has_next()) {
				output4 << MyBinaryHeap_4iterator->next() << " ";
			}
			Assert::IsTrue(output4.str() == "11 10 9 4 5 6 8 1 2 ");
		}
		TEST_METHOD(HeapifyBinaryHeapTest) {
			BinaryHeap MyBinaryHeap;
			stringstream output1;
			stringstream output2;
			int array1[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			for (int i = 0; i < 10; i++)
				MyBinaryHeap.Insert(array1[i]);
			MyBinaryHeap.BinaryHeap_Array.swap(0, 9);
			MyBinaryHeap.BinaryHeap_Array.pop_back();
			Iterator* MyBinaryHeap_1iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_1iterator->has_next()) {
				output1 << MyBinaryHeap_1iterator->next() << " ";
			}
			Assert::IsTrue(output1.str() == "4 11 9 10 5 6 8 1 2 ");
			
			MyBinaryHeap.Heapify(0);
			Iterator* MyBinaryHeap_2iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_2iterator->has_next()) {
				output2 << MyBinaryHeap_2iterator->next() << " ";
			}
			Assert::IsTrue(output2.str() == "11 10 9 4 5 6 8 1 2 ");
		}
		TEST_METHOD(BFT_Iterator_has_nextTest) {
			BinaryHeap MyBinaryHeap;
			MyBinaryHeap.Insert(3);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_bft_iterator();
			Assert::IsTrue(MyBinaryHeap_iterator->has_next() == 1);
			MyBinaryHeap_iterator->next();
			Assert::IsTrue(MyBinaryHeap_iterator->has_next() == 0);
		}
		TEST_METHOD(BFT_Iterator_nextTest) {
			BinaryHeap MyBinaryHeap;
			MyBinaryHeap.Insert(3);
			MyBinaryHeap.Insert(7);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_bft_iterator();
			try {
				int temp = MyBinaryHeap_iterator->next();
				Assert::IsTrue(temp == 7);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
			try {
				int temp = MyBinaryHeap_iterator->next();
				Assert::IsTrue(temp == 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
			try {
				MyBinaryHeap_iterator->next();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
		}
		TEST_METHOD(DFT_Iterator_has_nextTest) {
			BinaryHeap MyBinaryHeap;
			MyBinaryHeap.Insert(3);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_dft_iterator();
			Assert::IsTrue(MyBinaryHeap_iterator->has_next() == 1);
			MyBinaryHeap_iterator->next();
			Assert::IsTrue(MyBinaryHeap_iterator->has_next() == 0);
		}
		TEST_METHOD(DFT_Iterator_nextTest) {
			BinaryHeap MyBinaryHeap;
			MyBinaryHeap.Insert(3);
			MyBinaryHeap.Insert(7);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_dft_iterator();
			Assert::IsTrue(MyBinaryHeap_iterator->next() == 7);
			Assert::IsTrue(MyBinaryHeap_iterator->next() == 3);
		}
		TEST_METHOD(BFT_Test) {
			stringstream output;
			int array[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			BinaryHeap MyBinaryHeap;
			for (int i = 0; i < 10; i++)
				MyBinaryHeap.Insert(array[i]);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_bft_iterator();
			while (MyBinaryHeap_iterator->has_next()) {
				output << MyBinaryHeap_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "16 11 9 10 5 6 8 1 2 4 ");
		}
		TEST_METHOD(DFT_Test) {
			stringstream output;
			int array[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			BinaryHeap MyBinaryHeap;
			for (int i = 0; i < 10; i++)
				MyBinaryHeap.Insert(array[i]);
			Iterator* MyBinaryHeap_iterator = MyBinaryHeap.create_dft_iterator();
			while (MyBinaryHeap_iterator->has_next()) {
				output << MyBinaryHeap_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "16 11 10 1 2 5 4 9 6 8 ");
		}
		TEST_METHOD(ConsrtructorVectorTest) {
			Vector MyVector;
			Assert::IsTrue(MyVector.size() == 0);
			MyVector.emplace_back(3);
			Assert::IsTrue(MyVector.size() == 1);
		}
		TEST_METHOD(DesrtructorVectorTest) {
			Vector MyVector;
			Assert::IsTrue(MyVector.size() == 0);
			MyVector.emplace_back(3);
			Assert::IsTrue(MyVector.size() == 1);
			MyVector.~Vector();
			Assert::IsTrue(MyVector.size() == 0);
		}
		TEST_METHOD(emplace_backVectorTest){
			Vector MyVector;
			Assert::IsTrue(MyVector.size() == 0);
			MyVector.emplace_back(3);
			Assert::IsTrue(MyVector.size() == 1);
			Assert::IsTrue(MyVector.at(0) == 3);
			MyVector.emplace_back(7);
			Assert::IsTrue(MyVector.size() == 2);
			Assert::IsTrue(MyVector.at(0) == 3);
			Assert::IsTrue(MyVector.at(1) == 7);
		}
		TEST_METHOD(sizeVectorTest){
			Vector MyVector;
			Assert::IsTrue(MyVector.size() == 0);
			MyVector.emplace_back(3);
			Assert::IsTrue(MyVector.size() == 1);
			MyVector.emplace_back(7);
			Assert::IsTrue(MyVector.size() == 2);
			MyVector.pop_back();
			Assert::IsTrue(MyVector.size() == 1);
		}
		TEST_METHOD(atVectorTest){
			Vector MyVector;
			try {
				MyVector.at(7);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not element with that index", error.what());
			}
			MyVector.emplace_back(3);
			try {
				MyVector.at(0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not element with that index", error.what());
			}
			Assert::IsTrue(MyVector.at(0) == 3);
		}
		TEST_METHOD(pop_backVectorTest){
			Vector MyVector;
			Assert::IsTrue(MyVector.size() == 0);
			MyVector.emplace_back(3);
			Assert::IsTrue(MyVector.size() == 1);
			MyVector.emplace_back(7);
			Assert::IsTrue(MyVector.size() == 2);
			try {
				MyVector.pop_back();
				Assert::IsTrue(MyVector.size() == 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Vector is empty", error.what());
			}
			try {
				MyVector.pop_back();
				Assert::IsTrue(MyVector.size() == 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Vector is empty", error.what());
			}
			try {
				MyVector.pop_back();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Vector is empty", error.what());
			}
		}
		TEST_METHOD(swapVectorTest){
			Vector MyVector;
			MyVector.emplace_back(3);
			MyVector.emplace_back(7);
			try {
				MyVector.swap(0, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not element with that index", error.what());
			}
			try {
				MyVector.swap(17, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not element with that index", error.what());
			}
			Assert::IsTrue(MyVector.at(0) == 3);
			Assert::IsTrue(MyVector.at(1) == 7);
			try {
				MyVector.swap(0, 1);
				Assert::IsTrue(MyVector.at(0) == 7);
				Assert::IsTrue(MyVector.at(1) == 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not element with that index", error.what());
			}
		}
	};
}
