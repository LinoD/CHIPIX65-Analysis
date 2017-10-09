

import sys

import ROOT

fileName = sys.argv[1]



f = open(fileName, "rb")


l = f.read()

nChar = len(l)

h = ROOT.TH1F("h", "h", nChar, -0.5, nChar+0.5)

for i in range(0, len(l))  :

	print "%d \t %d" % (i, int(l[i].encode("hex"), 16))
	h.SetBinContent(i+1, int(l[i].encode("hex"), 16))

	
h.Draw()
