fi=input("Enter the file name:")
xfile=open(fi)
count=dict()
for line in xfile:
  word=line.split()
  for words in word:
    count[words]=count.get(words,0)+1
tmp=list()
for k,v in count.items():
  tmp.append((v,k))
tmp=sorted(tmp,reverse=True)
for k,v in tmp:
  print(v,k)
