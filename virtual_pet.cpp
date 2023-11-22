#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

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
  pet(string n) { setname(n); }
  void setname(string n) { name = n; }
  string getname() { return name; }
  void hunger_level(int h) { hunger = h; }
  void happiness_level(int ha) { happy = ha; }
  void energy_level(int e) { energy = e; }
  void age_level(double a) { age = a; }
  void feed() {
    hunger = max(0, hunger - 20);
    happy = min(100, happy + 10);
    energy = max(0, energy - 10);
    if (age > 10) {
      happy = min(0, happy - 10);
      energy = max(0, energy - 10);
    }
  }
  void play() {
    happy = min(100, happy + 20);
    hunger = max(0, hunger - 15);
    energy = max(0, energy - 20);
    if (age > 10) {
      hunger = max(0, hunger - 15);
      energy = max(0, energy - 10);
    }
  }
  void rest() {
    age = age + 0.5;
    energy = min(100, energy + 30);
    happy = max(0, happy - 15);
    if (age > 10) {
      hunger = max(0, hunger - 10);
      energy = max(100, energy + 20);
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

    cout << "Name : " << name << endl << endl;
    cout << "Hunger level : " << hunger << endl << endl;
    cout << "Happiness level : " << happy << endl << endl;
    cout << "Energy level : " << energy << endl << endl;
    cout << "Age of pet : " << age << endl << endl;
  }
  void saveToFile() const {
    ofstream file(name + ".txt");
    file << name << "\n"
         << hunger << "\n"
         << happy << "\n"
         << energy << "\n"
         << age << "\n";
    file.close();
  }
  void loadFromFile(const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
      file >> name >> hunger >> happy >> energy >> age;
      file.close();
    } else {
      throw invalid_argument("Unable to open file: " + fileName);
    }
  }
};

int main() {
  int d = 1, a;
  string l;
  pet loady("empty");
  pet savy("empty");
  cout << "Welcome to petsvilla" << endl << endl;
  while (d) {
    cout << "1. Load a pet" << endl << endl;
    cout << "2. Play with the pet" << endl << endl;
    cout << "3. Let the pet rest" << endl << endl;
    cout << "4. Feed the pet" << endl << endl;
    cout << "5. Info of the pet" << endl << endl;
    cout << "6. Enter a new pet" << endl << endl;
    cout << "7. Save session" << endl << endl;
    cin >> a;
    if (a == 1) {
      cout << "Which pet do you want to load : ";
      cin >> l;
      loady.loadFromFile(l + ".txt");
    } else if (a == 2) {
      if (loady.getname() == "empty") {
        cout << "Load a pet first" << endl << endl;
      } else {
        loady.play();
        cout << "Levels after this session" << endl << endl;
        loady.get_info();
      }
    } else if (a == 3) {
      if (loady.getname() == "empty") {
        cout << "Load a pet first" << endl << endl;
      } else {
        loady.rest();
        loady.get_info();
      }
    } else if (a == 4) {
      if (loady.getname() == "empty") {
        cout << "Load a pet first" << endl << endl;
      } else {
        loady.feed();
        loady.get_info();
      }
    } else if (a == 5) {
      if (loady.getname() == "empty") {
        cout << "Load a pet first" << endl << endl;
      } else {
        loady.get_info();
      }
    } else if (a == 6) {
      string n;
      int ha, h, e;
      double a;
      cout << "Enter following info of new pet : " << endl << endl;
      cout << "Enter name of pet : " << endl << endl;
      cin >> n;
      cout << "Enter happiness of pet : " << endl << endl;
      cin >> ha;
      cout << "Enter energy of pet : " << endl << endl;
      cin >> e;
      cout << "Enter hungriness of pet : " << endl << endl;
      cin >> h;
      cout << "Enter age of pet : " << endl << endl;
      cin >> a;
      pet newp(n, h, ha, e, a);
      newp.saveToFile();
      loady.loadFromFile(n + ".txt");
    } else if (a == 7) {
      if (loady.getname() == "empty") {
        cout << "Load a pet first" << endl << endl;
      } else {
        loady.saveToFile();
      }
    }
  }
}