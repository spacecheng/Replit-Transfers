import random
tries = 3
def check():
  if tries == 0:
    print ("game over")
    print(onerandnum, tworandnum, threerandnum)
    exit()
  else:
    print("")
#G = game, C = calculation for word, N = 1st and 2nd range starters and enders
print("welcome ta a fortune telling number guessing game")
print("")
print ("there will be 3 guessing games before the fortune")
oneGoneN = int(input("pick a starting range integer for the first game"))
oneGtwoN = int(input("pick a ending range integer fort the first game"))
onerandnum = random.randint(oneGoneN,oneGtwoN)
oneGoneC = (oneGtwoN - oneGoneN)/3 * 1
oneGtwoC = ((oneGtwoN - oneGoneN)/3) * 2
oneGthreeC = ((oneGtwoN - oneGoneN)/3) * 3
if onerandnum < oneGoneC:
  oneword = ("You")
if onerandnum > oneGoneC and onerandnum < oneGtwoC:
  oneword = ("your friend")
if onerandnum > oneGtwoC:
  oneword = ("Your teacher")
input("press enter to continue")
#____________________________________________________________________________
twoGoneN = int(input("pick a starting range integer for the second game"))
twoGtwoN = int(input("pick a ending range integer fort the second game"))
tworandnum = random.randint(twoGoneN,twoGtwoN)
twoGoneC = (twoGtwoN - twoGoneN)/3 * 1
twoGtwoC = ((twoGtwoN - twoGoneN)/3) * 2
twoGthreeC = ((twoGtwoN - twoGoneN)/3) * 3
if tworandnum < twoGoneC:
  twoword = ("might")
if tworandnum > twoGoneC and tworandnum < twoGtwoC:
  twoword = ("will")
if tworandnum > twoGtwoC:
  twoword = ("won't")
input("press enter to continue")
#__________________________________________________________________________
threeGoneN = int(input("pick a starting range integer for the third game"))
threeGtwoN = int(input("pick a ending range integer fort the thrid game"))
threerandnum = random.randint(threeGoneN,threeGtwoN)
threeGoneC = (threeGtwoN - threeGoneN)/3 * 1
threeGtwoC = ((threeGtwoN - threeGoneN)/3) * 2
threeGthreeC = ((threeGtwoN - threeGoneN)/3) * 3
if threerandnum < threeGoneC:
  threeword = ("yell today")
if threerandnum > threeGoneC and threerandnum < threeGtwoC:
  threeword = ("be annoying today")
if threerandnum > threeGtwoC:
  threeword = ("fail today")
input("press enter to continue")
#_____________________________________________________________
guessedone = True
while guessedone == True:
  guessone = int(input("guess the 1st games number"))
  if guessone == onerandnum: 
    print("correct")
    tries = 3
    guessedone = False
  else:
    tries = tries - 1
    if guessone > onerandnum:
      print ("the number is smaller")
    elif guessone < onerandnum:
      print("the number is bigger")
    print (tries,"tries remaning")
    check()
#_____________________________________________________________________________
input("press enter to continue")
guessedtwo = True
while guessedtwo == True:
  guesstwo = int(input("guess the 2nd games number"))
  if guesstwo == tworandnum:
    print("correct")
    tries = 3
    guessedtwo = False
  else:
    tries = tries - 1    
    if guesstwo > tworandnum:
      print ("the number is smaller")
    elif guesstwo < tworandnum:
      print("the number is bigger")
    print(tries,"tries remaning")
    check()\
#______________________________________________________________________________
input("press enter to continue")
guessedthree = True
while guessedthree == True:
  guessthree = int(input("guess the 3rd games number"))
  if guessthree == onerandnum:
    print("correct")
    guessedthree = False
  else:
    tries = tries - 1
    if guessthree > threerandnum:
      print ("the number is smaller")
    elif guessthree < threerandnum:
      print("the number is bigger")
    print (tries,"tries remaning")
    check()
print("the fortune is",oneword,twoword,threeword)
