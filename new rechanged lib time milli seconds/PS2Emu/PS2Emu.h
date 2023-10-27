//===-- PS2Emu.h - PS/2 Keyboard Host and Device Emulation -----------------===/
//
// Written by Daniel Kudrow (dkudrow@cs.ucsb.edu)
// August 2013
//
// Library to emulate device and hosts of PS/2 protocol
//
// TODO:
// check data/clock state before acting
// handle host inhibition
// listen for host requests to send
// handle host interrupt
//
//===-----------------------------------------------------------------------===/


#ifndef ps2emu_h
#define ps2emu_h

#include "Arduino.h"

class PS2Emu {
  private:
    int clk; // clock pin
    int dat; // data pin
    int cell; // one half of clock cycle time
    // logical high is high-impedance
    void setHigh(int pin) { pinMode(pin, INPUT); digitalWrite(pin, HIGH); }
    // logical low is low-impedance
    void setLow(int pin) { pinMode(pin, OUTPUT); digitalWrite(pin, LOW); }

  public:
    // construct and initialize
    PS2Emu(int c, int d, int t=40) : clk(c), dat(d), cell(t) {
        setHigh(clk);
        setHigh(dat);
    }
    // read as host (from device)
    unsigned char hostRead();
    // read as device (from host)
    unsigned char devRead();
    // write as host (to device)
    void hostWrite(unsigned char);
    // write as device (to host)
    void devWrite(unsigned char);
    // FIXME listen for host request to send
    bool devListen();
};

#endif