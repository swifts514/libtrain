#ifndef LIBTRAIN_TRAIN_INFO_H_
#define LIBTRAIN_TRAIN_INFO_H_

#include "datetime.h"
#include "static_string.h"
#include "station_info.h"

namespace trainsys {

const int MAX_STATION_NUM = 100;

struct TrainInfo {
    bool released;       // whether the train is released
    TrainID train_id;    // id of the train
    int station_number;  // number of stations the train passes
    int seat_number;     // number of seats in the train
    Time starting_time;  // depature time of the starting station
    Date starting_date;  // the first day of train operation
    Date ending_date;    // the last day of train operation

    StationInfo stations[MAX_STATION_NUM];  // information of all stations this train passes
                                            // including station ID, arriving time, departure time
                                            // and ticket price
};

}  // namespace trainsys

#endif  // LIBTRAIN_TRAIN_INFO_H_
