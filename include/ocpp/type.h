/*
 * SPDX-FileCopyrightText: 2024 Kyunghwan Kwon <k@libmcu.org>
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LIBMCU_OCPP_TYPE_H
#define LIBMCU_OCPP_TYPE_H

#if defined(__cplusplus)
extern "C" {
#endif

#include <stdbool.h>
#include <time.h>

#define OCPP_MESSAGE_ID_MAXLEN		(36 + 1/*null*/)
#define OCPP_ID_TOKEN_MAXLEN		(20 + 1/*null*/)

#define OCPP_CiString20			(20 + 1/*null*/)
#define OCPP_CiString25			(25 + 1/*null*/)
#define OCPP_CiString50			(50 + 1/*null*/)
#define OCPP_CiString255		(255 + 1/*null*/)
#define OCPP_CiString500		(500 + 1/*null*/)

typedef enum {
	OCPP_MSG_ROLE_NONE		= 0,
	OCPP_MSG_ROLE_ALLOC		= 1,
	OCPP_MSG_ROLE_CALL		= 2,
	OCPP_MSG_ROLE_CALLRESULT	= 3,
	OCPP_MSG_ROLE_CALLERROR		= 4,
} ocpp_message_role_t;

typedef enum {
	/* Core */
	OCPP_MSG_AUTHORIZE,
	OCPP_MSG_BOOTNOTIFICATION,
	OCPP_MSG_CHANGE_AVAILABILITY,
	OCPP_MSG_CHANGE_CONFIGURATION,
	OCPP_MSG_CLEAR_CACHE,
	OCPP_MSG_DATA_TRANSFER,
	OCPP_MSG_GET_CONFIGURATION,
	OCPP_MSG_HEARTBEAT,
	OCPP_MSG_METER_VALUES,
	OCPP_MSG_REMOTE_START_TRANSACTION,
	OCPP_MSG_REMOTE_STOP_TRANSACTION,
	OCPP_MSG_RESET,
	OCPP_MSG_START_TRANSACTION,
	OCPP_MSG_STATUS_NOTIFICATION,
	OCPP_MSG_STOP_TRANSACTION,
	OCPP_MSG_UNLOCK_CONNECTOR,
	/* Firmware Management */
	OCPP_MSG_DIAGNOSTICS_NOTIFICATION,
	OCPP_MSG_FIRMWARE_NOTIFICATION,
	OCPP_MSG_GET_DIAGNOSTICS,
	OCPP_MSG_UPDATE_FIRMWARE,
	/* Local Auth List Management */
	OCPP_MSG_GET_LOCAL_LIST_VERSION,
	OCPP_MSG_SEND_LOCAL_LIST,
	/* Reservation */
	OCPP_MSG_CANCEL_RESERVATION,
	OCPP_MSG_RESERVE_NOW,
	/* Smart Charging */
	OCPP_MSG_CLEAR_CHARGING_PROFILE,
	OCPP_MSG_GET_COMPOSITE_SCHEDULE,
	OCPP_MSG_SET_CHARGING_PROFILE,
	/* Remote Trigger */
	OCPP_MSG_TRIGGER_MESSAGE,
	/* Security */
	OCPP_MSG_CERTIFICATE_SIGNED,
	OCPP_MSG_DELETE_CERTIFICATE,
	OCPP_MSG_EXTENDED_TRIGGER_MESSAGE,
	OCPP_MSG_GET_INSTALLED_CERTIFICATE_IDS,
	OCPP_MSG_GET_LOG,
	OCPP_MSG_INSTALL_CERTIFICATE,
	OCPP_MSG_LOG_STATUS_NOTIFICATION,
	OCPP_MSG_SECURITY_EVENT_NOTIFICATION,
	OCPP_MSG_SIGN_CERTIFICATE,
	OCPP_MSG_SIGNED_FIRMWARE_STATUS_NOTIFICATION,
	OCPP_MSG_SIGNED_UPDATE_FIRMWARE,
	/* End */
	OCPP_MSG_MAX,
} ocpp_message_t;

