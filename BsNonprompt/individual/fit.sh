#!bin/bash
root -q -b -l fit1stfake.C
sed -i 's/true/false/g' fit1stfake.C  
root -q -b -l fit1stfake.C
sed -i 's/false/true/g' fit1stfake.C  
root -q -b -l -l fit2ndfake.C
sed -i 's/true/false/g' fit2ndfake.C  
root -q -b -l -l fit2ndfake.C
sed -i 's/false/true/g' fit2ndfake.C  
root -l -q -b -l fit3rdfake.C
sed -i 's/true/false/g' fit3rdfake.C  
root -l -q -b -l fit3rdfake.C
sed -i 's/false/true/g' fit3rdfake.C  
root -l -q -b -l fit4thfake.C
sed -i 's/true/false/g' fit4thfake.C  
root -l -q -b -l fit4thfake.C
sed -i 's/false/true/g' fit4thfake.C  
root -q -b -l -l fit5thfake.C
sed -i 's/true/false/g' fit5thfake.C  
root -q -b -l -l fit5thfake.C
sed -i 's/false/true/g' fit5thfake.C  
#root -q -b -l fitAll.C
#sed -i 's/true/false/g' fitAll.C  
#root -q -b -l fitAll.C
#sed -i 's/false/true/g' fitAll.C  
