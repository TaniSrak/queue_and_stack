#include <iostream>
#include <vector>
#include <list>

#include <stack> //FILO ������� ����� �������
#include <queue> //FIFO ������� � ������

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



	//������ ������
	std::ifstream inFile("T.txt");
	if (!inFile.is_open()) {
		std::cerr << "������ ��������";
		return 1;
	}
	else
		std::cout << "��� ��\n";

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

	// ������ ������ �� �������
	std::ofstream outFile("TT.txt");
	if (!outFile.is_open()) {
		std::cerr << "������ ��������";
		return 1;
	}
	else
		std::cout << "��� ��\n";

	//������� ��������� �����
	int randomIndex = rand() % peopleQueue.size();

	// ������������ � ���������� �������� � �������
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


	//�������� ������
	////pop front/top queue/stack
	//std::stack<DemoGood, std::list<DemoGood>> qwe;
	//{
	//	DemoGood tmp;
	//	for (int i = 0; i < 7; i++)
	//	{
	//		tmp.var = i;
	//		qwe.push(tmp); //���������
	//	}
	//}
	// 
	//for (int i = 0; i < 7; i++)
	//{
	//	
	//	std::cout << qwe.top().var << ' '; //���������� ������� �� ������ �������
	//	qwe.pop(); //���������� ������ ������� ��� �������, ������� ��� �� �������
	//}


	


	return 0;
}