#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

template<typename T>
class Queue {
private:

	int size;
	vector<T> queue;
	T* head, * tail;

public:

	Queue() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	~Queue() {
		queue.clear();
	}

	void operator + (T data) {
		queue.push_back(data);
		if (head == NULL) {
			head = &queue[0];
		}
		size = queue.size();
		tail = &queue[size - 1];
	}

	void operator - (int n) {
		queue.erase(queue.begin() + n);
		if (n == 0) {
			head = &queue[0];
		}
		size = queue.size();
		tail = &queue[size - 1];
	}

	void ReadFromFile(string fname) {
		T buf;
		ifstream in(fname); 
		if (in.is_open()) {
			while (in >> buf) {
				queue.push_back(buf);
			}
		}
		in.close();
		size = queue.size();
		head = &queue[0];
		tail = &queue[size - 1];
	}

	void WriteIntoFile(string fname) {

		ofstream out(fname);
		if (out.is_open())
		{
			for (int i = 0; i < queue.size(); i++)
			{
				out << queue[i] << endl;
			}
		}
		out.close();
	}

	void Minimal() {
		T min = T();
		for (int i = 0; i < queue.size(); i++) {
			if (min == T()) {
				min = queue[i];
				continue;
			}
			if (queue[i] < min) {
				min = queue[i];
			}
		}
		cout << "\n  Minimal element of the queue is " << min << endl;
	}

	void Output() {
		cout << "\n  Elements of the queue:  ";
		for (int i = 0; i < queue.size(); i++) {
			cout << "  " << queue[i];
		}
		cout << "\nHead is " << *head;
		cout << "\nTail is " << *tail;
		cout << endl;
	}
};



int main() {

	Queue<int> iq;

	iq.ReadFromFile("D:\\visual\\oop_int.txt");
	iq.Output();
	iq.operator-(3);
	iq.Output();
	iq.operator+(165);
	iq.Output();
	iq.Minimal();

	Queue<string> sq;

	sq.ReadFromFile("D:\\visual\\oop_string.txt");
	sq.Output();
	sq.operator-(5);
	sq.Output();
	sq.operator+("plant");
	sq.Output();
	sq.Minimal();

	return 0;
}