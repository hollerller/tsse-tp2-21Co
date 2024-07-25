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

/*

- Prender todos los leds juntos
- Prender y apagar todos los leds juntos
- Prender un led, voy a consultar el estado y tiene que figurar como prendido.
- Voy a consultar el estado de un led apagado y tiene que figurar como apagado.
- Revisar que los leds estan bien mapeados en la memoria
*/

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

static uint16_t puerto_virtual;   /// puerto en una direccion en memoria que no conozco (puede ser variable) (puntero)
                                        // Todos los leds prendidos

void setUp(void) {
   
    leds_init(&puerto_virtual);     // LLamo a la funcion de inicializacion del HW -> Direccion del puerto
}

void tearDown(void) { // Se ejecuta despues de cada prueba
   
     
}

// - Al arrancar el sistema todos los leds tienen que estar apagados.


void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xFFFF;   /// puerto en una direccion en memoria que no conozco (puede ser variable) (puntero)
                                        // Todos los leds prendidos
    leds_init(&puerto_virtual);     // LLamo a la funcion de inicializacion del HW -> Direccion del puerto
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);      // Me fijo que esa variable haya quedado en 0.
}

// - Despues de arrancar el sistema, con todos los leds apagados, voy a prender un led cualquiera.

void test_prender_un_solo_led(void) {
   
    leds_turn_on(3); 
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual); 

}

// - Voy a prender un led y volver a apagarlo para ver si se apaga

void test_prender_y_apagar_un_solo_led(void) {
  
    leds_turn_on(3); 
    leds_turn_off(3); 
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual); 

}

// - Prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y que el otro sigue prendido

void test_prender_dos_leds_y_apagar_un_solo_led(void) {
  
    leds_turn_on(3); 
    leds_turn_on(7); 
    leds_turn_off(3); 
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual); 

}

/* === End of documentation ==================================================================== */