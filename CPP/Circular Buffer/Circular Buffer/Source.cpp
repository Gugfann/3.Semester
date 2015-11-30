#include <boost\circular_buffer.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {

	// Create a circular buffer with a capacity for 3 integers.
	boost::circular_buffer<int> cb(10);

	// Insert some elements into the buffer.
	cb.push_back(1);
	cb.push_back(2);
	cb.push_back(3);

	int a = cb[0];  // a == 1
	int b = cb[1];  // b == 2
	int c = cb[2];  // c == 3

	for (int i = 0; i < cb.size(); i++)
	{
		//cout << "Element " << i << ": " << cb[i] << endl;
	}


					// The buffer is full now, pushing subsequent
					// elements will overwrite the front-most elements.

	cb.push_back(4);  // Overwrite 1 with 4.
	cb.push_back(5);  // Overwrite 2 with 5.

					  // The buffer now contains 3, 4 and 5.

	a = cb[0];  // a == 3
	b = cb[1];  // b == 4
	c = cb[2];  // c == 5

	for (int i = 0; i < 120; i++)
	{
		cb.push_back(i);
	}

	for (int i = 0; i < cb.size(); i++)
	{
		cout << "Element " << i << ": " << cb[i] << endl;
	}

	cb.resize(150);

	for (int i = 0; i < 120; i++)
	{
		cb.push_back(i);
	}

	for (int i = 0; i < cb.size(); i++)
	{
		cout << "Element " << i << ": " << cb[i] << endl;
	}			// Elements can be popped from either the front or the back.

	cb.pop_back();  // 5 is removed.
	cb.pop_front(); // 3 is removed.

	int d = cb[0];  // d == 4

	return 0;
}