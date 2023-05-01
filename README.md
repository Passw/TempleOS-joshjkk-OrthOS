# OrthOS

## About

I have made a few operating systems in the past, but I was never pleased with them. I hope to achieve all my goals in this one.

### Archived

I have completed my goals. I am archiving this repo because [drawing in linear framebuffers](https://wiki.osdev.org/Drawing_In_a_Linear_Framebuffer) is ridiculously hard. Feel free to try it yourself.

## Features

- 64-bit
- 640x480 16 colors
- 1.44MB floppy disk size
- C kernel
- Basic disk operations

## Installation

### Requirements

- gcc
- nasm
- qemu-system-x86

### Building and usage

For building the binary:

``` bash
make build
```

For running:

``` bash
make run
```

## License

OrthOS is under an [Apache 2.0](./LICENSE) license.
