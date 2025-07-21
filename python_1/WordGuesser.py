import random

# List of colors to choose from
words = ["red", "orange", "yellow", "green", "blue", "purple", "indigo", "violet", "magenta", "pink", "gray", "black", "brown", "silver", "maroon", "burgundy", "bronze", "golden", "beige", "navy", "white", "coral", "cerulean", "scarlet", "turquoise", "saffron", "crimson", "periwinkle", "teal", "amethyst", "charcoal", "lavender", "sage", "vermillion", "emerald", "ginger", "platinum", "skyblue"]

# Picks a random color from the list above that is between 3 and 10 letters
def choose_word ():  
    valid_words = [word for word in words if 3 <= len(word) <=10]
    return random.choice(valid_words)

# Runs one full round of the game, including displaying the dashes for the word, allowing player to guess, responds accordingly to the guesses (correct/incorrect), and keeps track of tries.
def play_game():
    word = choose_word()
    guessed = ["_"] * len(word) # Hidden version of color
    attempts_left = 10
    guessed_letters = [ ]

    print("\nWelcome to ColorGuesser!")
    print("I have chosen a color with", len(word), "letters.")
    print("You have 10 tries to guess letters or the full word!")

    while attempts_left > 0:
        print("\nColor:", " ".join(guessed))
        print("Tries left:", attempts_left)
        print("Guessed letters:", ", ".join(guessed_letters))

        guess = input("Enter a letter or guess the full word: ").lower()
        if len(guess) == 1:
            if guess in guessed_letters:
                print("You already guessed that letter.")
            elif guess in word:
                print("Good guess!")
                guessed_letters.append(guess)
                for i in range(len(word)):
                    if word[i] == guess:
                        guessed[i] = guess
                if "_" not in guessed:
                    print("\n🎉 You guessed the color:", word)
                    return
            else:
                print("Wrong letter.")
                guessed_letters.append(guess)
                attempts_left -= 1
        elif len(guess) == len(word):
            if guess == word:
                print("\n🎉 You guessed the color correctly:", word)
                return
            else:
                print("Wrong guess.")
                attempts_left -= 1
        else:
            print("Invalid input.")

    print("\n❌ You're out of tries! The color was:", word)

# This function allows the program to run and gives the option to play again (loop)
def main(): 
    play_again = "yes"
    while play_again.lower() == "yes":
        play_game()
        play_again = input("\nDo you want to play again? (yes/no): ")
    print("Thanks for playing!")

main()