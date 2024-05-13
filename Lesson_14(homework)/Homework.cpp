#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Exception
{
private:
	string message;
public:
	Exception(string message) : message(message) {}

	const string& what() const
	{
		return message;
	}
};

void Add_Element(vector<string>& obj, const string& element)
{
	obj.insert(obj.begin() + rand() % obj.size(), element);
}

int Min_Element(vector<string>& obj)
{
	string temp = obj[0];
	int index = 0;
	for (int i = 1; i < obj.size(); i++)
	{
		if (temp.size() > obj[i].size())
		{
			temp = obj[i];
			index = i;
		}
	}

	return index;
}

int Max_Element(vector<string>& obj)
{
	string temp = obj[0];
	int index = 0;
	for (int i = 1; i < obj.size(); i++)
	{
		if (temp.size() < obj[i].size())
		{
			temp = obj[i];
			index = i;
		}
	}

	return index;
}

void Move_Elements(vector<string>& obj, vector<string>& temp)
{
	int min_index = Min_Element(obj);
	int max_index = Max_Element(obj);
	if (min_index < 0 || min_index >= obj.size())
	{
		throw Exception("Index out of range");
	}
	if (min_index > max_index)
	{
		swap(min_index, max_index);
	}

	for (int i = min_index + 1; i < max_index; i++)
	{
		temp.push_back(obj[i]);
	}

	obj.erase(obj.begin() + min_index);
	obj.erase(obj.begin() + max_index - 1);
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	vector<string> obj_1{ "Hello", "Fofa", "Opa", "Yuil", "Nettttt" };
	vector<string> obj_2;
	try
	{
		Add_Element(obj_1, "Boba");
		for (auto element : obj_1)
		{
			cout << element << ' ';
		}
		cout << endl;

		cout << Min_Element(obj_1) << endl;
		cout << Max_Element(obj_1) << endl;


		Move_Elements(obj_1, obj_2);
		for (auto element : obj_2)
		{
			cout << element << ' ';
		}
		cout << endl;

		for (auto element : obj_1)
		{
			cout << element << ' ';
		}
		cout << endl;
	}
	catch (const Exception& exception)
	{
		cout << exception.what() << endl;
	}

	return 0;
}