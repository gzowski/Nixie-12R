# Nixie-12R - Keyboard/GamePad

* 11 key ortholinear keyboard
* 1 Rotary encoder in the top right
* OLED Display for displaying layer selected
* Pro Micro compatible

![PCB](https://github.com/gzowski/Nixie-12R/blob/main/Images/PCB.png?raw=true)

## Repository Info

* PCB Files within PCB folder, created with KiCad.
* VIA config export and via.json design files in VIA folder
* QMK firmware within QMK/QMK_Firmware/Keyboards/Nixie12r, can be pasted into a local copy of qmk repo and made.
* 3D printable case within Case folder

### [Parts](#Parts) || [Assembly Guide](#Assembly-Guide)

## Parts

| Part | Quantity     | Description                | 
| :-------- | :------- | :------------------------- |
| Diodes| 12  | Through-hole 1N4148 |
| Microcontroller | 1 | Pro-Micro compatible |
| MX Switches | 11 | Cherry MX compatible switches |
| EC11 | 1 | Rotary Encoder |
| MJTP1117 | 1 | Angled reset switch |
| Keycaps | 1 | 11x1u switches |
| OLED Display | 1 | 128x32 OLED (SSD1306) |

## Assembly Guide

* Insert all switches into the top plate and put to the side
* Diode installation: insert from top of the pcb so diodes are visible from the top
* Reset switch: insert switch on top and solder from underside, remove legs beforehand for clearance.
* Microcontroller needs to be positioned with the top facing the PCB, upsidedown (Test controller beforehand and flash firmware using QMK)
* Place OLED Display on top of PCB and solder from underside.
* Place the rotary encoder on the top side and solder all points ensuring it stays flush to the board.
* Press down the top plate with switches and stabalisers down on the middle plate ensuring that all the switches sit flush against the middle plate.
* Turn board over and proceed to solder switches to the board
* Connect USB to keyboard and check all keys are functional, this is assuming you've already flashed the firmware to the MCU.

