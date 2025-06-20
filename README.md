<div align="center">
  <a href="https://github.com/mpeyre-s/minitalk">
    <img src="https://github.com/mpeyre-s/42_project_badges/raw/main/badges/minitalk_bonus.svg" alt="minitalk badge" />
  </a>
</div>


## Overview

**minitalk** is a simple messaging system between two processes: a **client** and a **server**.  
It uses **UNIX signals** (`SIGUSR1` and `SIGUSR2`) to transmit data, bit by bit, from the client to the server.

The goal of this project is to explore inter-process communication (IPC) using basic system calls, bitwise operations, and signal handling in C, without using standard communication functions like sockets or pipes.

This project strengthens your understanding of:

- Bit manipulation
- UNIX signals (`signal`, `sigaction`, `kill`)
- Asynchronous communication
- Low-level system programming in C

## Compatibility

- 🖥️ Works on Linux (tested on Ubuntu/Debian)
- 📦 Written in **C99** standard
- ✅ Compatible with 42 school evaluation guidelines

---

## Example

To start the server:

```bash
./server
