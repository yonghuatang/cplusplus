# include <iostream>
# include <string>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        Person() {
            cout << "An object is created." << endl;
        }   // Constructor

        void set_name(string myname) {
            name = myname;
        }

        string get_name() {
            return name;
        }

        void set_age(int myage) {
            age = myage;
        }

        int get_age() {
            return age;
        }

};

class Customer : public Person {   // subclass or derived class
    public:
        
        
};


int main() {
    Person person1;
    person1.set_name("John Doe");
    person1.set_age(23);
    cout << person1.get_name() << endl;
    cout << person1.get_age() << endl;
    return 0;
}
