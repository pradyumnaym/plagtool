"""
This is a code to merge milepost features
Usage:
merge_ft.py <number_of_features> <path> <final_name.pkl> <s for sum, m for mean>
"""


import sys
import os
import numpy as np
import pickle


if(len(sys.argv) != 5 or sys.argv[4] != "s" or sys.argv[4] != "m"):
    sys.exit("Error:\nUsage:\nmerge_ft.py <number_of_features> <path> <final_name.pkl> <s for sum, m for mean>")

d = {}

n_feats = sys.argv[1]
PATH = sys.argv[2]
outfile = sys.argv[3]
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
        d[assignment]["orig"] = np.zeros((0,n_feats), dtype = np.float32)

    if(flag == 1):
        if submission not in d[assignment]["uplag"]:
            d[assignment]["uplag"][submission] = np.zeros((0,n_feats), dtype = np.float32)


    elif(flag == 2):
        if submission not in d[assignment]["plag"]:
            d[assignment]["plag"][submission] = np.zeros((0,n_feats), dtype = np.float32)

    with open(os.path.join(PATH,file), "r") as f:
        featvec = []
        lines = f.read().strip().split(",")
        for line in lines[:n_feats]:
            val = line.strip().split("=")[1]
            featvec.append(float(val))

        featvec = np.asarray(featvec, dtype = np.float32)
        featvec = np.expand_dims(featvec, 0)
        if(flag == 1):
            d[assignment]["uplag"][submission] = np.concatenate([d[assignment]["uplag"][submission], featvec], 0)
        elif(flag == 2):
            d[assignment]["plag"][submission] = np.concatenate([d[assignment]["plag"][submission], featvec], 0)
        else:
            d[assignment]["orig"] = np.concatenate([d[assignment]["orig"], featvec], 0)

if(sys.argv[4] == "s")
    for assignment in d:
        d[assignment]["orig"] = np.sum(d[assignment]["orig"], axis = 0)
        print(d[assignment]["orig"].shape)
        for plag_assignment in d[assignment]["plag"]:
            d[assignment]["plag"][plag_assignment] = np.sum(d[assignment]["plag"][plag_assignment], axis = 0)
            print(d[assignment]["plag"][plag_assignment].shape)
        for uplag_assignment in d[assignment]["uplag"]:
            d[assignment]["uplag"][uplag_assignment] = np.sum(d[assignment]["uplag"][uplag_assignment], axis = 0)
            print(d[assignment]["uplag"][uplag_assignment].shape)

if(sys.argv[4] == "m"):
    for assignment in d:
        d[assignment]["orig"] = np.mean(d[assignment]["orig"], axis = 0)
        print(d[assignment]["orig"].shape)
        for plag_assignment in d[assignment]["plag"]:
            d[assignment]["plag"][plag_assignment] = np.mean(d[assignment]["plag"][plag_assignment], axis = 0)
            print(d[assignment]["plag"][plag_assignment].shape)
        for uplag_assignment in d[assignment]["uplag"]:
            d[assignment]["uplag"][uplag_assignment] = np.mean(d[assignment]["uplag"][uplag_assignment], axis = 0)
            print(d[assignment]["uplag"][uplag_assignment].shape)


with open(outfile, "wb") as f:
    pickle.dump(d, f)
