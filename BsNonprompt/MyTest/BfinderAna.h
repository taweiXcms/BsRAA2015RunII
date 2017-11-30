//HltInfo
int           Bf_HLT_Run;
ULong64_t     Bf_HLT_Event;
int           Bf_HLT_LumiBlock;
int HLT_HIL1DoubleMu0ForPPRef_v1;
int HLT_HIL1DoubleMu0_v1;
int HLT_HIL1DoubleMu0_part1_v1;
int HLT_HIL1DoubleMu0_part2_v1;
int HLT_HIL1DoubleMu0_part3_v1;

void setHltBranch(TTree* hltroot, bool isPbPb)
{
  hltroot->SetBranchAddress("Run",&Bf_HLT_Run);
  hltroot->SetBranchAddress("Event",&Bf_HLT_Event);
  hltroot->SetBranchAddress("LumiBlock",&Bf_HLT_LumiBlock);
  if(isPbPb){
    hltroot->SetBranchAddress("HLT_HIL1DoubleMu0_v1",&HLT_HIL1DoubleMu0_v1);
    hltroot->SetBranchAddress("HLT_HIL1DoubleMu0_part1_v1",&HLT_HIL1DoubleMu0_part1_v1);
    hltroot->SetBranchAddress("HLT_HIL1DoubleMu0_part2_v1",&HLT_HIL1DoubleMu0_part2_v1);
    hltroot->SetBranchAddress("HLT_HIL1DoubleMu0_part3_v1",&HLT_HIL1DoubleMu0_part3_v1);
  }
  else
    hltroot->SetBranchAddress("HLT_HIL1DoubleMu0ForPPRef_v1",&HLT_HIL1DoubleMu0ForPPRef_v1);
}

//hiEvtInfo
unsigned int       Bf_HiTree_Run;
unsigned long long Bf_HiTree_Evt;
unsigned int       Bf_HiTree_Lumi;
void setHiTreeBranch(TTree* hitreeroot)
{
  hitreeroot->SetBranchAddress("run",&Bf_HiTree_Run);
  hitreeroot->SetBranchAddress("evt",&Bf_HiTree_Evt);
  hitreeroot->SetBranchAddress("lumi",&Bf_HiTree_Lumi);
}
