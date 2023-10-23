#include "USART.h"

void USART_init(void)
{
	/*Ustaw szybko�� transmisji */
	UBRR0H = (BAUDRATE>>8);	// przesu� rejestr w prawo o 8 bit�w, aby uzyska� g�rne 8 bit�w
	UBRR0L = BAUDRATE;		// ustaw szybko�� transmisji
	/*Podw�jna pr�dko�� transmisji */
	UCSR0A |= (1 << U2X0);
	/*W��cz nadajnik */
	UCSR0B = (1<<TXEN0);
	/* Ustaw format ramki: 8 bit�w danych */
	UCSR0C = (3<<UCSZ00);
}

void USART_SendByte(unsigned char x)	//Wysy�anie bitu do UART
{
	while(!((UCSR0A)&(1<<UDRE0)));	//Sprawdzanie czy rejestr jest odpowiedzialny za odbi�r danych (UDR0) jest gotowy do wys�ania danych (sprawdzaj�c bit UDRE0 w rejestrze UCSR0A)
	UDR0=x;	//Jak tak to wysy�a przez UDR0
}

/*Funkcja USART_SendByte(unsigned char x) s�u�y do wysy�ania jednego bajtu danych przez port szeregowy. 
Funkcja sprawdza czy bufor wyj�ciowy UDR0 jest gotowy do wys�ania danych
 i nast�pnie wysy�a dane za pomoc� UDR0. */



void Transmit_string(const char *s)	// Funkcja ta wysy�a ci�g znak�w za po�rednictwem USART. Przyjmuje ona jako argument wska�nik na ci�g znak�w, a nast�pnie iteruje po nim, wysy�aj�c pojedynczy znak na wyj�cie USART. Przed wys�aniem ka�dego znaku op�nienie trwa 2 milisekundy.
{
	char c;
	while ( (c = *s++) )	//Operator *s++ w j�zyku C zwraca zawarto�� wska�nika s (obecny element tablicy) i przesuwa wska�nik do kolejnego elementu.
	{
		USART_SendByte(c);
		_delay_ms(2);
	}
}
/*
Funkcja Transmit_string() w AVR C s�u�y do wysy�ania ci�gu znak�w przy u�yciu interfejsu USART.
 Ci�g znak�w jest przekazywany do funkcji jako wska�nik const char *s. 
 Wewn�trz funkcji kolejne znaki s� pobierane za pomoc� operatora *s++ i wysy�ane do interfejsu USART za pomoc� funkcji USART_SendByte().
 Po ka�dym wys�anym znaku nast�puje op�nienie w milisekundach przy u�yciu funkcji _delay_ms().
 */

void USART_SendLine(void)
{
	USART_SendByte(0X0D);	//Znak powrotu
	USART_SendByte(0X0A);	//Znak nowej lini w ASCII
}
/*
USART_SendLine() funkcja w AVR C s�u�y do wysy�ania znaku nowej linii (CR/LF) do po��czonego urz�dzenia. 
Funkcja ta wysy�a dwa bajty: 0X0D (znak powrotu) i 0X0A (znak nowej linii).
 Jest to u�yteczne, gdy chcemy wy�wietli� now� lini� na ekranie po��czonego urz�dzenia.*/