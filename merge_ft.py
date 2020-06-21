import os
import numpy as np
import pickle

d = {}
count = 0
PATH = "milepost_features/"
for file in os.listdir(PATH):
    fname = file.split(".")[0]
    flag = 0
    if("-" in fname):
        assignment = fname.split("-")[0]
        submission = fname.split("-")[1]
        flag = 1
    elif("_" in fname):
        assignment = fname.split("_")[0]
        submission = fname.split("_")[1]
        flag = 2
    else:
        assignment = fname 
        submission = "orig"
        flag = 0

    if assignment not in d:
        d[assignment] = {"orig": [], "plag": {}, "uplag": {}}

    if(submission == "orig"):
        d[assignment]["orig"] = np.zeros((0,65), dtype = np.float32)

    if(flag == 1):
        if submission not in d[assignment]["uplag"]:
            d[assignment]["uplag"][submission] = np.zeros((0,65), dtype = np.float32)


    elif(flag == 2):
        if submission not in d[assignment]["plag"]:
            d[assignment]["plag"][submission] = np.zeros((0,65), dtype = np.float32)

    with open(os.path.join(PATH,file), "r") as f:
        featvec = []
        lines = f.read().strip().split(",")
        for line in lines:
            val = line.strip().split("=")[1]
            featvec.append(float(val))

        featvec = np.asarray(featvec, dtype = np.float32)
        featvec = np.expand_dims(featvec, 0)
        #print(file, len(lines))
        if(flag == 1):
            d[assignment]["uplag"][submission] = np.concatenate([d[assignment]["uplag"][submission], featvec], 0)
        elif(flag == 2):
            d[assignment]["plag"][submission] = np.concatenate([d[assignment]["plag"][submission], featvec], 0)
        else:
            d[assignment]["orig"] = np.concatenate([d[assignment]["orig"], featvec], 0)

for assignment in d:
    #count += 1
    d[assignment]["orig"] = np.sum(d[assignment]["orig"], axis = 0)
    print(d[assignment]["orig"].shape)
    for plag_assignment in d[assignment]["plag"]:
        d[assignment]["plag"][plag_assignment] = np.sum(d[assignment]["plag"][plag_assignment], axis = 0)
        print(d[assignment]["plag"][plag_assignment].shape)
        
        #count += 1
    for uplag_assignment in d[assignment]["uplag"]:
        d[assignment]["uplag"][uplag_assignment] = np.sum(d[assignment]["uplag"][uplag_assignment], axis = 0)
        print(d[assignment]["uplag"][uplag_assignment].shape)
        #count += 1


with open("mfeat_sum.pkl", "wb") as f:
    pickle.dump(d, f)
