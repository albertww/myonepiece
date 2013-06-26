file = open("cardinfo2.txt", 'r')
file2 = open("carddata.txt", 'w')
src = ['2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A']
dst = ['POINT_TWO', 'POINT_THREE', 'POINT_FOUR', 'POINT_FIVE', 'POINT_SIX', 'POINT_SEVEN', 'POINT_EIGHT', 'POINT_NINE', 'POINT_TEN', 'POINT_JACK', 'POINT_QUENE', 'POINT_KING', 'POINT_ONE'] 
static = {}

total = 0
for each in file:
	each = each.strip()
	li = each.split()

	if li[6] != 'PACKAGE_WAR':
		continue
	#print li[3]
	index = src.index(li[3])
	if not li[3] in static:
		static[li[3]] = 1
	else:
		static[li[3]] += 1
	print "{%s, %s, %s}" % (li[1], li[2], dst[index])
	file2.write("{%s, %s, %s},\n" % (li[1], li[2], dst[index]))
	total += 1
file.close()
file2.close()
print "%d line processed" % (total)
print static
