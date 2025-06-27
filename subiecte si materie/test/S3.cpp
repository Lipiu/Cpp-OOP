#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

enum class Type {
	LOCATION,
	ONLINE
};

class FlowerShop {
private: 
	const int shopId = 0;
	char* name = nullptr;
	Type type = Type::LOCATION;
	bool hasWebsite = false;
	string url = "";
	int noSoldFlowers = 0;

	static const float AVERAGE_FLOWER_PRICE;

public:

	FlowerShop(int shopId, const char* name, Type type, int noSoldFlowers) : shopId(shopId) {
		this->type = type;
		this->noSoldFlowers = noSoldFlowers;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	FlowerShop(const FlowerShop& other) : shopId(other.shopId) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->type = other.type;
		this->hasWebsite = other.hasWebsite;
		this->url = other.url;
		this->noSoldFlowers = other.noSoldFlowers;
	}

	void setName(const char* name) {
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	char* getName() {
		char* rez = new char[strlen(this->name) + 1];
		strcpy(rez, this->name);
		return rez;
	}

	int getId() {
		return this->shopId;
	}

	void setNoSoldFlowers(int noSoldFlowers) {
		this->noSoldFlowers = noSoldFlowers;
	}

	int getNoSoldFlowers() {
		return this->noSoldFlowers;
	}

	void openWebsite(string url) {
		this->url = url;
		this->hasWebsite = true;
	}

	float getTotalRevenue() {
		return this->noSoldFlowers * AVERAGE_FLOWER_PRICE;
	}

	FlowerShop& operator=(const FlowerShop& other) {
		if (this == &other)
			return *this;

		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->type = other.type;
		this->hasWebsite = other.hasWebsite;
		this->url = other.url;
		this->noSoldFlowers = other.noSoldFlowers;

		return *this;
	}

	string getType() const {
		if ((int)type == 0)
			return "Location";
		return "Online";
	}

	FlowerShop operator+(int soldFlowers) {
		this->noSoldFlowers += soldFlowers;
		return *this;
	}

	void operator+=(int soldFlowers) {
		this->noSoldFlowers += soldFlowers;
	}

	FlowerShop& operator++(int) {
		FlowerShop copy(*this);
		this->noSoldFlowers += 1;
		return copy;
	}

	~FlowerShop() {
		delete[] name;
	}

	friend ostream& operator<<(ostream& out, const FlowerShop& fs);
	friend istream& operator>>(istream& in, FlowerShop& fs);
	friend FlowerShop operator+(int soldFlowers, const FlowerShop& fs);
};

const float FlowerShop::AVERAGE_FLOWER_PRICE = 7.5f;

FlowerShop operator+(int soldFlowers, const FlowerShop& fs) {
	FlowerShop copy(fs);
	copy.noSoldFlowers += soldFlowers;
	return copy;
}

ostream& operator<<(ostream& out, const FlowerShop& fs) {
	out << "Id: " << fs.shopId << endl;
	out << "Name: " << fs.name << endl;
	out << "Type: " << fs.getType() << endl;
	out << "Has Website: " << fs.hasWebsite << endl;
	out << "Url: " << fs.url << endl;
	out << "Number of sold flowers: " << fs.noSoldFlowers << endl;
	return out;
}

istream& operator>>(istream& in, FlowerShop& fs) {
	int type;
	string buffer;
	cout << "Insert name: ";
	in >> buffer;
	fs.setName(buffer.c_str());
	cout << "Insert type (0 or 1): ";
	in >> type;
	fs.type = (Type)type;
	cout << "Insert if the fs has an url (0 or 1): ";
	in >> fs.hasWebsite;
	if (fs.hasWebsite == 1) {
		cout << "Insert url: ";
		in >> fs.url;
	}
	cout << "Insert number of sold flowers: ";
	in >> fs.noSoldFlowers;
	return in;
}

int main() {
	//1
	FlowerShop f1(1, "Maria", Type::ONLINE, 15);

	//2
	FlowerShop ftest(f1);
	cout << ftest.getName() << endl;
	cout << ftest.getId() << endl;
	cout << ftest.getNoSoldFlowers() << endl;

	//3
	f1.openWebsite("www.maria.ro");
	float totalRevenue = f1.getTotalRevenue();
	cout << totalRevenue << endl;

	//4
	FlowerShop f2(2, "Daisy", Type::LOCATION, 35);
	f1 = f2;
	cout << f1;

	//5
	cin >> f1;
	cout << f1;

	//6
	f2 = 23 + f1;
	cout << f1;
	cout << f2;

	//7
	f1 += 47;
	cout << f1;

	//8
	f1++;
	cout << f1;

	return 0;
}