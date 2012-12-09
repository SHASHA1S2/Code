import os
def getFileExtList (dirPath,uniq=True,sorted=True):
    extList=list()
    for dirpath,dirnames,filenames in os.walk(dirPath):
		for file in filenames:
			fileExt=os.path.splitext(file)[-1]
			extList.append(fileExt)
     	
    if uniq:
    	extList=list(set(extList))
    if sorted:
    	extList.sort()
    return extList

print getFileExtList("/home/rishabh")
