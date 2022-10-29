# IDOBAO ID96

96-key Keyboard from IDOBAO. *(The PCB for this board is also commonly used in the Drop NYM96 and YMDK Melody96.)*

* Keyboard Maintainer: [Vino Rodrigues](https://github.com/vinorodrigues)
* Hardware Supported: IDOBAO ID96
* Hardware Availability: **IDOBAO ID96** *(no longer sold)*

Make example for this keyboard (after setting up your build environment):

    make idobao/id96:default

Flashing example for this keyboard:

    make idobao/id96:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.
Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Whilst holding down the top left key *(or `Escape`)* key and plug in the keyboard USB cable
* **Physical reset button**: Briefly press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` (`Reset` in VIA) if it is available
