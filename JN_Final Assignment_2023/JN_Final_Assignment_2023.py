# Array are remain empty so user can add to arrays
array = []
array_2 = []

# Used to add strings to array_2
def to_do_input_2():
   to_do = str(input("Add to List?: "))
   array_2.append(to_do)
   print("You Added: "+str(to_do))

# Used to see both of your arrays by the press of a number
def all_to_dos():
    list = int(input("Press any number to see full list of both lists: "))  
    print(array, array_2)

# Used to add strings to array
def to_do_input():
   to_do = str(input("Add to List?: "))
   array.append(to_do)
   print("You Added: "+str(to_do))

# Used to see how long the arrays are
def count_to_dos():
    size = len(array, array_2)
    print("This is how long your list is: ")
    print (size)

# Used to delete strings from the arrays
def deleting_to_dos():
    array.remove( input("Type whatever you wrote in your list to delete in the first list: "))
    array_2.remove(input("Type whatever you wrote in your list to delete in the second list: "))

#Used to add array and array_2 to create one singular list
def together():
  array_3 = array + array_2
  print("After you combined the two arrays: ", array_3)

# The main is a loop that will forever ask questions to access the other functions
def main():
     loop = "l"
     while loop == "l":
        print("A = Add to List, ", "A2 = Add to the second list, ", "W = See Whole List, ", "C = Is to see how long your list is, ", "D = Deleting items off your list, ", "T = To add the second list to the first list , ", "E = Ends Program")
        answer = str(input("Enter the letter to see what you want: "))

        if answer == str("A2"):
         to_do_input_2()

        if answer == str("A"):
         to_do_input()

        if answer == str("W"):
         all_to_dos()

        if answer == str("C"):
         count_to_dos()

        if answer == str("D"):
         deleting_to_dos()

        if answer == str("T"):
         together()

        if answer == str("E"):
         break

# Used to show the main function
main()
