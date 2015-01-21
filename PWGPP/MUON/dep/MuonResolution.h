//--------------------------------------------------------------------------
// Class compiled and launch by RunMuonResolution.C for submitting muon Resolution analysis locally or on CAF.
// See RunMuonResolution.C for more details
//
// Author: Philippe Pillot - SUBATECH Nantes
//--------------------------------------------------------------------------

#if !defined(__CINT__) || defined(__MAKECINT__)
// ROOT includes
#include <TString.h>
#include <TChain.h>

// STEER includes
#include "AliAnalysisTaskMuonResolution.h"

// MUON includes
#include "AliMUONTrackerData.h"

#endif

enum {kLocal, kInteractif_xml, kInteractif_ESDList, kProof};

void    LoadAlirootOnProof(TString& aaf, TString alirootVersion, TString& extraLibs, Int_t iStep);
AliAnalysisTaskMuonResolution* CreateAnalysisTrain(Int_t mode, Int_t iStep, Bool_t selectPhysics, Bool_t selectTrigger, Bool_t matchTrig,
						   Bool_t applyAccCut, Double_t minMomentum, Bool_t correctForSystematics, Int_t extrapMode,
						   Double_t clusterResNB[10], Double_t clusterResB[10]);
Bool_t  GetChamberResolution(Int_t iStep, Double_t clusterResNB[10], Double_t clusterResB[10],
			     Double_t clusterResNBErr[10], Double_t clusterResBErr[10]);
void    AddMCHViews(TFile* file);
AliMUONTrackerData* ConvertGraph(TGraphErrors& g, const char* name);
Int_t   GetMode(TString smode, TString input);
TChain* CreateChainFromCollection(const char *xmlfile);
TChain* CreateChainFromFile(const char *rootfile);
TChain* CreateChainFromESDList(const char *esdList);
TChain* CreateChain(Int_t mode, TString input);
void MuonResolution(TString smode, TString inputFileName, TString alirootVersion, Int_t nSteps, Bool_t selectPhysics, Bool_t selectTrigger, Bool_t matchTrig,
		    Bool_t applyAccCut, Double_t minMomentum, Bool_t correctForSystematics, Int_t extrapMode, Int_t nevents, TString extraLibs);

