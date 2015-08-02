'''
The MIT License (MIT)
Copyright (c) 2015 Timothy A. Handy


This module is intended to serve as a simple uniform numerical
grid implementation in Python 2.7.10. It is intended to support
cell, face, and edge centered variables in up to 3 dimensions.

Data is managed via the numpy library (www.numpy.org).
'''
from gridUniformConstants import *
import numpy as np
import collections
class gridUniform:
    NDIM = -1
    NUNKVAR  = 0
    NFACEVAR = 0
    NEDGEVAR = 0

    unkMap = dict()
    faceMap = dict()
    edgeMap = dict()

    extents = np.zeros([MDIM,HIGH])


    def parseVariables(self,confFile):

        varIdentifier = 'VARIABLE'
        varSuffix     = '_VAR'
        [self.NUNKVAR, self.unkMap] = parseVariableType(confFile, varIdentifier, varSuffix)

        varIdentifier = 'FACEVAR'
        varSuffix     = '_FACE'
        [self.NFACEVAR, self.faceMap] = parseVariableType(confFile, varIdentifier, varSuffix)

        varIdentifier = 'EDGEVAR'
        varSuffix     = '_EDGE'
        [self.NEDGEVAR, self.edgeMap] = parseVariableType(confFile, varIdentifier, varSuffix)

        print self.NUNKVAR
        print self.unkMap

        print self.NFACEVAR
        print self.faceMap

        print self.NEDGEVAR
        print self.edgeMap

    def __init__(self):
        print "Hello world!"
        self.parseVariables('variable_config.par')
        print self.extents

def parseVariableType(confFile, ident, suff):
    SZ = 0
    varList = []
    for line in open(confFile):
        lineNew = line.upper()
        if ident in lineNew:
            tmp = lineNew.split(None)
            varList = varList + [tmp[1].replace(' ','')]

    varList.sort()
    varList = set(varList)

    # Construct the {var}_{suff} map to integer indices
    varMap = dict()
    for v in varList:
        SZ += 1
        varMap['%s%s'%(v[:4].replace(' ',''),suff)] = SZ-1

    # Add the {var}_{suff} variable as a global constant
    for v in varMap:
        globals()[v] = varMap[v]

    return [SZ,varMap]

if __name__ == "__main__":
    grid = gridUniform()







