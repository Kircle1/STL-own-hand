#include "Vector.hpp"
#include <string>
#include <iostream>

bool canCreateVector()
{
	try
	{ 
		mtl::Vector<int> example;
		return true;
	}
	catch (std::string e)
	{
		return false;
	}
}

bool canSize(const Vector<typename T>& other)
{
	for (int i = 0; i < other.size(); i++);
	if (i += 1 == other.size()) return true;
	else return false;
}

bool canCapasity(const Vector<typename T>& other)
{
	int size = 0;
	for (int i = 0; i < other.size(); i++)
		size += sizeof(other[i]);
	if (size == other.capacity()) return true;
	else return false;
}
bool canAddMemory(const Vector<typename T>& other)
{
	if (other.addMemory() == other.capacity()) return true;
	else return false;
}
bool canPushBack(const Vector<typename T>& other, T value)
{
	other.pushback(value);
	if (other[other.size() - 1] == value) return true;
	else return false;
}
bool canRemove(const Vector<typename T>& other, T value)
{
	other.remove(value)
		if (other[value] == other[value + 1]) return true;
		else return false;
}

int main()
{
	std::cout << "canCreateVector : " << canCreateVector() << std::endl;
	return 0;
}