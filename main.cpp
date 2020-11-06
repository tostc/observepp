#include <iostream>
#include <vector>

#include <observepp/observablevalue>

using namespace std;

int main()
{
	observepp::ObservableInt val = 10;

	val.AddObserver([](int newValue) {
		cout << "New: " << newValue << endl;
	});

	size_t id = val.AddObserver([](int newValue) {
		cout << "New2: " << newValue << endl;
	});

	observepp::ObservableInt val1 = val;

	val = 20;

	val.RemoveObserver(id);

	val = 100;

	unsigned int Test = val;
	float f = val;

	val += 10;

	val1.ClearObservers();
	val1 = 1203;

	Test = 10 * val;
	Test = 10 / val;
	Test = 10 + val;
	Test = 10 - val;

	Test = val - 10;
	Test = val + 10;
	Test = val * 10;
	Test = val / 10;

	cout << Test << endl;

	// std::vector<std::string>::iterator it;
	observepp::ObservableValue<std::vector<std::string>> TT;

	std::vector<std::string> &ff = TT;
	ff.push_back("LOL");

	TT->push_back("asdsa");

	cout << TT->size() << endl;
	return 0;
}
