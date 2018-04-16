void canvasRAAPbPb_0_100_BpRAA()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Mon Apr 16 19:08:12 2018) by ROOT version6.08/07
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(-5.482353,-0.3726708,56.87059,2.732919);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLeftMargin(0.12);
   canvasRAA->SetRightMargin(0.03);
   canvasRAA->SetTopMargin(0.075);
   canvasRAA->SetBottomMargin(0.12);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff__1 = new TH2F("hemptyEff__1","",50,2,55,10,0,2.5);
   hemptyEff__1->SetMinimum(0);
   hemptyEff__1->SetMaximum(2);
   hemptyEff__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff__1->SetLineColor(ci);
   hemptyEff__1->SetMarkerStyle(20);
   hemptyEff__1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff__1->GetXaxis()->CenterTitle(true);
   hemptyEff__1->GetXaxis()->SetLabelFont(42);
   hemptyEff__1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetXaxis()->SetTitleFont(42);
   hemptyEff__1->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff__1->GetYaxis()->CenterTitle(true);
   hemptyEff__1->GetYaxis()->SetLabelFont(42);
   hemptyEff__1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff__1->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff__1->GetYaxis()->SetTitleFont(42);
   hemptyEff__1->GetZaxis()->SetLabelFont(42);
   hemptyEff__1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff__1->GetZaxis()->SetTitleFont(42);
   hemptyEff__1->Draw("");
   TLine *line = new TLine(2,1,55,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(0.2,0.936,"28.0 pb^{-1} (pp 5.02 TeV) + 351 #mub^{-1} (PbPb 5.02 TeV)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.81,0.2,"B_{s}");
tex->SetNDC();
   tex->SetTextSize(0.08);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.9,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.81,0.15,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.84,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t gNuclearModification_Bp_fx3001[5] = {
   8.5,
   12.5,
   17.5,
   25,
   40};
   Double_t gNuclearModification_Bp_fy3001[5] = {
   0.3458558,
   0.4480066,
   0.4402087,
   0.615181,
   0.3486562};
   Double_t gNuclearModification_Bp_felx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fely3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   Double_t gNuclearModification_Bp_fehx3001[5] = {
   1.5,
   2.5,
   2.5,
   5,
   10};
   Double_t gNuclearModification_Bp_fehy3001[5] = {
   0.06570926,
   0.07712284,
   0.07409171,
   0.1016717,
   0.05734825};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,gNuclearModification_Bp_fx3001,gNuclearModification_Bp_fy3001,gNuclearModification_Bp_felx3001,gNuclearModification_Bp_fehx3001,gNuclearModification_Bp_fely3001,gNuclearModification_Bp_fehy3001);
   grae->SetName("gNuclearModification_Bp");
   grae->SetTitle("Graph");
   grae->SetFillColor(111);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#0033cc");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_Graph_gNuclearModification30013001 = new TH1F("Graph_Graph_gNuclearModification30013001","Graph",100,2.7,54.3);
   Graph_Graph_gNuclearModification30013001->SetMinimum(0.2364759);
   Graph_Graph_gNuclearModification30013001->SetMaximum(0.7605233);
   Graph_Graph_gNuclearModification30013001->SetDirectory(0);
   Graph_Graph_gNuclearModification30013001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_gNuclearModification30013001->SetLineColor(ci);
   Graph_Graph_gNuclearModification30013001->SetMarkerStyle(20);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_gNuclearModification30013001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_gNuclearModification30013001);
   
   grae->Draw("5");
   Double_t xAxis1[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp__2 = new TH1D("hNuclearModification2_Bp__2","",5, xAxis1);
   hNuclearModification2_Bp__2->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp__2->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp__2->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp__2->SetBinContent(4,0.615181);
   hNuclearModification2_Bp__2->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp__2->SetBinError(1,0.1086955);
   hNuclearModification2_Bp__2->SetBinError(2,0.07447295);
   hNuclearModification2_Bp__2->SetBinError(3,0.07507186);
   hNuclearModification2_Bp__2->SetBinError(4,0.09192405);
   hNuclearModification2_Bp__2->SetBinError(5,0.1120147);
   hNuclearModification2_Bp__2->SetEntries(109.8058);
   hNuclearModification2_Bp__2->SetDirectory(0);
   hNuclearModification2_Bp__2->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp__2->SetLineColor(ci);
   hNuclearModification2_Bp__2->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp__2->SetMarkerColor(ci);
   hNuclearModification2_Bp__2->SetMarkerStyle(21);
   hNuclearModification2_Bp__2->SetMarkerSize(1.2);
   hNuclearModification2_Bp__2->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp__2->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__2->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__2->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp__2->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__2->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__2->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__2->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__2->Draw("same");
   TBox *box = new TBox(4,0.9586116,6,1.045662);

   ci = 1184;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#0099ff");
   box->SetLineColor(ci);
   box->Draw();
   
   TLegend *leg = new TLegend(0.5,0.66,0.95,0.92,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification_UnCor","B_{s} R_{AA}","pf");

   ci = 1180;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);

   ci = TColor::GetColor("#990099");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry->SetTextSize(0.038);
   entry=leg->AddEntry("","B^{+} R_{AA}","pf");

   ci = 1183;
   color = new TColor(ci, 0, 0.6, 1, " ", 0.5);
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#0033cc");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.038);
   leg->Draw();
   
   Double_t gNuclearModification_fx3002[2] = {
   11,
   32.5};
   Double_t gNuclearModification_fy3002[2] = {
   1.608022,
   0.860136};
   Double_t gNuclearModification_felx3002[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fely3002[2] = {
   0.3983932,
   0.114399};
   Double_t gNuclearModification_fehx3002[2] = {
   4,
   17.5};
   Double_t gNuclearModification_fehy3002[2] = {
   0.3983932,
   0.114399};
   grae = new TGraphAsymmErrors(2,gNuclearModification_fx3002,gNuclearModification_fy3002,gNuclearModification_felx3002,gNuclearModification_fehx3002,gNuclearModification_fely3002,gNuclearModification_fehy3002);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = 1179;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   grae->SetFillColor(ci);
   grae->SetLineColor(0);
   grae->SetLineWidth(0);

   ci = TColor::GetColor("#990099");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(33);
   grae->SetMarkerSize(1.2);
   
   TH1F *Graph_gNuclearModification3002 = new TH1F("Graph_gNuclearModification3002","Graph",100,2.7,54.3);
   Graph_gNuclearModification3002->SetMinimum(0.6196692);
   Graph_gNuclearModification3002->SetMaximum(2.132483);
   Graph_gNuclearModification3002->SetDirectory(0);
   Graph_gNuclearModification3002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3002->SetLineColor(ci);
   Graph_gNuclearModification3002->SetMarkerStyle(20);
   Graph_gNuclearModification3002->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3002->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3002->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3002->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3002->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3002);
   
   grae->Draw("5");
   Double_t xAxis2[6] = {7, 10, 15, 20, 30, 50}; 
   
   TH1D *hNuclearModification2_Bp__3 = new TH1D("hNuclearModification2_Bp__3","",5, xAxis2);
   hNuclearModification2_Bp__3->SetBinContent(1,0.3458558);
   hNuclearModification2_Bp__3->SetBinContent(2,0.4480066);
   hNuclearModification2_Bp__3->SetBinContent(3,0.4402087);
   hNuclearModification2_Bp__3->SetBinContent(4,0.615181);
   hNuclearModification2_Bp__3->SetBinContent(5,0.3486562);
   hNuclearModification2_Bp__3->SetBinError(1,0.1086955);
   hNuclearModification2_Bp__3->SetBinError(2,0.07447295);
   hNuclearModification2_Bp__3->SetBinError(3,0.07507186);
   hNuclearModification2_Bp__3->SetBinError(4,0.09192405);
   hNuclearModification2_Bp__3->SetBinError(5,0.1120147);
   hNuclearModification2_Bp__3->SetEntries(109.8058);
   hNuclearModification2_Bp__3->SetStats(0);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp__3->SetLineColor(ci);
   hNuclearModification2_Bp__3->SetLineWidth(3);

   ci = TColor::GetColor("#0033cc");
   hNuclearModification2_Bp__3->SetMarkerColor(ci);
   hNuclearModification2_Bp__3->SetMarkerStyle(21);
   hNuclearModification2_Bp__3->SetMarkerSize(1.2);
   hNuclearModification2_Bp__3->GetXaxis()->SetTitle("D^{0} p_{T} (GeV/c)");
   hNuclearModification2_Bp__3->GetXaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__3->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__3->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__3->GetXaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__3->GetYaxis()->SetTitle("Uncorrected dN(D^{0})/dp_{T}");
   hNuclearModification2_Bp__3->GetYaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__3->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__3->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__3->GetYaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__3->GetZaxis()->SetLabelFont(42);
   hNuclearModification2_Bp__3->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2_Bp__3->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2_Bp__3->GetZaxis()->SetTitleFont(42);
   hNuclearModification2_Bp__3->Draw("same");
   Double_t xAxis3[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification__4 = new TH1D("hNuclearModification__4","",2, xAxis3);
   hNuclearModification__4->SetBinContent(1,1.608022);
   hNuclearModification__4->SetBinContent(2,0.860136);
   hNuclearModification__4->SetBinError(1,0.5990549);
   hNuclearModification__4->SetBinError(2,0.2981538);
   hNuclearModification__4->SetEntries(13.60499);

   ci = TColor::GetColor("#990099");
   hNuclearModification__4->SetLineColor(ci);
   hNuclearModification__4->SetLineStyle(0);
   hNuclearModification__4->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification__4->SetMarkerColor(ci);
   hNuclearModification__4->SetMarkerStyle(33);
   hNuclearModification__4->SetMarkerSize(2.2);
   hNuclearModification__4->GetXaxis()->SetLabelFont(42);
   hNuclearModification__4->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification__4->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification__4->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification__4->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification__4->GetXaxis()->SetTitleFont(42);
   hNuclearModification__4->GetYaxis()->SetLabelFont(42);
   hNuclearModification__4->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification__4->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification__4->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification__4->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification__4->GetYaxis()->SetTitleFont(42);
   hNuclearModification__4->GetZaxis()->SetLabelFont(42);
   hNuclearModification__4->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification__4->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification__4->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification__4->GetZaxis()->SetTitleFont(42);
   hNuclearModification__4->Draw("same p");
   Double_t xAxis4[3] = {7, 15, 50}; 
   
   TH1D *hNuclearModification__5 = new TH1D("hNuclearModification__5","",2, xAxis4);
   hNuclearModification__5->SetBinContent(1,1.608022);
   hNuclearModification__5->SetBinContent(2,0.860136);
   hNuclearModification__5->SetBinError(1,0.5990549);
   hNuclearModification__5->SetBinError(2,0.2981538);
   hNuclearModification__5->SetEntries(13.60499);

   ci = TColor::GetColor("#990099");
   hNuclearModification__5->SetLineColor(ci);
   hNuclearModification__5->SetLineStyle(0);
   hNuclearModification__5->SetLineWidth(3);

   ci = TColor::GetColor("#990099");
   hNuclearModification__5->SetMarkerColor(ci);
   hNuclearModification__5->SetMarkerStyle(33);
   hNuclearModification__5->SetMarkerSize(2.2);
   hNuclearModification__5->GetXaxis()->SetLabelFont(42);
   hNuclearModification__5->GetXaxis()->SetLabelOffset(0.007);
   hNuclearModification__5->GetXaxis()->SetLabelSize(0.05);
   hNuclearModification__5->GetXaxis()->SetTitleSize(0.06);
   hNuclearModification__5->GetXaxis()->SetTitleOffset(0.9);
   hNuclearModification__5->GetXaxis()->SetTitleFont(42);
   hNuclearModification__5->GetYaxis()->SetLabelFont(42);
   hNuclearModification__5->GetYaxis()->SetLabelOffset(0.007);
   hNuclearModification__5->GetYaxis()->SetLabelSize(0.05);
   hNuclearModification__5->GetYaxis()->SetTitleSize(0.06);
   hNuclearModification__5->GetYaxis()->SetTitleOffset(1.05);
   hNuclearModification__5->GetYaxis()->SetTitleFont(42);
   hNuclearModification__5->GetZaxis()->SetLabelFont(42);
   hNuclearModification__5->GetZaxis()->SetLabelOffset(0.007);
   hNuclearModification__5->GetZaxis()->SetLabelSize(0.05);
   hNuclearModification__5->GetZaxis()->SetTitleSize(0.06);
   hNuclearModification__5->GetZaxis()->SetTitleFont(42);
   hNuclearModification__5->Draw("same");
   box = new TBox(2,0.9586116,4,1.045662);

   ci = 1182;
   color = new TColor(ci, 0.8, 0.2, 0.8, " ", 0.5);
   box->SetFillColor(ci);

   ci = TColor::GetColor("#cc33cc");
   box->SetLineColor(ci);
   box->Draw();
   
   TH2F *hemptyEff_copy__6 = new TH2F("hemptyEff_copy__6","",50,2,55,10,0,2.5);
   hemptyEff_copy__6->SetMinimum(0);
   hemptyEff_copy__6->SetMaximum(2);
   hemptyEff_copy__6->SetDirectory(0);
   hemptyEff_copy__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy__6->SetLineColor(ci);
   hemptyEff_copy__6->SetMarkerStyle(20);
   hemptyEff_copy__6->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy__6->GetXaxis()->CenterTitle(true);
   hemptyEff_copy__6->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy__6->GetXaxis()->SetTitleSize(0.05);
   hemptyEff_copy__6->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy__6->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy__6->GetYaxis()->CenterTitle(true);
   hemptyEff_copy__6->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy__6->GetYaxis()->SetTitleSize(0.05);
   hemptyEff_copy__6->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff_copy__6->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy__6->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy__6->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy__6->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy__6->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy__6->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
