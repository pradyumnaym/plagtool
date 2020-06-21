import os

#add #include stdio to each code file
PATH = 'Codes/'
for root,dirs,files in os.walk(PATH):
    for file in files:
        with open(os.path.join(root,file),'r+') as f:
            l = f.read();
            f.seek(0,0)
            f.write('#include<stdio.h>\n' + l)

