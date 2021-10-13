#include <iostream>
#include <string>
#include <iostream>
#include <iostream>
using namespace std;
#define EXPENSIVE "EXPENSIVE"
#define POOR "POOR"
#define WHITE 0
#define RED 1
#define BLACK 2
#define WITH -10

class Car {
public:
    virtual ~Car(){};
    virtual string UsefulCar() const = 0;
    virtual string colorOfCar() const = 0;
    virtual int speedOfCar() const = 0;
    virtual int priceOfCar() const = 0;
    virtual string whatIsSalon() const = 0;
};

class AudiCar : public Car {
public:
    string UsefulCar() const override {
      return "The Audi Car has created";
    }
    string colorOfCar() const override {
      return "WHITE";
    }
    int speedOfCar() const override {
      return 100;
    }
    int priceOfCar() const override {
      return 1000000;
    }
    string whatIsSalon() const override {
      return POOR;
    }
    
};
class AudiCar1 : public AudiCar {
public:
    string UsefulCar() const override {
      return "The Audi Car type 1 has created";
    }
    string colorOfCar() const override {
      return "WHITE";
    }
    int speedOfCar() const override {
      return 150;
    }
    int priceOfCar() const override {
      return 3000000;
    }
    string whatIsSalon() const override {
      return EXPENSIVE;
    }
    
};
class AudiCar2 : public AudiCar {
public:
    string UsefulCar() const override {
      return "The Audi Car type 2 has created";
    }
    string colorOfCar() const override {
      return "RED";
    }
    int speedOfCar() const override {
      return 160;
    }
    int priceOfCar() const override {
      return 3100005;
    }
    string whatIsSalon() const override {
      return POOR;
    }
    
};

class BMWCar : public Car {
    string UsefulCar() const override {
      return "The BMW Car has created";
    }
    string colorOfCar() const override {
      return "WHITE";
    }
    int speedOfCar() const override {
      return 100;
    }
    int priceOfCar() const override {
      return 1000000;
    }
    string whatIsSalon() const override {
      return POOR;
    }
};
class BMWCar1 : public BMWCar {
    string UsefulCar() const override {
      return "The BMW Car type 1 has created";
    }
    string colorOfCar() const override {
      return "BLACK";
    }
    int speedOfCar() const override {
      return 200;
    }
    int priceOfCar() const override {
      return 5500000;
    }
    string whatIsSalon() const override {
      return EXPENSIVE;
    }
};
class BMWCar2 : public BMWCar {
    string UsefulCar() const override {
      return "The BMW Car type 2 has created";
    }
    string colorOfCar() const override {
      return WHITE;
    }
    int speedOfCar() const override {
      return 190;
    }
    int priceOfCar() const override {
      return 5300000;
    }
    string whatIsSalon() const override {
      return EXPENSIVE;
    }
};

class Autobus {
public:
    virtual ~Autobus(){};
    virtual string UsefulBus() const = 0;
    //virtual string colorOfBus() const = 0;
    virtual int countOfSeats() const = 0;
    virtual string AnotherUsefulBus(const Car &collaborator) const = 0;
};


class AudiBus : public Autobus {
public:
    string UsefulBus() const override {
        return "The Audi Bus has created";
    }
    int countOfSeats() const override {
        return 28;
    }

  string AnotherUsefulBus(const Car &collaborator) const override {
    const string result = collaborator.colorOfCar();
      return "Audi bus was created with ( " + result + " )";
  }
};

class BMWBus : public Autobus {
public:
    string UsefulBus() const override {
        return "The BMW Bus has created";
    }
    int countOfSeats() const override {
        return 34;
    }

  string AnotherUsefulBus(const Car &collaborator) const override {
    const string result = collaborator.colorOfCar();
      return "BMW bus was created with ( " + result + " )";
  }
 
};

class AbstractFactory {
 public:
    virtual Car *CreateCarA() const = 0;
    virtual Car *CreateCarB() const = 0;
    virtual Car *CreateCarA1() const = 0;
    virtual Car *CreateCarA2() const = 0;
    virtual Car *CreateCarB1() const = 0;
    virtual Car *CreateCarB2() const = 0;
    virtual Autobus *CreateBusB() const = 0;
    virtual Autobus *CreateBusA() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    Car *CreateCarA() const override {
      return new AudiCar();
    }
    Car *CreateCarB() const override {
      return new BMWCar();
    }
    
