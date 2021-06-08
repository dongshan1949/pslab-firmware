#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

void PIN_MANAGER_Initialize(void) {
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x0080;
    LATC = 0x0000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0797;
    TRISB = 0xFD7F;
    TRISC = 0x03F7;
    LED_SetDigitalOutput();
    LED_SetLow();

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    CNPDA = 0x0000;
    CNPDB = 0x0000;
    CNPDC = 0x0000;
    CNPUA = 0x0000;
    CNPUB = 0x0000;
    CNPUC = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;
    ODCC = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSELA = 0x0003;
    ANSELB = 0x000F;
    ANSELC = 0x0007;

    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPOR2bits.RP39R = RPN_U1TX_PORT; //RB7->UART1:U1TX
    RPINR18bits.U1RXR = RPI_RP40; //RB8->UART1:U1RX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
}

