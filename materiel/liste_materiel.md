
**QUIZZ CLARINS**
=================

# LISTE DE MATÉRIEL


# Tuto

<https://learn.adafruit.com/32x16-32x32-rgb-led-matrix?view=all>

# Medium 16x32 RGB LED matrix panel

![](http://www.adafruit.com/images/970x728/420-08.jpg)

<http://www.adafruit.com/product/420>



# Voir aussi

Nootropic RGB Matrix Backpack Kit for 16x32 Panel

<http://www.adafruit.com/product/1072>







# 8x2 Header connector Pinout

![](https://learn.adafruit.com/system/assets/assets/000/002/943/medium800/led_matrix_inputidc.jpg?1396789239)


        UNO   MATRIX | MATRIX   UNO
        ============================
        PD2   R1     |     G1   PD3  ¹
        PD4   B1     |    GND   GND
        PD5   R2     |     G2   PD6
    ²   PD7   B2     |    GND   GND
        PC0   A      |      B   PC1
        PC2   C      |    GND   GND ⁴ - PC3 ⁵
        PB0   CLK    |    LAT ³ PC3 ⁴ - PB2 ⁵
        PB1   OE     |    GND   GND

¹ Fil rouge (pin 1)
² Détrompeur
³ LATCH
⁴ sur la matrice 16×16
⁵ sur la matrice 32×32

## Définitions au début d’un programme

    #define CLK 8
    #define LAT A3
    #define OE  9
    #define A   A0
    #define B   A1
    #define C   A2



# Changement de config matrice

## 16×16
Fil bleu A3
Fil jaune GND

## 32×32
Fil bleu PIN 10
Fil jaune A3





# RF433

<http://fr.aliexpress.com/item/1pcs-433Mhz-RF-transmitter-and-receiver-kit-for-Arduino-project-FREE-SHIPPING-3235/1308017760.html?recommendVersion=1>

XY-MK-5V




# 2.4 GHz

10 x nRF24L01P+ Wireless Transceiver Module

- <http://www.aliexpress.com/snapshot/6459431728.html>
- <http://www.nordicsemi.com/eng/Products/2.4GHz-RF/nRF24L01P>


