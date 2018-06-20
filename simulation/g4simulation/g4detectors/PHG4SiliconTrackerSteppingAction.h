#ifndef PHG4VSiliconTrackerSteppingAction_h
#define PHG4VSiliconTrackerSteppingAction_h

#include <g4main/PHG4SteppingAction.h>

#include <map>

class PHG4SiliconTrackerDetector;
class PHParametersContainer;
class PHG4Hit;
class PHG4HitContainer;
class PHG4Shower;

class PHG4SiliconTrackerSteppingAction : public PHG4SteppingAction
{
 public:
  PHG4SiliconTrackerSteppingAction(PHG4SiliconTrackerDetector *, const PHParametersContainer *parameters);

  virtual ~PHG4SiliconTrackerSteppingAction();

  virtual bool UserSteppingAction(const G4Step *, bool);

  virtual void SetInterfacePointers(PHCompositeNode *);

 private:
  //! pointer to the detector
  PHG4SiliconTrackerDetector *detector_;

  //! pointer to hit container
  PHG4HitContainer *hits_;
  PHG4HitContainer *absorberhits_;
  PHG4Hit *hit;
  PHG4HitContainer *savehitcontainer;
  PHG4Shower *saveshower;
  const PHParametersContainer *paramscontainer;

  double strip_y[4];
  double strip_z[4][2];
  int nstrips_z_sensor[4][2];
  int nstrips_phi_cell[4];
  std::map<int, int> IsActive;
  std::map<int, int> IsBlackHole;
  std::map<std::string, int> AbsorberIndex;
  std::set<std::string> missingabsorbers;
};

#endif  // PHG4SiliconTrackerSteppingAction_h
