#include <iostream>
#include <string>
using namespace std;

class pet {
    private:
        string name;
        int hunger, happy, energy;
        double age;
    public:
        pet(string n,int h,int ha,int e,double a){
            if (a<=0) {
                cout<<"pet can't have 0 or negative age"<<endl;
                return;
            }
            setname(n);
            hunger_level(h);
            happiness_level(ha);
            energy_level(e);
            age_level(a);
        }
        void setname(string n){
            name = n;
        }
        void hunger_level(int h){
            hunger = h; 
        }
        void happiness_level(int ha){
            happy = ha;
        }
        void energy_level(int e){
            energy = e;
        }
        void age_level(double a){
            age = a;
        }
        void feed(){
            hunger = hunger-10;
            happy = happy+20;
            energy = energy-15;
            if (age>10) {
                happy = happy-10;
                energy = energy-10;
            }
        }
        void play(){
            hunger = hunger-10;
            happy = happy+20;
            energy = energy-15;
            if (age>10) {
                happy = happy-10;
                energy = energy-10;
            }
        }
        void rest(){
            age = age+0.5;
            happy = happy-10;
            energy = energy+15;
            if (age>10) {
                happy = happy-10;
                energy = energy-10;
                hunger = hunger+20;
            }
        }
        void get_info(){
            if (hunger>100) {
                hunger_level(100);
            }
            else if (happy>100) {
                happiness_level(100);
            }
            else if (energy>100) {
                energy_level(100);
            }
            else if (hunger<0) {
                hunger_level(0);
            }
            else if (happy<0) {
                happiness_level(0);
            }
            else if (energy<0) {
                energy_level(0);
            }

            cout<<"Name : "<<name<<endl;
            cout<<"Hunger level : "<<hunger<<endl;
            cout<<"Happiness level : "<<happy<<endl;
            cout<<"Energy level : "<<energy<<endl;
            cout<<"Age of pet : "<<age<<endl;
        }
};

int main() {
    int d=1;
    cout<<"Welcome to petsvilla"<<endl;
    while (d) {
        cout<<"1. Feed a pet"<<endl;
        cout<<"2. Play with a pet"<<endl;
        cout<<"3. Let a pet rest"<<endl;
        cout<<"4. Info of a pet"<<endl;
        cout<<"5. Enter new pet"<<endl;
    }
}