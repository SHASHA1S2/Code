text = open("bhag.txt").read()
text = text.decode("utf-8")
output=''
words = text.split()
for word in words:
	output+=word
print output
