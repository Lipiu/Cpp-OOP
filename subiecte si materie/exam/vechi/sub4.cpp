#include <iostream>
#include <vector>

using namespace std;

class Printer {
protected:
	string manufacturer = "";
	char* model = nullptr;
	int noPrintedPages = 0;
	float temperature = 0.0f;
	const int tonerCapacity;

	static int MAX_PAGES;
public:
	Printer() : tonerCapacity(500) {}
	Printer(string manufacturer, const char* model, int noPrintedPages, float temperature, int tonerCapacity) :
		manufacturer(manufacturer), noPrintedPages(noPrintedPages), temperature(temperature), tonerCapacity(tonerCapacity) {
		setModel(model);
	}
	Printer(const Printer& old) :
		manufacturer(old.manufacturer), noPrintedPages(old.noPrintedPages), temperature(old.temperature), tonerCapacity(old.tonerCapacity) {
		setModel(old.model);
	}
	~Printer() {
		delete[] model;
	}

	void setModel(const char* model) {
		if (model == nullptr || strlen(model) > 30)
			throw exception("invalid argument");
		delete[] this->model;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}

	virtual void doSomething() { cout << endl << "something from base"; }

	explicit operator float() const {
		return ((temperature * (float)9 / 5) + 32);
	}

	inline string getManufacturer() const { return this->manufacturer; }
	inline char* getModel() const { return this->model; }
	inline int getNoPrintedPages() const { return this->noPrintedPages; }
	inline float getTemperature() const { return this->temperature; }
	inline int getTonerCapacity() const { return this->tonerCapacity; }
};

class UpgradedPrinter : public Printer {
public:
	UpgradedPrinter() : Printer() {}
	UpgradedPrinter(string manufacturer, const char* model, int noPrintedPages, float temperature, int tonerCapacity) :
		Printer(manufacturer, model, noPrintedPages, temperature, tonerCapacity) {}

	void doSomething() override { cout << endl << "something from derived"; }
};

int Printer::MAX_PAGES = 2000;

template<typename T>
T* deepCopy(const T* arr, int size) {
	T* copy = new T[size];
	for (int i = 0; i < size; ++i)
		copy[i] = arr[i];
	return copy;
}

int main() {
	//1
	Printer a("toyota", "L", 500, 30.0f, 1000);

	//2
	cout << (float)a << endl;

	Printer b(a);
	Printer c(a);
	
	//3
	vector<Printer*> printers{ &a,&b,&c };

	for (auto& printer : printers)
		printer->doSomething();
	//alternativa super amuzanta si hilara: for (std::vector<Printer*>::iterator::value_type& printer : printers)

	//5
	UpgradedPrinter d;
	Printer* basePointer = &d;
	basePointer->doSomething();

	//6
	float o[] = { 1.0f,2.5f,3.54f,4.34f,5.82f };
	int p[] = { 1,2,3,4,5 };

	float* pointerFloat = deepCopy(o, 5);
	int* pointerInt = deepCopy(p, 5);

	for (int i = 0; i < 5; ++i) {
		cout << endl << pointerFloat[i] << " " << pointerInt[i];
	}

	return 0;
}