class Person:
    def __init__(self,firstname,lastname):
        self.firstname=firstname
        self.lastname=lastname
    
    def printName(self):
        print(self.firstname, self.lastname)

class Student(Person):
    def __init__(self,first,last,age):
        self.first=first
        self.last=last
        self.age=age
        Person.__init__(self,"Kawshik","Bhai")

    def printStudent(self):
        print(self.first,self.last)


objPerson=Student("Rana", "Bhai",30)
objPerson.printName()
objPerson.printStudent()