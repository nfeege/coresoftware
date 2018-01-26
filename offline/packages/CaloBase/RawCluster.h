#ifndef RAWCLUSTER_H__
#define RAWCLUSTER_H__

#include "RawClusterDefs.h"
#include "RawTowerDefs.h"

#include <CLHEP/Vector/ThreeVector.h>

#include <phool/PHObject.h>
#include <phool/phool.h>
#include <climits>
#include <cmath>  // def of NAN
#include <map>

class RawTower;

class RawCluster : public PHObject
{
 public:
  typedef std::map<RawTowerDefs::keytype, float> TowerMap;
  typedef TowerMap::iterator TowerIterator;
  typedef TowerMap::const_iterator TowerConstIterator;
  typedef std::pair<TowerIterator, TowerIterator> TowerRange;
  typedef std::pair<TowerConstIterator, TowerConstIterator> TowerConstRange;

  virtual ~RawCluster() {}
  virtual void Reset() { PHOOL_VIRTUAL_WARNING; }

  /// make a copy, using TObject::Clone() function instead
//  virtual PHObject* clone() const
//  {
//    PHOOL_VIRTUAL_WARNING;
//    return nullptr;
//  };

  virtual int isValid() const
  {
    PHOOL_VIRTUAL_WARNING;
    return 0;
  }
  virtual void identify(std::ostream& os = std::cout) const { PHOOL_VIRTUAL_WARNING; }
  /** @defgroup getters
   *  @{
   */
  //! cluster ID
  virtual RawClusterDefs::keytype get_id() const
  {
    PHOOL_VIRTUAL_WARN("get_id()");
    return 0;
  }
  //! total energy
  virtual float get_energy() const
  {
    PHOOL_VIRTUAL_WARN("get_energy()");
    return NAN;
  }
  //! Tower operations
  virtual size_t getNTowers() const
  {
    PHOOL_VIRTUAL_WARNING;
    return 0;
  }
  virtual TowerConstRange get_towers()
  {
    PHOOL_VIRTUAL_WARN("get_towers()");
    static TowerMap dummy;
    return make_pair(dummy.begin(), dummy.end());
  }
  //! return tower map for c++11 range-based for-loop
  virtual const TowerMap& get_towermap() const
  {
    PHOOL_VIRTUAL_WARN("get_towers()");
    static TowerMap dummy;
    return dummy;
  }

  virtual CLHEP::Hep3Vector get_position() const
  {
    PHOOL_VIRTUAL_WARN("get_position()");
    return CLHEP::Hep3Vector(NAN, NAN, NAN);
  }
  //
  //!  access to intrinsic cylindrical coordinate system
  virtual float get_phi() const
  {
    PHOOL_VIRTUAL_WARN("get_phi()");
    return NAN;
  }
  virtual float get_r() const
  {
    PHOOL_VIRTUAL_WARN("get_r()");
    return NAN;
  }
  virtual float get_z() const
  {
    PHOOL_VIRTUAL_WARN("get_z()");
    return NAN;
  }
  //
  //  //! convert cluster location to psuedo-rapidity given a user chosen z-location
  //  virtual float get_eta(const float z) const
  //  {
  //    PHOOL_VIRTUAL_WARN("get_eta()");
  //    return NAN;
  //  }
  //  //! convert cluster E_T given a user chosen z-location
  //  virtual float get_et(const float z) const
  //  {
  //    PHOOL_VIRTUAL_WARN("get_et()");
  //    return NAN;
  //  }
  //
  //! access Cartesian coordinate system
  virtual float get_x() const
  {
    PHOOL_VIRTUAL_WARN("get_x()");
    return NAN;
  }
  virtual float get_y() const
  {
    PHOOL_VIRTUAL_WARN("get_y()");
    return NAN;
  }
  //
  //! access additional optional properties
  //! cluster core energy for EM shower
  virtual float get_ecore() const
  {
    PHOOL_VIRTUAL_WARN("get_ecore()");
    return NAN;
  }
  //! reduced chi2 for EM shower
  virtual float get_chi2() const
  {
    PHOOL_VIRTUAL_WARN("get_chi2()");
    return NAN;
  }
  //! cluster template probability for EM shower
  virtual float get_prob() const
  {
    PHOOL_VIRTUAL_WARN("get_prob()");
    return NAN;
  }
  //! isolation ET
  virtual float get_et_iso() const
  {
    PHOOL_VIRTUAL_WARN("get_et_iso()");
    return NAN;
  }
  //  //! truth cluster's PHG4Particle ID
  //  virtual int get_truth_track_ID() const
  //  {
  //    PHOOL_VIRTUAL_WARN("get_truth_track_ID()");
  //    return 0;
  //  }
  //  //! truth cluster's PHG4Particle flavor
  //  virtual int get_truth_flavor() const
  //  {
  //    PHOOL_VIRTUAL_WARN("get_truth_flavor()");
  //    return 0;
  //  }
  //
  /** @} */  // end of getters

