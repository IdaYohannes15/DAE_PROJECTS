import random

# Loop to play multiple times
play_again = "yes"  # Start the loop
while play_again.lower() == "yes":
    print("\nWelcome to the Guess the Number Game!")
    print("I'm thinking of a number between 1 and 20.")

    # Generate a random number
    secret_number = random.randint(1, 20)

    # Ask the user to guess
    guess = int(input("Take a guess: "))

    # Keep asking until they guess correctly
    while guess != secret_number:
        if guess < secret_number:
            print("Too low!")
        else:
            print("Too high!")
        guess = int(input("Try again: "))

    print("You got it! 🎉")

    # Ask if they want to play again
    play_again = input("Do you want to play again? (yes or no): ")

print("Thanks for playing! 👋")
