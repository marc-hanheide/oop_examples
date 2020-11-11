
class User: 
    last_name = ''
    first_name = ''
    email = ''

    def authenticate(self):
        # some logic to authenticate should be added here, currently it does nothing
        # e.g. we can access the attributes of the object to authenticate via email
        # address. Here, we just print it out instead of actually logging in anywhere:
        print("logging in user " 
            + self.first_name + " " + self.last_name
            + " with email address "
            + self.email)
    
    
    def setName(self, fn, ln):
        # "self" is the reference, pointing the current object the
        # method is called on. We are assigning the parameter values from this method
        # to the attributes of THIS object here
        self.last_name = ln
        self.first_name = fn
    
    
    def setEmail(self, email):
        # same as above. Methods like this one that just set internal attributes are called
        # setter methods. To access internal attributes, we can also write getter methods.
        # Think how one could look like!
        self.email = email
    

# Now we can generate a subclass "Student" from the base class "User".
# All methods and attributes of the base class are inherited and down
# have to be written again!
class Student(User):
    student_id = ''
    starting_year = 0 
    def setId(self, id):
        self.student_id = id

    def setStartingYear(self, year):
        self.starting_year = year

# We can do the same for the Staff class. Again, just *extending* the base 
# class with the additional methods and attributes required.
class Staff(User):
    phone = ''
    def setPhone(self, phone):
        self.phone = phone;


# And the same for the Administrator
class Administrator(User):
    role = ''
    def setRole(self, role):
        self.role = role

student1 = Student()
student1.setName("Homer", "Simpson")
student1.setEmail("hsimpson@springfield.edu")  
student1.setId("SIM2343342")

student2 = Student()
student2.setName("Martin", "Meyer")
student2.setEmail("mmeyer@springfield.edu")
student2.setId("MEY8284342")
student2.setStartingYear(2019)

staff1 = Staff()
staff1.setName("Daniel", "Cobham")
staff1.setEmail("dcobham2323@gmail.com")
staff1.setPhone("+43 4534234275")

staff1.authenticate()

all_users = []

all_users.append(student1)
all_users.append(student2)
all_users.append(staff1)
    
print("number of users in list: %d" % len(all_users))

for u in all_users:
    u.authenticate()
