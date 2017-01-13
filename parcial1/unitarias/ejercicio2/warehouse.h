#include <iostream>
#include <vector>

class Warehouse
{
private:
	std::vector<int> v;
public:
	Warehouse(int spaces) {
		v.reserve(spaces);
	}
	void addFront (int element) {
		std::vector<int> temp (v);
		v.clear();
		v.push_back(element);
		for (int i = 0; i < temp.size(); i++)
		{
			v.push_back(temp[i]);
		}
	}
	void addBack (int element) {
		v.push_back(element);
	}
	void deleteElement (int position) {
		v.erase(v.begin()+position);
	}
	bool empty() {
		return v.empty();
	}
	int size() {
		return v.size();
	}
	int capacity() {
		return v.capacity();
	}
	void print() {
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
};