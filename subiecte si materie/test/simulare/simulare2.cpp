#include <iostream>
#include <string>
using namespace std;

enum class Type {
	INDIVIDUAL,
	TEAM
};

class CppProject {
private:
	const int projectId;
	string* members = nullptr;
	int noMembers = 0;
	int noLinesOfCode = 0;
	Type type = Type::INDIVIDUAL;
	bool isComplex = false;

	static const int LINES_OF_CODE_PER_HOUR = 30;

public:

	CppProject(int id, string name) : projectId(id) {
		members = new string[1];
		members[noMembers++] = name;
	}

	CppProject(int id, string* names, int ppl) : projectId(id) {
		type = Type::TEAM;
		noMembers = ppl;
		isComplex = true;
		members = new string[ppl];
		for (size_t i = 0; i < ppl; ++i) {
			members[i] = names[i];
		}
	}

	CppProject(const CppProject& a) : projectId(a.projectId) {
		this->noMembers = a.noMembers;
		this->noLinesOfCode = a.noLinesOfCode;
		this->type = a.type;
		this->isComplex = a.isComplex;
		this->members = new string[noMembers];
		for (size_t i = 0; i < noMembers; ++i) {
			members[i] = a.members[i];
		}
	}

	CppProject operator=(const CppProject& a) {
		this->noMembers = a.noMembers;
		this->noLinesOfCode = a.noLinesOfCode;
		this->type = a.type;
		this->isComplex = a.isComplex;
		this->members = new string[noMembers];
		for (size_t i = 0; i < noMembers; ++i) {
			members[i] = a.members[i];
		}
		return *this;
	}

	void setNoLinesOfCode(int lines) {
		noLinesOfCode = lines;
	}

	int getNoLinesOfCode() {
		return noLinesOfCode;
	}

	bool isEasy() {
		if (isComplex == 1)
			return 0;
		else return 1;
	}

	bool operator>(const CppProject& a) {
		if (this->noLinesOfCode > a.noLinesOfCode)
			return true;
		return false;
	}

	int getId() {
		return projectId;
	}

	void markAsEasy() {
		isComplex = 0;
	}

	string getType() const {
		if ((int)type == 0)
			return "Individual";
		return "Team";
	}

	void writeCode(int code) {
		noLinesOfCode += code;
	}

	void operator+=(string newName) {
		string* temp = new string[noMembers+1];
		for (size_t i = 0; i < noMembers; ++i) {
			temp[i] = members[i];
		}
		temp[noMembers++] = newName;
		delete[] members;
		members = temp;
	}

	explicit operator float() {
		float a = (float)this->noLinesOfCode / (float)LINES_OF_CODE_PER_HOUR;
		return a;
	}

	~CppProject() {
		delete[] members;
	}

	friend ostream& operator<<(ostream& out, const CppProject& a);
};

ostream& operator<<(ostream& out, const CppProject& a) {
	out << "Project id: " << a.projectId << endl;
	out << "Number of members: " << a.noMembers << endl;
	out << "List of members: " << endl;
	for (size_t i = 0; i < a.noMembers; ++i)
		out << "- " << a.members[i] << endl;
	out << "Lines of code: " << a.noLinesOfCode << endl;
	out << "Type of project: " << a.getType() << endl;
	out << "Is complex? : " << a.isComplex << endl;
	return out;
}

int main() {
	//1
	CppProject prj1(1, "John");       //1 is the project id
								   //the project has only 1 member
												  //the project type will be set to INDIVIDUAL
	prj1.setNoLinesOfCode(1000);

	cout << prj1.getNoLinesOfCode() << endl;  // prints 1000

	//2
	cout << prj1.getType() << endl;           // prints “Individual” or “Team” based on project type

	//3
	string members[] = { "John", "Alice", "Bob" };
	int noPersons = 3;
	CppProject prj2(2, members, noPersons);        //2 is the project id

													//the project type will be set to TEAM

													//the project is set to be a complex one

	cout << prj2.getType();                             // prints Team

	//4
	if (!prj2.isEasy())

		cout << endl << "Is complex";        //prints this message


	cout << endl << prj2.getId();        //prints 2

	prj2.markAsEasy();

	//5
	prj1.writeCode(1500);                              //adds the lines of code to the existing ones

	cout << endl << prj1.getNoLinesOfCode();          // prints 2500

	//6
	CppProject prj3 = prj2;

	//7
	prj1 = prj2;

	prj1 = prj1;

	//8
	cout << endl << prj2;

	//9
	if (prj2 > prj1)

		cout << "\n Station 3 has sold more than 1000 liters";

	else

		cout << "\n Station 3 has sold less than 1000 liters";

	//10
	CppProject prj4(1, "John");

	prj4 += "Alice";

	cout << endl << prj4;

	//11
	prj2.writeCode(1000);
	float totalHours = (float)prj2;
	cout << "\n Total hours " << totalHours;
	return 0;
}