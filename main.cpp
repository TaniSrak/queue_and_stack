#include <iostream>
#include <vector>
#include <list>

#include <stack> //FILO очередь задом наперед
#include <queue> //FIFO очередь с начала

#include <fstream>
#include <string>
#include <iterator>
#include <sstream>

class DemoGood
{
public:
	DemoGood()
	{
		std::cout << this << " create by default constructor\n\n";
	}
	DemoGood(int a, bool b)
	{
		std::cout << this << " create by parametric constructor\n\n";
	}
	DemoGood(const DemoGood& other)
	{
		std::cout << this << " create by copy constructor\n\n";
		std::cout << "from " << &other << " object\n\n";
	}
	~DemoGood()
	{
		std::cout << this << " destroyed\n\n";
	}
	int var;
private:

};

struct Person {
	std::string name;
	std::string surname;
};


int main() {
	setlocale(LC_ALL, "Russian");
	int n;



	//чтение данных
	std::ifstream inFile("T.txt");
	if (!inFile.is_open()) {
		std::cerr << "ќшибка открыти€";
		return 1;
	}
	else
		std::cout << "¬се ок\n";

	std::queue<Person> peopleQueue;

	std::string line;
	while (std::getline(inFile, line)) 
	{
		std::stringstream ss(line);
		Person person;
		if (ss >> person.name >> person.surname) 
		{
			peopleQueue.push(person);
		}
	}

	inFile.close();

	// запись данных из очереди
	std::ofstream outFile("TT.txt");
	if (!outFile.is_open()) {
		std::cerr << "ќшибка открыти€";
		return 1;
	}
	else
		std::cout << "¬се ок\n";

	//генерим случайное число
	int randomIndex = rand() % peopleQueue.size();

	// перемещаемс€ к случайному элементу в очереди
	for (int i = 0; i < randomIndex; ++i) {
		peopleQueue.push(peopleQueue.front());
		peopleQueue.pop();
	}

	while (!peopleQueue.empty()) {
		outFile << peopleQueue.front().name << " " << peopleQueue.front().surname << std::endl;
		std::cout << peopleQueue.front().name << " " << peopleQueue.front().surname << std::endl;
		peopleQueue.pop();
	}

	outFile.close();


	//классна€ работа
	////pop front/top queue/stack
	//std::stack<DemoGood, std::list<DemoGood>> qwe;
	//{
	//	DemoGood tmp;
	//	for (int i = 0; i < 7; i++)
	//	{
	//		tmp.var = i;
	//		qwe.push(tmp); //заполн€ем
	//	}
	//}
	// 
	//for (int i = 0; i < 7; i++)
	//{
	//	
	//	std::cout << qwe.top().var << ' '; //возвращает элемент на первой позиции
	//	qwe.pop(); //уничтожает внутри очереди тот элемент, который был по очереди
	//}


	


	return 0;
}