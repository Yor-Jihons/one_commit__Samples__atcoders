import sys

# 0. Gets the command-line arguments.
args = sys.argv
if len( args ) <= 1:
    print( "[CMD]\n$ Python InstallTestor.py <PROJECT_NAME> <NUMBER_OF_TESTCASE>" )
    sys.exit( -1 )

# 1. Reads the file as a CSV file.
# 2. Loops for number of lines
#     2.1. Writes the file "testor" (as a makefile).
#     2.2. Writes the file makefile (as a main makefile).
