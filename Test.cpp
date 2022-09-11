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
template <typename T>
bool canSize(const mtl::Vector<T>& other)
{
	for (int i = 0; i < other.size(); i++);
	if (i += 1 == other.size()) return true;
	else return false;
}
template <typename T>
bool canCapasity(const mtl::Vector<T>& other)
{
	int size = 0;
	for (int i = 0; i < other.size(); i++)
		size += sizeof(other[i]);
	if (size == other.capacity()) return true;
	else return false;
}
template <typename T>
bool canAddMemory(const mtl::Vector<T>& other)
{
	if (other.addMemory() == other.capacity()) return true;
	else return false;
}
template <typename T>
bool canPushBack(const mtl::Vector<T>& other, T value)
{
	other.pushback(value);
	if (other[other.size() - 1] == value) return true;
	else return false;
}
template <typename T>
bool canRemove(const mtl::Vector<T>& other, T value)
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