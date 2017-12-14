#include "iostream"
double sf_pp[43] = {1686.64/1425.57, 3566.86/3126.53, 6482.80/5859.38, 9576.24/8863.06, 13247.07/12442.27, 14913.72/14183.52, 15691.37/15041.16, 16079.18/15512.96, 14953.39/14502.84, 14092.39/13725.93, 12725.89/12438.81, 10718.28/10496.66, 10242.79/10069.88, 8422.21/8281.88, 7516.16/7404.56, 6546.33/6471.83, 5784.66/5730.73, 4656.86/4618.05, 4382.37/4347.23, 3844.92/3816.71, 3294.63/3277.72, 2770.70/2760.09, 2347.43/2344.99, 2092.43/2089.39, 1778.49/1779.74, 1548.47/1552.52, 1355.74/1358.74, 1122.91/1127.68, 1092.18/1096.76, 911.85/917.59, 758.39/761.95, 697.95/703.84, 667.76/672.66, 544.02/550.62, 500.06/505.09, 427.36/432.24, 387.47/392.63, 336.53/341.10, 293.71/297.14, 271.98/276.26, 225.21/228.50, 210.01/213.49, 171.99/175.04, };
double sf_pbpb[43] = {0.00/0.00, 0.00/0.00, 0.00/0.00, 422.62/393.80, 435.44/420.73, 572.18/548.66, 1110.10/1080.77, 1581.95/1583.64, 1614.02/1602.53, 1528.97/1529.33, 1623.29/1644.31, 1606.09/1634.04, 1499.05/1515.78, 1445.99/1477.68, 1363.32/1388.49, 1051.08/1071.81, 986.27/1013.43, 962.05/986.36, 684.96/702.85, 819.50/842.04, 688.14/704.64, 549.72/564.79, 553.69/571.46, 412.85/424.58, 468.84/484.22, 390.62/403.04, 262.13/268.75, 297.68/307.35, 222.53/228.48, 169.84/175.74, 197.80/204.26, 158.21/163.45, 123.53/128.07, 148.08/153.78, 88.09/90.77, 114.77/118.60, 93.43/96.34, 79.32/81.91, 64.55/66.81, 68.47/70.56, 56.52/58.24, 47.47/49.12, 65.83/67.33, };
const int nBins=43;
double ptBins[nBins+1]={7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
void print(){
	printf("(");
	for(int i = 0; i < 43; i ++){
//		printf("(Bpt>%.0f&&Bpt<%.0f)*%f + ", ptBins[i], ptBins[i+1], sf_pp[i]);
		printf("(Bpt>%.0f&&Bpt<%.0f)*%f + ", ptBins[i], ptBins[i+1], sf_pbpb[i]);
	}
	printf(")\n");
//result
//((Bpt>7&&Bpt<8)*1.183134 + (Bpt>8&&Bpt<9)*1.140837 + (Bpt>9&&Bpt<10)*1.106397 + (Bpt>10&&Bpt<11)*1.080467 + (Bpt>11&&Bpt<12)*1.064683 + (Bpt>12&&Bpt<13)*1.051482 + (Bpt>13&&Bpt<14)*1.043229 + (Bpt>14&&Bpt<15)*1.036500 + (Bpt>15&&Bpt<16)*1.031066 + (Bpt>16&&Bpt<17)*1.026698 + (Bpt>17&&Bpt<18)*1.023079 + (Bpt>18&&Bpt<19)*1.021113 + (Bpt>19&&Bpt<20)*1.017171 + (Bpt>20&&Bpt<21)*1.016944 + (Bpt>21&&Bpt<22)*1.015072 + (Bpt>22&&Bpt<23)*1.011511 + (Bpt>23&&Bpt<24)*1.009411 + (Bpt>24&&Bpt<25)*1.008404 + (Bpt>25&&Bpt<26)*1.008083 + (Bpt>26&&Bpt<27)*1.007391 + (Bpt>27&&Bpt<28)*1.005159 + (Bpt>28&&Bpt<29)*1.003844 + (Bpt>29&&Bpt<30)*1.001041 + (Bpt>30&&Bpt<31)*1.001455 + (Bpt>31&&Bpt<32)*0.999298 + (Bpt>32&&Bpt<33)*0.997391 + (Bpt>33&&Bpt<34)*0.997792 + (Bpt>34&&Bpt<35)*0.995770 + (Bpt>35&&Bpt<36)*0.995824 + (Bpt>36&&Bpt<37)*0.993744 + (Bpt>37&&Bpt<38)*0.995328 + (Bpt>38&&Bpt<39)*0.991632 + (Bpt>39&&Bpt<40)*0.992715 + (Bpt>40&&Bpt<41)*0.988014 + (Bpt>41&&Bpt<42)*0.990041 + (Bpt>42&&Bpt<43)*0.988710 + (Bpt>43&&Bpt<44)*0.986858 + (Bpt>44&&Bpt<45)*0.986602 + (Bpt>45&&Bpt<46)*0.988457 + (Bpt>46&&Bpt<47)*0.984507 + (Bpt>47&&Bpt<48)*0.985602 + (Bpt>48&&Bpt<49)*0.983699 + (Bpt>49&&Bpt<50)*0.982575)
//((Bpt>10&&Bpt<11)*1.073184 + (Bpt>11&&Bpt<12)*1.034963 + (Bpt>12&&Bpt<13)*1.042868 + (Bpt>13&&Bpt<14)*1.027138 + (Bpt>14&&Bpt<15)*0.998933 + (Bpt>15&&Bpt<16)*1.007170 + (Bpt>16&&Bpt<17)*0.999765 + (Bpt>17&&Bpt<18)*0.987217 + (Bpt>18&&Bpt<19)*0.982895 + (Bpt>19&&Bpt<20)*0.988963 + (Bpt>20&&Bpt<21)*0.978554 + (Bpt>21&&Bpt<22)*0.981872 + (Bpt>22&&Bpt<23)*0.980659 + (Bpt>23&&Bpt<24)*0.973200 + (Bpt>24&&Bpt<25)*0.975354 + (Bpt>25&&Bpt<26)*0.974546 + (Bpt>26&&Bpt<27)*0.973232 + (Bpt>27&&Bpt<28)*0.976584 + (Bpt>28&&Bpt<29)*0.973318 + (Bpt>29&&Bpt<30)*0.968904 + (Bpt>30&&Bpt<31)*0.972373 + (Bpt>31&&Bpt<32)*0.968238 + (Bpt>32&&Bpt<33)*0.969184 + (Bpt>33&&Bpt<34)*0.975367 + (Bpt>34&&Bpt<35)*0.968537 + (Bpt>35&&Bpt<36)*0.973958 + (Bpt>36&&Bpt<37)*0.966428 + (Bpt>37&&Bpt<38)*0.968374 + (Bpt>38&&Bpt<39)*0.967941 + (Bpt>39&&Bpt<40)*0.964551 + (Bpt>40&&Bpt<41)*0.962934 + (Bpt>41&&Bpt<42)*0.970475 + (Bpt>42&&Bpt<43)*0.967707 + (Bpt>43&&Bpt<44)*0.969794 + (Bpt>44&&Bpt<45)*0.968380 + (Bpt>45&&Bpt<46)*0.966173 + (Bpt>46&&Bpt<47)*0.970380 + (Bpt>47&&Bpt<48)*0.970467 + (Bpt>48&&Bpt<49)*0.966409 + (Bpt>49&&Bpt<50)*0.977722)

}