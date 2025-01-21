/*
 * SPDX-FileCopyrightText: 2024 권경환 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LIBMCU_OCPP_RESERVE_MESSAGES_H
#define LIBMCU_OCPP_RESERVE_MESSAGES_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <time.h>
#include "ocpp/type.h"

struct ocpp_CancelReservation {
	int reservationId;
};

struct ocpp_CancelReservation_conf {
	ocpp_reservation_status_t status;
};

struct ocpp_ReserveNow {
	int connectorId;
	time_t expiryDate;
	char idTag[20+1];
	char parentIdTag[20+1];
	int reservationId;
};

struct ocpp_ReserveNow_conf {
	ocpp_reservation_status_t status;
};

#if defined(__cplusplus)
}
#endif

#endif /* LIBMCU_OCPP_RESERVE_MESSAGES_H */
