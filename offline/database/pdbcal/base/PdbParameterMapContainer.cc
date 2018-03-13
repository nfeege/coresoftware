#include "PdbParameterMapContainer.h"
#include "PdbParameterMap.h"
#include "PdbBankID.h"

#include <phool/phool.h>
#include <phool/PHTimeStamp.h>

#include <TBufferXML.h>
#include <TFile.h>
#include <TSystem.h>

#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

PdbParameterMapContainer::~PdbParameterMapContainer()
{
  while(parametermap.begin() != parametermap.end())
    {
      delete parametermap.begin()->second;
      parametermap.erase(parametermap.begin());
    }
  return;
}

void
PdbParameterMapContainer::print() const
{
  for (map<int, PdbParameterMap *>::const_iterator iter = parametermap.begin(); 
       iter != parametermap.end(); ++iter)
    {
      cout << "layer " << iter->first << endl;
      iter->second->print();
    }
  return;
}
void PdbParameterMapContainer::Reset()
{
  while(parametermap.begin() != parametermap.end())
    {
      delete parametermap.begin()->second;
      parametermap.erase(parametermap.begin());
    }
  return;
}

void
PdbParameterMapContainer::AddPdbParameterMap(const int layer, PdbParameterMap *params)
{
  if (parametermap.find(layer) != parametermap.end())
    {
      cout << PHWHERE << " layer " << layer << " already exists" << endl; 
      gSystem->Exit(1);
    }
  parametermap[layer] = params;
}

const PdbParameterMap *
PdbParameterMapContainer::GetParameters(const int layer) const
{
  map<int, PdbParameterMap *>::const_iterator iter = parametermap.find(layer);
  if (iter == parametermap.end())
    {
      return NULL;
    }
  return iter->second;
}

PdbParameterMap *
PdbParameterMapContainer::GetParametersToModify(const int layer)
{
  map<int, PdbParameterMap *>::iterator iter = parametermap.find(layer);
  if (iter == parametermap.end())
    {
      return NULL;
    }
  return iter->second;
}

int
PdbParameterMapContainer::WriteToFile(const std::string &detector_name,
    const string &extension, const string &dir)
{
  //Note the naming convention should be consistent with PHParameters::WriteToFile

  ostringstream fullpath;
  ostringstream fnamestream;
  PdbBankID bankID(0); // lets start at zero
  PHTimeStamp TStart(0);
  PHTimeStamp TStop(0xffffffff);
  fullpath << dir;
  // add / if directory lacks ending /
  if (*(dir.rbegin()) != '/')
    {
      fullpath << "/";
    }
  fnamestream << detector_name << "_geoparams" << "-"
      << bankID.getInternalValue() << "-" << TStart.getTics() << "-"
      << TStop.getTics() << "-" << time(0) << "." << extension;
  string fname = fnamestream.str();
  std::transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
  fullpath << fname;

  cout << "PdbParameterMapContainer::WriteToFile - save to " << fullpath.str()
      << endl;

  TFile *f = TFile::Open(fullpath.str().c_str(), "recreate");

  PdbParameterMapContainer * container = new PdbParameterMapContainer();
  for (std::map<int, PdbParameterMap *>::const_iterator it =
      parametermap.begin(); it != parametermap.end(); ++it)
    {
      PdbParameterMap *myparm = static_cast<PdbParameterMap *> (it->second->Clone());
      container->AddPdbParameterMap(it->first, myparm);
    }

  // force xml file writing to use extended precision shown experimentally
  // to not modify input parameters (.15e)
  string floatformat = TBufferXML::GetFloatFormat();
  TBufferXML::SetFloatFormat("%.17g"); // for IEEE 754 double
  container->Write("PdbParameterMapContainer");
  delete f;
  // restore previous xml float format
  TBufferXML::SetFloatFormat(floatformat.c_str());
  cout << "sleeping 1 second to prevent duplicate inserttimes" << endl;
  sleep(1);
  return 0;
}
