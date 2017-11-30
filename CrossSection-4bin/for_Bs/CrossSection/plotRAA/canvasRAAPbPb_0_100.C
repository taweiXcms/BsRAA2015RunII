void canvasRAAPbPb_0_100()
{
//=========Macro generated from canvas: canvasRAA/canvasRAA
//=========  (Sat Sep 23 08:38:08 2017) by ROOT version6.02/13
   TCanvas *canvasRAA = new TCanvas("canvasRAA", "canvasRAA",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvasRAA->SetHighLightColor(2);
   canvasRAA->Range(1.015265,-0.2310559,1.837583,1.69441);
   canvasRAA->SetFillColor(0);
   canvasRAA->SetBorderMode(0);
   canvasRAA->SetBorderSize(2);
   canvasRAA->SetLogx();
   canvasRAA->SetLeftMargin(0.12);
   canvasRAA->SetRightMargin(0.03);
   canvasRAA->SetTopMargin(0.075);
   canvasRAA->SetBottomMargin(0.12);
   canvasRAA->SetFrameBorderMode(0);
   canvasRAA->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,13,65,10,0,1.55);
   hemptyEff1->SetMinimum(0);
   hemptyEff1->SetMaximum(2);
   hemptyEff1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff1->SetLineColor(ci);
   hemptyEff1->SetMarkerStyle(20);
   hemptyEff1->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff1->GetXaxis()->CenterTitle(true);
   hemptyEff1->GetXaxis()->SetLabelFont(42);
   hemptyEff1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff1->GetXaxis()->SetTitleFont(42);
   hemptyEff1->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff1->GetYaxis()->CenterTitle(true);
   hemptyEff1->GetYaxis()->SetLabelFont(42);
   hemptyEff1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff1->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff1->GetYaxis()->SetTitleFont(42);
   hemptyEff1->GetZaxis()->SetLabelFont(42);
   hemptyEff1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleFont(42);
   hemptyEff1->Draw("");
   TLine *line = new TLine(13,1,65,1);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TBox *box = new TBox(13,0.8492652,13.35,1.150735);
   box->SetFillColor(16);
   box->SetLineColor(16);
   box->Draw();
   TLatex *   tex = new TLatex(0.38,0.595,"Centrality 0-100%");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.13,0.936,"27.4 pb^{-1} (5.02 TeV pp) + 350.68 #mub^{-1} (5.02 TeV PbPb)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.9,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.15,0.84,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.23,0.7,"T_{AA} and lumi.");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.23,0.65,"uncertainty");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t gNuclearModification_fx3001[1] = {
   37.5};
   Double_t gNuclearModification_fy3001[1] = {
   0.4876816};
   Double_t gNuclearModification_felx3001[1] = {
   22.5};
   Double_t gNuclearModification_fely3001[1] = {
   0.1184507};
   Double_t gNuclearModification_fehx3001[1] = {
   22.5};
   Double_t gNuclearModification_fehy3001[1] = {
   0.1184507};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(1,gNuclearModification_fx3001,gNuclearModification_fy3001,gNuclearModification_felx3001,gNuclearModification_fehx3001,gNuclearModification_fely3001,gNuclearModification_fehy3001);
   grae->SetName("gNuclearModification");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#0099ff");
   grae->SetFillColor(ci);
   grae->SetFillStyle(3001);

   ci = TColor::GetColor("#0099ff");
   grae->SetLineColor(ci);

   ci = TColor::GetColor("#330066");
   grae->SetMarkerColor(ci);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_gNuclearModification3001 = new TH1F("Graph_gNuclearModification3001","Graph",100,10.5,64.5);
   Graph_gNuclearModification3001->SetMinimum(0.3455407);
   Graph_gNuclearModification3001->SetMaximum(0.6298225);
   Graph_gNuclearModification3001->SetDirectory(0);
   Graph_gNuclearModification3001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_gNuclearModification3001->SetLineColor(ci);
   Graph_gNuclearModification3001->SetMarkerStyle(20);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetXaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetXaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetYaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetYaxis()->SetTitleFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelFont(42);
   Graph_gNuclearModification3001->GetZaxis()->SetLabelSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleSize(0.035);
   Graph_gNuclearModification3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_gNuclearModification3001);
   
   grae->Draw("5");
   Double_t xAxis1[2] = {15, 60}; 
   
   TH1D *hNuclearModification2 = new TH1D("hNuclearModification2","",1, xAxis1);
   hNuclearModification2->SetBinContent(1,0.4876816);
   hNuclearModification2->SetBinError(1,0.2376797);
   hNuclearModification2->SetEntries(4.210062);

   ci = TColor::GetColor("#330066");
   hNuclearModification2->SetLineColor(ci);
   hNuclearModification2->SetLineWidth(3);

   ci = TColor::GetColor("#330066");
   hNuclearModification2->SetMarkerColor(ci);
   hNuclearModification2->SetMarkerStyle(21);
   hNuclearModification2->SetMarkerSize(1.2);
   hNuclearModification2->GetXaxis()->SetTitle("Bs^{0} p_{T} (GeV/c)");
   hNuclearModification2->GetXaxis()->SetLabelFont(42);
   hNuclearModification2->GetXaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetXaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetXaxis()->SetTitleFont(42);
   hNuclearModification2->GetYaxis()->SetTitle("Uncorrected dN(Bs^{0})/dp_{T}");
   hNuclearModification2->GetYaxis()->SetLabelFont(42);
   hNuclearModification2->GetYaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetYaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetYaxis()->SetTitleFont(42);
   hNuclearModification2->GetZaxis()->SetLabelFont(42);
   hNuclearModification2->GetZaxis()->SetLabelSize(0.035);
   hNuclearModification2->GetZaxis()->SetTitleSize(0.035);
   hNuclearModification2->GetZaxis()->SetTitleFont(42);
   hNuclearModification2->Draw("same");
   
   TLegend *leg = new TLegend(0.6036242,0.7474695,0.942953,0.8457592,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.04);
   leg->SetLineColor(0);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("gNuclearModification","B^{+} |y| < 2.4","pf");

   ci = TColor::GetColor("#0099ff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(3001);

   ci = TColor::GetColor("#0099ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);

   ci = TColor::GetColor("#330066");
   entry->SetMarkerColor(ci);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry->SetTextSize(0.038);
   leg->Draw();
   
   TH2F *hemptyEff_copy3 = new TH2F("hemptyEff_copy3","",50,13,65,10,0,1.55);
   hemptyEff_copy3->SetMinimum(0);
   hemptyEff_copy3->SetMaximum(2);
   hemptyEff_copy3->SetDirectory(0);
   hemptyEff_copy3->SetStats(0);

   ci = TColor::GetColor("#000099");
   hemptyEff_copy3->SetLineColor(ci);
   hemptyEff_copy3->SetMarkerStyle(20);
   hemptyEff_copy3->GetXaxis()->SetTitle("p_{T} (GeV/c)");
   hemptyEff_copy3->GetXaxis()->CenterTitle(true);
   hemptyEff_copy3->GetXaxis()->SetLabelFont(42);
   hemptyEff_copy3->GetXaxis()->SetTitleSize(0.05);
   hemptyEff_copy3->GetXaxis()->SetTitleFont(42);
   hemptyEff_copy3->GetYaxis()->SetTitle("R_{AA}");
   hemptyEff_copy3->GetYaxis()->CenterTitle(true);
   hemptyEff_copy3->GetYaxis()->SetLabelFont(42);
   hemptyEff_copy3->GetYaxis()->SetTitleSize(0.05);
   hemptyEff_copy3->GetYaxis()->SetTitleOffset(1.1);
   hemptyEff_copy3->GetYaxis()->SetTitleFont(42);
   hemptyEff_copy3->GetZaxis()->SetLabelFont(42);
   hemptyEff_copy3->GetZaxis()->SetLabelSize(0.035);
   hemptyEff_copy3->GetZaxis()->SetTitleSize(0.035);
   hemptyEff_copy3->GetZaxis()->SetTitleFont(42);
   hemptyEff_copy3->Draw("sameaxis");
   canvasRAA->Modified();
   canvasRAA->cd();
   canvasRAA->SetSelected(canvasRAA);
}
