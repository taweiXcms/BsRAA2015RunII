void canvasSigmaBplusRatiopp_AddPbPb()
{
//=========Macro generated from canvas: cSigma/
//=========  (Fri Aug  3 00:40:33 2018) by ROOT version6.02/13
   TCanvas *cSigma = new TCanvas("cSigma", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cSigma->SetHighLightColor(2);
   cSigma->Range(-10.27799,1.872944,57.93308,7.569673);
   cSigma->SetFillColor(0);
   cSigma->SetBorderMode(0);
   cSigma->SetBorderSize(2);
   cSigma->SetLogy();
   cSigma->SetLeftMargin(0.18);
   cSigma->SetRightMargin(0.043);
   cSigma->SetBottomMargin(0.145);
   cSigma->SetFrameBorderMode(0);
   cSigma->SetFrameBorderMode(0);
   
   TH2F *hemptySigma1 = new TH2F("hemptySigma1","",50,2,55,10,500,1e+07);
   hemptySigma1->SetMinimum(0);
   hemptySigma1->SetMaximum(2);
   hemptySigma1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptySigma1->SetLineColor(ci);
   hemptySigma1->SetMarkerStyle(20);
   hemptySigma1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptySigma1->GetXaxis()->CenterTitle(true);
   hemptySigma1->GetXaxis()->SetLabelFont(42);
   hemptySigma1->GetXaxis()->SetLabelSize(0.048);
   hemptySigma1->GetXaxis()->SetTitleSize(0.055);
   hemptySigma1->GetXaxis()->SetTitleFont(42);
   hemptySigma1->GetYaxis()->SetTitle("#frac{d#sigma_{pp}}{dp_{T}} or #frac{1}{T_{AA}} #frac{dN_{PbPb}}{dp_{T}} ( pb GeV^{-1}c)");
   hemptySigma1->GetYaxis()->CenterTitle(true);
   hemptySigma1->GetYaxis()->SetLabelFont(42);
   hemptySigma1->GetYaxis()->SetLabelSize(0.048);
   hemptySigma1->GetYaxis()->SetTitleSize(0.045);
   hemptySigma1->GetYaxis()->SetTitleOffset(1.7);
   hemptySigma1->GetYaxis()->SetTitleFont(42);
   hemptySigma1->GetZaxis()->SetLabelFont(42);
   hemptySigma1->GetZaxis()->SetLabelSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleFont(42);
   hemptySigma1->Draw("");
   Double_t xAxis1[3] = {7, 15, 50}; 
   
   TH1D *hPtSigma2 = new TH1D("hPtSigma2","",2, xAxis1);
   hPtSigma2->SetBinContent(1,316468.6);
   hPtSigma2->SetBinContent(2,8318.448);
   hPtSigma2->SetBinError(1,36647.64);
   hPtSigma2->SetBinError(2,1050.076);
   hPtSigma2->SetEntries(78.47818);
   hPtSigma2->SetLineStyle(0);
   hPtSigma2->SetLineWidth(2);
   hPtSigma2->SetMarkerStyle(20);
   hPtSigma2->SetMarkerSize(1.2);
   hPtSigma2->GetXaxis()->SetLabelFont(42);
   hPtSigma2->GetXaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetXaxis()->SetLabelSize(0.05);
   hPtSigma2->GetXaxis()->SetTitleSize(0.06);
   hPtSigma2->GetXaxis()->SetTitleOffset(0.9);
   hPtSigma2->GetXaxis()->SetTitleFont(42);
   hPtSigma2->GetYaxis()->SetLabelFont(42);
   hPtSigma2->GetYaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetYaxis()->SetLabelSize(0.05);
   hPtSigma2->GetYaxis()->SetTitleSize(0.06);
   hPtSigma2->GetYaxis()->SetTitleOffset(1.05);
   hPtSigma2->GetYaxis()->SetTitleFont(42);
   hPtSigma2->GetZaxis()->SetLabelFont(42);
   hPtSigma2->GetZaxis()->SetLabelOffset(0.007);
   hPtSigma2->GetZaxis()->SetLabelSize(0.05);
   hPtSigma2->GetZaxis()->SetTitleSize(0.06);
   hPtSigma2->GetZaxis()->SetTitleFont(42);
   hPtSigma2->Draw("epsame");
   
   Double_t gaeCrossSyst_fx3001[2] = {
   11,
   32.5};
   Double_t gaeCrossSyst_fy3001[2] = {
   316468.6,
   8318.448};
   Double_t gaeCrossSyst_felx3001[2] = {
   4,
   17.5};
   Double_t gaeCrossSyst_fely3001[2] = {
   61706.28,
   799.082};
   Double_t gaeCrossSyst_fehx3001[2] = {
   4,
   17.5};
   Double_t gaeCrossSyst_fehy3001[2] = {
   61706.28,
   799.082};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(2,gaeCrossSyst_fx3001,gaeCrossSyst_fy3001,gaeCrossSyst_felx3001,gaeCrossSyst_fehx3001,gaeCrossSyst_fely3001,gaeCrossSyst_fehy3001);
   grae->SetName("gaeCrossSyst");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.8);
   
   TH1F *Graph_gaeCrossSyst3001 = new TH1F("Graph_gaeCrossSyst3001","Graph",100,2.7,54.3);
   Graph_gaeCrossSyst3001->SetMinimum(6767.429);
   Graph_gaeCrossSyst3001->SetMaximum(415240.4);
   Graph_gaeCrossSyst3001->SetDirectory(0);
   Graph_gaeCrossSyst3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gaeCrossSyst3001->SetLineColor(ci);
   Graph_gaeCrossSyst3001->SetMarkerStyle(20);
   Graph_gaeCrossSyst3001->GetXaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3001->GetXaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3001->GetXaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3001->GetXaxis()->SetTitleFont(42);
   Graph_gaeCrossSyst3001->GetYaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3001->GetYaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3001->GetYaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3001->GetYaxis()->SetTitleFont(42);
   Graph_gaeCrossSyst3001->GetZaxis()->SetLabelFont(42);
   Graph_gaeCrossSyst3001->GetZaxis()->SetLabelSize(0.035);
   Graph_gaeCrossSyst3001->GetZaxis()->SetTitleSize(0.035);
   Graph_gaeCrossSyst3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gaeCrossSyst3001);
   
   grae->Draw("5");
   TLatex *   tex = new TLatex(0.21,0.88,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.95,"28 pb^{-1} (pp) + 351 #mub^{-1} (PbPb) 5.02 TeV");
