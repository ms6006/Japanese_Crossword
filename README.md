# Japanese_Crossword

# Input data

Before solving the puzzle, you need to read the clues from the file. The data in the file is stored in the form: 1 line - the size of the field, after the hint horizontally followed by them vertically. For the input file, we use ifstream InF, read the first line and write the field size to the SizeX, SizeY variables. In the two-dimensional array BHor we write hints horizontally, in the zero element of each line we write the number of hints in this line. In the two-dimensional array BVer we write tips vertically, in the zero element of each line we write the number of tips in this line. We finish working with the input file and close the stream.

# Algorithm

Turning to the algorithm, we consider that we are on the 1st line of hints vertically and 0th line horizontally, a two-dimensional bool-type array M is the crossword solution matrix. We check if all the hints have passed horizontally, if not, then go to the next line horizontally, if yes, then go to the next line vertically and return to the first line horizontally, check if all the hints have passed vertically, if yes , then we output the result.

We count the number of breaks along the vertical and determine where we are.

We check the top, count the number of filled cells (in a given gap), compare the number of filled cells with the hint, if they are equal, then note that the cell does not need to be painted over and increase the number of gaps, if they are not equal, then note that the cell needs to be painted over.
Checking the bottom, counting the number of possible shaded cells. We compare with the size, if we enter the size, then we note that the cell needs to be painted over. We compare the number of gaps with the hint; if there are more of them, then we note that the cell does not need to be painted over.

We do the same actions for the horizontal (check on the right and left).

We designate the state of the cell on the decision matrix and move on to the next cell.

# Solutions

We output the solutions of the crossword puzzle to a file, and also demonstrate it in the console.
