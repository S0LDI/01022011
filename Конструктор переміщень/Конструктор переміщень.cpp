#include <iostream>
#include <vector>

class Ion {
public:
    Ion(char charge, int valence) : charge_(charge), valence_(valence) {
        std::cout << "Ion constructor called" << std::endl;
    }

    Ion(const Ion& other) : charge_(other.charge_), valence_(other.valence_) {
        std::cout << "Ion copy constructor called" << std::endl;
    }

    Ion(Ion&& other) : charge_(other.charge_), valence_(other.valence_) {
        std::cout << "Ion move constructor called" << std::endl;
    }

    Ion& operator=(const Ion& other) {
        std::cout << "Ion copy assignment operator called" << std::endl;
        charge_ = other.charge_;
        valence_ = other.valence_;
        return *this;
    }

    Ion& operator=(Ion&& other) {
        std::cout << "Ion move assignment operator called" << std::endl;
        charge_ = other.charge_;
        valence_ = other.valence_;
        return *this;
    }

    ~Ion() {
        std::cout << "Ion destructor called" << std::endl;
    }

    char getCharge() const {
        return charge_;
    }

    int getValence() const {
        return valence_;
    }

private:
    char charge_;
    int valence_;
};

int main() {
    std::vector<Ion> ions;
    ions.emplace_back('-', 1);
    ions.emplace_back('+', 2);
    ions.emplace_back('-', 3);
    ions.emplace_back('+', 4);
    ions.emplace_back('-', 5);
    ions.emplace_back('+', 6);
    ions.emplace_back('-', 7);

    std::vector<Ion> reactingIons;
    std::vector<Ion> nonReactingIons;

    for (auto& ion : ions) {
        if (ion.getCharge() == '-' && ion.getValence() == 1) {
            reactingIons.emplace_back(std::move(ion));
        }
        else if (ion.getCharge() == '+' && ion.getValence() == 2) {
            reactingIons.emplace_back(std::move(ion));
        }
        else {
            nonReactingIons.emplace_back(std::move(ion));
        }
    }

    std::cout << "Reacting ions: ";
    for (auto& ion : reactingIons) {
        std::cout << ion.getCharge() << ion.getValence() << " ";
    }
    std::cout << std::endl;

    std::cout << "Non-reacting ions: ";
    for (auto& ion : nonReactingIons) {
        std::cout << ion.getCharge() << ion.getValence() << " ";
    }
    std::cout << std::endl;

    return 0;
}
