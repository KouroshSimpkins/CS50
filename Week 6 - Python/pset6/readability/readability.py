"""A program that computes the coleman-liau index of a given piece of text, received as an input."""

import re

TEXT = input("Text: ")


# return the number of letters in the text, excluding spaces
def count_letters(text):
    """return the number of letters in the text"""
    # Using regex, find the number of letters in the text.
    letters = 0
    for i in range(len(text)):
        if re.match("[a-zA-Z]", text[i]):
            letters += 1

    return letters


# return the number of words in the text
def count_words(text):
    """return the number of words in the text"""
    return len(text.split())


# return the number of sentences in the text
def count_sentences(text):
    """return the number of sentences in the text"""
    return text.count(".") + text.count("!") + text.count("?")


# compute the colman-liau index
def coleman_liau_index(text):
    """compute the colman-liau index"""
    L = count_letters(text) / count_words(text) * 100
    S = count_sentences(text) / count_words(text) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    # Round index to the nearest whole number
    index = round(index)
    return index

# if the index is less than 1, print "Before Grade 1"
# if the index is between 1 and 16, print "Grade {0}"
# if the index is greater than 16, print "Grade 16+"
def print_grade(index):
    """print the grade of the text"""
    if index < 1:
        print("Before Grade 1")
    elif index >= 1 and index <= 16:
        print("Grade {0}".format(int(index)))
    else:
        print("Grade 16+")


# print the index
print_grade(coleman_liau_index(TEXT))
