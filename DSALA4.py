def create():
    myset = []
    n = int(input("Enter number of elements to add in set: "))
    while (len(myset) < n):
        elem = input("Enter an element to insert in the set: ")
        if elem in myset:
            print("Element already exists in the set.")
        else:
            myset.append(elem)
    return myset
        

def add(myset, elem):
    if elem in myset:
            print("Element already exists in the set.")
    else:
        myset.append(elem)


def remove(myset, elem):
    if elem in myset:
        myset.remove(elem)
    else:
        print("Element does not exist in the list.")    
                    

def contains(myset, elem):
    if elem in myset:
        print("TRUE")
    else:
        print("FALSE")


def size(myset):
    count = 0
    myit = iter(myset)
    for i in myit:
        count += 1
    print(f"There are {count} elements in the set.")
    

def union(set1, set2):
    set3 = []
    for i in set1:
        set3.append(i)
    for j in set2:
        if j not in set1:
            set3.append(j)
    return set3


def intersection(set1, set2):
    set3 = []
    for i in set1:
        if i in set2:
            set3.append(i)
    return set3
    
    
def difference(set1, set2):
    set3 = []
    for i in set2:
        if i not in set1:
            set3.append(i)
    return set3


#while(True):
#    print("----------MENU----------\n1) Create sets.\n2) Remove an element.\n3) Check whether an element exists in a set or not.\n4) Check size of set.\n5) Union.\n6) Intersection.\n7) Difference.\n8) Exit.")
#    ch = int(input("Enter your choice: "))
#    if ch == 1:
#        print("Create set 1: ")
#        one = create()
#        print("\n\nCreate set 2: ")
#        two = create()
#    elif ch == 2:
