import math
sys0 = [0, 8, 5.5, 2.7, 3.1, 2.8, 5.6, 0.49]
sys1 = [0, 8, 5.5, 2.7, 4.2, 0.45, 5.6, 0.49]
sys2 = [0, 8, 5.5, 2.7, 3.3, 0.81, 5.6, 0.49]
sys3 = [0, 8, 5.5, 2.7, 3.0, 2.2, 5.6, 0.49]
sys4 = [0, 8, 5.5, 2.7, 2.8, 3.2, 5.6, 0.49]
sysAA = [0, 12, 5.6, 4.9, 3.8, 3.0, 2.5, 2.1]
for i in range (len(sys0)):
	sys0[0] += sys0[i]*sys0[i]
	sys1[0] += sys1[i]*sys1[i]
	sys2[0] += sys2[i]*sys2[i]
	sys3[0] += sys3[i]*sys3[i]
	sys4[0] += sys4[i]*sys4[i]
	sysAA[0] += sysAA[i]*sysAA[i]
print sys0[0], math.sqrt(sys0[0])
print sys1[0], math.sqrt(sys1[0])
print sys2[0], math.sqrt(sys2[0])
print sys3[0], math.sqrt(sys3[0])
print sys4[0], math.sqrt(sys4[0])
print sysAA[0], math.sqrt(sysAA[0])
tot = sys0[0] + sysAA[0]
print tot, math.sqrt(tot)

