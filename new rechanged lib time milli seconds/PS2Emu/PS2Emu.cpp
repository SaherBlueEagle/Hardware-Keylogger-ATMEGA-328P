//===-- PS2Emu.cpp - PS/2 Keyboard Host and Device Emulation ---------------===/
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

#include "ps2emu.h"

unsigned char PS2Emu::hostRead() {
  unsigned char data = 0x00;
  unsigned char p = 0x01;

  // discard the start bit
  while (digitalRead(clk) == HIGH);
  while (digitalRead(clk) == LOW);  
  
  // read each data bit
  for (int i=0; i<8; i++) {
    while (digitalRead(clk) == HIGH);
    if (digitalRead(dat) == HIGH) {
      data = data | (1 << i);
      p = p ^ 1;
    }
    while (digitalRead(clk) == LOW);
  }
  
  // read the parity bit
  while (digitalRead(clk) == HIGH);
  if (digitalRead(dat) != p) {
    // TODO handle parity bit
  }
  while (digitalRead(clk) == LOW);
  
  // discard the stop bit
  while (digitalRead(clk) == HIGH);
  while (digitalRead(clk) == LOW);
  
  return data;
}

unsigned char PS2Emu::devRead() {
  unsigned char data = 0x00;
  unsigned char p = 0x01;
  
  // wait for the host to release the clock
  while (digitalRead(dat) == HIGH);
  while (digitalRead(clk) == LOW);
  
  // read start bit
  delayMicroseconds(cell/2);
  setLow(clk);
  delayMicroseconds(cell);
  setHigh(clk);
  delayMicroseconds(cell/2);

  // read data bits
  for (int i=0; i<8; i++) {
    if (digitalRead(dat) == HIGH) {
      data = data | (1 << i);
      p = p ^ 1;
    }
    delayMicroseconds(cell/2);
    setLow(clk);    
    delayMicroseconds(cell);
    setHigh(clk);
    delayMicroseconds(cell/2);
  }

  // read parity bit
  if (digitalRead(dat) != p) {
    // handle parity bit
  }
  delayMicroseconds(cell/2);
  setLow(clk);    
  delayMicroseconds(cell);
  setHigh(clk);
  delayMicroseconds(cell/2);
  
  // send 'ack' bit
  setLow(dat);
  delayMicroseconds(cell/2);
  setLow(clk);    
  delayMicroseconds(cell);
  setHigh(clk);
  setHigh(dat);

  return data;
}

void PS2Emu::hostWrite(unsigned char data) {
  unsigned char p = 0x01;

  // inhibit device transmission
  setLow(clk);
  delayMicroseconds(110);
  // send request to communicate with device
  setLow(dat);
  setHigh(clk);

  // send data
  for (int i=0; i<8 ;i++) {
    while (digitalRead(clk) == HIGH);
    if (data & (1 << i)) {
      setHigh(dat);
      p = p ^ 1;
    } else {
      setLow(dat);
    }
    while (digitalRead(clk) == LOW);
  }
  
  // send parity bit
  while (digitalRead(clk) == HIGH);
  if (p) {
    setHigh(dat);
  } else {
    setLow(dat);
  }
  while (digitalRead(clk) == LOW);

  // send stop bit
  while (digitalRead(clk) == HIGH);
  setHigh(dat);
  while (digitalRead(clk) == LOW);

  // eat the 'ack' bit
  while (digitalRead(clk) == HIGH);
  while (digitalRead(clk) == LOW);

}

void PS2Emu::devWrite(unsigned char data) {
  unsigned char p = 0x01;;

  // set start bit
  setLow(dat);
  delayMicroseconds(cell/2);
  setLow(clk);
  delayMicroseconds(cell);
  setHigh(clk);
  delayMicroseconds(cell/2);

  // set data bits
  for (int i=0; i<8; i++) {
    if (data & (1 << i)) {
      setHigh(dat);
      p = p ^ 1;
    } else {
      setLow(dat);
    }
    delayMicroseconds(cell/2);
    setLow(clk);
    delayMicroseconds(cell);
    setHigh(clk);
    delayMicroseconds(cell/2);
  }

  // set parity bit
  if (p) {
    setHigh(dat);
  } else {
    setLow(dat);
  }
  delayMicroseconds(cell/2);
  setLow(clk);
  delayMicroseconds(cell);
  setHigh(clk);
  delayMicroseconds(cell/2);

  // stet stop bit
  setHigh(dat);
  delayMicroseconds(cell/2);
  setLow(clk);
  delayMicroseconds(cell);
  setHigh(clk);
  delayMicroseconds(cell/2);
}

// FIXME this doesn't work
bool PS2Emu::devListen() {
  if (digitalRead(clk) == HIGH)
    return false;

  int c_stop = micros();
  int c_start = micros();

  while (digitalRead(clk) == LOW) {
    c_stop = micros();
    if (c_stop - c_start >= 100)
      return true;
  }

  return false;
}