typedef enum {
	OCPP_MEASURAND_CURRENT_EXPORT			= 0x000001,
	OCPP_MEASURAND_CURRENT_IMPORT			= 0x000002,
	OCPP_MEASURAND_CURRENT_OFFERED			= 0x000004,
	OCPP_MEASURAND_ENERGY_ACTIVE_EXPORT_REGISTER	= 0x000008,
	OCPP_MEASURAND_ENERGY_ACTIVE_IMPORT_REGISTER	= 0x000010,
	OCPP_MEASURAND_ENERGY_REACTIVE_EXPORT_REGISTER	= 0x000020,
	OCPP_MEASURAND_ENERGY_REACTIVE_IMPORT_REGISTER	= 0x000040,
	OCPP_MEASURAND_ENERGY_ACTIVE_EXPORT_INTERVAL	= 0x000080,
	OCPP_MEASURAND_ENERGY_ACTIVE_IMPORT_INTERVAL	= 0x000100,
	OCPP_MEASURAND_ENERGY_REACTIVE_EXPORT_INTERVAL	= 0x000200,
	OCPP_MEASURAND_ENERGY_REACTIVE_IMPORT_INTERVAL	= 0x000400,
	OCPP_MEASURAND_FREQUENCY			= 0x000800,
	OCPP_MEASURAND_POWER_ACTIVE_EXPORT		= 0x001000,
	OCPP_MEASURAND_POWER_ACTIVE_IMPORT		= 0x002000,
	OCPP_MEASURAND_POWER_FACTOR			= 0x004000,
	OCPP_MEASURAND_POWER_OFFERED			= 0x008000,
	OCPP_MEASURAND_POWER_REACTIVE_EXPORT		= 0x010000,
	OCPP_MEASURAND_POWER_REACTIVE_IMPORT		= 0x020000,
	OCPP_MEASURAND_RPM				= 0x040000,
	OCPP_MEASURAND_SOC				= 0x080000,
	OCPP_MEASURAND_TEMPERATURE			= 0x100000,
	OCPP_MEASURAND_VOLTAGE				= 0x200000,
} ocpp_measurand_t;

typedef enum {
	OCPP_PHASE_UNKNOWN,
	OCPP_PHASE_L1,
	OCPP_PHASE_L2,
	OCPP_PHASE_L3,
	OCPP_PHASE_N,
	OCPP_PHASE_L1_N,
	OCPP_PHASE_L2_N,
	OCPP_PHASE_L3_N,
	OCPP_PHASE_L1_L2,
	OCPP_PHASE_L2_L3,
	OCPP_PHASE_L3_L1,
} ocpp_phase_t;

typedef enum {
	OCPP_LOCATION_UNKNOWN,
	OCPP_LOCATION_BODY,
	OCPP_LOCATION_CABLE,
	OCPP_LOCATION_EV,
	OCPP_LOCATION_INLET,
	OCPP_LOCATION_OUTLET,
} ocpp_location_t;

typedef enum {
	OCPP_UNIT_UNKNOWN,
	OCPP_UNIT_WH,
	OCPP_UNIT_KWH,
	OCPP_UNIT_VARH,
	OCPP_UNIT_KVARH,
	OCPP_UNIT_W,
	OCPP_UNIT_KW,
	OCPP_UNIT_VA,
	OCPP_UNIT_KVA,
	OCPP_UNIT_VAR,
	OCPP_UNIT_KVAR,
	OCPP_UNIT_A,
	OCPP_UNIT_V,
	OCPP_UNIT_CELSIUS,
	OCPP_UNIT_FAHRENHEIT,
	OCPP_UNIT_K,
	OCPP_UNIT_PERCENT,
} ocpp_measure_unit_t;

typedef enum {
	OCPP_INOPERATIVE,
	OCPP_OPERATIVE,
} ocpp_availability_t;

