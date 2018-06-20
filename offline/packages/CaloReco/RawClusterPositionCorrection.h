#ifndef __RAWCLUSTERPOSITIONCORRECTION_H__
#define __RAWCLUSTERPOSITIONCORRECTION_H__

#include <fun4all/SubsysReco.h>
#include <phparameter/PHParameters.h>
#include <phool/PHObject.h>
#include <string>

class RawClusterContainer;
class RawCluster;
class RawTowerContainer;
class RawTower;
class RawClusterv1;

class RawClusterPositionCorrection : public SubsysReco
{
 public:
  explicit RawClusterPositionCorrection(const std::string &name);

  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void CreateNodeTree(PHCompositeNode *topNode);

  const PHParameters &Get_eclus_CalibrationParameters() const
  {
    return _eclus_calib_params;
  }
  PHParameters &Get_eclus_CalibrationParameters()
  {
    return _eclus_calib_params;
  }
  const PHParameters &Get_eore_CalibrationParameters() const
  {
    return _ecore_calib_params;
  }
  PHParameters &Get_ecore_CalibrationParameters()
  {
    return _ecore_calib_params;
  }

  void Set_eclus_CalibrationParameters(const PHParameters &calib_params)
  {
    _eclus_calib_params = calib_params;
  }
  void Set_ecore_CalibrationParameters(const PHParameters &calib_params)
  {
    _ecore_calib_params = calib_params;
  }

 private:
  PHParameters _eclus_calib_params;
  PHParameters _ecore_calib_params;
  void SetDefaultParameters(PHParameters &param);
  RawClusterContainer *_recalib_clusters;

  std::string _det_name;

  int bins;
  std::vector<float> binvals;
  std::vector<std::vector<double> > eclus_calib_constants;
  std::vector<std::vector<double> > ecore_calib_constants;
};

#endif  // __RAWCLUSTERPOSITIONCORRECTION_H__
