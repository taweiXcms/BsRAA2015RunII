void canvas1DhEff_pp()
{
//=========Macro generated from canvas: canvas1D/
//=========  (Fri Oct  6 16:07:45 2017) by ROOT version6.02/13
   TCanvas *canvas1D = new TCanvas("canvas1D", "",0,0,600,600);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   canvas1D->SetHighLightColor(2);
   canvas1D->Range(-8.125001,-0.07500001,73.125,0.675);
   canvas1D->SetFillColor(0);
   canvas1D->SetBorderMode(0);
   canvas1D->SetBorderSize(2);
   canvas1D->SetFrameBorderMode(0);
   canvas1D->SetFrameBorderMode(0);
   
   TH2F *hemptyEff1 = new TH2F("hemptyEff1","",50,0,65,10,0,0.6);
   hemptyEff1->SetMinimum(0);
   hemptyEff1->SetMaximum(0.6);
   hemptyEff1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   hemptyEff1->SetLineColor(ci);
   hemptyEff1->SetMarkerStyle(20);
   hemptyEff1->GetXaxis()->SetTitle("p_{T} GeV/c)");
   hemptyEff1->GetXaxis()->CenterTitle(true);
   hemptyEff1->GetXaxis()->SetLabelFont(42);
   hemptyEff1->GetXaxis()->SetLabelSize(0.035);
   hemptyEff1->GetXaxis()->SetTitleSize(0.05);
   hemptyEff1->GetXaxis()->SetTitleOffset(0.9);
   hemptyEff1->GetXaxis()->SetTitleFont(42);
   hemptyEff1->GetYaxis()->SetTitle("#alpha x #epsilon");
   hemptyEff1->GetYaxis()->CenterTitle(true);
   hemptyEff1->GetYaxis()->SetLabelFont(42);
   hemptyEff1->GetYaxis()->SetLabelSize(0.035);
   hemptyEff1->GetYaxis()->SetTitleSize(0.05);
   hemptyEff1->GetYaxis()->SetTitleOffset(0.95);
   hemptyEff1->GetYaxis()->SetTitleFont(42);
   hemptyEff1->GetZaxis()->SetLabelFont(42);
   hemptyEff1->GetZaxis()->SetLabelSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleSize(0.035);
   hemptyEff1->GetZaxis()->SetTitleFont(42);
   hemptyEff1->Draw("");
   Double_t xAxis1[5] = {5, 10, 15, 20, 60}; 
   
   TH1D *hEff2 = new TH1D("hEff2","",4, xAxis1);
   hEff2->SetBinContent(1,0.002574449);
   hEff2->SetBinContent(2,0.04625647);
   hEff2->SetBinContent(3,0.123867);
   hEff2->SetBinContent(4,0.2083601);
   hEff2->SetBinContent(5,0.1157392);
   hEff2->SetBinError(1,0.0002427035);
   hEff2->SetBinError(2,0.002037258);
   hEff2->SetBinError(3,0.00631603);
   hEff2->SetBinError(4,0.01065728);
   hEff2->SetBinError(5,0.1100276);
   hEff2->SetEntries(920.8898);
   hEff2->SetStats(0);
   hEff2->SetLineColor(2);
   hEff2->SetMarkerColor(2);
   hEff2->SetMarkerStyle(20);
   hEff2->GetXaxis()->CenterTitle(true);
   hEff2->GetXaxis()->SetLabelFont(42);
   hEff2->GetXaxis()->SetLabelSize(0.035);
   hEff2->GetXaxis()->SetTitleSize(0.035);
   hEff2->GetXaxis()->SetTitleFont(42);
   hEff2->GetYaxis()->CenterTitle(true);
   hEff2->GetYaxis()->SetLabelFont(42);
   hEff2->GetYaxis()->SetLabelSize(0.035);
   hEff2->GetYaxis()->SetTitleSize(0.035);
   hEff2->GetYaxis()->SetTitleFont(42);
   hEff2->GetZaxis()->SetLabelFont(42);
   hEff2->GetZaxis()->SetLabelSize(0.035);
   hEff2->GetZaxis()->SetTitleSize(0.035);
   hEff2->GetZaxis()->SetTitleFont(42);
   hEff2->Draw("same");
   TLatex *   tex = new TLatex(0.5,0.75,"|y| < 2.4");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.08,0.95,"CMS Internal");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.9,0.92,"27.87 pb^{-1} (5.03 TeV pp)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.038);
   tex->SetLineWidth(2);
   tex->Draw();
   canvas1D->Modified();
   canvas1D->cd();
   canvas1D->SetSelected(canvas1D);
}
