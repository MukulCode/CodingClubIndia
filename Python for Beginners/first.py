#Exercise 1- Taking input from user and using print keyword.

name=input('what is your name? ')
print('hi '+ name)                #'+' opertor concatenates two or more strings
colour=input("what's your favourite colour? ")
print(name + ' likes '+ colour)

#typeconversions - to convert string to int ,float.
birth_year=input('birth year: ')           #getting age of person using birth year 
#input is always taken as STRING ,so we need to TYPECAST it to INT
age= 2022-int(birth_year)

print(age)

#to check type of variable
age=20
print(type(age))
name='anmol'
print(type(name))


#Exercise 2- input weight i pounds and converting it in kilo
weight_lbs=input('weight in pound: ')
weight_kg= int(weight_lbs)* 0.45
print(weight_kg)


#strings
name='my name is "anmol taneja"'
print(name)

#to print multiple lines, we use triple quotes
email ='''
 Hi anmol,
 We are glad to tell you that you are selected for interview.
 thanks and regards 
 '''
print(email)


name='my name is anmol taneja'
#to get characters of string form the end, we use -1,-2 ...and so on
print(name[-1])

#to get whole string:                   
print(name[:])

#to get characters b/w 6th and 9th postion excluding 9th position                
print(name[6:9])

#removing first and last occurance
print(name[1:-1])


#formatted strings- used to visualize the output easily    f'.....'
first='anmol'
last='taneja'
message= first + ' [' +last+ '] '+ 'is a coder'
#instead we can write it as
message= f'{first} [{last}] is a coder'

print(message)


#string methods
name='my name is anmol taneja'
#to get length of string
print(len(name))
#to convert to upper or lower case, we use-
name.upper()
name.lower()
#to find first occurance of character or subtsring, we use-
name.find('a')
name.find('anmol')
#to replace character or string we use-
name.replace('anmol','anubhav')
#to check if character or substring is oresent in string or not
print('anmol' in name)




#arithmetic operations
print(10/3)      #gives floating number
print(10//3)     #gives integer
print(10**3)     #10 ki power 3

#math functions, we also have math module having different fucntions for different uses, check here-> chhttps://docs.python.org/3/library/math.html
x=-3.4
print(round(x));
print(abs(x));


#if-else statements
its_hot=False;
its_cold=False;
if its_hot:
    print("It's a hot day, drink a plenty of water")
elif its_cold :
    print("It's a cold day, Wear warm clothes")
else: 
    print("It's a lovely day")



#exercise- you are give credit price, input the condition to have a good credit then calculate the down paymet accordingly

price= 1000000
has_good_credit= input("Enter credit: ")
if bool(has_good_credit)==True:
    down_pay=0.1 *price
else:
    down_pay=0.2 *price

print(f'Down Payment=${down_pay}')  #using formatted string feature



#logical operators
has_hight_income=True
good_credit=False
has_criminal_record=True

#and operator
if has_hight_income and good_credit:
    print("eligible for loan")
else:
    print("not eligible for loan")

#or operator
if has_hight_income or good_credit:
    print("eligible for loan")
else:
    print("not eligible for loan")

#not operator
if has_hight_income and not has_criminal_record:
    print("eligible for loan")
else:
    print("not eligible for loan")



#comparison operators:easy to understand
temperature=30
if temperature>=40:
    print("its a hot day")
else:
    print("its not a hot day")
 
#exercise
name=input("write the name :")
if len(name)<3:
    print("name must be at least 3 characters")
elif len(name) >50:
    print("number can be a maxmum of 50 characters")
else:
    print("name looks good") 



#exrcise- convert given weight form given unit to another unit
weight=input('weight: ')
unit=input("(L)bs or (K)g: ")
if unit=='k' or unit=='K':
    print(f"You are {int(weight)/0.45} pounds")
elif unit=='l' or unit=='L':
    print(f"You are {int (weight)* 0.45} kilos")




#while loops
i=1
while(i<=5):
    print (i * '*')
    i+=1



#guessing game
secret_num=9
i=0
while(i<3):
    guess_num=input("Guess: ")
    if(int(guess_num)==secret_num):
        print("you won")
        break;
    i=i+1  
else:
    print("sorry you failed") 





#Car game
command = ""
while command != "quit":
    command= input(">").lower()
    if command == "help":
        print("start - to start the car")
        print("stop - to stop the car")
        print("quit - to exit")
    elif command == "start":
        print("Car started...Ready to go!")
    elif command == "stop":
        print("Car stopped")
    else:
        print("sorry I did not understand")





#for loop
#sum of elements of array


# nested for loops
for x in range(4):
    for y in range(3):
        print(f'({x},{y})')





#exercise
 
# (make F using for loop)
numbers=[5,2,5,2,2]
for item in numbers:
    output=""

    for i in range(item):
        output+='x'
    print(output)    

# (make L using for loop)
numbers=[1,1,1,1,5]
for item in numbers:
    output=""

    for i in range(item):
        output+='x '
    print(output) 



#Lists
names=['anmol','anubhav','shivansh','ansh']
print(names[2:3])

#modify the list
names[0]='taneja'
print(names)


#find largest number
numbers=[3,5,395,364,98,36]
max=numbers[0]
for item in numbers:
    if item>max:
        max=item 
print(max)



