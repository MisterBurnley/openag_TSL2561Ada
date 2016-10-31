# openag_TSL2561Ada
openag modified Adafruit TSL2561 light sensor driver code.

    @file     Adafruit_TSL2561.cpp
    @author   K.Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    Driver for the TSL2561 digital luminosity (light) sensors.

    Pick one up at http://www.adafruit.com/products/439

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v2.0 - Rewrote driver for Adafruit_Sensor and Auto-Gain support, and
           added lux clipping check (returns 0 lux on sensor saturation)
    v1.0 - First release (previously TSL2561)
    
    This version has code to integrate into the Open Agriculture Initiative,
    Farming for the Future, http://openag.media.mit.edu/
    V1.0 - November 2016 - Readout of light intensity in Lux.
