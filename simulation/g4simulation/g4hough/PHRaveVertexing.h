/*!
 *  \file		PHRaveVertexing.h
 *  \brief		Refit SvtxTracks with PHGenFit.
 *  \details	Refit SvtxTracks with PHGenFit.
 *  \author		Haiwang Yu <yuhw@nmsu.edu>
 */

#ifndef __PHRaveVertexing_H__
#define __PHRaveVertexing_H__

#include <fun4all/SubsysReco.h>
#include <GenFit/GFRaveVertex.h>
#include <GenFit/Track.h>
#include <string>
#include <vector>

namespace PHGenFit {
class Track;
} /* namespace PHGenFit */

namespace genfit {
class GFRaveVertexFactory;
} /* namespace genfit */

class SvtxTrack;
namespace PHGenFit {
class Fitter;
} /* namespace PHGenFit */

class PHTimer;
class SvtxTrackMap;
class SvtxVertexMap;
class SvtxVertex;
class PHCompositeNode;
class PHG4TruthInfoContainer;

//! \brief		Refit SvtxTracks with PHGenFit.
class PHRaveVertexing: public SubsysReco {
public:

	typedef std::map<const genfit::Track*, unsigned int> GenFitTrackMap;

	//! Default constructor
	PHRaveVertexing(const std::string &name = "PHRaveVertexing");

	//! dtor
	~PHRaveVertexing();

	//!Initialization, called for initialization
	int Init(PHCompositeNode *);

	//!Initialization Run, called for initialization of a run
	int InitRun(PHCompositeNode *);

	//!Process Event, called for each event
	int process_event(PHCompositeNode *);

	//!End, write and close files
	int End(PHCompositeNode *);

	const std::string& get_vertexing_method() const {
		return _vertexing_method;
	}

	void set_vertexing_method(const std::string& vertexingMethod) {
		_vertexing_method = vertexingMethod;
	}

	int get_primary_pid_guess() const {
		return _primary_pid_guess;
	}

	void set_primary_pid_guess(int primaryPidGuess) {
		_primary_pid_guess = primaryPidGuess;
	}

	bool is_over_write_svtxvertexmap() const {
		return _over_write_svtxvertexmap;
	}

	void set_over_write_svtxvertexmap(bool overWriteSvtxvertexmap) {
		_over_write_svtxvertexmap = overWriteSvtxvertexmap;
	}

	double get_vertex_min_ndf() const {
		return _vertex_min_ndf;
	}

	void set_vertex_min_ndf(double vertexMinPT) {
		_vertex_min_ndf = vertexMinPT;
	}

private:

	//! Event counter
	int _event;

	//! Get all the nodes
	int GetNodes(PHCompositeNode *);

	//!Create New nodes
	int CreateNodes(PHCompositeNode *);

	genfit::Track* TranslateSvtxToGenFitTrack(SvtxTrack* svtx);

	//! Fill SvtxVertexMap from GFRaveVertexes and Tracks
	bool FillSvtxVertexMap(
			const std::vector<genfit::GFRaveVertex*> & rave_vertices,
			const GenFitTrackMap & gf_track_map);

	bool _over_write_svtxvertexmap;
	std::string _svtxvertexmaprefit_node_name;

	PHGenFit::Fitter* _fitter;

	int _primary_pid_guess;
	double _vertex_min_ndf;

	genfit::GFRaveVertexFactory* _vertex_finder;

	//! https://rave.hepforge.org/trac/wiki/RaveMethods
	std::string _vertexing_method;

	//! Input Node pointers
	PHG4TruthInfoContainer* _truth_container;
	SvtxTrackMap* _trackmap;
	SvtxVertexMap* _vertexmap;

	//! Output Node pointers
	SvtxVertexMap* _vertexmap_refit;

	PHTimer *_t_translate;
	PHTimer *_t_rave;
};

#endif //* __PHRaveVertexing_H__ *//
