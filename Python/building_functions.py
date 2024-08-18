def emptyOffices(building):
    """
    This function takes a dictionary 'building' and returns a list of offices in the building that are empty.
    """
    empty = []
    for floor in building:
        for office in building[floor]:
            if building[floor][office] == []:
                empty.append((floor, office))
    return empty



def resolveConflicts(conflicts, empty, building):
    """
    This function takes the offices with more than one person, the empty offices, and the building, and relocates the people 
    to other empty offices if available, otherwise, it removes them.
    """
    for office in conflicts:
        numPeople = len(office)
        floor = office[0]
        off = office[1]
        while len(building[floor][off]) > 1:
            person = building[floor][off][0]
            building[floor][off].remove(person) # remove the first person from the office
            if len(empty) > 0: # relocate the person if there are empty offices, otherwise do not relocate
                emptyFloor = empty[0][0]
                emptyOffice = empty[0][1]
                building[emptyFloor][emptyOffice] = [person]
                empty.pop(0)
    return building