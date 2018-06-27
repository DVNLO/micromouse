#include "VL6180X.h"

const uint_fast8_t sense::VL6180X::IDENTIFICATION__MODEL_ID = 0x00;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__MODEL_REV_MAJOR = 0x01;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__MODEL_REV_MINOR = 0x02;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__MODULE_REV_MAJOR = 0x03;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__MODULE_REV_MINOR = 0x04;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__DATE_HI = 0x06;
const uint_fast8_t sense::VL6180X::IDENTIFICATION__DATE_LO = 0x07;
const uint_fast16_t	sense::VL6180X::IDENTIFICATION__TIME = 0x0008;

const uint_fast8_t sense::VL6180X::SYSTEM__MODE_GPIO0 = 0x10;
const uint_fast8_t sense::VL6180X::SYSTEM__MODE_GPIO1 = 0x11;
const uint_fast8_t sense::VL6180X::SYSTEM__HISTORY_CTRL = 0x12;
const uint_fast8_t sense::VL6180X::SYSTEM__INTERRUPT_CONFIG_GPIO = 0x14;
const uint_fast8_t sense::VL6180X::SYSTEM__INTERRUPT_CLEAR = 0x15;
const uint_fast8_t sense::VL6180X::SYSTEM__FRESH_OUT_OF_RESET = 0x16;
const uint_fast8_t sense::VL6180X::SYSTEM__GROUPED_PARAMETER_HOLD = 0x017;

const uint_fast8_t sense::VL6180X::SYSRANGE__START = 0x18;
const uint_fast8_t sense::VL6180X::SYSRANGE__THRESH_HIGH = 0x19;
const uint_fast8_t sense::VL6180X::SYSRANGE__THRESH_LOW = 0x1A;
const uint_fast8_t sense::VL6180X::SYSRANGE__INTERMEASUREMENT_PERIOD = 0x1B;
const uint_fast8_t sense::VL6180X::SYSRANGE__MAX_CONVERGENCE_TIME = 0x1C;

const uint_fast16_t sense::VL6180X::SYSRANGE__CROSSTALK_COMPENSATION_RATE = 0x001E;
const uint_fast8_t sense::VL6180X::SYSRANGE__CROSSTALK_VALID_HEIGHT = 0x21;
const uint_fast16_t sense::VL6180X::SYSRANGE__EARLY_CONVERGENCE_ESTIMATE = 0x0022;
const uint_fast8_t sense::VL6180X::SYSRANGE__PART_TO_PART_RANGE_OFFSET = 0x24;
const uint_fast8_t sense::VL6180X::SYSRANGE__RANGE_IGNORE_VALID_HEIGHT = 0x25;
const uint_fast16_t sense::VL6180X::SYSRANGE__RANGE_IGNORE_THRESHOLD = 0x0026;
const uint_fast8_t sense::VL6180X::SYSRANGE__MAX_AMBIENT_LEVEL_MULT = 0x2C;
const uint_fast8_t sense::VL6180X::SYSRANGE__RANGE_CHECK_ENABLES = 0x2D;
const uint_fast8_t sense::VL6180X::SYSRANGE__VHV_RECALIBRATE = 0x2E;
const uint_fast8_t sense::VL6180X::SYSRANGE__VHV_REPEAT_RATE = 0x31;

const uint_fast8_t sense::VL6180X::SYSALS__START = 0x38;
const uint_fast8_t sense::VL6180X::SYSALS__THRESH_HIGH = 0x3A;
const uint_fast8_t sense::VL6180X::SYSALS__THRESH_LOW = 0x3C;
const uint_fast8_t sense::VL6180X::SYSALS__INTERMEASUREMENT_PERIOD = 0x3E;
const uint_fast8_t sense::VL6180X::SYSALS__ANALOGUE_GAIN = 0x3F;
const uint_fast8_t sense::VL6180X::SYSALS__INTEGRATION_PERIOD = 0x40;

const uint_fast8_t sense::VL6180X::RESULT__RANGE_STATUS = 0x4D;
const uint_fast8_t sense::VL6180X::RESULT__ALS_STATUS = 0x4E;
const uint_fast8_t sense::VL6180X::RESULT__INTERRUPT_STATUS_GPIO = 0x4F;
const uint_fast16_t sense::VL6180X::RESULT__ALS_VAL = 0x0050;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_0 = 0x0052;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_1 = 0x0054;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_2 = 0x0056;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_3 = 0x0058;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_4 = 0x005A;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_5 = 0x005C;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_6 = 0x005E;
const uint_fast16_t sense::VL6180X::RESULT__HISTORY_BUFFER_7 = 0x0060;
const uint_fast8_t sense::VL6180X::RESULT__RANGE_VAL = 0x62;
const uint_fast8_t sense::VL6180X::RESULT__RANGE_RAW = 0x64;
const uint_fast16_t	sense::VL6180X::RESULT__RANGE_RETURN_RATE = 0x0066;
const uint_fast16_t sense::VL6180X::RESULT__RANGE_REFERENCE_RATE = 0x0068;
const uint_fast32_t	sense::VL6180X::RESULT__RANGE_RETURN_SIGNAL_COUNT = 0x0000006C;
const uint_fast32_t sense::VL6180X::RESULT__RANGE_REFERENCE_SIGNAL_COUNT = 0x00000070;
const uint_fast32_t sense::VL6180X::RESULT__RANGE_RETURN_AMB_COUNT = 0x00000074;
const uint_fast32_t sense::VL6180X::RESULT__RANGE_REFERENCE_AMB_COUNT = 0x00000078;
const uint_fast32_t	sense::VL6180X::RESULT__RANGE_RETURN_CONV_TIME = 0x0000007C;
const uint_fast32_t sense::VL6180X::RESULT__RANGE_REFERENCE_CONV_TIME = 0x00000080;

const uint_fast16_t sense::VL6180X::RANGE_SCALER = 0x0096;
const uint_fast16_t sense::VL6180X::READOUT__AVERAGING_SAMPLE_PERIOD = 0x010A;
const uint_fast16_t sense::VL6180X::FIRMWARE__BOOTUP = 0x0119;
const uint_fast16_t	sense::VL6180X::FIRMWARE__RESULT_SCALER = 0x0120;
const uint_fast16_t sense::VL6180X::I2C_SLAVE__DEVICE_ADDRESS = 0x0212;
const uint_fast16_t sense::VL6180X::INTERLEAVED_MODE__ENABLE = 0x02A3;