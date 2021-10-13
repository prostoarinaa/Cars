#include <iostream>
#include <string>
#include <iostream>
#include <iostream>
using namespace std;
#define EXPENSIVE 1
#define POOR 0
#define WHITE 0
#define RED 1
#define BLACK 2
#define WITH -10
/**
 * Каждый отдельный продукт семейства продуктов должен иметь базовый интерфейс.
 * Все вариации продукта должны реализовывать этот интерфейс.
 */
class Car {
public:
    virtual ~Car(){};
    virtual string UsefulCar() const = 0;
    virtual int colorOfCar()  = 0;
    virtual int speedOfCar()  = 0;
    virtual int priceOfCar() = 0;
    virtual bool whatIsSalon() = 0;
};

/**
 * Конкретные продукты создаются соответствующими Конкретными Фабриками.
 */
class AudiCar : public Car {
public:
    string UsefulCar() const override {
      return "The Audi Car has created";
    }
    int colorOfCar() override {
      return WHITE;
    }
    int speedOfCar() override {
      return 150;
    }
    int priceOfCar() override {
      return 3000000;
    }
    bool whatIsSalon() override {
      return EXPENSIVE;
    }
    
};
class AudiCar1 : public AudiCar {
public:
    string UsefulCar() const override {
      return "The Audi Car type 1 has created";
    }
    int colorOfCar() override {
      return WHITE;
    }
    int speedOfCar() override {
      return 150;
    }
    int priceOfCar() override {
      return 3000000;
    }
    bool whatIsSalon() override {
      return EXPENSIVE;
    }
    
};

class BMWCar : public Car {
    string UsefulCar() const override {
      return "The BMW Car has created";
    }
    int colorOfCar() override {
      return WHITE;
    }
    int speedOfCar() override {
      return 150;
    }
    int priceOfCar() override {
      return 3000000;
    }
    bool whatIsSalon() override {
      return EXPENSIVE;
    }
};
class BMWCar1 : public Car {
    string UsefulCar() const override {
      return "The BMW Car type 1 has created";
    }
    int colorOfCar() override {
      return BLACK;
    }
    int speedOfCar() override {
      return 200;
    }
    int priceOfCar() override {
      return 5500000;
    }
    bool whatIsSalon() override {
      return POOR;
    }
};

/**
 * Базовый интерфейс другого продукта. Все продукты могут взаимодействовать друг
 * с другом, но правильное взаимодействие возможно только между продуктами одной
 * и той же конкретной вариации.
 */
class Autobus {
  /**
   * Продукт B способен работать самостоятельно...
   */
 public:
  virtual ~Autobus(){};
  virtual string UsefulBus() const = 0;
  /**
   * ...а также взаимодействовать с Продуктами A той же вариации.
   *
   * Абстрактная Фабрика гарантирует, что все продукты, которые она создает,
   * имеют одинаковую вариацию и, следовательно, совместимы.
   */
  virtual string AnotherUsefulBus(const Car &collaborator) const = 0;
};

/**
 * Конкретные Продукты создаются соответствующими Конкретными Фабриками.
 */
class AudiBus : public Autobus {
 public:
    string UsefulBus() const override {
    return "The Audi Bus has created";
  }
  /**
   * Продукт B1 может корректно работать только с Продуктом A1. Тем не менее, он
   * принимает любой экземпляр Абстрактного Продукта А в качестве аргумента.
   */
  std::string AnotherUsefulBus(const Car &collaborator) const override {
    const string result = collaborator.UsefulCar();
    return "The result of the B1 collaborating with ( " + result + " )";
  }
};

class BMWBus : public Autobus {
 public:
    string UsefulBus() const override {
    return "The BMW Bus has created";
  }
  /**
   * Продукт B2 может корректно работать только с Продуктом A2. Тем не менее, он
   * принимает любой экземпляр Абстрактного Продукта А в качестве аргумента.
   */
  std::string AnotherUsefulBus(const Car &collaborator) const override {
    const std::string result = collaborator.UsefulCar();
    return "The result of the B2 collaborating with ( " + result + " )";
  }
};

/**
 * Интерфейс Абстрактной Фабрики объявляет набор методов, которые возвращают
 * различные абстрактные продукты. Эти продукты называются семейством и связаны
 * темой или концепцией высокого уровня. Продукты одного семейства обычно могут
 * взаимодействовать между собой. Семейство продуктов может иметь несколько
 * вариаций, но продукты одной вариации несовместимы с продуктами другой.
 */
class AbstractFactory {
 public:
  virtual Car *CreateCar() const = 0;
  virtual Autobus *CreateBus() const = 0;
};

/**
 * Конкретная Фабрика производит семейство продуктов одной вариации. Фабрика
 * гарантирует совместимость полученных продуктов. Обратите внимание, что
 * сигнатуры методов Конкретной Фабрики возвращают абстрактный продукт, в то
 * время как внутри метода создается экземпляр конкретного продукта.
 */
class ConcreteFactory1 : public AbstractFactory {
 public:
  Car *CreateCar() const override {
    return new AudiCar();
  }
  Autobus *CreateBus() const override {
    return new AudiBus();
  }
};
class ConcreteFactoryTypes1 : public ConcreteFactory1 {
 public:
  Car *CreateCar() const override {
    return new AudiCar();
  }
  Autobus *CreateBus() const override {
    return new AudiBus();
  }
};

/**
 * Каждая Конкретная Фабрика имеет соответствующую вариацию продукта.
 */
class ConcreteFactory2 : public AbstractFactory {
 public:
  Car *CreateCar() const override {
    return new BMWCar();
  }
  Autobus *CreateBus() const override {
    return new BMWBus();
  }
};

/**
 * Клиентский код работает с фабриками и продуктами только через абстрактные
 * типы: Абстрактная Фабрика и Абстрактный Продукт. Это позволяет передавать
 * любой подкласс фабрики или продукта клиентскому коду, не нарушая его.
 */

void ClientCode(const AbstractFactory &factory) {
  const Car *car = factory.CreateCar();
  const Autobus *bus = factory.CreateBus();
  std::cout << bus->UsefulBus() << "\n";
  std::cout << bus->AnotherUsefulBus(*car) << "\n";
  delete car;
  delete bus;
}

int main() {
  std::cout << "Client: Testing client code with the first factory type:\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;
  std::cout << std::endl;
  std::cout << "Client: Testing the same client code with the second factory type:\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}
