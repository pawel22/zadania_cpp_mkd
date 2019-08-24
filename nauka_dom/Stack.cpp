// Stack.cpp 

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

template<typename T>
class Stack {
	vector<T> m_top;
public:
	bool isEmpty();
	T Top();
	void Push(T val);
	void Pop();
};
template<typename T>
T Stack<T>::Top() {
		return m_top.at(0);
}
template<typename T>
bool Stack<T>::isEmpty() {
	return m_top.size() <= 0;
}
template<typename T>
void Stack<T>::Push(T value) {
	m_top.push_back(value);
}
template<typename T>
void Stack<T>::Pop() {
	if (isEmpty()) {
		return;
	};
	m_top.erase(m_top.begin());
}

int main()
{
	Stack<int> MyStack;
	//dodawanie elementów do stosu
	MyStack.Push(10);
	MyStack.Push(33);
	MyStack.Push(43);
	
	//zwraca elementy stosu
	while (!MyStack.isEmpty()) {
		cout << "Element stosu: " << MyStack.Top() << endl;
		MyStack.Pop(); //usuwa element po zwróceniu
	}
}

