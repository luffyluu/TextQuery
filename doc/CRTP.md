template <typename T>
class Animal {
public:
    void speak() {
        static_cast<T*>(this)->makeSound();
    }
};

class Dog: public Animal<Dog> {
public:
    void makeSound() {
        std::cout << "Woof!";
    }
};

class Cat: public Animal<Cat> {
public:
    void makeSound() {
        std::cout << "Meow!";
    }
};

template <typename T>
void letAnimalSpeak(Animal<T>& animal){
    animal.speak();
}

