#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace std;

class pet {
private:
  string name;
  int hunger, happy, energy;
  double age;

public:
  pet(string n, int h, int ha, int e, double a) {
    if (a <= 0) {
      cout << "pet can't have 0 or negative age" << endl;
      return;
    }
    setname(n);
    hunger_level(h);
    happiness_level(ha);
    energy_level(e);
    age_level(a);
  }
  pet(){

  }
  void setname(string n) { name = n; }
  void hunger_level(int h) { hunger = h; }
  void happiness_level(int ha) { happy = ha; }
  void energy_level(int e) { energy = e; }
  void age_level(double a) { age = a; }
  void feed() {
    hunger = std::max(0, hunger - 20);
    happy = std::min(100, happy + 10);
    energy = std::max(0, energy - 10);
    if (age > 10) {
      happy = std::min(0, happy - 10);
      energy = std::max(0, energy - 10);
    }
  }
  void play() {
    happy = std::min(100, happy + 20);
    hunger = std::max(0, hunger - 15);
    energy = std::max(0, energy - 20);
    if (age > 10) {
      hunger = std::max(0, hunger - 15);
      energy = std::max(0, energy - 10);
    }
  }
  void rest() {
    age = age + 0.5;
    energy = std::min(100, energy + 30);
    happy = std::max(0, happy - 15);
    if (age > 10) {
      hunger = std::max(0, hunger - 10);
      happy = std::min(0, happy - 10);
      energy = std::max(100, energy + 20);
    }
  }
  void get_info() {
    if (hunger > 100) {
      hunger_level(100);
    } else if (happy > 100) {
      happiness_level(100);
    } else if (energy > 100) {
      energy_level(100);
    } else if (hunger < 0) {
      hunger_level(0);
    } else if (happy < 0) {
      happiness_level(0);
    } else if (energy < 0) {
      energy_level(0);
    }

    cout << "Name : " << name << endl;
    cout << "Hunger level : " << hunger << endl;
    cout << "Happiness level : " << happy << endl;
    cout << "Energy level : " << energy << endl;
    cout << "Age of pet : " << age << endl;
  }
  void saveToFile() const {
    std::ofstream file(name + ".txt");
    file << name << "\n"
         << hunger << "\n"
         << happy << "\n"
         << energy << "\n"
         << age << "\n";
    file.close();
  }
  void loadFromFile(const std::string &fileName) {
    std::ifstream file(fileName);
    if (file.is_open()) {
      file >> name >> hunger >> happy >> energy >> age;
      file.close();
    } else {
      throw std::invalid_argument("Unable to open file: " + fileName);
    }
  }
};

int main() {
  //   int d = 1;
  //   cout << "Welcome to petsvilla" << endl;
  //   while (d) {
  //     cout << "1. Feed a pet" << endl;
  //     cout << "2. Play with a pet" << endl;
  //     cout << "3. Let a pet rest" << endl;
  //     cout << "4. Info of a pet" << endl;
  //     cout << "5. Enter new pet" << endl;
  //   }
  pet a;
  a.loadFromFile("mohit.txt");
  a.get_info();
}