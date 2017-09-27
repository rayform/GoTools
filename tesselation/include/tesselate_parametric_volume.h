#ifndef _TESSELATE_PARAMETRIC_VOLUME_H
#define _TESSELATE_PARAMETRIC_VOLUME_H

#include <vector>
#include "common_defs.h"
#include "GoTools/geometry/ParamCurve.h"
#include "MeshXD.h"

namespace TesselateUtils {
  
  // tesselate parametric curve, returning a vector of parameter values
  std::vector<double>
  tesselateParametricCurve(const std::shared_ptr<const Go::ParamCurve> pc,
                           const double vdist);

  Mesh2D tesselateParametricSurface(const shared_ptr<const ParamSurface> surf,
                                    const Point2D* const bpoints,
                                    const uint num_bpoints,
                                    const double vdist);

                                               
};

#endif
