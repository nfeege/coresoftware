#ifndef RawTowerGeomContainerv1_H__
#define RawTowerGeomContainerv1_H__


#include "RawTowerGeomContainer.h"

/*! \class RawTowerGeomContainerv1
    \brief Generic tower geometry class, store each tower's geometry individually
*/
class RawTowerGeomContainerv1 : public RawTowerGeomContainer
{

 public:

  RawTowerGeomContainerv1( RawTowerDefs::CalorimeterId caloid = RawTowerDefs::NONE);
  virtual ~RawTowerGeomContainerv1();

  virtual void Reset();
  virtual int isValid() const;
  virtual void identify(std::ostream& os=std::cout) const;

  void set_calorimeter_id( RawTowerDefs::CalorimeterId caloid ) { _caloid = caloid; }
  RawTowerDefs::CalorimeterId get_calorimeter_id( ) const { return _caloid; }

  ConstIterator add_tower_geometry(RawTowerGeom *geo);
  RawTowerGeom *get_tower_geometry(RawTowerDefs::keytype key);

  //! return all tower geometries
  ConstRange get_tower_geometries( void ) const;
  Range get_tower_geometries( void );

  unsigned int size() const {return _geoms.size();}

 protected:

  RawTowerDefs::CalorimeterId _caloid;
  Map _geoms;

  ClassDef(RawTowerGeomContainerv1,1)
};

#endif /* RawTowerGeomContainerv1_H__ */
