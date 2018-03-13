// $$Id: PHG4FullProjTiltedSpacalDetector.h,v 1.2 2015/02/10 15:39:26 pinkenbu Exp $$

/*!
 * \file ${file_name}
 * \brief
 * \author Jin Huang <jhuang@bnl.gov>
 * \version $$Revision: 1.2 $$
 * \date $$Date: 2015/02/10 15:39:26 $$
 */

#ifndef PHG4FullProjTiltedSpacalDetector_h
#define PHG4FullProjTiltedSpacalDetector_h

#include "PHG4CylinderGeom_Spacalv3.h"
#include "PHG4SpacalDetector.h"

#include <Geant4/G4Region.hh>
#include <Geant4/G4Types.hh>
#include <Geant4/globals.hh>

#include <map>
#include <set>

class G4Material;
class G4Tubs;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4UserLimits;
class PHParameters;

//! Fully projective SPACAL built from 2D tapered modules and allow azimuthal tilts
class PHG4FullProjTiltedSpacalDetector : public PHG4SpacalDetector
{
 public:
  typedef PHG4CylinderGeom_Spacalv3 SpacalGeom_t;

  PHG4FullProjTiltedSpacalDetector(PHCompositeNode* Node, const std::string& dnam,
                                   PHParameters* parameters, const int layer = 0);

  // empty dtor, step limits are deleted in base class
  virtual ~PHG4FullProjTiltedSpacalDetector(void) {}
  virtual void
  Construct(G4LogicalVolume* world);

  virtual std::pair<G4LogicalVolume*, G4Transform3D>
  Construct_AzimuthalSeg();

  //! a block along z axis built with G4Trd that is slightly tapered in x dimension
  virtual G4LogicalVolume*
  Construct_Tower(const SpacalGeom_t::geom_tower& tower);
  //! a block for the light guide along z axis that fit to the tower
  virtual G4LogicalVolume*
  Construct_LightGuide(const SpacalGeom_t::geom_tower & tower, const int index_x, const int index_y);

  //! a block along z axis built with G4Trd that is slightly tapered in x dimension
  virtual int
  Construct_Fibers(const SpacalGeom_t::geom_tower& tower, G4LogicalVolume* LV_tower);

  //! Fully projective spacal with 2D tapered modules. To speed up construction, same-length fiber is used cross one tower
  virtual int
  Construct_Fibers_SameLengthFiberPerTower(const SpacalGeom_t::geom_tower& tower, G4LogicalVolume* LV_tower);

  virtual void
  Print(const std::string& what = "ALL") const;

  virtual PHG4CylinderGeom* clone_geom() const
  {
    return new SpacalGeom_t(*get_geom_v3());
  }


 private:
//  SpacalGeom_t* _geom;

  //! get the v3 cast of the geometry object
  SpacalGeom_t *
  get_geom_v3()
  {
    return dynamic_cast<SpacalGeom_t *> (_geom);
  }

  const SpacalGeom_t *
  get_geom_v3() const
  {
    return dynamic_cast<const SpacalGeom_t *> (_geom);
  }

};

#endif
