#include "G4RootScintillatorTower.h"

#include <calobase/RawTower.h>

#include <cmath>
#include <iostream>


using namespace std;

ClassImp(G4RootScintillatorTower)

G4RootScintillatorTower::G4RootScintillatorTower() : 
  row(-1),
  column(-1),
  energy(0)
{}

G4RootScintillatorTower::G4RootScintillatorTower(const RawTower &tower) :
  row(tower.get_bineta()),
  column(tower.get_binphi()),
  energy(tower.get_energy())
{}

void G4RootScintillatorTower::Reset()
{
  row = -1;
  column = -1;
  energy = 0;
}

int G4RootScintillatorTower::isValid() const
{
  return (row >= 0);
}

void G4RootScintillatorTower::identify(std::ostream& os) const
{
  os << "G4RootScintillatorTower: row: " << row << ", column: " << column 
     << " energy=" << energy << std::endl;
}

