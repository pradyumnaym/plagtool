import pickle 
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial
from tf import generate_text_features

import os.path as osp

with open("mfeat_mean.pkl", "rb") as f:
    d = pickle.load(f)

def euclidean_distance(v1, v2):
    return np.sqrt(np.sum(np.square(v1-v2)))

assignments = {}

for assignment in d:
    labelarray = [0]    #0 - orig, 1 - plag, 2 - uplag

    asgnfeatures = np.zeros((0, 65), dtype = np.float32)

    asgnfeatures = np.concatenate(
        [asgnfeatures, 
        np.expand_dims(d[assignment]['orig'],0)
        ], 0)


    for submission in sorted(d[assignment]["plag"]):

        d[assignment]["plag"][submission] = np.expand_dims(d[assignment]["plag"][submission], 0)
        asgnfeatures = np.concatenate([asgnfeatures, d[assignment]["plag"][submission]], 0)
        labelarray.append(1)

    for submission in sorted(d[assignment]["uplag"]):
        d[assignment]["uplag"][submission] = np.expand_dims(d[assignment]["uplag"][submission], 0)
        asgnfeatures = np.concatenate([asgnfeatures, d[assignment]["uplag"][submission]], 0)
        
        labelarray.append(2)
    assignments[assignment] = asgnfeatures

    assignments[assignment] = np.concatenate([assignments[assignment], np.expand_dims(np.asarray(labelarray, dtype = np.float32), 1)], 1)

for assignment in assignments:
    scaler = MinMaxScaler()
    scaler.fit(assignments[assignment][:,:65])
    assignments[assignment][:,:65] = scaler.transform(assignments[assignment][:,:65])

print("Successfully normalized each feature to [0,1]")

pairlabel = []
pairrep = []
firstele = []
secondele = []
pair_u = []

for assignment in assignments:
    featmat = assignments[assignment]

    if(featmat.shape[0]<=2): #atleast 3 sumbission per assignment 
        continue

    for i in range(featmat.shape[0]):
        pivot = featmat[i][:65]
        type1 = featmat[i][65]

        if(type1 == 0):
            f1 = osp.join("D:\plagtool\Test_lance","IR_files",  "%s.ir.c"%assignment)
            f1_u = osp.join("D:\plagtool\Test_lance",  "%s.c"%assignment)

        elif(type1== 1):
            subid = list(sorted(list(d[assignment]["plag"].keys())))[i-1]
            f1 =osp.join("D:\plagtool\Test_lance","IR_files", '%s_%s.ir.c'%(assignment, subid))
            f1_u =osp.join("D:\plagtool\Test_lance", '%s_%s.c'%(assignment, subid))

        else:
            subid =list(sorted(list(d[assignment]["uplag"].keys())))[i-1-len(list(d[assignment]['plag'].keys()))]
            f1 = osp.join("D:\plagtool\Test_lance","IR_files",  '%s-%s.ir.c'%(assignment,subid))
            f1_u = osp.join("D:\plagtool\Test_lance", '%s-%s.c'%(assignment,subid))

        
        for j in range(i+1, featmat.shape[0]):
            newfeats = featmat[j][:65]
            type2 = featmat[j][65]
            if(type2 == 0):
                f2 = osp.join("D:\plagtool\Test_lance","IR_files",  "%s.ir.c"%assignment)
                f2_u = osp.join("D:\plagtool\Test_lance",  "%s.c"%assignment)

            elif(type2== 1):
                subid = list(sorted(list(d[assignment]["plag"].keys())))[j-1]
                f2 = osp.join("D:\plagtool\Test_lance","IR_files", '%s_%s.ir.c'%(assignment, subid))
                f2_u = osp.join("D:\plagtool\Test_lance", '%s_%s.c'%(assignment, subid))

            else:
                subid =list(sorted(list(d[assignment]["uplag"].keys())))[j-1-len(list(d[assignment]['plag'].keys()))]
                f2 = osp.join("D:\plagtool\Test_lance","IR_files",  '%s-%s.ir.c'%(assignment,subid))
                f2_u = osp.join("D:\plagtool\Test_lance",  '%s-%s.c'%(assignment,subid))


            diff = np.abs(pivot - newfeats)
            textfeats = generate_text_features(f1, f2)
            textfeats_u = generate_text_features(f1_u, f2_u)
            diff = np.concatenate([diff, np.asarray(textfeats, dtype = np.float32)], 0)
            diff_u = np.concatenate([diff, np.asarray(textfeats_u, dtype = np.float32)], 0)

            firstele.append(pivot)
            secondele.append(newfeats)
            pairrep.append(diff)
            pair_u.append(diff_u)

            if type1==0 and type2==1:
                pairlabel.append(1)
            elif type1==1 and type2==1:
                pairlabel.append(1)
            else:
                pairlabel.append(0)

pairlabel  =  np.asarray(pairlabel, dtype = np.float32)
pairrep = np.asarray(pairrep, dtype = np.float32)
firstele =  np.asarray(firstele, dtype = np.float32)
secondele =  np.asarray(secondele, dtype = np.float32)
pair_u = np.asarray(pair_u, dtype  = np.float32)
all_proc = {
    "labels" : pairlabel,
    "pair_rep" : pairrep, #incl textual features
    "firstele": firstele,
    "secondele" : secondele,
    "pair_rep_u": pair_u
}

with open("D:\plagtool\\all_proc_u.pkl", "wb") as f:
    pickle.dump(all_proc, f)

print(pairlabel.shape, pairrep.shape, firstele.shape, secondele.shape)
