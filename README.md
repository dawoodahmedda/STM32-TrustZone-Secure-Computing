# TrustZone-Based Secure Computing on STM32


## Project Overview

This project explores secure embedded computing on the STM32WBA55 platform using ARM TrustZone technology.

Implemented features include:

- Register-level LED control
- Hardware Random Number Generation (RNG)
- TrustZone Secure and Non-Secure architecture
- Secure callable functions
- Cryptographic data processing validation
- Runtime verification using STM32CubeIDE Live Expressions

## Hardware

- NUCLEO-WBA55CG
- STM32WBA55CGU
- ARM Cortex-M33

## Software

- STM32CubeIDE
- STM32CubeProgrammer
- STM32 HAL
- CMSIS

## Objectives

- Study ARM TrustZone
- Implement secure random number generation
- Explore cryptographic processing
- Validate Secure/Non-Secure communication
- Investigate secure execution environments

## Results

The project successfully demonstrated:

- TrustZone project separation
- Secure function architecture
- Random number generation
- Cryptographic data transformations
- Runtime validation through debugging tools

## Note

Some advanced BLE middleware integration and hardware cryptographic deployment were limited by linker dependencies
and watchdog-related debugging constraints. A software validation framework was developed to verify the architecture
and execution flow.
