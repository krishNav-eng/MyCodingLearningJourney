#include <iostream>
#include <vector>
using namespace std;

class Human {
    public:
        string name;
        int age;
        vector<string> hobbies;
        vector<string> friends;

        void introduce() {
            cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
        }

        void eat(string food) {
            cout << name << " is eating " << food << "." << endl;
        }

        void drink(string beverage) {
            cout << name << " is drinking " << beverage << "." << endl;
        }

        void sleep(int hours) {
            cout << name << " is sleeping for " << hours << " hours." << endl;
        }

        void work(string job) {
            cout << name << " is working as a " << job << "." << endl;
        }

        void makeNewFriend(Human& newFriend) {
            friends.push_back(newFriend.name);
            cout << name << " made a new friend: " << newFriend.name << endl;
        }

        void loveDoing(string hobby) {
            hobbies.push_back(hobby);
            cout << name << " loves " << hobby << "!" << endl;
        }
 
};


int main() {
    // to create an object we use the class name followed by the object name

    Human Abhijay;
    
}