import random
score = 0
target = random.randint(1, 100)

def guess():
    guess = input("Guess a number between 1 & 100: ")

def win():
    print("Congrats! You guessed it!")
    score += 1
    print("Your score is: " + score)
    replay = input("Do you want to play again? yes/no")
    if replay == "yes":
      guess() 
    else:
      print("Game Over" + "Score = " + score)

def guessEvaluation():
    if target == guess:
      win() 

    elif target > guess:
      print("Guess too high")
      guess()


    else:
      print("Guess too low")
      guess()


print("Welcome to Guess the Number!")
guess()
guessEvaluation()

