# Wasm3 Kernel Module

This repository contains a kernel module that runs a small WASM program in kernel space. It illustrates how to expose functions from the kernel module to the WASM program as well as how to pass a variable-length data structure from the module to the program.

## Structure

- `main.c`
    - This is the kernel module itself.
- `Makefile`
    - This is a `Makefile` that can be used to build the kernel module.
- `wasm3-kernel/`
    - This is a submodule that points to a fork of the `wasm3` repository that has been modified to run in kernel space.
    - All the heavy lifting was done by [this fork](https://github.com/bonifaido/wasm3/tree/linux-kernel), but I merged in the latest changes from the [upstream repository](https://github.com/wasm3/wasm3).
- `wasm/`
    - This directory contains the WASM program as well as a `Makefile` to compile it and convert its binary form to a C array suitable for inclusion in the kernel module.

## Build

```
$ make
```

## Install

```
$ sudo insmod wasm.ko
```

## Verify Install

```
$ sudo lsmod | grep wasm
```

## Uninstall

```
$ sudo rmmod wasm
```

## Check Output

```
$ sudo journalctl --since "1 hour ago" | grep kernel
```