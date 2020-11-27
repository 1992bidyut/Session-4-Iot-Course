class IOTClass:
    def __init__(self,eeeStudent,cseStudent):
        self.eeeStudent=eeeStudent
        self.cseStudent=cseStudent

    def sumFunction(self):
        add=self.eeeStudent+self.cseStudent
        print(add)

obj = IOTClass(8,12)
obj1 = IOTClass(15,15)

obj.sumFunction()
obj1.sumFunction()

