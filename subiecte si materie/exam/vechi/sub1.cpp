#include <iostream>
#include <string>
#include <map>

using namespace std;

class Condition {
private:
	string date = "";
	float temperature = 0.0f;
	char* description = nullptr;
	int schedule = 0;
	const int humidity;
	string location = "";

	static int TOTAL_CONDITIONS;

public:
	Condition(int humidity) : humidity(humidity) {
		TOTAL_CONDITIONS++;
	}

	Condition(string date, float temperature, const char* description, int schedule, int humidity, string location) : 
		humidity(humidity), date(date), schedule(schedule), location(location) {
		setTemperature(temperature);
		setDescription(description);
		TOTAL_CONDITIONS++;
	}

	Condition(const Condition& other) : 
		humidity(humidity), date(date), schedule(schedule), location(location) {
		setTemperature(other.temperature);
		setDescription(other.description);
	}

	Condition& operator=(const Condition& other) {
		this->date = other.date;
		this->schedule = other.schedule;
		this->location = other.location;
		setTemperature(other.temperature);
		setDescription(other.description);
		return *this;
	}

	~Condition() {
		delete[] description;
	}

	inline int getSchedule() const { return this->schedule; }

	inline float getTemperature() const { return this->temperature; }

	inline string getDate() const { return this->date; }
	
	inline string getLocation() const { return this->location; }

	void setTemperature(float temperature) {
		if (temperature < -20 || temperature > 60)
			throw exception("invalid argument");
		this->temperature = temperature;
	}

	void setDescription(const char* description) {
		if(description == nullptr)
			throw exception("invalid argument");
		delete[] this->description;
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void setDescription(string description) {
		if(description == "")
			throw exception("invalid argument");
		delete[] this->description;
		this->description = new char[strlen(description.c_str()) + 1];
		strcpy_s(this->description, strlen(description.c_str()) + 1, description.c_str());
	}

	Condition operator++(int) {
		Condition copy(*this);
		if (this->schedule == 23)
			throw exception("schedule out of bounds");
		this->schedule++;
		return copy;
	}
};

class Region {
public:
	string name;
	map<string, Condition*> conditions;

	Region(string name, map<string, Condition*> conditions) :
		name(name) {
		this->conditions = conditions;
	}

	float getTemperatureAtLocation(string idx) {
		return conditions.at(idx)->getTemperature();
	}

	void operator+=(Condition& cond) {
		conditions[cond.getLocation()] = &cond;
	}
};

class Base {
public:
	virtual void doSomething() { cout << endl << "something from base"; }
};

class Derived : public Base{
public:
	void doSomething() { cout << endl << "something from derived"; }
};


int Condition::TOTAL_CONDITIONS = 0;

int main() {
	Condition a("today", 5.5f, "raining", 22, 89, "sector 1");
	Condition b("tommorow", 6.8f, "cloudy", 21, 60, "sector 2");
	a++;
	cout << a.getSchedule() << endl;

	map<string, Condition*> conditions;
	conditions[a.getLocation()] = &a;
	conditions[b.getLocation()] = &b;

	Region c("bucuresti", conditions);

	cout << endl << "In sector 1 the temperature is " << c.getTemperatureAtLocation("sector 1");

	Condition d("in 2 days", 1.3f, "stormy", 16, 65, "sector 3");
	c += d;

	cout << endl << "In sector 3 the temperature is " << c.getTemperatureAtLocation("sector 3");

	//

	Derived o;
	Base* basePointer = &o;
	basePointer->doSomething();

	return 0;
}