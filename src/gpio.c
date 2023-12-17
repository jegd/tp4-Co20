/************************************************************************************************
Copyright (c) 2023, Jesus Gonzales  <jesus.e.1997.eg@gmail.com>

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

/** @file
 ** @brief Capa de abstracción para gestión de puertos digitales
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stddef.h>
/* === Macros definitions ====================================================================== */
#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 16
#endif
/* === Private data type declarations ========================================================== */
//! Estructura con los atributos de un puerto digital
struct gpio_h {
    uint8_t port; //!< Número de puerto GPIO
    uint8_t pin;  //!< Pin del puerto GPIO
    bool state;   //!< Estado actual del puerto digital
    bool output;  //!< El puerto está configurado como salida
#ifdef USE_STATIC_MEM
    bool used;
#endif
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */
static gpio_t GpioAllocate(void);
/* === Private function implementation ========================================================= */
#ifdef USE_STATIC_MEM
static gpio_t GpioAllocate(void) {
    static struct gpio_h instances[GPIO_MAX_INSTANCES] = {0};
    gpio_t self = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            self = &instances[index];
            self->used = true;
            break;
        }
    }
    return self;
}
#endif

/* === Public function implementation ========================================================== */

gpio_t GpioCreate(uint8_t port, uint8_t bit) {
    gpio_t self;
#ifdef USE_STATIC_MEM
    self = GpioAllocate();
#else
    self = malloc(sizeof(struct gpio_h));
#endif
    if (self) {
        self->port = port;
        self->pin = bit;
        self->output = false;
        self->state = false;
    }

    return self;
}

void GpioSetDirection(gpio_t self, bool output) {
    self->output = output;
}

void GpioSetState(gpio_t self, bool state) {
    if (self->output) {
        self->output = state;
    }
}

bool GpioGetState(gpio_t self) {
    return self->state;
}

uint8_t GpioGetDirection(gpio_t self) {
    return self->port;
}

/* === End of documentation ==================================================================== */
