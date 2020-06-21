import os
import numpy as np
import pickle

d = {}

PATH = "milepost_features/"
for file in os.listdir(PATH):
    fname = file.split(".")[0]
    if(len(fname.split("_")) < 2):
        continue

    if(len(fname.split("_")) == 3):
        assignment = fname.split("_")[0]+fname.split("_")[1]
        submission = fname.split("_")[2]
    else:
        assignment = fname.split("_")[0]
        submission = fname.split("_")[1]

    if assignment not in d:
        d[assignment] = {}

    if submission not in d[assignment]:
        d[assignment][submission] = np.zeros((0,57), dtype = np.float32)

    with open(os.path.join(PATH,file), "r") as f:
        featvec = []
        lines = f.read().strip().split(",")
        for line in lines[:57]:
            val = line.strip().split("=")[1]
            featvec.append(float(val))

        featvec = np.asarray(featvec, dtype = np.float32)
        featvec = np.expand_dims(featvec, 0)
        d[assignment][submission] = np.concatenate([d[assignment][submission], featvec], 0)

with open("exf.pkl", "wb") as f:
    pickle.dump(d, f)
