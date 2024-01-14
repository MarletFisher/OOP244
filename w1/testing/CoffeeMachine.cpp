#include<iostream>
using namespace std;
class CoffeeMachine {
private:
	int water = 0;
	int milk = 0;
	int coffee = 0;

	void addWater() {
		cout << "Adding water" << endl;
		water += 100;
	}
	void addCoffee() {
		cout << "Adding coffee" << endl;
		coffee += 100;
	}
	void addMilk() {
		cout << "Adding milk" << endl;
		milk += 100;
	}

public:
	void brewCoffee(int type) {
		// What kind of coffee
		switch (type) {
		case 0:
			// drip coffee
			if (water <= 0) {
				//refill water
				addWater();
			}
			if (coffee <= 0) {
				// refill coffee
				addCoffee();
			}
			if (milk <= 0) {
				// refill milk
				addMilk();
			}
		}
	}

};

int main() {
	CoffeeMachine cof;
	int type;
	while (true) {
		cout << "Welcome to robo coffee" 
	}
}