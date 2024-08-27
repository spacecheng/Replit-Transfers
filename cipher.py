original = input("the word for your password ")
half = original
while len(half)%2 == 0:
 number = int(len(half)/2)
 half = half[:number]
 #print(half)
 half2 = half[number:]
 #print(half)
 #print(half2)
