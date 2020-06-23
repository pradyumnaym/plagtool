import pickle 
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial
from tf import generate_text_features

import os.path as osp

with open(".\Feature_files\mfeat_mean.pkl", "rb") as f:
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

pairlabel_t = []
pairrep_t = []
firstele_t = []
secondele_t = []
pair_u_t = []

for assignment in assignments:
    featmat = assignments[assignment]

    if(featmat.shape[0]<=2): #atleast 3 sumbission per assignment 
        continue

    for i in range(featmat.shape[0]):
        pivot = featmat[i][:65]
        type1 = featmat[i][65]

        if(type1 == 0):
            f1 = osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR",  "%s.ir.c"%assignment)
            f1_u = osp.join("D:\plagtool\lance_ir_generator\C_files",  "%s.c"%assignment)

        elif(type1== 1):
            subid = list(sorted(list(d[assignment]["plag"].keys())))[i-1]
            f1 =osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR", '%s_%s.ir.c'%(assignment, subid))
            f1_u =osp.join("D:\plagtool\lance_ir_generator\C_files", '%s_%s.c'%(assignment, subid))

        else:
            subid =list(sorted(list(d[assignment]["uplag"].keys())))[i-1-len(list(d[assignment]['plag'].keys()))]
            f1 = osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR",  '%s-%s.ir.c'%(assignment,subid))
            f1_u = osp.join("D:\plagtool\lance_ir_generator\C_files", '%s-%s.c'%(assignment,subid))

        
        for j in range(i+1, featmat.shape[0]):
            newfeats = featmat[j][:65]
            type2 = featmat[j][65]
            if(type2 == 0):
                f2 = osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR",  "%s.ir.c"%assignment)
                f2_u = osp.join("D:\plagtool\lance_ir_generator\C_files",  "%s.c"%assignment)

            elif(type2== 1):
                subid = list(sorted(list(d[assignment]["plag"].keys())))[j-1]
                f2 = osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR", '%s_%s.ir.c'%(assignment, subid))
                f2_u = osp.join("D:\plagtool\lance_ir_generator\C_files", '%s_%s.c'%(assignment, subid))

            else:
                subid =list(sorted(list(d[assignment]["uplag"].keys())))[j-1-len(list(d[assignment]['plag'].keys()))]
                f2 = osp.join("D:\plagtool\lance_ir_generator","Cleaned_IR",  '%s-%s.ir.c'%(assignment,subid))
                f2_u = osp.join("D:\plagtool\lance_ir_generator\C_files",  '%s-%s.c'%(assignment,subid))


            diff = np.abs(pivot - newfeats)
            textfeats = generate_text_features(f1, f2)
            textfeats_u = generate_text_features(f1_u, f2_u)
            diff_u = np.concatenate([diff, np.asarray(textfeats_u, dtype = np.float32)], 0)
            diff = np.concatenate([diff, np.asarray(textfeats, dtype = np.float32)], 0)

            

            if assignment != "mul" and assignment !="pd":
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
            else:
                firstele_t.append(pivot)
                secondele_t.append(newfeats)
                pairrep_t.append(diff)
                pair_u_t.append(diff_u)
                if type1==0 and type2==1:
                    pairlabel_t.append(1)
                elif type1==1 and type2==1:
                    pairlabel_t.append(1)
                else:
                    pairlabel_t.append(0)

pairlabel  =  np.asarray(pairlabel, dtype = np.float32)
pairrep = np.asarray(pairrep, dtype = np.float32)
firstele =  np.asarray(firstele, dtype = np.float32)
secondele =  np.asarray(secondele, dtype = np.float32)
pair_u = np.asarray(pair_u, dtype  = np.float32)

pairlabel_t  =  np.asarray(pairlabel_t, dtype = np.float32)
pairrep_t = np.asarray(pairrep_t, dtype = np.float32)
firstele_t =  np.asarray(firstele_t, dtype = np.float32)
secondele_t =  np.asarray(secondele_t, dtype = np.float32)
pair_u_t = np.asarray(pair_u_t, dtype  = np.float32)


#normalize the textual features
scaler = MinMaxScaler()
pairrep[:, 58:] = scaler.fit_transform(pairrep[:, 58:])
scaler = MinMaxScaler()
pair_u[:, 58:] = scaler.fit_transform(pair_u[:, 58:])


all_proc = {
    "labels" : pairlabel,
    "pair_rep" : pairrep, #incl textual features
    "firstele": firstele,
    "secondele" : secondele,
    "pair_rep_u": pair_u,
    "labels_t" : pairlabel_t,
    "pair_rep_t" : pairrep_t, #incl textual features
    "firstele_t": firstele_t,
    "secondele_t" : secondele_t,
    "pair_rep_u_t": pair_u_t

}

with open("D:\plagtool\\all_proc_u.pkl", "wb") as f:
    pickle.dump(all_proc, f)

print(pairlabel.shape, pairrep.shape, firstele.shape, secondele.shape, pair_u.shape)
