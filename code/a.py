separators = [u"\n"]
text = open("bhag.txt").read()
#This converts the encoded text to an internal unicode object, where
# all characters are properly recognized as an entity:
text = text.decode("utf-8")

#this breaks the text on the white spaces, yielding a list of words:
words = text.split()

counter = 1

output = ""
for word in words:
	output += u" * "
    #if the last char is a separator, and is joined to the word:
 	output += word
	output += u" # "

print output
