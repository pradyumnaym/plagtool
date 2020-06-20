import pickle as pkl 
import numpy as np

# with open("exf.pkl","rb") as f:
#     d = pkl.load(f)

# for key in d:
#     shape = None
#     for assgn in d[key]:
#         # if(not shape):
#         #     shape = d[key][assgn].shape
#         # else:
#         #     assert shape == d[key][assgn].shape, str(key)+" "+str(assgn)
#         d[key][assgn] = np.mean(d[key][assgn], 0)

# with open('exf_m.pkl',"wb") as f:
#     pkl.dump(d,f)

# with open("exf.pkl","rb") as f:
#     d = pkl.load(f)

with open("exf_m.pkl","rb") as f:
     d = pkl.load(f)
for key in d:
    shape = None
    for assgn in d[key]:
        if(not shape):
            shape = d[key][assgn].shape
        else:
            assert shape == d[key][assgn].shape, str(key)+" "+str(assgn)
        