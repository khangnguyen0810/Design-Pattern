#include <iostream>

class ChocolateBoiler {
public:
    static ChocolateBoiler& getInstance() {
        static ChocolateBoiler uniqueInstance;
        return uniqueInstance;
    }
 
    void fill() {
        if (isEmpty()) {
            empty = false;
            boiled = false;
            std::cout << "Filling the boiler with chocolate and milk mixture." << std::endl;
        }
    }
 
    void drain() {
        if (!isEmpty() && isBoiled()) {
            empty = true;
            std::cout << "Draining the boiled chocolate and milk." << std::endl;
        }
    }
 
    void boil() {
        if (!isEmpty() && !isBoiled()) {
            boiled = true;
            std::cout << "Bringing the contents to a boil." << std::endl;
        }
    }
 
    bool isEmpty() {
        return empty;
    }
 
    bool isBoiled() {
        return boiled;
    }

private:
    bool empty;
    bool boiled;
 
    ChocolateBoiler() {
        empty = true;
        boiled = false;
    }
 
    // prevent copy construction and assignment
    ChocolateBoiler(const ChocolateBoiler&);
    ChocolateBoiler& operator=(const ChocolateBoiler&);
};

int main() {
    ChocolateBoiler& boiler1 = ChocolateBoiler::getInstance();
    boiler1.fill();
    boiler1.boil();
    boiler1.drain();

    ChocolateBoiler& boiler2 = ChocolateBoiler::getInstance();
    boiler2.fill();
    boiler2.boil();
    boiler2.drain();

    // The two references should be to the same instance of the class
    std::cout << "Are the two references pointing to the same instance? ";
    std::cout << (&boiler1 == &boiler2 ? "Yes" : "No") << std::endl;

    return 0;
}