typedef enum {
	OCPP_VALUE_FORMAT_UNKNOWN,
	OCPP_VALUE_FORMAT_RAW,
	OCPP_VALUE_FORMAT_SIGNED,
} ocpp_value_format_t;

typedef enum {
	OCPP_CHARGING_UNIT_WATT,
	OCPP_CHARGING_UNIT_AMPERE,
} ocpp_charging_unit_t;

typedef enum {
	OCPP_READ_CTX_UNKNOWN,
	OCPP_READ_CTX_INT_BEGIN,
	OCPP_READ_CTX_INT_END,
	OCPP_READ_CTX_OTHER,
	OCPP_READ_CTX_SAMPLE_CLOCK,
	OCPP_READ_CTX_SAMPLE_PERIODIC, /* default */
	OCPP_READ_CTX_TRANSACTION_BEGIN,
	OCPP_READ_CTX_TRANSACTION_END,
	OCPP_READ_CTX_TRIGGER,
} ocpp_reading_context_t;

typedef enum {
	OCPP_CHARGING_PROFILE_MAX,
	OCPP_CHARGING_PROFILE_TX_DEFAULT,
	OCPP_CHARGING_PROFILE_TX,
} ocpp_charging_profile_purpose_t;

typedef enum {
	OCPP_CHARGING_PROFILE_KIND_ABSOLUTE,
	OCPP_CHARGING_PROFILE_KIND_RECURRING,
	OCPP_CHARGING_PROFILE_KIND_RELATIVE,
} ocpp_charging_profile_kind_t;

typedef enum {
	OCPP_CHARGING_PROFILE_RECURRENCY_DAILY,
	OCPP_CHARGING_PROFILE_RECURRENCY_WEEKLY,
} ocpp_charging_profile_recurrency_t;

typedef enum {
	OCPP_RESET_HARD,
	OCPP_RESET_SOFT,
} ocpp_reset_t;

typedef enum {
	OCPP_UPDATE_DIFFERENTIAL,
	OCPP_UPDATE_FULL,
} ocpp_update_t;

typedef enum {
	OCPP_ERROR_NONE,
	OCPP_ERROR_CONNECTOR_LOCK_FAILURE,
	OCPP_ERROR_EV_COMMUNICATION,
	OCPP_ERROR_GROUND,
	OCPP_ERROR_HIGH_TEMPERATURE,
	OCPP_ERROR_INTERNAL,
	OCPP_ERROR_LOCAL_LIST_CONFLICT,
	OCPP_ERROR_OTHER,
	OCPP_ERROR_OVER_CURRENT,
	OCPP_ERROR_OVER_VOLTAGE,
	OCPP_ERROR_POWER_METER,
	OCPP_ERROR_POWER_SWITCH,
	OCPP_ERROR_READER,
	OCPP_ERROR_RESET,
	OCPP_ERROR_UNDER_VOLTAGE,
	OCPP_ERROR_WEAK_SIGNAL,
} ocpp_error_t;

typedef enum {
	OCPP_STOP_REASON_LOCAL,
	OCPP_STOP_REASON_DEAUTHORIZED,
	OCPP_STOP_REASON_EMERGENCY_STOP,
	OCPP_STOP_REASON_EV_DISCONNECTED,
	OCPP_STOP_REASON_HARD_RESET,
	OCPP_STOP_REASON_OTHER,
	OCPP_STOP_REASON_POWER_LOSS,
	OCPP_STOP_REASON_REBOOT,
	OCPP_STOP_REASON_REMOTE,
	OCPP_STOP_REASON_SOFT_RESET,
	OCPP_STOP_REASON_UNLOCK_COMMAND,
} ocpp_stop_reason_t;

