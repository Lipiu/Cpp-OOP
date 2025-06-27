#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

class Team {
protected:
	char* name = nullptr;
	string coordinator = "";
	vector<string> members;
	int linesOfCode = 0;
	const string projectType;

public:
	Team(const char* name, string coordinator, vector<string> members, int linesOfCode, string projectType) :
		coordinator(coordinator), members(members), linesOfCode(linesOfCode), projectType(projectType) {
		setName(name);
	}

	Team() : projectType("SQLite") {}

	~Team() {
		delete[] name;
	}

	void setName(const char* name) {
		if (name == nullptr || strlen(name) > 50)
			throw exception("invalid argument");
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void operator-=(int multiplicator) { // polymorphism - overloading
		this->linesOfCode *= multiplicator;
	}

	bool operator()(string value, int index) {
		if (members.at(index) == value)
			return true;
		return false;
	}

	virtual void doSomething() { cout << endl << "something from base"; }

	inline char* getName() const { return this->name; }

	inline int getLinesOfCode() const { return this->linesOfCode; }

	inline string getCoordinator() const { return this->coordinator; }

	inline vector<string> getMembers() const { return this->members; }

};

class UpgradedTeam : public Team {
public:
	UpgradedTeam(const char* name, string coordinator, vector<string> members, int linesOfCode, string projectType) :
		Team(name, coordinator, members, linesOfCode, projectType) {}

	UpgradedTeam() : Team() {}

	void doSomething() { cout << endl << "something from derived"; }

	friend ostream& operator<<(ostream& out, const UpgradedTeam& obj);
	friend istream& operator>>(istream& in, UpgradedTeam& obj);
};

ostream& operator<<(ostream& out, const UpgradedTeam& obj) {
	out << obj.name << endl;
	out << obj.coordinator << endl;
	out << obj.members.size() << endl;
	for (auto& mem : obj.members) {
		out << mem << endl;
	}
	out << obj.linesOfCode << endl;
	out << obj.projectType << endl;
	return out;
}

istream& operator>>(istream& in, UpgradedTeam& obj) {
	string name, coordinator, n, memberName, linesOfCode, projectType;
	vector<string> members;
	getline(in, name);
	getline(in, coordinator);
	getline(in, n);
	for (int i = 0; i < stoi(n); i++) {
		getline(in, memberName);
		members.emplace_back(memberName);
	}
	getline(in, linesOfCode);
	getline(in, const_cast<string&>(obj.projectType));
	
	obj.setName(name.c_str());
	obj.coordinator = coordinator;
	obj.members = members;
	obj.linesOfCode = stoi(linesOfCode);
	return in;
}

int main() {
	vector<string> memb = { "tudor", "andrei", "cristian"};
	UpgradedTeam a("echipa 1", "tudor", memb, 2000, "ticketing app");
	cout << a.getMembers().at(1) << endl;

	ofstream fout("test.dat", fstream::out);
	fout << a;

	ifstream fin("test.dat", fstream::in);
	UpgradedTeam b;
	fin >> b;

	cout << endl << b;

	//

	a.doSomething(); // early binding - compile time polymorphism - overriding
	Team* basePointer = &a;
	basePointer->doSomething(); // late binding - run time polymorphism - overriding

	return 0;
}