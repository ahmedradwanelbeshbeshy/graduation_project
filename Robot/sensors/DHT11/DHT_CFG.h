/* 
 * File:   DHT_CFG.h
 * Author: ahmed radwan
 *
 * Created on February 26, 2023, 2:45 AM
 */

#ifndef DHT_CFG_H
#define	DHT_CFG_H

/* write macro of desired pin will conect with data pin of the sensor*/
#define DHT1_PIN_DIR  TRISDbits.TRISD7
#define DHT1_PIN_STAT PORTDbits.RD7
#define DHT1_PIN_OUT LATDbits.LATD7


#endif	/* DHT_CFG_H */

