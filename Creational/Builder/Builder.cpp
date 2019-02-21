/*
* C++ Design Patterns: Builder
* Author: walid Abbassi [https://github.com/walidAbbassi]
* 2019
*
* Source code is licensed under MIT License
* (for more details see LICENSE)
*
*/

#include <iostream>
#include <ostream>
#include <string>
#include <memory>

/*
* Car  ==>  Product
* the final object that will be created using Builder
*/
class Car {
public:
	void makeSeat(const std::string &part) {
		partSeat = part;
	}
	void makeEngine(const std::string &part) {
		partEngine = part;
	}
	void makeWheel(const std::string &part) {
		partWheel = part;
	}

	friend std::ostream &operator<<(std::ostream &out, const std::unique_ptr<Car> &car)
	{
		return out << " Seat : " << car->partSeat << " , Engine : " << car->partEngine << " and Wheel : " << car->partWheel;
	}
	// ...

private:
	std::string partSeat;
	std::string partEngine;
	std::string partWheel;
	// ...
};

/*
* Builder
* abstract interface for creating products
*/
class Builder {
public:
	virtual ~Builder() {
		// ...
	}

	virtual void buildPartSeat(const std::unique_ptr<Car> &car) = 0;
	virtual void buildPartEngine(const std::unique_ptr<Car> &car) = 0;
	virtual void buildPartWheel(const std::unique_ptr<Car> &car) = 0;
	// ...
};

/*
* Concrete Builder Luxury
* create real products and stores them in the composite structure
*/
class ConcreteBuilderLuxury : public Builder {
public:
	void buildPartSeat(const std::unique_ptr<Car> &car) override {
		car->makeSeat("Luxury Seat");
	}
	void buildPartEngine(const std::unique_ptr<Car> &car) override {
		car->makeEngine("Luxury Engine");
	}
	void buildPartWheel(const std::unique_ptr<Car> &car) override {
		car->makeWheel("Luxury Wheel");
	}
	// ...
};

/*
* Concrete Builder Basic
* create real products and stores them in the composite structure
*/
class ConcreteBuilderBasic : public Builder {
public:
	void buildPartSeat(const std::unique_ptr<Car> &car) override {
		car->makeSeat("Basic Seat");
	}
	void buildPartEngine(const std::unique_ptr<Car> &car) override {
		car->makeEngine("Basic Engine");
	}
	void buildPartWheel(const std::unique_ptr<Car> &car) override {
		car->makeWheel("Basic Wheel");
	}
	// ...
};

/*
* Director
* responsible for managing the correct sequence of object creation
*/
class Director {
public:
	Director(const std::shared_ptr<Builder> &builder) : builder_ptr(builder) {}

	void set(const std::shared_ptr<Builder> &builder) {
		if (builder_ptr) {			 
			 builder_ptr.reset();	//builder_ptr = nullptr;
		}
		builder_ptr = builder;
	}


	std::unique_ptr<Car> construct() {
		std::unique_ptr<Car> car = std::make_unique<Car>();
		builder_ptr->buildPartSeat(car);
		builder_ptr->buildPartEngine(car);
		builder_ptr->buildPartWheel(car);
		return car;
		// ...
	}
	// ...

private:
	std::shared_ptr<Builder> builder_ptr;
};

int main()
{
	std::shared_ptr<Builder> concreteBuilderLuxury = std::make_shared<ConcreteBuilderLuxury>();
	Director director(concreteBuilderLuxury);
	std::unique_ptr<Car> carLuxury = director.construct();
	std::cout << "Product car1 " << carLuxury << std::endl;

	std::shared_ptr<Builder> concreteBuilderBasic = std::make_shared<ConcreteBuilderBasic>();
	director.set(concreteBuilderBasic);
	std::unique_ptr<Car> carBasic = director.construct();
	std::cout << "Product car2 " << carBasic << std::endl;

	system("pause");
	return 0;
}
