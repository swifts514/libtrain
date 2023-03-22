#ifndef LIBTRAIN_TRAIN_SYSTEM_H_
#define LIBTRAIN_TRAIN_SYSTEM_H_

#include "route_info.h"
#include "train_info.h"

namespace trainsys {

enum RoutePreference { TIME, PRICE, INTERCHANGE };

class TrainSystemManager {
   private:
    /**
     * @brief query the number of seats remaining in a particular station
     *
     * @param train_id ID of the train which passes the station
     * @param date date of query
     * @param station_id ID of the station to be queried
     * @return int, the number of seats remaining, -1 if unexpected error occurs
     */
    int querySeat(const TrainID &train_id, const Date &date, const StationID &station_id);
    /**
     * @brief modify the number of seats remaining in a particular station
     *
     * @param train_id ID of the train which passes the station
     * @param date date of modification
     * @param station_id ID of the station to be modified
     * @param delta increacement of remaining seats, negtive if the number decreased
     * @return int, 0 if update succeeded, -1 otherwise
     */
    int updateSeat(
        const TrainID &train_id, const Date &date, const StationID &station_id, int delta);

   public:
    /**
     * @brief register information of a new train
     *
     * @param train_id ID of the train to be registered
     * @param train_info information of the added train
     * @return int, 0 if registry succeeded, -1 otherwise
     */
    int registerTrain(const TrainID &train_id, const TrainInfo &train_info);
    /**
     * @brief remove an unreleased train
     *
     * @param train_id ID of the train to be removed
     * @return int, 0 if successfully removed, -1 otherwise
     */
    int removeTrain(const TrainID &train_id);
    /**
     * @brief lookup information of an existed train
     *
     * @param train_id ID of the train to be queried
     * @return int, 0 if lookup succeeded, -1 otherwise
     */
    int lookupTrain(const TrainID &train_id);
    /**
     * @brief release a train
     *
     * @param train_id ID of the train to be released
     * @return int, 0 if successfully released, -1 otherwise
     */
    int releaseTrain(const TrainID &train_id);

    /**
     * @brief query ticket information for all possible routes, sorted according to the preference
     *
     * @param date date of query
     * @param start_station the starting station
     * @param destination_station the destination station
     * @param preference route preference (sorted by TIME, PRICE, or number of INTERCHANGEs)
     * @return int, 0 if lookup succeeded, -1 otherwise
     */
    int lookupTicket(const Date &date, const StationID &start_station,
        const StationID &destination_station, RoutePreference preference);
    /**
     * @brief book tickets for a particular route
     *
     * @param route_info travel route, involving trains and passed stations
     * @param ticket_number number of tickets to be booked
     * @return int, total price if booking succeeded, -1 otherwise
     */
    int bookTicket(const RouteInfo &route_info, int ticket_number);
    /**
     * @brief refund tickets for a particular route
     *
     * @param route_info travel route, involving trains and passed stations
     * @param ticket_number number of tickets to be refunded
     * @return int, 0 if successfully refunded, -1 otherwise
     */
    int refundTicket(const RouteInfo &route_info, int ticket_number);
};

}  // namespace trainsys

#endif  // LINTRAIN_TRAIN_SYSTEM_H_
