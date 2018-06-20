#ifndef RawClusterBuilderTemplateFEMC_H__
#define RawClusterBuilderTemplateFEMC_H__

#include <fun4all/SubsysReco.h>
#include <string>

class PHCompositeNode;
class RawCluster;
class RawClusterContainer;
class RawTowerContainer;
class RawTowerGeomContainer;
class BEmcRecFEMC;

class RawClusterBuilderTemplateFEMC : public SubsysReco {

 public:
  RawClusterBuilderTemplateFEMC(const std::string& name = "RawClusterBuilderGraph");
  virtual ~RawClusterBuilderTemplateFEMC();

  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);
  void Detector(const std::string &d) {detector = d;}

  void set_threshold_energy(const float e) {_min_tower_e = e;}
  void setEnergyNorm(float norm) {fEnergyNorm = norm;}
  void checkenergy(const int i = 1) {chkenergyconservation = i;}

 private:
  void CreateNodes(PHCompositeNode *topNode);
  bool Cell2Abs(RawTowerGeomContainer *towergeom, float phiC, float etaC, float& phi, float& eta);

  RawClusterContainer* _clusters;

  BEmcRecFEMC* bemc;
  float fEnergyNorm;

  float _min_tower_e;
  int chkenergyconservation;

  std::string detector;
  std::string ClusterNodeName;

  int BINX0;
  int NBINX;
  int BINY0;
  int NBINY;
  float Zcenter;
};

#endif /* RawClusterBuilderTemplateFEMC_H__ */
