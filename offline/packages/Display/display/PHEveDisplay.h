/*
        \file PHEveDisplay.cxx
        \author Sookhyun Lee
        \brief main display module, load geometry, configure b-field, draw default
        \version $Revision: 1.2 $
        \date    $Date: 07/26/2016
*/

#ifndef __PHEVEDISPLAY_H__
#define __PHEVEDISPLAY_H__

#include<string>
#include "TEveTrackPropagator.h"

class TEveManager;
class TEveElementList;
class PHBFieldMap;
class PHCompositeNode;
class PHEventDisplay;

class PHEveDisplay
{
public:

  class MappedField : public TEveMagField
  {
  public:
    MappedField(const std::string& fname);
    ~MappedField(){};
    using TEveMagField::GetFieldD;

    virtual TEveVectorD GetFieldD(Double_t x, Double_t y, Double_t z) const;
  private:
    PHBFieldMap* _fieldmap;
  };

  PHEveDisplay(int w,
	       int h,
	       bool use_fieldmap,
	       bool use_goefile,
	       const std::string& mapname,
	       const std::string& filename,
	       int verb);
  ~PHEveDisplay();

  void load_geometry(PHCompositeNode* topNode, TEveManager* geve);
  void add_elements(TEveManager* geve);
  void config_bfields();
  void go_fullscreen(TEveManager* geve);
 
  /// Set a pointer to the underlying TEveManager 
  void set_eve_manager(TEveManager* geve){_eve_manager = geve;}
  /// Return a pointer to the underlying TEveManager
  TEveManager* get_eve_manager() const { return _eve_manager;}
  TEveTrackPropagator* get_cnt_prop() const { return cnt_prop; }
  TEveElementList* get_top_list() const { return _top_list;}
  TEveElementList* get_svtx_list() const { return _svtx_list;}
  TEveElementList* get_calo_list() const { return _calo_list;}
  TEveElementList* get_jet_list() const {return _jet_list;}
  TEveElementList* get_true_list() const { return _true_list;}  
  
  void set_jet_pt_threshold(float pt){_jet_pt_threshold = pt;}
  float get_jet_pt_threshold() const {return _jet_pt_threshold;}
  void set_jet_e_scale(float e_scale){_jet_e_scale = e_scale;}
  float get_jet_e_scale() const {return _jet_e_scale;}
  void set_calo_e_threshold(float e){_calo_e_threshold = e;}
  float get_calo_e_threshold() const {return _calo_e_threshold;}
  int get_verbosity() const {return verbosity;}

protected:

  TEveManager *_eve_manager; 
  TEveElementList* _top_list;
  TEveElementList* _svtx_list;
  TEveElementList* _calo_list;
  TEveElementList* _jet_list;
  TEveElementList* _true_list;

  TEveTrackPropagator* cnt_prop;
  MappedField* mapped_field;


  int _width, _height;
  bool _use_fieldmap;
  bool _use_geofile;
  float _jet_pt_threshold;
  float _jet_e_scale;
  float _calo_e_threshold;

  std::string map_filename;
  std::string geo_filename;

  int verbosity;
};

#endif // __PHEVEDISPLAY_H__
