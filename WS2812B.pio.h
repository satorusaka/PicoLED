// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

// ------- //
// WS2812B //
// ------- //

#define WS2812B_wrap_target 0
#define WS2812B_wrap 3

#define WS2812B_T1 2
#define WS2812B_T2 5
#define WS2812B_T3 3

static const uint16_t WS2812B_program_instructions[] = {
            //     .wrap_target
    0x6221, //  0: out    x, 1            side 0 [2] 
    0x1123, //  1: jmp    !x, 3           side 1 [1] 
    0x1400, //  2: jmp    0               side 1 [4] 
    0xa442, //  3: nop                    side 0 [4] 
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program WS2812B_program = {
    .instructions = WS2812B_program_instructions,
    .length = 4,
    .origin = -1,
};

static inline pio_sm_config WS2812B_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + WS2812B_wrap_target, offset + WS2812B_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}

#include "hardware/clocks.h"
static inline void WS2812B_program_init(PIO pio, uint sm, uint offset, uint pin, float freq, uint bits) {
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
    pio_sm_config c = WS2812B_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, pin);
    sm_config_set_out_shift(&c, false, true, bits);
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);
    int cycles_per_bit = WS2812B_T1 + WS2812B_T2 + WS2812B_T3;
    float div = clock_get_hz(clk_sys) / (freq * cycles_per_bit);
    sm_config_set_clkdiv(&c, div);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

#endif

// ---------------- //
// WS2812B_inverted //
// ---------------- //

#define WS2812B_inverted_wrap_target 0
#define WS2812B_inverted_wrap 3

#define WS2812B_inverted_T1 2
#define WS2812B_inverted_T2 5
#define WS2812B_inverted_T3 3

static const uint16_t WS2812B_inverted_program_instructions[] = {
            //     .wrap_target
    0x7221, //  0: out    x, 1            side 1 [2] 
    0x0123, //  1: jmp    !x, 3           side 0 [1] 
    0x0400, //  2: jmp    0               side 0 [4] 
    0xb442, //  3: nop                    side 1 [4] 
            //     .wrap
};

#if !PICO_NO_HARDWARE
static const struct pio_program WS2812B_inverted_program = {
    .instructions = WS2812B_inverted_program_instructions,
    .length = 4,
    .origin = -1,
};

static inline pio_sm_config WS2812B_inverted_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + WS2812B_inverted_wrap_target, offset + WS2812B_inverted_wrap);
    sm_config_set_sideset(&c, 1, false, false);
    return c;
}

#include "hardware/clocks.h"
static inline void WS2812B_inverted_program_init(PIO pio, uint sm, uint offset, uint pin, float freq, uint bits) {
    pio_gpio_init(pio, pin);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 1, true);
    pio_sm_config c = WS2812B_inverted_program_get_default_config(offset);
    sm_config_set_sideset_pins(&c, pin);
    sm_config_set_out_shift(&c, false, true, bits);
    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);
    int cycles_per_bit = WS2812B_inverted_T1 + WS2812B_inverted_T2 + WS2812B_inverted_T3;
    float div = clock_get_hz(clk_sys) / (freq * cycles_per_bit);
    sm_config_set_clkdiv(&c, div);
    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

#endif