typedef enum {
	OCPP_TRIGGER_BOOT_NOTIFICATION,
	OCPP_TRIGGER_LOG_STATUS_NOTIFICATION, /* extended */
	OCPP_TRIGGER_DIAGNOSTICS_STATUS,
	OCPP_TRIGGER_FIRMWARE_STATUS,
	OCPP_TRIGGER_HEARTBEAT,
	OCPP_TRIGGER_METER_VALUE,
	OCPP_TRIGGER_SIGN_CP_CERTIFICATE, /* extended */
	OCPP_TRIGGER_STATUS_NOTIFICATION,
} ocpp_trigger_message_t;

typedef enum {
	OCPP_COMM_IDLE,
	OCPP_COMM_UPLOADED,
	OCPP_COMM_UPLOAD_FAILED,
	OCPP_COMM_UPLOADING,
	OCPP_COMM_DOWNLOADED,
	OCPP_COMM_DOWNLOAD_FAILED,
	OCPP_COMM_DOWNLOADING,
	OCPP_COMM_INSTALLATION_FAILED,
	OCPP_COMM_INSTALLING,
	OCPP_COMM_INSTALLED,
} ocpp_comm_status_t;

typedef enum {
	OCPP_AUTH_STATUS_UNKNOWN,
	OCPP_AUTH_STATUS_ACCEPTED,
	OCPP_AUTH_STATUS_BLOCKED,
	OCPP_AUTH_STATUS_EXPIRED,
	OCPP_AUTH_STATUS_INVALID,
	OCPP_AUTH_STATUS_CONCURRENT_TX,
} ocpp_auth_status_t;

typedef enum {
	OCPP_AVAILABILITY_STATUS_ACCEPTED,
	OCPP_AVAILABILITY_STATUS_REJECTED,
	OCPP_AVAILABILITY_STATUS_SCHEDULED,
} ocpp_availability_status_t;

typedef enum {
	OCPP_CONFIG_STATUS_ACCEPTED,
	OCPP_CONFIG_STATUS_REJECTED,
	OCPP_CONFIG_STATUS_REBOOT_REQUIRED,
	OCPP_CONFIG_STATUS_NOT_SUPPORTED,
} ocpp_config_status_t;

typedef enum {
	OCPP_DATA_STATUS_ACCEPTED,
	OCPP_DATA_STATUS_REJECTED,
	OCPP_DATA_STATUS_UNKNOWN_MESSAGE_ID,
	OCPP_DATA_STATUS_UNKNOWN_VENDOR_ID,
} ocpp_data_status_t;

typedef enum {
	OCPP_STATUS_AVAILABLE,
	OCPP_STATUS_PREPARING,
	OCPP_STATUS_CHARGING,
	OCPP_STATUS_SUSPENDED_EVSE,
	OCPP_STATUS_SUSPENDED_EV,
	OCPP_STATUS_FINISHING,
	OCPP_STATUS_RESERVED,
	OCPP_STATUS_UNAVAILABLE,
	OCPP_STATUS_FAULTED,
} ocpp_status_t;

typedef enum {
	OCPP_PROFILE_STATUS_ACCEPTED,
	OCPP_PROFILE_STATUS_REJECTED,
	OCPP_PROFILE_STATUS_NOT_SUPPORTED,
	OCPP_PROFILE_STATUS_UNKNOWN,
} ocpp_profile_status_t;

typedef enum {
	OCPP_BOOT_STATUS_ACCEPTED,
	OCPP_BOOT_STATUS_PENDING,
	OCPP_BOOT_STATUS_REJECTED,
} ocpp_boot_status_t;

typedef enum {
	OCPP_REMOTE_STATUS_ACCEPTED,
	OCPP_REMOTE_STATUS_REJECTED,
} ocpp_remote_status_t;

typedef enum {
	OCPP_RESERVE_STATUS_ACCEPTED,
	OCPP_RESERVE_STATUS_FAULTED,
	OCPP_RESERVE_STATUS_OCCUPIED,
	OCPP_RESERVE_STATUS_REJECTED,
	OCPP_RESERVE_STATUS_UNAVAILABLE,
} ocpp_reservation_status_t;

