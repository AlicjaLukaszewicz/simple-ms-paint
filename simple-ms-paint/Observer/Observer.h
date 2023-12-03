#pragma once
#include <SFML/Graphics/Color.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Observer {
public:
	virtual void updateColor(const Color& color) = 0;
	virtual ~Observer() {}
};

class Observable {
public:
	void addObserver(Observer* observer) {
		observers.push_back(observer);
	}

	void removeObserver(Observer* observer) {
		// Remove the observer from the list
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	void notifyObservers(const Color& color) {
		for (Observer* observer : observers) {
			cout << "4b: Notified listener (i hope so)" << endl;
			observer->updateColor(color);
		}
	}

private:
	vector<Observer*> observers;
};