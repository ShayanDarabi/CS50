# TODO
import cs50

# The user input will be saved in text variable.
text = cs50.get_string("Text: ")

# This block of code counts the number of letters in the text.
letters = 0
for char in text:
    if char.isalpha():
        letters += 1

# We define a variable called words for counting the total words in the text.
# This variable is set to 1 because the last word wouldn't be counted if it had set to 0.
words = 1
for char in text:
    if " " == char:
        words += 1

# The charaters indicate the end of a sentence were stored as a list inside the sentence_indicator.
sentence_indicator = [".", "!", "?"]
sentences = 0
for char in text:
    if char in sentence_indicator:
        sentences += 1

# Calculating the Coleman-Liau formula,
L = (letters / words) * 100
S = (sentences / words) * 100
index = round(0.0588 * L - 0.296 * S -15.8)

# # Printing part
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")

