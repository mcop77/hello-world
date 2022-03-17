import folium

imageName = ""
#nameFound = False
#locationFound = False
latitude = 0
longitude = 0
slotOne = ""
slotTwo = ""
slotThree = ""

columns = 0
count = 0

f = open("exifOutput.txt")

for i in f:
	if i[:12] == "GPS Position":
		columns += 1

imageList = []
imageCoordinates = [[0 for x in range(2)] for y in range(columns)]

f = open("exifOutput.txt")

for i in f:
	if i[:9] == "File Name":
		#nameFound = True
		line = i.split()
		imageName = line[3]
		imageList.append(imageName)

	if i[:12] == "GPS Position":
		#locationFound = True
		line = i.split()
	
		latitude = float(line[3])
		slotOne = line[5][:-1]
		slotTwo = line[6][:-1]
		slotThree = line[7][:-1]

		latitude = latitude + float(slotOne) / 60
		latitude = latitude + float(slotTwo) / 3600

		if slotThree == "S":
			latitude = latitude - latitude - latitude

		longitude = float(line[8])
		slotOne = line[10][:-1]
		slotTwo = line[11][:-1]

		longitude = longitude + float(slotOne) / 60
		longitude = longitude + float(slotTwo) / 3600

		if line[12] == "W":
			longitude = longitude - longitude - longitude

		imageCoordinates[count][0] = latitude
		imageCoordinates[count][1] = longitude

		count = count + 1

	#if nameFound == True and locationFound == True:
		#nameFound = False
		#locationFound = False
	#elif nameFound == True and locationFound == False:
		#imageList.pop()
		#nameFound = False

m = folium.Map()

for i in range(columns):
	folium.Marker(
		location=[imageCoordinates[i][0], imageCoordinates[i][1]],
		popup=str(imageCoordinates[i][0]) + ", " + str(imageCoordinates[i][1]),
		#popup="<img src=\"/media/sf_Germany/" + str(imageList[i]) + "\" width=\"100\" height=\"120\">",
		icon=folium.Icon(color="purple")
		).add_to(m)

m.save("map.html")
