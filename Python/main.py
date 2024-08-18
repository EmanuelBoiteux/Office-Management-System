from file_functions import createStructure, generateOutput
from building_functions import emptyOffices, resolveConflicts
import sys

def main():
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    result = createStructure(input_file)
    building = result[0]
    conflicts = result[1]    
    empty = emptyOffices(building)
    final_result = resolveConflicts(conflicts, empty, building)
    generateOutput(final_result, output_file)

if __name__ == "__main__":
    main()