tex->SetNDC();
   tex->SetTextAlign(32);
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.65,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.85,0.82,"B^{0}_{s}");
tex->SetNDC();
   tex->SetTextSize(0.07);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t gaeCrossSyst_fx3002[2] = {
   11,
   32.5};
   Double_t gaeCrossSyst_fy3002[2] = {
   477201.3,
   7268.978};
   Double_t gaeCrossSyst_felx3002[2] = {
   4,
   17.5};
   Double_t gaeCrossSyst_fely3002[2] = {
   126156.8,
   1185.805};
   Double_t gaeCrossSyst_fehx3002[2] = {
   4,
   17.5};
   Double_t gaeCrossSyst_fehy3002[2] = {
   126156.8,
   1185.805};
   grae = new TGraphAsymmErrors(2,gaeCrossSyst_fx3002,gaeCrossSyst_fy3002,gaeCrossSyst_felx3002,gaeCrossSyst_fehx3002,gaeCrossSyst_fely3002,gaeCrossSyst_fehy3002);
   grae->SetName("gaeCrossSyst");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineColor(2);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.8);
   
   TH1F *Graph_Graph_gaeCrossSyst30013002 = new TH1F("Graph_Graph_gaeCrossSyst30013002","Graph",100,2.7,54.3);
   Graph_Graph_gaeCrossSyst30013002->SetMinimum(5474.856);
   Graph_Graph_gaeCrossSyst30013002->SetMaximum(663085.6);
   Graph_Graph_gaeCrossSyst30013002->SetDirectory(0);
   Graph_Graph_gaeCrossSyst30013002->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph_gaeCrossSyst30013002->SetLineColor(ci);
   Graph_Graph_gaeCrossSyst30013002->SetMarkerStyle(20);
   Graph_Graph_gaeCrossSyst30013002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_gaeCrossSyst30013002->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_gaeCrossSyst30013002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_gaeCrossSyst30013002->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_gaeCrossSyst30013002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_gaeCrossSyst30013002->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph_gaeCrossSyst30013002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_gaeCrossSyst30013002);
   
   grae->Draw("5");
   Double_t xAxis2[3] = {7, 15, 50}; 
   
   TH1D *hPtSigma3 = new TH1D("hPtSigma3","",2, xAxis2);
   hPtSigma3->SetBinContent(1,477201.3);
   hPtSigma3->SetBinContent(2,7268.978);
   hPtSigma3->SetBinError(1,183403.5);
   hPtSigma3->SetBinError(2,2350.78);
   hPtSigma3->SetEntries(6.976662);
   hPtSigma3->SetLineColor(2);
   hPtSigma3->SetLineStyle(0);
   hPtSigma3->SetLineWidth(2);
   hPtSigma3->SetMarkerColor(2);
   hPtSigma3->SetMarkerStyle(21);
   hPtSigma3->SetMarkerSize(1.2);
   hPtSigma3->GetXaxis()->SetLabelFont(42);
   hPtSigma3->GetXaxis()->SetLabelOffset(0.007);
   hPtSigma3->GetXaxis()->SetLabelSize(0.05);
   hPtSigma3->GetXaxis()->SetTitleSize(0.06);
   hPtSigma3->GetXaxis()->SetTitleOffset(0.9);
   hPtSigma3->GetXaxis()->SetTitleFont(42);
   hPtSigma3->GetYaxis()->SetLabelFont(42);
   hPtSigma3->GetYaxis()->SetLabelOffset(0.007);
   hPtSigma3->GetYaxis()->SetLabelSize(0.05);
   hPtSigma3->GetYaxis()->SetTitleSize(0.06);
   hPtSigma3->GetYaxis()->SetTitleOffset(1.05);
   hPtSigma3->GetYaxis()->SetTitleFont(42);
   hPtSigma3->GetZaxis()->SetLabelFont(42);
   hPtSigma3->GetZaxis()->SetLabelOffset(0.007);
   hPtSigma3->GetZaxis()->SetLabelSize(0.05);
   hPtSigma3->GetZaxis()->SetTitleSize(0.06);
   hPtSigma3->GetZaxis()->SetTitleFont(42);
   hPtSigma3->Draw("epsame");
   
   TLegend *leg = new TLegend(0.52,0.7,0.85,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.055);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("hPtSigma","Data pp","pf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("hPtSigma","Data PbPb","pf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
      tex = new TLatex(0.53,0.594,"Global uncertainty:");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.54,"pp: #pm7.9%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.48,"PbPb: #plus8.3, #minus8.5%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
   cSigma->Modified();
   cSigma->cd();
   cSigma->SetSelected(cSigma);
}
