// Tell emacs that this is a C++ source
// This file is really -*- C++ -*-.
#ifndef G4MAIN_PHG4DETECTOR_H
#define G4MAIN_PHG4DETECTOR_H

#include <Geant4/G4RotationMatrix.hh>

#include <iostream>
#include <string>

class G4LogicalVolume;
class G4UserSteppingAction;
class G4VSolid;
class PHCompositeNode;

//! base class for phenix detector creation
/*! derived classes must implement construct method, which takes the "world" logical volume as argument */
class PHG4Detector
{
 public:
  //! constructor
  // delete default ctor, nobody should use it
  PHG4Detector() = delete;
  // this is the ctor we use
  PHG4Detector(PHCompositeNode *Node, const std::string &nam = "NONE");

  //! destructor
  virtual ~PHG4Detector(void)
  {
  }

  //! construct method
  /*!
  construct all logical and physical volumes relevant for given detector and place them
  inside the world logical volume
  */
  virtual void Construct(G4LogicalVolume *world) = 0;

  virtual void Verbosity(const int v) { m_Verbosity = v; }

  virtual int Verbosity() const { return m_Verbosity; }
  virtual G4UserSteppingAction *GetSteppingAction() { return nullptr; }
  virtual std::string GetName() const { return m_Name; }
  virtual void OverlapCheck(const bool chk) { m_OverlapCheck = chk; }
  virtual bool OverlapCheck() const { return m_OverlapCheck; }
  virtual void Print(const std::string &what = "ALL") const
  {
    std::cout << GetName() << ": Print method not implemented" << std::endl;
  }
  virtual int DisplayVolume(G4VSolid *volume, G4LogicalVolume *logvol, G4RotationMatrix *rotm = nullptr);
  virtual int DisplayVolume(G4LogicalVolume *checksolid, G4LogicalVolume *logvol, G4RotationMatrix *rotm = nullptr);
  virtual PHCompositeNode *topNode() {return m_topNode;}

 private:
  PHCompositeNode *m_topNode;
  int m_Verbosity;
  bool m_OverlapCheck;
  int m_ColorIndex;
  std::string m_Name;
};

#endif  // G4MAIN_PHG4DETECTOR_H
