#ifndef PHG4HcalCellReco_H
#define PHG4HcalCellReco_H

#include <phparameter/PHParameterInterface.h>

#include <fun4all/SubsysReco.h>
#include <phool/PHTimeServer.h>
#include <string>
#include <map>
#include <vector>

class PHCompositeNode;
class PHG4CylinderCell;

class PHG4HcalCellReco : public SubsysReco, public PHParameterInterface
{
 public:

  PHG4HcalCellReco(const std::string &name = "HcalCellReco");

  virtual ~PHG4HcalCellReco(){}
  
  //! module initialization
  int InitRun(PHCompositeNode *topNode);
  
    //! event processing
  int process_event(PHCompositeNode *topNode);
  
  //! end of process
  int End(PHCompositeNode *topNode);
  
  void SetDefaultParameters();

  void Detector(const std::string &d) {detector = d;}
  void checkenergy(const int i=1) {chkenergyconservation = i;}

  void   set_timing_window(const double tmi, const double tma);
  
 protected:
  int CheckEnergy(PHCompositeNode *topNode);
  std::string detector;
  std::string hitnodename;
  std::string cellnodename;
  PHTimeServer::timer _timer;

  int chkenergyconservation;

  double tmin;
  double tmax;
};

#endif
