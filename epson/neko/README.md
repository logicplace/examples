# Neko

This is a port of the [EPSON Simulator](https://global.epson.com/products_and_drivers/semicon/pdf/id000926.pdf)'s sample progam, subfolder `SIM\s1c88\samples\IOT sample`, called "neko". It's based on an old Windows program known as `NEKO.EXE`. It was specifically written for the [S1C88348](https://global.epson.com/products_and_drivers/semicon/pdf/id000646.pdf).

Here I provide two verions of this sample program: `port` is a faithful port of the original code, largely keeping to the conventions as established and just adjusting things to work for PM. `repro` is a rewrite using our typical conventions for PM development, and should be updated to reflect any changes in that model.

Perhaps some day we can get this running on the sim, too!

## port

There are some considerations to be made here, because neko.c is written as if there's no BIOS on the device, whereas we have to deal with the existence of one. While using the software interrupts in the BIOS might cut out and improve some code, this version does not do that.

In order to not break modern editors, I added occlusive comments around ASM blocks.

Code which refers to features that are not present in the S1C88V20 was completely removed. Unused code which refers to something that does exist was kept (and adjusted as needed). Some names may not be accurate to the V20 but were kept as-is. `sfr_r00` was changed to be the PokeMini UINT8 debug output.

To compile the example, use the following commands (assuming these tools are on your PATH):

```sh
cc88 -v -Md -d pokemini -Tlc-f2 neko.c CSTART.c
srec_cat neko.abs -o neko.min -binary
```

## repro

TODO
