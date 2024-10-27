#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

// MinHeap class to implement a minimum heap
class MinHeap {
	private:
		vector<int> heap; // Vector to store heap elements

		// Helper function to maintain the heap property by shifting up the element at index i
		void shiftUp(int i) {
			while (i > 0) {
				int p = (i - 1) / 2; // Calculate parent index
				if (heap[i] >= heap[p]) break; // If the current element is greater than or equal to the parent, stop
				swap(heap[i], heap[p]); // Swap the current element with its parent
				i = p; // Move to the parent's index
			}
		}

		// Helper function to maintain the heap property by shifting down the element at index i
		void shiftDown(int i) {
			int l, r, smlst;
			while (1) {
				l = 2 * i + 1; // Left child index
				r = 2 * i + 2; // Right child index
				smlst = i;     // Assume the smallest element is the current element

				// Check if the left child is smaller than the current smallest
				if (l < heap.size() && heap[l] < heap[smlst]) smlst = l;
				// Check if the right child is smaller than the current smallest
				if (r < heap.size() && heap[r] < heap[smlst]) smlst = r;
				// If the current element is the smallest, stop
				if (smlst == i) break;
				// Swap the current element with the smallest child
				swap(heap[i], heap[smlst]);
				// Move to the smallest child's index
				i = smlst;
			}
		}

	public:
		// Constructor to initialize an empty MinHeap
		MinHeap() {}

		// Insert a new value into the heap
		void insert(int value) {
			heap.push_back(value); // Add the value to the end of the heap
			shiftUp(heap.size() - 1); // Restore the heap property by shifting up the last element
		}

		// Remove and return the minimum value from the heap
		int removeMin() {
			if (heap.empty()) {
				cout << "Heap is empty" << endl;
				return -1; // Return -1 if the heap is empty
			}
			int minV = heap[0]; // The minimum value is at the root (index 0)
			heap[0] = heap.back(); // Replace the root with the last element
			heap.pop_back(); // Remove the last element
			if (!heap.empty()) shiftDown(0); // Restore the heap property by shifting down the root element
			return minV; // Return the removed minimum value
		}

		// Get the minimum value from the heap without removing it
		int getMin() const {
			if (heap.empty()) {
				cout << "Heap is empty" << endl;
				return -1; // Return -1 if the heap is empty
			}
			return heap[0]; // Return the root element, which is the minimum value
		}

		// Get the current size of the heap
		size_t size() const {
			return heap.size();
		}

		// Check if the heap is empty
		bool isEmpty() const {
			return heap.empty();
		}

		// Remove a specific value from the heap
		void remove(int val) {
			auto it = find(heap.begin(), heap.end(), val); // Find the position of the value
			if (it == heap.end()) {
				cout << "Element not found" << endl;
				return; // If the value is not found, return
			}
			int i = it - heap.begin(); // Get the index of the value
			heap[i] = heap.back(); // Replace the value with the last element
			heap.pop_back(); // Remove the last element
			if (i < heap.size()) {
				shiftDown(i); // Restore the heap property by shifting down
				shiftUp(i); // Restore the heap property by shifting up
			}
		}
};

int main() {
    MinHeap hello; // Create a MinHeap instance

    // Insert elements into the heap
    hello.insert(3);
    hello.insert(1);
    hello.insert(5);
    hello.insert(2);
    hello.insert(9);
    hello.insert(12);

    // Get and print the minimum element
    cout << "Minimum: " << hello.getMin() << endl;

    // Remove and print the minimum element
    cout << "Removed: " << hello.removeMin() << endl;

    // Get and print the new minimum element
    cout << "New min: " << hello.getMin() << endl;

    // Remove a specific element (9) from the heap
    hello.remove(9);
    cout << "Removed 9. New Min: " << hello.getMin() << endl;

    // Try to remove an element that is not in the heap (10)
    hello.remove(10);

    return 0;
}
