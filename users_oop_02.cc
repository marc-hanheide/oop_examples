#include <iostream>
#include <string>
#include <vector>

// one feature that C++ has on top of C is namespaces. Here we use the "std" namespace
// to avoid having to write std::string all the time.
using namespace std;

class User {
  protected:
    // declaring all attributes of this class
    string last_name;
    string first_name;
    string email;

  public:  
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
  protected:
    string student_id;
    unsigned int starting_year;
  public:
    void setId(string id) {
        this->student_id = id;
    }
    void setStartingYear(unsigned int year) {
        this->starting_year = year;
    }
};

// We can do the same for the Staff class. Again, just *extending* the base 
// class with the additional methods and attributes required.
class Staff : public User {
  protected:
    string phone;
  public:
    void setPhone(string phone) {
        this->phone = phone;
    }
};

// And the same for the Administrator
class Administrator : public User {
  protected:
    string role;
  public:
    void setRole(string role) {
        this->role = role;
    }
};


int main() {
    Student student1;  // instantiate object of type Student and assign to variable student1
    student1.setName("Homer", "Simpson");  // Call the methods to set parameters
    student1.setEmail("hsimpson@springfield.edu");  
    student1.setId("SIM2343342");

    Student student2;  // instantiate object of type Student and assign to variable student2
    student2.setName("Martin", "Meyer");  // Call the methods to set parameters
    student2.setEmail("mmeyer@springfield.edu");  
    student2.setId("MEY8284342");
    student2.setStartingYear(2019);

    Staff staff1;      // instantiate object of type Staff and assign to variable staff1
    staff1.setName("Daniel", "Cobham");  // Call the methods to set parameters
    staff1.setEmail("dcobham2323@gmail.com");  
    staff1.setPhone("+43 4534234275");

    // this method would be called when a user logs in, e.g.:
    staff1.authenticate();

    // Now as all of these objects are *also* of type "User", we can assign them
    // a list of Users:
    vector<User> all_users;

    all_users.push_back(student1);
    all_users.push_back(student2);
    all_users.push_back(staff1);
    
    cout << "number of users in list: " << all_users.size() << endl;
    for(unsigned int i = 0; i<all_users.size(); i++) {
        // we can now treat all users the same, irrespective if they 
        // are students, staff, or administrators
        all_users[i].authenticate();
    }


  return 0;
}
