class Person:
    def __init__(self):
        self.mobile = 0
        self.name = ""

    def read_data(self):
        self.name = input("Enter name: ")
        self.mobile = int(input("Enter mobile number: "))

    def put_data(self):
        print(f"\t|\t{self.name}\t|\t{self.mobile}\t\t|")

class HashTable:
    def __init__(self):
        self.max = 10
        self.ht = [Person() for _ in range(self.max)]

    def hash(self, key):
        return key % 10

    def insert_l(self, person):
        pos = self.hash(person.mobile)
        if self.ht[pos].mobile == 0:
            self.ht[pos] = person
        else:
            for i in range(self.max):
                pos = (self.hash(person.mobile) + (7 - person.mobile % 7)) % 10
                if self.ht[pos].mobile == 0:
                    self.ht[pos] = person
                    return
            print("The hashtable is full!")
            
    def insert_q(self, person):
        pos = self.hash(person.mobile)
        if self.ht[pos].mobile == 0:
            self.ht[pos] = person
        else:
            for j in range(self.max):
                n_pos= pos+j*j%10
                 
                if self.ht[pos].mobile == 0:
                    self.ht[pos] = person
                    return
            print("The hashtable is full!")

    def search(self, key):
        pos = self.hash(key)
        if self.ht[pos].mobile == key:
            print("Record found!")
            print("|Sr.no. |\tName\t|\tMobile Number\t|")
            print(f"|{pos}", end="")
            self.ht[pos].put_data()
        else:
            for i in range(self.max):
                pos = (self.hash(key) + (7 - key % 7)) % 10
                if self.ht[pos].mobile == key:
                    print("Record found!")
                    print("|Sr.no. |\tName\t|\tMobile Number\t|")
                    print(f"|{pos}", end="")
                    self.ht[pos].put_data()
                    return
            print("Record not found!")

    def delete_record(self, key):
        pos = self.hash(key)
        if self.ht[pos].mobile == key:
            self.ht[pos].mobile = 0
            self.ht[pos].name = ""
            print("Record deleted successfully!")
        else:
            for i in range(self.max):
                pos = (self.hash(key) + (7 - key % 7)) % 10
                if self.ht[pos].mobile == key:
                    self.ht[pos].mobile = 0
                    self.ht[pos].name = ""
                    print("Record deleted successfully!")
                    return
            print("Record not found!")

    def display(self):
        print("The contents of the hashtable are: ")
        print("|Sr.no. |\tName\t|\tMobile Number\t|")
        for i in range(self.max):
            print(f"|{i}", end="")
            self.ht[i].put_data()

if __name__ == "__main__":
    h = HashTable()

    while True:
        print("\nOptions:\n1. Insert Data using linear probing\n2.Insert Data using quadratic probing \n3.Search\n4. Delete\n5. Display\n6. Exit")
        choice = int(input("Enter your choice: "))
        
        if choice == 1:
            p = Person()
            p.read_data()
            h.insert_l(p)
        elif choice == 2:
            p = Person()
            p.read_data()
            h.insert_q(p)            
        elif choice == 3:
            key = int(input("Enter the phone number that you want to search: "))
            h.search(key)
        elif choice == 4:
            key = int(input("Enter the phone number of the person whose record you want to delete: "))
            h.delete_record(key)
        elif choice == 5:
            h.display()
        elif choice == 6:
            break
