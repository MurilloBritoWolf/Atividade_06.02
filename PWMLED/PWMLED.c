#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22  // GPIO para o PWM do servo
#define LED_PIN 12     // GPIO para o LED RGB (experimento BitDogLab)
#define PWM_FREQ 50    // Frequência do PWM (50Hz)
#define PWM_WRAP 20000 // Valor de "wrap" para um período de 20ms (50Hz)

void set_pwm_duty(uint slice, uint channel, uint duty_us) {
    pwm_set_chan_level(slice, channel, duty_us);
}

int main() {
    stdio_init_all();
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    uint servo_slice = pwm_gpio_to_slice_num(SERVO_PIN);
    uint servo_channel = pwm_gpio_to_channel(SERVO_PIN);
    uint led_slice = pwm_gpio_to_slice_num(LED_PIN);
    uint led_channel = pwm_gpio_to_channel(LED_PIN);
    
    pwm_set_wrap(servo_slice, PWM_WRAP);
    pwm_set_clkdiv(servo_slice, 125.0f); // Ajuste para 50Hz
    pwm_set_enabled(servo_slice, true);

    pwm_set_wrap(led_slice, PWM_WRAP);
    pwm_set_clkdiv(led_slice, 125.0f); // Ajuste para LED PWM
    pwm_set_enabled(led_slice, true);

    while (1) {
        // Posição 180° (2400us) e LED brilho máximo
        set_pwm_duty(servo_slice, servo_channel, 2400);
        set_pwm_duty(led_slice, led_channel, 20000);
        sleep_ms(5000);

        // Posição 90° (1470us) e LED meia intensidade
        set_pwm_duty(servo_slice, servo_channel, 1470);
        set_pwm_duty(led_slice, led_channel, 10000);
        sleep_ms(5000);

        // Posição 0° (500us) e LED apagado
        set_pwm_duty(servo_slice, servo_channel, 500);
        set_pwm_duty(led_slice, led_channel, 0);
        sleep_ms(5000);

        // Movimentação suave entre 0° e 180° e variação de brilho
        for (uint duty = 500; duty <= 2400; duty += 5) {
            set_pwm_duty(servo_slice, servo_channel, duty);
            set_pwm_duty(led_slice, led_channel, duty * 8);
            sleep_ms(10);
        }
        for (uint duty = 2400; duty >= 500; duty -= 5) {
            set_pwm_duty(servo_slice, servo_channel, duty);
            set_pwm_duty(led_slice, led_channel, duty * 8);
            sleep_ms(10);
        }
    }
}
