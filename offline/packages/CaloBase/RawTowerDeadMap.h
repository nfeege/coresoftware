#ifndef RawTowerDeadMap_H__
#define RawTowerDeadMap_H__

#include "RawTowerDefs.h"

#include <phool/PHObject.h>
#include <set>

class RawTowerDeadMap : public PHObject
{
 public:
  typedef std::set<RawTowerDefs::keytype> Map;

  virtual ~RawTowerDeadMap() {}
  virtual void Reset();
  virtual int isValid() const;

  virtual void identify(std::ostream &os = std::cout) const;

  virtual void setCalorimeterID(RawTowerDefs::CalorimeterId caloid) {}
  virtual RawTowerDefs::CalorimeterId getCalorimeterID() { return RawTowerDefs::NONE; }
  virtual void addDeadTower(const unsigned int ieta, const unsigned int iphi);
  virtual void addDeadTower(RawTowerDefs::keytype key);

  virtual bool isDeadTower(RawTowerDefs::keytype key);
  virtual bool isDeadTower(const unsigned int ieta, const unsigned int iphi);
  //! return all towers
  virtual const Map &getDeadTowers(void) const;
  virtual Map &getDeadTowers(void);

  virtual unsigned int size() const { return 0; }
 protected:
  RawTowerDeadMap(RawTowerDefs::CalorimeterId caloid = RawTowerDefs::NONE)
  {
  }

 private:
  ClassDef(RawTowerDeadMap, 1)
};

#endif /* RawTowerDeadMap_H__ */
