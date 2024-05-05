class HashTable:
    def __init__(self):
        self.hash_table = [-1] * 10
        self.count = 0
        self.prob = 0

    def linear(self, key):
        address = key % 10
        while True:
            if self.hash_table[address] == -1:
                self.hash_table[address] = key
                self.count += 1
                break
            else:
                address += 1
                if address == 10:
                    address = 0
            if self.count == 10:
                print("Hash Table is Full")
                break

    def quadratic(self, key):
        address = key % 10
        while True:
            if self.hash_table[address] == -1:
                self.hash_table[address] = key
                self.count += 1
                break
            else:
                for i in range(10):
                    address1 = (address + (i* i)) % 10
                    if address1 == 10:
                        address1 = 0
                    if self.hash_table[address1] == -1:
                        self.hash_table[address1] = key
                        self.count += 1
                        break
            break
            if self.count == 10:
                print("Hash Table is Full")
                break

    def linear_search(self, search):
        address = search % 10
    
        while self.prob < 10:
            if self.hash_table[address] == search:
                print("Found")
                self.prob += 1
                break
            else:
                address += 1
                self.prob += 1
                if address == 10:
                    address = 0
        else:
            print("Not found")

    def quadratic_search(self, search):
        address = search % 10
        self.prob = 0
        while self.prob < 10:
            if self.hash_table[address] == search:
                print("Found")
                self.prob += 1
                break
            else:
                    for i in range(10):
                        address1 = (address + (i* i)) % 10
                        self.prob += 1
                        if address1 == 10:
                            address1=0
                        if self.hash_table[address1] == search:
                            print("Found")
                            break
            break
        else:
            print("Not found")

    def display(self):
        print("Hash Table:", self.hash_table)


if __name__ == "__main__":
    obj1 = HashTable()
    obj2 = HashTable()

    while True:
        print("\n1) Linear")
        print("2) Quadratic")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            obj1.hash_table = [-1] * 10
            obj1.count = 0
            obj1.prob = 0
            n = int(input("Enter Total number of records: "))
            if n<=10:
                for i in range(n):
                    key = int(input("Enter number: "))
                    obj1.linear(key)
            obj1.display()
            search = int(input("Enter the mobile number to be searched: "))
            obj1.linear_search(search)
            print("The comparison required is:", obj1.prob)
        elif ch == 2:
            obj2.hash_table = [-1] * 10
            obj2.count = 0
            obj1.prob = 0
            n = int(input("Enter Total number of records: "))
            if n<=10:
                for i in range(n):
                    key = int(input("Enter number: "))
                    obj2.quadratic(key)
            obj2.display()
            search = int(input("Enter the mobile number to be searched: "))
            obj2.quadratic_search(search)
            print("The comparison required is:", obj2.prob)
        else:
            print("Invalid choice")
