def display_position(pos):
    print("   %s to move" %(pos[4][0]))
    print("                     ")
    print("   ---------------   ")
    for i in range(3, -1, -1):
        line = "" + str(i+1) + " | "
        for j in range(4):
            line = line + pos[i][j] + " | "

        print(line)
        if i > 0:
            print("  |---------------|  ")

    print("   ---------------   ")
    print("    A   B   C   D    ")
    print("                     ")
