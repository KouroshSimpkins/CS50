"""an implementation of the credit problem in Python"""

import re
import sys

INVALID = True

while INVALID:
    try:
        number = int(input("Number: "))
        NDIGITS = len(str(number))

        # Check if the number is 13, 15 or 16 digits long using regular expressions
        if re.search(r'^\d{13,16}$', str(number)):
            INVALID = False
        else:
            print("INVALID\n")
            sys.exit()

    except ValueError:
        print("INVALID\n")
        sys.exit()


# Perform luhn algorithm on the given value, where the argument of the function is "value"
# First, split the value into a list of digits
def luhn_algorithm(value):
    """perform luhn algorithm on the given value, where the argument of the function is "value"""
    digits = [int(x) for x in str(value)]
    digits.reverse()
    for i in range(1, len(digits), 2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9
    return sum(digits) % 10 == 0


# Check the first two digits of the number to determine the type of card
def check_type(number):
    """check the first two digits of the number to determine the type of card"""
    if number[0] == '4':
        return 'VISA\n'
    elif number[0] == '5' and number[1] in ['1', '2', '3', '4', '5']:
        return 'MASTERCARD\n'
    elif number[0] == '3' and number[1] in ['4', '7']:
        return 'AMEX\n'
    else:
        return 'INVALID\n'

if luhn_algorithm(number):
    print(check_type(str(number)))
else:
    print('INVALID\n')
