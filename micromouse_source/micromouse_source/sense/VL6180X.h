#ifndef MICROMOUSE_VL6180X_H
#define MICROMOUSE_VL6180X_H
#include <cstdint>

namespace sense
{
	class VL6180X
	{
	public:
		VL6180X();
		VL6180X(const uint_fast8_t& device_id);
		void setup(const uint_fast8_t& device_id);

	private:
		int_fast16_t file_descriptor_;
	public:
		const static uint_fast8_t IDENTIFICATION__MODEL_ID;
		const static uint_fast8_t IDENTIFICATION__MODEL_REV_MAJOR;
		const static uint_fast8_t IDENTIFICATION__MODEL_REV_MINOR;
		const static uint_fast8_t IDENTIFICATION__MODULE_REV_MAJOR;
		const static uint_fast8_t IDENTIFICATION__MODULE_REV_MINOR;
		const static uint_fast8_t IDENTIFICATION__DATE_HI;
		const static uint_fast8_t IDENTIFICATION__DATE_LO;
		const static uint_fast16_t	IDENTIFICATION__TIME;
		
		const static uint_fast8_t SYSTEM__MODE_GPIO0;
		const static uint_fast8_t SYSTEM__MODE_GPIO1;
		const static uint_fast8_t SYSTEM__HISTORY_CTRL;
		const static uint_fast8_t SYSTEM__INTERRUPT_CONFIG_GPIO;
		const static uint_fast8_t SYSTEM__INTERRUPT_CLEAR;
		const static uint_fast8_t SYSTEM__FRESH_OUT_OF_RESET;
		const static uint_fast8_t SYSTEM__GROUPED_PARAMETER_HOLD;
		
		const static uint_fast8_t SYSRANGE__START;
		const static uint_fast8_t SYSRANGE__THRESH_HIGH;
		const static uint_fast8_t SYSRANGE__THRESH_LOW;
		const static uint_fast8_t SYSRANGE__INTERMEASUREMENT_PERIOD;
		const static uint_fast8_t SYSRANGE__MAX_CONVERGENCE_TIME;
		
		const static uint_fast16_t SYSRANGE__CROSSTALK_COMPENSATION_RATE;
		const static uint_fast8_t SYSRANGE__CROSSTALK_VALID_HEIGHT;
		const static uint_fast16_t SYSRANGE__EARLY_CONVERGENCE_ESTIMATE;
		const static uint_fast8_t SYSRANGE__PART_TO_PART_RANGE_OFFSET;
		const static uint_fast8_t SYSRANGE__RANGE_IGNORE_VALID_HEIGHT;
		const static uint_fast16_t SYSRANGE__RANGE_IGNORE_THRESHOLD;
		const static uint_fast8_t SYSRANGE__MAX_AMBIENT_LEVEL_MULT;
		const static uint_fast8_t SYSRANGE__RANGE_CHECK_ENABLES;
		const static uint_fast8_t SYSRANGE__VHV_RECALIBRATE;
		const static uint_fast8_t SYSRANGE__VHV_REPEAT_RATE;

		const static uint_fast8_t SYSALS__START;
		const static uint_fast8_t SYSALS__THRESH_HIGH;
		const static uint_fast8_t SYSALS__THRESH_LOW;
		const static uint_fast8_t SYSALS__INTERMEASUREMENT_PERIOD;
		const static uint_fast8_t SYSALS__ANALOGUE_GAIN;
		const static uint_fast8_t SYSALS__INTEGRATION_PERIOD;
		
		const static uint_fast8_t RESULT__RANGE_STATUS;
		const static uint_fast8_t RESULT__ALS_STATUS;
		const static uint_fast8_t RESULT__INTERRUPT_STATUS_GPIO;
		const static uint_fast16_t RESULT__ALS_VAL;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_0;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_1;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_2;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_3;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_4;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_5;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_6;
		const static uint_fast16_t RESULT__HISTORY_BUFFER_7;
		const static uint_fast8_t RESULT__RANGE_VAL;
		const static uint_fast8_t RESULT__RANGE_RAW;
		const static uint_fast16_t	RESULT__RANGE_RETURN_RATE;
		const static uint_fast16_t RESULT__RANGE_REFERENCE_RATE;
		const static uint_fast32_t	RESULT__RANGE_RETURN_SIGNAL_COUNT;
		const static uint_fast32_t RESULT__RANGE_REFERENCE_SIGNAL_COUNT;
		const static uint_fast32_t RESULT__RANGE_RETURN_AMB_COUNT;
		const static uint_fast32_t RESULT__RANGE_REFERENCE_AMB_COUNT;
		const static uint_fast32_t	RESULT__RANGE_RETURN_CONV_TIME;
		const static uint_fast32_t RESULT__RANGE_REFERENCE_CONV_TIME;

		const static uint_fast16_t RANGE_SCALER;
		const static uint_fast16_t READOUT__AVERAGING_SAMPLE_PERIOD;
		const static uint_fast16_t FIRMWARE__BOOTUP;
		const static uint_fast16_t	FIRMWARE__RESULT_SCALER;
		const static uint_fast16_t I2C_SLAVE__DEVICE_ADDRESS;
		const static uint_fast16_t INTERLEAVED_MODE__ENABLE;
	};
}

#endif // MICROMOUSE_VL6180X_H