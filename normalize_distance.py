import pickle 
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial
from tf import generate_text_features

with open("mfeat_mean.pkl", "rb") as f:
    d = pickle.load(f)

def euclidean_distance(v1, v2):
    return np.sqrt(np.sum(np.square(v1-v2)))

assignments = {}

for assignment in d:
    labelarray = [0] #0 - orig, 1 - plag, 2 - uplag

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

for assignment in assignments:
    featmat = assignments[assignment]

    if(featmat.shape[0]<=2): #atleast 3 sumbission per assignment 
        continue

    print(assignment)
    for submission in sorted(d[assignment]):
        print(submission)
    
    
    for i in range(featmat.shape[0]-3):
        pivot = featmat[i][:65]
        f1 = 'Test_lance/IR_files/%s.ir.c'%assignment
        distlist = []
        for j in range(featmat.shape[0]):
            if j==i:
                continue
            ed = euclidean_distance(pivot, featmat[j][:65])
            distlist.append(ed)
        
        mean = sum(distlist)/len(distlist)
        least = min(distlist)
        most = max(distlist)

        poly = lagrange([1, mean/most, 0], [0., 0.5, 1.0])

        print("The plagiarism predictions are:")
        for k in distlist:
            print(round(np.polyval(Polynomial(poly).coef, k/most), 3))
        print(featmat[:,65])
        break
    break