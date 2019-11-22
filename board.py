def display_position( pos ):
	print("")
	print("   ---------------- ")
	
	for i in range ( 4, 0 ):
		print("%d | %s | %s | %s | %s | ", 
			%(i, pos[i][0], pos[i][1], pos[i][2], pos[i][3]) )
		print("  --------------------  ")
		
	print("     A    B    C    D   ")
