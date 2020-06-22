"""
A python program to extract unsupervised features for model
Usage:

unsupervised.py <PATH>

"""

import sys
import os
from sklearn.preprocessing import MinMaxScaler
import Levenshtein
from difflib import Differ
import re
import pprint
from scipy.interpolate import lagrange
from numpy.polynomial.polynomial import Polynomial
import pickle
import numpy as np


with open(os.path.join(".", "Feature_files", "mfeat_mean.pkl"), "rb") as f:
    d = pickle.load(f)


def getMilepostFeatures(filename):
    filename = filename.split(".")[0] #remove the extension
    if "-" in filename :
        return d[filename.split("-")[0]]["uplag"][filename.split("-")[1]]
    elif "_" in filename:
        return d[filename.split("_")[0]]["plag"][filename.split("_")[1]]
    else:
        return d[filename]["orig"]

PATH = sys.argv[1]

def file_length(fname):
    sumlength = 0  # to store avg line length
    with open(fname) as f:
        for i, l in enumerate(f):
            sumlength += len(l)  # finds total number of characters
    sumlength = sumlength / (i + 1)  # find avg by dividing by line count
    return i + 1, sumlength

def get_comments(text):
    pattern = r"(\".*?\"|\'.*?\')|(/\*.*?\*/|//[^\r\n]*$)"
    regex = re.compile(pattern, re.MULTILINE | re.DOTALL)
    comments = [m.group(2) for m in regex.finditer(text) if m.group(2)]
    return comments

def generate_text_features(f_1, f_2):
    os.getcwd()
    os.chdir("..")
    line_diff = []  # list containing line difference for every pair
    line_diff_ratio = []
    av_diff = []  # list containing avg line difference for every pair
    edit_dist = []
    common_line = []
    common_line_ratio = []
    common_comment = []
    common_comment_ratio = []
    d = Differ()

    l1, a1 = file_length(f_1)
    l2, a2 = file_length(f_2)
    diff = abs(l1 - l2)
    diff2 = abs(a1 - a2)
    line_diff.append(diff)
    line_diff_ratio.append(diff / max(l1, l2))
    av_diff.append(diff2)
    
# Below is to find edit distance
    f1 = open(f_1)
    f2 = open(f_2)
    x1 = f1.read()
    x2 = f2.read()
    
# print(x1)
    # print(x2)
    diff3 = Levenshtein.distance(x1, x2)
    edit_dist.append(diff3)
    
# Below is to find the number of common lines of code
    count = 0
    p1 = x1.splitlines()
    p2 = x2.splitlines()
    if "" in p1:
        p1.remove("")
    if "" in p2:
        p2.remove("")
    
    for line in d.compare(p1, p2):
        if line.startswith(" "):
            count = count + 1
    
    common_line.append(count)
    common_line_ratio.append(count / max(len(p1), len(p2)))
    c1 = get_comments(x1)
    c2 = get_comments(x2)
    count = 0
    for line in d.compare(c1, c2):
        if line.startswith(" "):
            count = count + 1
    common_comment.append(count)
    temp = max(len(c1), len(c2))
    if temp != 0:
        common_comment_ratio.append(count / temp)
    else:
        common_comment_ratio.append(0)
    f1.close()
    f2.close()

    return np.asarray([line_diff[0], line_diff_ratio[0], av_diff[0], edit_dist[0], common_line[0], common_line_ratio[0], common_comment[0], common_comment_ratio[0]])



f_names = list()
for root,dirs,files in os.walk(PATH):
    for f in files:
        f_names.append(os.path.abspath(os.path.join(root,f)))

feats = list()
for i in range(0,1):#range(len(f_names)):
    pivot = f_names[i].split(os.path.sep)[-1]
    p_f = getMilepostFeatures(pivot)
    distlist = []
    
    for j in range(len(f_names)):
        if(i == j):
             continue
        o_f = getMilepostFeatures(f_names[j].split(os.path.sep)[-1])
        diff = np.abs(p_f - o_f)
        feats.append(np.concatenate([diff,generate_text_features(f_names[i],f_names[j])]))
    
    scaler = MinMaxScaler()
    feats = scaler.fit_transform(feats)

    distlist = [np.sum(x) for x in feats]

    mean = sum(distlist)/len(distlist)
    least = min(distlist)
    most = max(distlist)

    poly = lagrange([1, mean/most, 0], [0., 0.5, 1.0])

    print("The plagiarism predictions are:")
    for k in distlist:
        
        print(round(np.polyval(Polynomial(poly).coef, k/most), 3))