    Car *CreateCarA1() const override {
        return new AudiCar1();
    }
    Car *CreateCarA2() const override {
        return new AudiCar2();
    }
    Car *CreateCarB1() const override {
        return new BMWCar1();
    }
    Car *CreateCarB2() const override {
        return new BMWCar2();
    }
    Autobus *CreateBusA() const override {
        return new AudiBus();
    }
    Autobus *CreateBusB() const override {
        return new BMWBus();
    }

};

class ConcreteFactory2 : public AbstractFactory {
public:
    Autobus *CreateBusA() const override {
        return new AudiBus();
    }
    Autobus *CreateBusB() const override {
        return new BMWBus();
    }
};

void ClientCode(const AbstractFactory &factory) {
    int anser = 0;
    cout << "Would you like to buy a Car(1) or Bus(2)?" << endl;
    cin >> anser;
    switch(anser) {
        case 1: {
            int anser1 = 0;
            cout << "Would you like to buy a Audi(1) or BMW(2)?" << endl;
            cin >> anser1;
            switch(anser1) {
                case 1: {
                    int anser11 = 0;
//                    const Car *car = factory.CreateCarA();
//                    cout << car->UsefulCar() << "\n";
                    cout << "Would you like to buy a first complectation(1) or second complectation(2)?" << endl;
                    cin >> anser11;
                    switch(anser11) {
                        case 1: {
                            const Car *car1 = factory.CreateCarA1();
                            cout << car1->UsefulCar() <<" with: \n"<< car1->colorOfCar() << "\n" << car1->colorOfCar() << "\n" << car1->speedOfCar() << "\n" << car1->priceOfCar() << "\n" << car1->whatIsSalon() << endl;
                           // delete car;
                            delete car1;break;
                        }
                        case 2: {
                            const Car *car1 = factory.CreateCarA2();
                            cout << car1->UsefulCar() <<" with: \n"<< car1->colorOfCar() << "\n" << car1->colorOfCar() << "\n" << car1->speedOfCar() << "\n" << car1->priceOfCar() << "\n" << car1->whatIsSalon() << endl;
                           // delete car;
                            delete car1;break;
                        }
                    }
                  //  delete car;
                    break;
                }
                case 2: {
                    int anser12 = 0;

                    cout << "Would you like to buy a first complectation(1) or second complectation(2)?" << endl;
                    cin >> anser12;
                    switch(anser12) {
                        case 1: {
                            const Car *car1 = factory.CreateCarB1();
                            cout << car1->UsefulCar() <<" with: \n"<< car1->colorOfCar() << "\n" << car1->colorOfCar() << "\n" << car1->speedOfCar() << "\n" << car1->priceOfCar() << "\n" << car1->whatIsSalon() << endl;
                           
                            delete car1; break;
                        }
                        case 2: {
                            const Car *car1 = factory.CreateCarB2();
                            cout << car1->UsefulCar() <<" with: \n"<< car1->colorOfCar() << "\n" << car1->colorOfCar() << "\n" << car1->speedOfCar() << "\n" << car1->priceOfCar() << "\n" << car1->whatIsSalon() << endl;
                            
                            delete car1;break;
                        }
                    }
                  //  delete car;
                    break;
                }
            }
            break;
        }
        case 2: {
            cout << "Would you like to buy a Audi(1) or BMW(2)?" << endl;
            int anserB = 0;
            cin >> anserB;
            switch(anserB) {
                case 1: {
                    const Autobus *bus1 = factory.CreateBusA();
                    const Car *car = factory.CreateCarA();
                    cout << bus1->UsefulBus() <<" with: \n" << bus1->countOfSeats() << " seats\n" << bus1->AnotherUsefulBus(*car) << endl;
                    delete bus1;
                    delete car;
                    break;
                }
                case 2: {
                    const Autobus *bus1 = factory.CreateBusB();
                    const Car *car = factory.CreateCarB();
                    cout << bus1->UsefulBus() <<" with: \n" << bus1->countOfSeats() << " seats\n" << bus1->AnotherUsefulBus(*car) << endl;
                    delete bus1;
                    delete car;
                    break;
                }
            }
            break;
        }
            
    }
}

int main() {
    cout << "The dialog with customer: \n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
  return 0;
}