typedef enum {
	OCPP_TRIGGER_STATUS_ACCEPTED,
	OCPP_TRIGGER_STATUS_REJECTED,
	OCPP_TRIGGER_STATUS_NOT_IMPLEMENTED,
} ocpp_trigger_status_t;

typedef enum {
	OCPP_UPDATE_STATUS_ACCEPTED,
	OCPP_UPDATE_STATUS_FAILED,
	OCPP_UPDATE_STATUS_NOT_SUPPORTED,
	OCPP_UPDATE_STATUS_VERSION_MISMATCH,
} ocpp_update_status_t;

typedef enum {
	OCPP_UNLOCK_UNLOCKED,
	OCPP_UNLOCK_FAILED,
	OCPP_UNLOCK_NOT_SUPPORTED,
} ocpp_unlock_status_t;

typedef enum {
	OCPP_PHASE_ROTATION_NOT_APPLICABLE,
	OCPP_PHASE_ROTATION_UNKNOWN,
	OCPP_PHASE_ROTATION_RST,
	OCPP_PHASE_ROTATION_RTS,
	OCPP_PHASE_ROTATION_SRT,
	OCPP_PHASE_ROTATION_STR,
	OCPP_PHASE_ROTATION_TRS,
	OCPP_PHASE_ROTATION_TSR,
} ocpp_connector_phase_rotation_t;

typedef enum {
	OCPP_PROFILE_CORE			= 0x0001,
	OCPP_PROFILE_FW_MGMT			= 0x0002,
	OCPP_PROFILE_LOCAL_AUTH			= 0x0004,
	OCPP_PROFILE_RESERVATION		= 0x0008,
	OCPP_PROFILE_SMART_CHARGING		= 0x0010,
	OCPP_PROFILE_REMOTE_TRIGGER		= 0x0020,
} ocpp_profile_t;

typedef enum {
	OCPP_HASH_SHA256,
	OCPP_HASH_SHA384,
	OCPP_HASH_SHA512,
} ocpp_hash_t;

typedef enum {
	OCPP_LOG_DIAGNOSTICS,
	OCPP_LOG_SECURITY,
} ocpp_log_t;

struct ocpp_KeyValue {
	char key[OCPP_CiString50];
	bool readonly;
	char value[OCPP_CiString500];
};

struct ocpp_idTagInfo {
	time_t expiryDate;
	char parentIdTag[OCPP_CiString20];
	ocpp_auth_status_t status;
};

struct ocpp_AuthorizationData {
	char idTag[OCPP_CiString20];
	struct ocpp_idTagInfo idTagInfo;
};

struct ocpp_ChargingSchedulePeriod {
	int startPeriod;
	int limit_tenth;
	int numberPhases;
};

struct ocpp_ChargingSchedule {
	int duration;
	time_t startSchedule;
	ocpp_charging_unit_t chargingRateUnit;
	int minChargingRate_tenth;
	int nr_chargingSchedulePeriod;
	struct ocpp_ChargingSchedulePeriod chargingSchedulePeriod[0];
};

struct ocpp_ChargingProfile {
	int chargingProfileId;
	int transactionId;
	int stackLevel;
	ocpp_charging_profile_purpose_t chargingProfilePurpose;
	ocpp_charging_profile_kind_t chargingProfileKind;
	ocpp_charging_profile_recurrency_t recurrencyKind;
	time_t validFrom;
	time_t validTo;
	struct ocpp_ChargingSchedule chargingSchedule;
};

struct ocpp_SampledValue {
	char value[32+1];
	ocpp_reading_context_t context;
	ocpp_value_format_t format;
	ocpp_measurand_t measurand;
	ocpp_phase_t phase;
	ocpp_location_t location;
	ocpp_measure_unit_t unit;
};

struct ocpp_MeterValue {
	time_t timestamp;
	struct ocpp_SampledValue sampledValue[0];
};

#if defined(__cplusplus)
}
#endif

#endif /* LIBMCU_OCPP_TYPE_H */
