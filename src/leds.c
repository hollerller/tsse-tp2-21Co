/************************************************************************************************
Copyright (c) 2024, David Tobasura <hollerller@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

#define LED_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

static uint16_t * puerto_virtual;

static uint16_t led_to_mask(int led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

void leds_init(uint16_t * puerto) {
    puerto_virtual = puerto;
    *puerto_virtual = ALL_LEDS_OFF;
}

void leds_turn_on(int led) {
    *puerto_virtual |= led_to_mask(led);
}

void leds_turn_off(int led) {
    *puerto_virtual &= ~led_to_mask(led);
}



/* === End of documentation ==================================================================== */