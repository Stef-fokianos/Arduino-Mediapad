# Arduino MediaPad

There are two sections to this project. The hardware and housing comes first followed by the Arduino IDE-written software. It can be programmed and modified to meet its users needs thanks to buttons and rotary encoders attached to and Arduino board. I started by creating the end user's requirements before procceeding on to hardware, casing and software possibilities and approach to solution

## Contents

1. [Introduction](#introduction)
2. [PART 1: Arduino MediaPad](#part-1-arduino-mediapad)
   - Arduino Pro Micro
   - Rotary Encoder Module
   - Buttons
   - Connecting Wires
   - Breadboard
   - Cable Connectors
3. [PART 2: Light Dimmer](#part-2-light-dimmer)
   - Voltage Regulator
4. [PART 3: Assembly](#part-3-assembly)
   - Case Preparation
   - Arduino Circuit
   - Light Dimmer Circuit
   - Final Assembly

---

## Introduction

Have you ever wished you could skip the procedures necessary to manage the media on your personal computer? While saving time and effort, keyboard shortcuts frequently need more than one key, and finding the appropriate combination of keys can be challenging. 

The MediaPad solves this problem with buttons and rotary encoders, connecting to an Arduino board programmed to fulfill the needs of the user. Current features include:

- PC sound volume control.
- Music playback.
- Common keyboard shortcuts.

### Features

Additionally, a built-in dimmer mechanism controls the light emitted by a desk lamp for ergonomic comfort and productivity.

---

## PART 1: Arduino MediaPad

### Arduino Pro Micro

The Arduino Pro Micro is a clone of the original Arduino board, based on the ATmega32u4 microcontroller, capable of emulating USB HID devices such as keyboards or mice.

### Rotary Encoder Module (KY040)

A rotary encoder is an input device that detects rotational direction and amount.

### Buttons

12mm square momentary push buttons are used for user inputs.

### Connecting Wires

Insulated 1-pin connecting wires of 150mm length and various colors.

### Breadboard

A breadboard simplifies prototyping with 400 contact points and dual power rails.

### Cable Connectors

Screw-based cable connectors allow easy and modular connections.

---

## PART 2: Light Dimmer

### Voltage Regulator Module

The module adjusts voltage output to control the desk lamp's brightness.

---

## PART 3: Assembly

### Case Preparation

An old Digital Receiver case was repurposed for housing components.

### Arduino Circuit

The Arduino Pro Micro is soldered and connected to:

- Rotary encoder(s)
- Pushbuttons
- USB cable for power

### Light Dimmer Circuit

The dimmer circuit is assembled with the voltage regulator module and connected to the case.

### Final Assembly

All components are secured within the case, painted for a sleek design.

---

## Final Product

The MediaPad combines custom controls for media and lighting, with a stealthy blacked-out design that fits under a desk.
