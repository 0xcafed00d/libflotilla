#ifndef ARDUINO_FLOTILLA_AVERAGE_VALUE_H
#define ARDUINO_FLOTILLA_AVERAGE_VALUE_H

#include <Arduino.h>

template <typename total_t, typename value_t>
class AverageValue {
  private:
	total_t m_total;
	value_t m_count;

  public:
	AverageValue() : m_count(0), m_total(0) {
	}

	void reset() {
		m_count = 0;
		m_total = 0;
	}

	value_t value() {
		if (m_count == 0) {
			return 0;
		}
		return value_t(m_total / m_count);
	}

	void addValue(value_t val) {
		m_count++;
		m_total += val;
	}
};

#endif