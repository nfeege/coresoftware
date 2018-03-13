#ifndef PHG4BeamlineMagnetDetector_h
#define PHG4BeamlineMagnetDetector_h

#include <g4main/PHG4Detector.h>

#include <string>

class G4LogicalVolume;
class G4VPhysicalVolume;
class PHParameters;

class PHG4BeamlineMagnetDetector: public PHG4Detector
{

  public:

  //! constructor
  PHG4BeamlineMagnetDetector( PHCompositeNode *Node,  PHParameters *parameters, const std::string &dnam, const int layer = 0 );

  //! destructor
  virtual ~PHG4BeamlineMagnetDetector( void )
  {}

  //! construct
  void Construct( G4LogicalVolume* world );

  bool IsInBeamlineMagnet(const G4VPhysicalVolume*) const;
  void SuperDetector(const std::string &name) {superdetector = name;}
  const std::string SuperDetector() const {return superdetector;}
  int get_Layer() const {return layer;}

  private:

  PHParameters *params;

  G4VPhysicalVolume* magnet_physi;
  G4VPhysicalVolume* cylinder_physi;

  int layer;
  std::string superdetector;
};

#endif
