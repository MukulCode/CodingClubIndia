print ("1. Temp")
print ("2. speed")
print ("3. area")

aa= int(input("want to convert in "))

def temp(t):
    
    switcher = {
        1: (((b*9)/5)+32),
        2: (((b-32)*5)/9),
    }
    return switcher.get(t, "nothing")
def Speed(s):
    switcher ={
        
       
        1: ((b*5)/18),
        2: ((b*18)/5),
    }
    return switcher.get(s, "nothing")

def area(a):
    switcher ={
        
        
        1: (b*39.37),
        2: (b*3.281),
        3: (b*10.764),
        4: (b*0.0001),
        5: (b*0.000247),
    }
    return switcher.get(a, "nothing")

if (aa==1):
    print ("1. degree C to degree F")
    print ("2. degree F to degree C")
    t=int(input("enter the converter number "))
    b=int(input("enter the data "))
    print(temp(t))

elif (aa==2):
    print ("1. km/hr to m/s")
    print ("2. m/s to km/hr")
    s=int(input("enter the converter number "))
    b=int(input("enter the data "))
    print(Speed(s))

elif (aa==3):
    print ("1. m to inch")
    print ("2. m to feet")
    print ("3. m.sq to sq.feet")
    print ("4. m.sq to hectare")
    print ("5. m.sq to acre")
    a=int(input("enter the converter number "))
    b=int(input("enter the data "))
    print(area(a))
    
