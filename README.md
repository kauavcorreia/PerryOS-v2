# PerryOS

PerryOS is a hobby operating system developed for learning low-level programming, operating system architecture, and kernel development.

The project is written mainly in **C** for the kernel and **Go** for the userland tools.

## Overview

PerryOS is designed as a modular operating system with a simple kernel and a small userland environment.

The goal of the project is to explore:

* Kernel architecture
* Memory management
* Interrupt handling
* Filesystem implementation
* Device drivers
* Shell and user programs

## Architecture

The project is divided into two main parts:

### Kernel (C)

Responsible for the core system functionality:

* Memory management
* Interrupt handling
* Scheduling
* Filesystem
* Hardware drivers

```
kernel/
 ├ kernel.c
 ├ memory.c
 ├ interrupts.c
 ├ scheduler.c
 └ event.c
```
Fix the attached problem
### Drivers

Low-level hardware communication.

```
drivers/
 ├ screen.c
 ├ keyboard.c
 ├ disk.c
 └ timer.c
```

### Filesystem

Handles file operations.

```
fs/
 ├ fs.c
 └ fs.h
```

### Userland (Go)

User-level programs and shell utilities.

```
user/
 ├ shell
 ├ filemanager
 ├ ls
 ├ cat
 ├ echo
```

## Current Features

* Basic kernel initialization
* VGA text screen driver
* Keyboard input driver
* Interrupt system (IDT/IRQ structure)
* Simple memory management structure
* Filesystem module (work in progress)
* Custom shell written in Go
* Basic userland commands

## Example

```
PerryOS iniciado
>
```

Userland shell example:

```
perryos> filemanager
Directory: .
----------------
[FILE] main.go
```

## Goals

Planned features for PerryOS:

* Complete memory allocator (`kmalloc`, `kfree`)
* Interrupt handling system
* Process management
* Syscalls
* Filesystem implementation
* User program loader
* Multitasking scheduler

## Build

To compile userland tools:

```
cd user/filemanager
go build
```

To run the shell:

```
cd user/shell
go run main.go
```

## Project Status

PerryOS is currently in **early development**.

The kernel structure and drivers are being implemented before expanding the system functionality.

## License

MIT License
