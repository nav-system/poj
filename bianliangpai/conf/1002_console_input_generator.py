# number of '-' in telephone number is meaningless
# the key factor is red_black tree size

import random

source_list=['0','1','2','3','4','5','6','7','8','9', \
			 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','W','X','Y']
sl = len(source_list)

f = open("./conf/1002_console_input.txt", 'w')
f.write('100000\n')

for i in range(100000):
	for j in range(7):
		ch = source_list[random.randint(0,sl-1)]
		f.write(ch)
	f.write('\n')

f.close()