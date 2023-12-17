/************************************************************************************************
Copyright (c) 2023, Jesus Gonzales <jesus.e.1997.eg@gmail.com>

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

#ifndef GPIO_H
#define GPIO_H

/** @file
 ** @brief Capa de abstracción para gestión de puertos digitales
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

typedef struct gpio_h * gpio_t;

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/**
 * @brief   Función para crear el puerto GPIO
 *
 * @param port Dirección del puerto que se usará
 * @param bit   Número del GPIO que se usará
 * @return gpio_t Puntero al objeto del puerto creado
 */
gpio_t GpioCreate(uint8_t port, uint8_t bit);
/**
 * @brief   Función para colocar una dirección de puerto
 *
 * @param gpio Puntero al objeto obtenido al llamar a la función GpioCreate
 * @param output Variable booleana para indicar si el puerto se usará como salida true o entrada
 * false
 */
void GpioSetDirection(gpio_t gpio, bool output);
/**
 * @brief   Función para cambiar el estado del puerto
 *
 * @param gpio Puntero al objeto obtenido al llamar a la función GpioCreate
 * @param state Estado al que se quiere cambiar el puerto
 */
void GpioSetState(gpio_t gpio, bool state);
/**
 * @brief   Función para consultar el estado del puerto digital
 *
 * @param gpio Puntero al objeto obtenido al llamar a la función GpioCreate
 * @param bit
 * @return gpio_t
 */
bool GpioGetState(gpio_t gpio);
/**
 * @brief   Función consultar la dirección del puerto
 *
 * @param gpio Puntero al objeto obtenido al llamar a la función GpioCreate
 * @return uint8_t Entrega el número de puerto
 */
uint8_t GpioGetDirection(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
