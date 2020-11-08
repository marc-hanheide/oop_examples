#include <iostream>
#include <string>
#include <vector>

// one feature that C++ has on top of C is namespaces. Here we use the "std" namespace
// to avoid having to write std::string all the time.
using namespace std;

class User {
    // declaring all attributes of this class
    string last_name;
    string first_name;
    string email;

    void authenticate() {
        // some logic to authenticate should be added here, currently it does nothing
        // e.g. we can access the attributes of the object to authenticate via email
        // address. Here, we just print it out instead of actually logging in anywhere:
        cout << "logging in user "
            << this->first_name << " " << this->last_name 
            << " with email address " << this->email
            << endl;
    }
    
    void setName(string fn, string ln) {
        // "this" is the pointer (like in "C"), pointing the current object the
        // method is called on. We are assigning the parameter values from this method
        // to the attributes of THIS object here
        this->last_name = ln;
        this->first_name = fn;
    }
    
    void setEmail(string email) {
        // same as above. Methods like this one that just set internal attributes are called
        // setter methods. To access internal attributes, we can also write getter methods.
        // Think how one could look like!
        this->email = email;
    }
};

// Now we can generate a subclass "Student" from the base class "User".
// All methods and attributes of the base class are inherited and down
// have to be written again!
class Student : public User {
    string student_id;

    void setId(string id) {
        this->student_id = id;
    }
};

// We can do the same for the Staff class. Again, just *extending* the base 
// class with the additional methods and attributes required.
class Staff : public User {
    string phone;

    void setPhone(string phone) {
        this->phone = phone;
    }
};

// And the same for the Administrator
class Administrator : public User {
    string role;
    void setRole(string role) {
        this->role = role;
    }
};


int main() {
    Student student1;  // instantiate object of type Student and assign to variable student1
    Student student2;  // instantiate object of type Student and assign to variable student2
    Staff staff1;      // instantiate object of type Staff and assign to variable staff1
    return 0;
}
