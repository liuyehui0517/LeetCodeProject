__pragma(once)
#include <string>
#include <iostream>

using std::string;

class Person
{
public:
	inline string getName() const { return this->name; }
	inline string getAddress()const { return this->address; }
	
private:
	string name;
	string address;

};

