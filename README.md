# minitalk

A simple client-server messaging system using UNIX signals. Developed during the 42 Vienna program.

## What is it?

`minitalk` allows sending messages from a client process to a server process one bit at a time via UNIX signals (`SIGUSR1` and `SIGUSR2`). The server reconstructs the message and prints it to stdout.

## Highlights

- Implements inter-process communication using signals
- Encodes and decodes messages bit by bit
- Handles asynchronous signals safely
- Good exercise in working close to the operating system

## Why I built this

This project was challenging because it required precise handling of signals, timing, and error cases. It improved my understanding of how processes can communicate in a low-level environment.
