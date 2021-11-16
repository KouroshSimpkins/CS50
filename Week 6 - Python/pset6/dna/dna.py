"""Write a program that will take a sequence of DNA and a CSV file containing
STR counts for a list of individuals and then output to whom the DNA (most likely)
belongs. An STR stands for a Short Tandem Repeat"""

import csv

# The program should take 2 command line arguments:
# a DNA sequence and a CSV file containing STR counts

def jls_extract_def(csv_file):
    """function that extracts data from a CSV file"""
    # the first column will be the word name
    # the remaining columns will be the STR sequences themselves
    with open(csv_file, 'r') as csv_file: # pylint: disable=unspecified-encoding
        csv_reader = csv.reader(csv_file)
        csv_data = list(csv_reader)
    return csv_data


def STR_Compare(sequence, csv_data):
    """function that compares the dna_sequence to the STR sequences in the csv_data"""

    Max_Repeats = 0
    Max_Repeats_Temp = 0
    Strs_In_Sequence = []
    get_From_Sequence = []

    # Creates a list of all the STRs in the sequence that have the same length as the STR in the csv_data
    for i in range(len(sequence)):
        for j in range(len(csv_data)):
            get_From_Sequence.append(sequence[i:i+j+1])
        
        temp = get_From_Sequence[len(csv_data) - 1]

        if len(temp) == len(csv_data):
            Strs_In_Sequence.append(temp)

        get_From_Sequence = []

    # compare each value in Strs_In_Sequence with the value in csv_data
    for i in range(len(Strs_In_Sequence)):
        if Strs_In_Sequence[i] == csv_data:
            Max_Repeats_Temp += 1
            if Strs_In_Sequence[i+len(csv_data)] == csv_data:
                pass
            else:
                if Max_Repeats_Temp > Max_Repeats:
                    Max_Repeats = Max_Repeats_Temp
                Max_Repeats_Temp = 0
    
    return Max_Repeats


def main(argv):
    """The main function of the program"""
    # The program should take 2 command line arguments:
    # a DNA sequence and a CSV file containing STR counts

    Final_Str_Dictionary = {}

    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1

    csv_file = argv[1]
    dna_sequence = argv[2]

    # Check if the dna_sequence is a txt file
    if dna_sequence.endswith('.txt'):
        with open(dna_sequence, 'r') as dna_file: # pylint: disable=unspecified-encoding
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

    for j in range(len(csv_data[0])):
        if csv_data[0][j] == 'name':
            pass
        else:
            Final_Str_Dictionary[csv_data[0][j]] = STR_Compare(dna_sequence, csv_data[0][j])

    for word in Final_Str_Dictionary:
        for column in csv_data:
            print(column[0], Final_Str_Dictionary[word])

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
