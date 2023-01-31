/* 
 * File:   DHT11_cfg.h
 * Author: ahmed radwan
 *
 * Created on January 21, 2023, 11:23 PM
 */

#ifndef DHT11_CFG_H
#define	DHT11_CFG_H

/* write macro of desired pin will conect with data pin of the sensor*/
#define DHT1_PIN_DIR  TRISDbits.TRISD7
#define DHT1_PIN_STAT PORTDbits.RD7
#define DHT1_PIN_OUT LATDbits.LATD7

#endif	/* DHT11_CFG_H */

