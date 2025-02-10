#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO para o PWM do servo
#define LED_PIN 12     // GPIO para o LED RGB (experimento BitDogLab)
#define PWM_FREQ 50    // Frequência do PWM (50Hz)
#define PWM_WRAP 20000 // Valor de "wrap" para um período de 20ms (50Hz)

void set_servo_position(uint slice, uint channel, uint duty_us) {
    pwm_set_chan_level(slice, channel, duty_us);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel = pwm_gpio_to_channel(SERVO_PIN);
    
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f); // Ajuste para 50Hz
    pwm_set_enabled(slice_num, true);

    while (1) {
        // Posição 180° (2400us)
        set_servo_position(slice_num, channel, 2400);
        sleep_ms(5000);

        // Posição 90° (1470us)
        set_servo_position(slice_num, channel, 1470);
        sleep_ms(5000);

        // Posição 0° (500us)
        set_servo_position(slice_num, channel, 500);
        sleep_ms(5000);

        // Movimentação suave entre 0° e 180°
        for (uint duty = 500; duty <= 2400; duty += 5) {
            set_servo_position(slice_num, channel, duty);
            sleep_ms(10);
        }
        for (uint duty = 2400; duty >= 500; duty -= 5) {
            set_servo_position(slice_num, channel, duty);
            sleep_ms(10);
        }
    }
}