  /** @defgroup setters
   *  @{
   */
  //! cluster ID
  virtual void set_id(const RawClusterDefs::keytype id) { PHOOL_VIRTUAL_WARNING; }
  //! Tower operations
  virtual void addTower(const RawClusterDefs::keytype twrid, const float etower) { PHOOL_VIRTUAL_WARNING; }
  //! total energy
  virtual void set_energy(const float energy) { PHOOL_VIRTUAL_WARNING; }
  //
  //!  access to intrinsic cylindrical coordinate system
  virtual void set_phi(const float phi) { PHOOL_VIRTUAL_WARNING; }
  virtual void set_z(const float z) { PHOOL_VIRTUAL_WARNING; }
  virtual void set_r(const float r) { PHOOL_VIRTUAL_WARNING; }
  //
  //! access additional optional properties
  //! cluster core energy for EM shower
  virtual void set_ecore(const float ecore) { PHOOL_VIRTUAL_WARNING; }
  //! reduced chi2 for EM shower
  virtual void set_chi2(const float chi2) { PHOOL_VIRTUAL_WARNING; }
  //! cluster template probability for EM shower
  virtual void set_prob(const float prob) { PHOOL_VIRTUAL_WARNING; }
  //! isolation ET
  virtual void set_et_iso(const float e) { PHOOL_VIRTUAL_WARNING; }
  //  //! truth cluster's PHG4Particle ID
  //  virtual void set_truth_track_ID(const int i) { PHOOL_VIRTUAL_WARNING; }
  //  //! truth cluster's PHG4Particle flavor
  //  virtual void set_truth_flavor(const int f) { PHOOL_VIRTUAL_WARNING; }
  //
  /*
   *
   * @} */  // end of setters

  /** @defgroup property_map property map definitions
   *  @{
   */

 public:
  //! Procedure to add a new PROPERTY tag:
  //! 1.add new tag below with unique value,
  //! 2.add a short name to RawCluster::get_property_info()
  enum PROPERTY
  {  //
    // ----- additional cluster properties -----
    //! cluster core energy for EM shower
    prop_ecore = 0,
    //! cluster template probability for EM shower
    prop_prob = 1,
    //! reduced chi2 for EM shower
    prop_chi2 = 2,

    // ----- analysis specific quantities -----
    //! isolation ET
    prop_et_iso = 20,

    //    // ----- truth cluster quantities -----
    //    //! truth cluster's PHG4Particle ID
    //    prop_truth_track_ID = 100,
    //    //! truth cluster's PHG4Particle flavor
    //    prop_truth_flavor = 101,

    //! max limit in order to fit into 8 bit unsigned number
    prop_MAX_NUMBER = UCHAR_MAX
  };

  enum PROPERTY_TYPE
  {  //
    type_int = 1,
    type_uint = 2,
    type_float = 3,
    type_unknown = -1
  };

  //! getters
  virtual bool has_property(const PROPERTY prop_id) const { return false; }
  virtual float get_property_float(const PROPERTY prop_id) const { return NAN; }
  virtual int get_property_int(const PROPERTY prop_id) const { return INT_MIN; }
  virtual unsigned int get_property_uint(const PROPERTY prop_id) const { return UINT_MAX; }
  //! setters
  virtual void set_property(const PROPERTY prop_id, const float value) { return; }
  virtual void set_property(const PROPERTY prop_id, const int value) { return; }
  virtual void set_property(const PROPERTY prop_id, const unsigned int value) { return; }
  //! type management
  static std::pair<const std::string, PROPERTY_TYPE> get_property_info(PROPERTY prop_id);
  static bool check_property(const PROPERTY prop_id, const PROPERTY_TYPE prop_type);
  static std::string get_property_type(const PROPERTY_TYPE prop_type);

  /** @} */  // end of property map definitions

 protected:
  RawCluster() {}  // make sure nobody calls ctor of base class
  ClassDef(RawCluster, 1)
};

#endif /*RAWCLUSTER_H__ */
