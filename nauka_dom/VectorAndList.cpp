// VectorAndList.cpp 

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void Show_element(vector<int>, list<int>);

int main()
{
	//inicjalizacja
	vector<int> vector_test = { 1, 2, 3, 4 };
	list<int> list_test = { 1, 2, 3, 4 };
	//tworzenie iteratorow
	vector<int>::iterator itr_vector;
	list<int>::iterator itr_list;
	//wyswietlanie vector
	for (int i = 0; i < vector_test.size(); i++) {
		cout<<"Wyswietlanie wektora metoda 'tablicowa' : "<<vector_test[i]<<endl;
		cout << "Wyswietlanie wektora metoda at : " << vector_test.at(i)<<endl;
	}
	//wyswietlanie list
	for (itr_list = list_test.begin(); itr_list != list_test.end(); itr_list++) {
		cout << "Wyswietlanie listy za pomoca iteracji : " << *itr_list<<endl;
	}
	//dodawanie nowego elementu vector
		//na koniec
		vector_test.push_back(10);
	//za pomoca iteratora
		//na poczatek 
		itr_vector = vector_test.begin();
		vector_test.insert(itr_vector, 9);
		//na 2 pozycje
		itr_vector = vector_test.begin();
		vector_test.insert(itr_vector + 1, 8);

	//dodawanie nowego elementu list
		//na koniec
		list_test.push_back(10);
		//na poczatek
		list_test.push_front(9);
		//na 2 pozycje z iteratorem
		itr_list = list_test.begin();
		advance(itr_list, 1); //iterator na 3 pozycje
		list_test.insert(itr_list, 8);
		
	Show_element(vector_test, list_test);

	//usuwanie elementu wektora
	itr_vector = vector_test.begin();
	vector_test.erase(itr_vector+1);

	//usuwanie elementu listy
	itr_list = list_test.begin();
	advance(itr_list, 1);
	list_test.erase(itr_list);
		
	Show_element(vector_test, list_test);
}

void Show_element(vector<int> vector_test, list<int> list_test) {
	list<int>::iterator itr_list;

	for (int i = 0; i < vector_test.size(); i++) {
		cout << "Wyswietlanie wektora metoda 'tablicowa' : " << vector_test[i] << endl;
	}
	for (itr_list = list_test.begin(); itr_list != list_test.end(); itr_list++) {
		cout << "Wyswietlanie listy za pomoca iteracji : " << *itr_list << endl;
	}
}
