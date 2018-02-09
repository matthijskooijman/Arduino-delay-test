struct Results {
  uint32_t f_cpu;
  uint16_t ok_count;
  uint16_t error_count;
  uint32_t total_error;
};
Results results[7];

static const bool show_ok = false;

static void process_results(Results& results, uint16_t us, uint16_t start, uint16_t end, bool overflow, uint8_t cpu_mhz) {
  uint16_t cycles = (end - start);
  // Subtract the time to read TCNT1: 2 lds instructions at 2 cycles each
  cycles -= 4;
  bool expected_overflow = us > (0xffff / cpu_mhz);
  uint16_t expected_cycles = us * cpu_mhz;
  bool ok = expected_cycles == cycles && overflow == expected_overflow;

  if (ok) {
    results.ok_count++;
    if (!show_ok)
      return;
  }

  Serial.print("delayMicroseconds(");
  Serial.print(us);
  Serial.print("): ");
  if (ok) {
    Serial.println("OK");
  } else {
    if (overflow && !expected_overflow)
      Serial.print("OVERFLOW ");
    else if (!overflow && expected_overflow)
      Serial.print("NO OVERFLOW ");

    Serial.print("ERR: ");
    int16_t err_cycles = cycles - expected_cycles;
    Serial.print(err_cycles);
    Serial.print(" cycles == ");
    Serial.print(err_cycles / float(cpu_mhz));
    Serial.println("us");

    results.error_count++;
    results.total_error += abs(err_cycles);
  }
}

namespace CPU24 {
  #undef F_CPU
  #define F_CPU 24000000
  //#include "test.h"
}
namespace CPU20 {
  #undef F_CPU
  #define F_CPU 20000000
  //#include "test.h"
}
namespace CPU16 {
  #undef F_CPU
  #define F_CPU 16000000
  #include "test.h"
}
namespace CPU8 {
  #undef F_CPU
  #define F_CPU 8000000
  #include "test.h"
}
namespace CPU4 {
  #undef F_CPU
  #define F_CPU 4000000
  #include "test.h"
}
namespace CPU2 {
  #undef F_CPU
  #define F_CPU 2000000
  #include "test.h"
}
namespace CPU1 {
  #undef F_CPU
  #define F_CPU 1000000
  #include "test.h"
}

//void measurerange(const uint16_t from, const uint16_t to, const uint16_t step = 1) __attribute__((__always_inline__));

void setup() {
  Serial.begin(115200);
  // Start timer1, run with /1 prescaler
  TCCR1A = 0;
  TCCR1B = (1 << CS10);

  // Disable interrupts, so we don't measure interference from the timer or serial interrupts
  cli();
  //CPU24::measure_all(results[0]);
  //CPU20::measure_all(results[1]);
  CPU16::measure_all(results[2]);
  CPU8::measure_all(results[3]);
  CPU4::measure_all(results[4]);
  CPU2::measure_all(results[5]);
  CPU1::measure_all(results[6]);
  sei();
  
  Serial.println();
  Serial.println(">> Summary");
  for (auto result : results) {
    if (!result.f_cpu)
      continue;
    Serial.print(result.f_cpu / 1000000);
    Serial.print("Mhz: ");
    Serial.print(result.ok_count);
    Serial.print(" ok, ");
    Serial.print(result.error_count);
    Serial.print(" errors, totalling ");
    Serial.print(result.total_error);
    Serial.println(" cycles");
  }
}

void loop() {
}
