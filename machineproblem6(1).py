#Write the Student Record Program in Python using functions to get record 
# and display records (using 1. Global variables 2. Local variables)

namelst = []
q1lst = []
q2lst = []
q3lst = []

def get_record():

    print("ADD RECORD \n")
    for i in range(1, 2):
        name = input("Student's Name: ")
        q1 = int(input("Input Quiz 1: "))
        q2 = int(input("Input Quiz 2: "))
        q3 = int(input("Input Quiz 3: "))
        namelst.append(name)
        q1lst.append(q1)
        q2lst.append(q2)
        q3lst.append(q3)
        print("\n")

def display():

    print(" Name  Q1 Q2 Q3  Ave  Remarks")
    for i in range(0, 1):
        ave = (q1lst[i] + q2lst[i] + q3lst[i]) / 3

        if ave >= 75.0:
            remarks = "Passed"
        else:
            remarks = "Failed"

        print(str(i + 1) + ".)" + namelst[i] + " " + str(q1lst[i]) + " " + str(q2lst[i]) + " " + str(q3lst[i]) + " " + str("%.2f" % ave) + " " + remarks)
        print("\n")

if __name__ == '__main__':
    print("\n")
    run = True
    while run:
        print("[1] ADD RECORD")
        print("[2] DISPLAY")

        choice = int(input("Enter your choice: "))
        print("\n")

        if choice == 1:
            get_record()
        elif choice == 2:
            display()
        else:
            print("Please enter your choice\n")

