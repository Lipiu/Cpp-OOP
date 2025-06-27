#include <iostream>
#include <vector>

using namespace std;

class Character {
protected:
	char* name = nullptr;
	int HP = 0;
	vector<string> abilities;
	string alignment;

	static int MAX_HP;

public:
	Character(const char* name, int HP, vector<string> abilities, string alignment) :
		HP(HP), abilities(abilities), alignment(alignment) {
		setName(name);
	}

	~Character() {
		delete[] this->name;
	}

	void setName(const char* name) {
		if (name == nullptr || strlen(name) > 40)
			throw exception("invalid argument");
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void operator+=(int value) {
		this->HP += value;
	}

	bool operator >=(const Character& other) {
		if (this->HP >= other.HP)
			return true;
		return false;
	}

	virtual void attack() = 0;

	inline int getHP() const { return this->HP; }
	inline vector<string> getAbilities() const { return this->abilities; }
	inline string getAlignemtn() const { return this->alignment; }
};

class UpgradedCharacter : public Character {
protected:
	string feat = "";
public:
	UpgradedCharacter(const char* name, int HP, vector<string> abilities, string alignment, string feat) :
		Character(name, HP, abilities, alignment) {
		this->feat = feat;
	}

	void attack() { cout << endl << name << " has attacked!"; }
};

int Character::MAX_HP = 500;

int main() {
	vector<string> abilities1{ "divine smite", "toll the dead" };
	UpgradedCharacter char1("sigfried", 25, abilities1, "neutral good", "some feat name");

	//1
	char1 += 5;
	cout << endl << char1.getHP();

	//2
	vector<string> abilities2{ "turtle shell", "healing touch" };
	UpgradedCharacter char2("eats-many-leaves", 30, abilities2, "chaotic evil", "he died i dont have any feats for him");
	if (char2 >= char1)
		cout << endl << "char 2 has more HP";
	else cout << endl << "char 2 has less HP";

	//3
	UpgradedCharacter char3("pog", 25, abilities1, "neutral good", "crossbow mastery");

	//4
	vector<Character*> characters{ &char1,&char2,&char3 };
	for (auto& chr : characters)
		chr->attack();

	//5
	UpgradedCharacter* upchrPointer = new UpgradedCharacter("pog", 25, abilities1, "neutral good", "crossbow mastery");
	delete upchrPointer;
	cout << endl << "Dangling pointer -> " << upchrPointer;

	return 0;
}