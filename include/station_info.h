#ifndef LIBTRAIN_STATION_INFO_H_
#define LIBTRAIN_STATION_INFO_H_

#include "datetime.h"
#include "static_string.h"

namespace trainsys {

struct StationInfo {
    StationID station_id;  // id of the station
    Time arrival_time;     // arrival time of the station (undefined for starting station)
    Time departure_time;   // departure time of the station (undefined for terminal station)
    int ticket_price;      // ticket price from previous station to this one in a particular line
                           // (undefined for starting station)
};

}  // namespace trainsys

#endif  // LIBTRAIN_STATION_INFO_H_
