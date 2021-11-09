"""Write a program that will take a sequence of DNA and a CSV file containing
STR counts for a list of individuals and then output to whom the DNA (most likely)
belongs"""

import csv

# The program should take 2 command line arguments:
# a DNA sequence and a CSV file containing STR counts

def jls_extract_def(csv_file):
    """function that extracts data from a CSV file"""
    # the first column will be the word name
    # the remaining columns will be the STR sequences themselves
    with open(csv_file, 'r') as csv_file:
        csv_reader = csv.reader(csv_file)
        csv_data = list(csv_reader)
    return csv_data


def main(argv):
    """The main function of the program"""
    # The program should take 2 command line arguments:
    # a DNA sequence and a CSV file containing STR counts
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    csv_file = argv[1]
    dna_sequence = argv[2]

    # Check if the dna_sequence is a txt file
    if dna_sequence.endswith('.txt'):
        with open(dna_sequence, 'r') as dna_file:
            dna_sequence = dna_file.read()
    else:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    # Check if csv_file is a csv file
    if csv_file.endswith('.csv'):
        csv_data = jls_extract_def(csv_file)
    else:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
