// Test Source.
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
using namespace std;

class Lamp {
public:
	Lamp() {
		this->power = false;
		this->illuminance = 1;
	}
	Lamp(bool power, int illuminance) {
		this->power = power;
		this->illuminance = illuminance;
	}
	bool power;
	int illuminance;

	void onOff() {
		power = !power;
		if (power)
			cout << "전원이 켜졌습니다\n";
		else
			cout << "전원이 꺼졌습니다\n";
	}

	void lightChange() {
		if (power) {
			illuminance = illuminance % 3 + 1;
			cout << "조도 : " << illuminance << "\n";
		}
		else {
			cout << "전원이 꺼져있습니다\n";
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Lamp gini = Lamp();
	gini.lightChange();
	gini.onOff();

	for(int i = 0; i < 5; i++)
		gini.lightChange();
	return 0;
}