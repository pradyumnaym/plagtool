import os
import pickle
import Levenshtein
from difflib import Differ
import re

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

    return [line_diff[0], line_diff_ratio[0], av_diff[0], edit_dist[0], common_line[0], common_line_ratio[0], common_comment[0], common_comment_ratio[0]]

    

f_1 = '/home/anushkini/Desktop/PD/plagtool/Test_lance/IR_files/addSub.ir.c'
f_2 = '/home/anushkini/Desktop/PD/plagtool/Test_lance/IR_files/addSub_1.ir.c'
print(generate_text_features(f_1, f_2))
