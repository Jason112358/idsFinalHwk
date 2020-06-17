import random
numd = 0
numn = 0
with open("../Data/notdga.txt") as notdga:
	with open("../Data/dga.txt") as dga:
		with open("../Data/test.txt","w") as result:
			for line in notdga:
				if random.randint(0,5) == 0:
					notdgainfo = line.strip()
					notdgainfo = notdgainfo.split(",")
					print(notdgainfo[0],file = result)
					numn += 1
			for line in dga:
				if random.randint(0,5) == 1:
					dgainfo = line.strip()
					dgainfo = dgainfo.split(",")
					print(dgainfo[0],file = result)
					numd += 1
print("notdga:"+str(numn)+" dga:"+str(numd))
