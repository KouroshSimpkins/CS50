isValid = False
while not isValid:
    try:
        height = int(input("Height: "))
        if height < 1 or height > 8:
            print("Height must be between 1 and 8.")
        else:
            isValid = True
    except ValueError:
        print("Height must be an integer.")

# Print a mario pyramid of the specified height, with a reversed pyramid beside it
for i in range(height):
    print(" " * (height - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))

