#!/usr/bin/python

import re
import matplotlib.pyplot as plt
import numpy as np
import itertools
import math

colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k', 'w']

class Point():
    def __init__(self, x, y):
        self._x = x
        self._y = y

def dist(a, b):
    dx = a._x - b._x
    dy = a._y - b._y
    return math.sqrt(dx*dx +dy*dy)

def readPoints():
    x = []
    y = []
    try:
        line = raw_input()
        l = re.findall(r'([0-9.-]+, [0-9.-]+)', line)
        for p in l:
            x1, y1 = p.split(',')
            x.append(float(x1))
            y.append(float(y1))
    except:
        pass
    return x, y

def plot(x, y, c):
    plt.plot(x, y, marker='o', color=c, ls='')

def drawLine2P(x,y,xlims):
    xrange = np.arange(xlims[0],xlims[1],0.1)
    if x[0] == x[1]:
        plt.plot(0*xrange + x[0], xrange, 'k')
        return
    
    A = np.vstack([x, np.ones(len(x))]).T
    k, b = np.linalg.lstsq(A, y)[0]
    plt.plot(xrange, k*xrange + b, 'k')

if __name__ == '__main__':
    cc = 0
    while(True):
        x, y = readPoints()
        if(len(x) == 0):
            break
        plot(x, y, colors[cc])
        cc += 1

    l = [[4, 3], [4, 0], [0, 3], [2, -0.5]]
    n = len(l)
    '''for i in range(0, n):
        for j in range(i+1, n):
            drawLine2P([l[i][0], l[j][0]], [l[i][1], l[j][1]], [-10, 10])
    '''    
    plt.show()

