from collections import Counter
from multiprocessing.connection import answer_challenge

while True:
 string = input("Enter words: ")
 char_counts = {}
 count = 0
 
 str=""
 for i in string:
     str=i+str

 for i in string: 
     count+=1

 for char in string:
    if char in char_counts:
        char_counts[char] += 1
    else:
        char_counts[char] = 1

 print("The string '{}' has {} characters".format(string, count))
 print("Original string:", string)
 print("Reversed string:", str)
 for char, count in char_counts.items():
    print("{}: {}".format(char, count))

 cont = input("Do you want to type more words? yes or no? > ")
 if cont == "no":
        break



