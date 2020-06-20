import pickle 
import numpy as np
from sklearn.preprocessing import MinMaxScaler
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial

with open("exf_m.pkl", "rb") as f:
    d = pickle.load(f)

def euclidean_distance(v1, v2):
    return np.sqrt(np.sum(np.square(v1-v2)))

assignments = {}

for assignment in d:
    asgnfeatures = np.zeros((0, 57), dtype = np.float32)
    for submission in sorted(d[assignment]):
        d[assignment][submission] = np.expand_dims(d[assignment][submission], 0)
        asgnfeatures = np.concatenate([asgnfeatures, d[assignment][submission]], 0)
    assignments[assignment] = asgnfeatures

for assignment in assignments:
    scaler = MinMaxScaler()
    scaler.fit(assignments[assignment])
    assignments[assignment] = scaler.transform(assignments[assignment])

print("Successfully normalized each feature to [0,1]")

for assignment in assignments:
    featmat = assignments[assignment]

    if(featmat.shape[0]<=2): #atleast 3 sumbission per assignment 
        continue

    print(assignment)
    
    for i in range(featmat.shape[0]-3):
        pivot = featmat[i]
        distlist = []
        for j in range(featmat.shape[0]):
            if j==i:
                continue
            ed = euclidean_distance(pivot, featmat[j])
            distlist.append(ed)
        
        mean = sum(distlist)/len(distlist)
        least = min(distlist)
        most = max(distlist)

        poly = lagrange([1, mean/most, 0], [0., 0.5, 1.0])

        print("The plagiarism predictions are:")
        for k in distlist:
            print(round(np.polyval(Polynomial(poly).coef, k/most), 3))
        break
    break