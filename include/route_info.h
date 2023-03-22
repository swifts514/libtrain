#ifndef LIBTRAIN_ROUTE_INFO_H_
#define LIBTRAIN_ROUTE_INFO_H_

#include <algorithm>
#include <vector>

#include "datetime.h"
#include "static_string.h"

namespace trainsys {

struct RouteInfo {
    Date date;
    // replaced by self-implemented list
    std::vector<std::pair<TrainID, int>> route;
};

}  // namespace trainsys

#endif  // LIBTRAIN_ROUTE_INFO_H_
