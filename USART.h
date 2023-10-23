
#ifndef _HAL_USART_H_ //jest to dyrektywa preprocesora, kt�ra s�u�y do zapobiegania podw�jnemu za�adowaniu tego samego pliku nag��wkowego wiele razy. Je�li plik nag��wkowy zostanie za�adowany, to dyrektywa preprocesora sprawdza, czy zmienna _HAL_USART_H_ jest definiowana. Je�li nie jest, oznacza to, �e plik nag��wkowy nie zosta� do tej pory za�adowany. W przeciwnym razie, je�li zmienna jest ju� zdefiniowana, oznacza to, �e plik n
#define _HAL_USART_H_

#include <avr/io.h>
#include "common.h"

void USART_init(void);
void USART_SendByte(unsigned char x);	//USART_Transmit
void Transmit_string(const char *s);
void USART_SendLine(void);


#endif
