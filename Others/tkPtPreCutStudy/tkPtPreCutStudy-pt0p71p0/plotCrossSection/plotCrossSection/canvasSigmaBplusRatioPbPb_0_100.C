void canvasSigmaBplusRatioPbPb_0_100()
{
//=========Macro generated from canvas: cSigma/
//=========  (Wed Mar  7 02:25:06 2018) by ROOT version6.02/13
   TCanvas *cSigma = new TCanvas("cSigma", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   cSigma->SetHighLightColor(2);
   cSigma->Range(1.83879,1.47101,58.06045,7.348675);
   cSigma->SetFillColor(0);
   cSigma->SetBorderMode(0);
   cSigma->SetBorderSize(2);
   cSigma->SetLogy();
   cSigma->SetLeftMargin(0.1451613);
   cSigma->SetRightMargin(0.05443548);
   cSigma->SetTopMargin(0.05932203);
   cSigma->SetFrameBorderMode(0);
   cSigma->SetFrameBorderMode(0);
   
   TH2F *hemptySigma1 = new TH2F("hemptySigma1","",50,10,55,10,100,1e+07);
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
   hemptySigma1->GetXaxis()->SetLabelOffset(0.0015);
   hemptySigma1->GetXaxis()->SetLabelSize(0.036);
   hemptySigma1->GetXaxis()->SetTitleSize(0.036);
   hemptySigma1->GetXaxis()->SetTitleFont(42);
   hemptySigma1->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{dN}{dp_{T}} ( pb GeV^{-1}c)");
   hemptySigma1->GetYaxis()->CenterTitle(true);
   hemptySigma1->GetYaxis()->SetLabelFont(42);
   hemptySigma1->GetYaxis()->SetLabelSize(0.042);
   hemptySigma1->GetYaxis()->SetTitleSize(0.042);
   hemptySigma1->GetYaxis()->SetTitleOffset(1.428571);
   hemptySigma1->GetYaxis()->SetTitleFont(42);
   hemptySigma1->GetZaxis()->SetLabelFont(42);
   hemptySigma1->GetZaxis()->SetLabelSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleSize(0.035);
   hemptySigma1->GetZaxis()->SetTitleFont(42);
   hemptySigma1->Draw("");
   Double_t xAxis1[2] = {15, 50}; 
   
   TH1D *hPtSigma2 = new TH1D("hPtSigma2","",1, xAxis1);
   hPtSigma2->SetBinContent(1,5320.19);
   hPtSigma2->SetBinError(1,2065.128);
   hPtSigma2->SetEntries(6.636828);
   hPtSigma2->SetLineWidth(2);
   hPtSigma2->SetMarkerStyle(20);
   hPtSigma2->SetMarkerSize(0.84);
   hPtSigma2->GetXaxis()->SetLabelFont(42);
   hPtSigma2->GetXaxis()->SetLabelSize(0.035);
   hPtSigma2->GetXaxis()->SetTitleSize(0.035);
   hPtSigma2->GetXaxis()->SetTitleFont(42);
   hPtSigma2->GetYaxis()->SetLabelFont(42);
   hPtSigma2->GetYaxis()->SetLabelSize(0.035);
   hPtSigma2->GetYaxis()->SetTitleSize(0.035);
   hPtSigma2->GetYaxis()->SetTitleFont(42);
   hPtSigma2->GetZaxis()->SetLabelFont(42);
   hPtSigma2->GetZaxis()->SetLabelSize(0.035);
   hPtSigma2->GetZaxis()->SetTitleSize(0.035);
   hPtSigma2->GetZaxis()->SetTitleFont(42);
   hPtSigma2->Draw("epsame");
   
   Double_t gaeCrossSyst_fx3001[1] = {
   32.5};
   Double_t gaeCrossSyst_fy3001[1] = {
   5320.19};
   Double_t gaeCrossSyst_felx3001[1] = {
   17.5};
   Double_t gaeCrossSyst_fely3001[1] = {
   827.1083};
   Double_t gaeCrossSyst_fehx3001[1] = {
   17.5};
   Double_t gaeCrossSyst_fehy3001[1] = {
   827.1083};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(1,gaeCrossSyst_fx3001,gaeCrossSyst_fy3001,gaeCrossSyst_felx3001,gaeCrossSyst_fehx3001,gaeCrossSyst_fely3001,gaeCrossSyst_fehy3001);
   grae->SetName("gaeCrossSyst");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);
   grae->SetFillStyle(0);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   grae->SetMarkerSize(0.8);
   
   TH1F *Graph_gaeCrossSyst3001 = new TH1F("Graph_gaeCrossSyst3001","Graph",100,11.5,53.5);
   Graph_gaeCrossSyst3001->SetMinimum(4327.66);
   Graph_gaeCrossSyst3001->SetMaximum(6312.72);
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
   TLatex *   tex = new TLatex(0.18,0.909,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.056);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.18,0.853,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.056);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.9552,"351 #mub^{-1} (PbPb 5.02 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.755,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.77,0.874,"B_{s}");
tex->SetNDC();
   tex->SetTextSize(0.063);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.53,0.713,"Global uncert. #plus8.3, #minus8.5%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.52,0.79,0.85,0.86,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.035);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("hPtSigma","Data","pf");
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(0.84);
   entry->SetTextFont(42);
   leg->Draw();
   cSigma->Modified();
   cSigma->cd();
   cSigma->SetSelected(cSigma);
}
