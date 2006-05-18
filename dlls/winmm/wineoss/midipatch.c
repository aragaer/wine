/* -*- tab-width: 8; c-basic-offset: 4 -*- */

/*
 * FM patches for wine MIDI driver
 *
 * Copyright 1999 Eric Pouech
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/*
 * Eric POUECH : MIDI FM patches for GM instruments
 */

#define	NOT_DEFINED	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

unsigned char midiFMInstrumentPatches[128 * 16] = {
/*   0 Acoustic Grand Piano             */ 0x21, 0x11, 0x4c, 0x00, 0xf1, 0xf2, 0x63, 0x72, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   1 Bright Acoustic Piano            */ 0x01, 0x11, 0x4f, 0x00, 0xf1, 0xd2, 0x53, 0x74, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   2 Electric Grand Piano             */ 0x01, 0x01, 0x4f, 0x04, 0xf1, 0xd2, 0x50, 0x7c, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   3 Honky-Tonk Piano                 */ 0x81, 0x13, 0x9d, 0x00, 0xf2, 0xf2, 0x51, 0xf1, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   4 Rhodes Piano                     */ 0x01, 0x01, 0x4f, 0x04, 0xf1, 0xd2, 0x50, 0x7c, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   5 Chorused Piano                   */ 0x01, 0x11, 0x4d, 0x00, 0xf1, 0xd2, 0x60, 0x7b, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   6 Harpsichord                      */ 0x32, 0x16, 0x87, 0x80, 0xa1, 0x7d, 0x10, 0x33, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   7 Clavinet                         */ 0x13, 0x08, 0x80, 0x00, 0xfb, 0xe8, 0xff, 0xff, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   8 Celesta                          */ 0x14, 0x04, 0x07, 0x00, 0x93, 0xb6, 0x73, 0x62, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00,
/*   9 Glockenspiel                     */ 0x07, 0x12, 0x4f, 0x00, 0xf2, 0xf2, 0x60, 0x72, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  10 Music Box                        */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  11 Vibraphone                       */ 0x44, 0x60, 0x53, 0x80, 0xf5, 0xfd, 0x33, 0x25, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  12 Marimba                          */ 0x05, 0x01, 0x4e, 0x00, 0xda, 0xf9, 0x25, 0x15, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  13 Xylophone                        */ 0x11, 0x31, 0x2d, 0x00, 0xc8, 0xf5, 0x2f, 0xf5, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  14 Tubular Bells                    */ 0x03, 0x17, 0x4f, 0x03, 0xf1, 0xf2, 0x53, 0x74, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  15 Dulcimer                         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  16 Hammond Organ                    */ 0x72, 0x71, 0xcd, 0x80, 0x91, 0x91, 0x2a, 0x2a, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  17 Percussive Organ                 */ 0x0c, 0x00, 0x00, 0x00, 0xf8, 0xd6, 0xb5, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  18 Rock Organ                       */ 0x72, 0x70, 0xce, 0x80, 0x9f, 0x94, 0x12, 0x11, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  19 Church Organ                     */ 0xa5, 0xb1, 0xd2, 0x80, 0x81, 0xf1, 0x03, 0x05, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  20 Reed Organ                       */ 0x3e, 0xb1, 0x29, 0x80, 0xfb, 0xa0, 0xf0, 0x9b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  21 Accordion                        */ 0x24, 0x31, 0x4f, 0x00, 0xf2, 0x52, 0x0b, 0x0b, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  22 Harmonica                        */ 0x22, 0xf2, 0x8f, 0x40, 0x41, 0x61, 0x03, 0x05, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  23 Tango Accordion                  */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  24 Acoustic Nylon Guitar            */ 0x01, 0x01, 0x11, 0x00, 0xf2, 0xf5, 0x1f, 0x88, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  25 Acoustic Steel Guitar            */ 0x01, 0xa1, 0x46, 0x03, 0xf1, 0x31, 0x83, 0x86, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  26 Electric Jazz Guitar             */ 0x03, 0x11, 0x5e, 0x00, 0x85, 0xd2, 0x51, 0x71, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  27 Electric Clean Guitar            */ 0x32, 0x16, 0x87, 0x80, 0xa1, 0x7d, 0x10, 0x33, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  28 Electric Muted Guitar            */ 0x13, 0x11, 0x96, 0x80, 0xff, 0xff, 0x21, 0x03, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  29 Overdriven Guitar                */ 0x07, 0x14, 0x8f, 0x80, 0x82, 0x82, 0x7d, 0x7d, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  30 Distortion Guitar                */ 0x05, 0x01, 0x8f, 0x80, 0xda, 0xf9, 0x15, 0x14, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  31 Guitar Harmonics                 */ 0xc3, 0x01, 0x05, 0x0d, 0x91, 0xf1, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  32 Acoustic Bass                    */ 0x21, 0x01, 0x2a, 0x00, 0xf2, 0xf5, 0x1f, 0x88, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  33 Electric Bass Fingered           */ 0x01, 0x21, 0x15, 0x80, 0x25, 0x65, 0x2f, 0x6c, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  34 Electric Bass Picked             */ 0x01, 0x01, 0x1d, 0x00, 0xf2, 0xf5, 0xef, 0x78, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  35 Fretless Bass                    */ 0x30, 0x21, 0x1e, 0x00, 0xf2, 0xf5, 0xef, 0x78, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  36 Slap Bass 1                      */ 0x20, 0x21, 0x40, 0x00, 0x7b, 0x75, 0x04, 0x72, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  37 Slap Bass 2                      */ 0x20, 0x21, 0x40, 0x00, 0x7b, 0xf5, 0x04, 0x72, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  38 Synth Bass 1                     */ 0x41, 0x91, 0x83, 0x00, 0x65, 0x32, 0x05, 0x74, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  39 Synth Bass 2                     */ 0x30, 0xb1, 0x88, 0x80, 0xd5, 0x61, 0x19, 0x1b, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  40 Violin                           */ 0x72, 0x62, 0x1c, 0x05, 0x51, 0x52, 0x03, 0x13, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  41 Viola                            */ 0x70, 0x71, 0xd0, 0x80, 0x52, 0x31, 0x11, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  42 Cello                            */ 0x70, 0x71, 0xc5, 0x80, 0x52, 0x31, 0x11, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  43 Contrabass                       */ 0x01, 0x00, 0x00, 0x00, 0x94, 0x83, 0xb6, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  44 Tremolo Strings                  */ 0x71, 0xa1, 0x8b, 0x40, 0x71, 0x42, 0x11, 0x15, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  45 Pizzicato Strings                */ 0xf2, 0xe1, 0x40, 0x80, 0xf5, 0xfd, 0xa8, 0xad, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  46 Orchestral Harp                  */ 0x21, 0x11, 0x11, 0x00, 0xa3, 0xc4, 0x43, 0x22, 0x02, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  47 Timpani                          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  48 String Ensemble 1                */ 0xe1, 0x21, 0x4f, 0x00, 0xc1, 0x32, 0xd3, 0x74, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  49 String Ensemble 2                */ 0xe1, 0x21, 0x4f, 0x00, 0xb1, 0x12, 0xd3, 0x74, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  50 Synth Strings 1                  */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  51 Synth Strings 2                  */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  52 Choir Aahs                       */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  53 Voice oohs                       */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  54 Synth Voice                      */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  55 Orchestra Hit                    */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  56 Trumpet                          */ 0x31, 0xa1, 0x1c, 0x80, 0x41, 0x92, 0x0b, 0x3b, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  57 Trombone                         */ 0x21, 0xa1, 0x18, 0x80, 0x53, 0x52, 0x1d, 0x3b, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  58 Tuba                             */ 0x21, 0x21, 0x19, 0x80, 0x43, 0x85, 0x8c, 0x2f, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  59 Muted Trumpet                    */ 0x31, 0xa1, 0x1c, 0x80, 0x41, 0x92, 0x0b, 0x3b, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  60 French Horn                      */ 0x21, 0x21, 0x9f, 0x80, 0x53, 0xaa, 0x5a, 0x1a, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  61 Brass Section                    */ 0x21, 0x21, 0x16, 0x00, 0x71, 0x81, 0xae, 0x9e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  62 Synth Brass 1                    */ 0x61, 0x60, 0x1c, 0x00, 0x71, 0x81, 0xae, 0x2e, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  63 Synth Brass 2                    */ 0x21, 0x21, 0x8e, 0x80, 0xbb, 0x90, 0x29, 0x0a, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  64 Soprano Sax                      */ 0x01, 0x12, 0x4f, 0x00, 0x71, 0x52, 0x53, 0x7c, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  65 Alto Sax                         */ 0x01, 0x13, 0x4f, 0x00, 0x71, 0x62, 0x53, 0x84, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  66 Tenor Sax                        */ 0x01, 0x13, 0x8d, 0x00, 0x51, 0x52, 0x53, 0x7c, 0x01, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  67 Baritone Sax                     */ 0x01, 0x12, 0x4f, 0x00, 0x71, 0x22, 0x53, 0x7c, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  68 Oboe                             */ 0x71, 0x62, 0xc5, 0x05, 0x6e, 0x8b, 0x17, 0x0e, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  69 English Horn                     */ 0xe1, 0xe4, 0x23, 0x00, 0x71, 0x82, 0xae, 0x9e, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  70 Bassoon                          */ 0x30, 0xb1, 0xcd, 0x80, 0xd5, 0x61, 0x19, 0x1b, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  71 Clarinet                         */ 0x32, 0xa1, 0x1c, 0x80, 0x51, 0x82, 0x15, 0x45, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  72 Piccolo                          */ 0xe4, 0xe4, 0x0f, 0x00, 0x70, 0x60, 0x0f, 0x9f, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  73 Flute                            */ 0xe1, 0x61, 0x27, 0x80, 0x53, 0x53, 0x8a, 0x57, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  74 Recorder                         */ 0x61, 0x61, 0x27, 0x80, 0x74, 0x65, 0x8f, 0x2a, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  75 Pan Flute                        */ 0xe0, 0xa1, 0xec, 0x00, 0x6e, 0x65, 0x8f, 0x2a, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  76 Bottle Blow                      */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  77 Shakuhashi                       */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  78 Whistle                          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  79 Ocarina                          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  80 Synth lead 1 - Sq wave lead      */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  81 Synth lead 2 - Sawtooth Wave     */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  82 Synth lead 3 - Caliope lead      */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  83 Synth lead 4 - Chiff lead        */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  84 Synth lead 5 - Charang           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  85 Synth lead 6 - Solo Synth Voice  */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  86 Synth lead 7 - Bright Saw Wave   */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  87 Synth lead 8 - Brass and Lead    */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  88 Synth pad 1 - Fantasia Pad       */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  89 Synth pad 2 - Warm Pad           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  90 Synth pad 3 - Poly Synth Pad     */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  91 Synth pad 4 - Space Voice Pad    */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  92 Synth pad 5 - Bowed Glass Pad    */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  93 Synth pad 6 - Metal Pad          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  94 Synth pad 7 - Halo Pad           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  95 Synth pad 8 - Sweep Pad          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  96 Synth SFX 1 - Ice Rain           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  97 Synth SFX 2 - Soundtrack         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  98 Synth SFX 3 - Crystal            */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/*  99 Synth SFX 4 - Athmosphere        */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 100 Synth SFX 5 - Brightness         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 101 Synth SFX 6 - Goblin             */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 102 Synth SFX 7 - Echo drops         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 103 Synth SFX 8 - Star Theme         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 104 Sitar                            */ 0x01, 0x08, 0x40, 0x00, 0xf2, 0xf2, 0x54, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 105 Banjo                            */ 0x31, 0x16, 0x87, 0x80, 0xa1, 0x7d, 0x11, 0x43, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 106 Shamisen                         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 107 Koto                             */ 0x0e, 0x02, 0x40, 0x00, 0x09, 0xf7, 0x53, 0x94, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 108 Kalimba                          */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 109 Bagpipe                          */ 0x31, 0x22, 0x43, 0x05, 0x6e, 0x8b, 0x17, 0x0c, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 110 Fiddle                           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 111 Shanai                           */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 112 Tinkle Bell                      */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 113 Agogo                            */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 114 Steel Drums                      */ 0x00, 0x00, 0x0b, 0x00, 0xa8, 0xd6, 0x4c, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 115 Woodblock                        */ 0x02, 0x11, 0x4f, 0x00, 0x71, 0x52, 0x53, 0x7c, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 116 Taiko Drum                       */ 0x12, 0x02, 0x0b, 0x00, 0x95, 0xd4, 0x4c, 0xdd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 117 Melodic Tom                      */ 0x01, 0x02, 0x00, 0x00, 0xfa, 0xda, 0xbf, 0xbf, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 118 Synth Drum                       */ 0x06, 0x00, 0x00, 0x00, 0xf0, 0xf6, 0xf0, 0xb4, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 119 Reverse Cymbal                   */ 0x64, 0x03, 0x00, 0x40, 0xb2, 0x97, 0x82, 0xd4, 0x02, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 120 Guitar Fret Noise                */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 121 Breath Noise                     */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 122 Seashore                         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 123 Bird Tweet                       */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 124 Telephone Ring                   */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 125 Helicopter                       */ 0xf0, 0xe2, 0x00, 0xc0, 0x1e, 0x11, 0x11, 0x11, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 126 Applause                         */ 0x07, 0x01, 0x87, 0x80, 0xf0, 0xf0, 0x05, 0x05, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
/* 127 Gunshot                          */ 0x0c, 0x50, 0x00, 0x21, 0xf8, 0x09, 0xb6, 0x04, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
};

unsigned char midiFMDrumsPatches[16 * 128] = {
/*     1 Not defined					*/ NOT_DEFINED
/*     2 Not defined					*/ NOT_DEFINED
/*     3 Not defined					*/ NOT_DEFINED
/*     4 Not defined					*/ NOT_DEFINED
/*     5 Not defined					*/ NOT_DEFINED
/*     6 Not defined					*/ NOT_DEFINED
/*     7 Not defined					*/ NOT_DEFINED
/*     8 Not defined					*/ NOT_DEFINED
/*     9 Not defined					*/ NOT_DEFINED
/*    10 Not defined					*/ NOT_DEFINED
/*    11 Not defined					*/ NOT_DEFINED
/*    12 Not defined					*/ NOT_DEFINED
/*    13 Not defined					*/ NOT_DEFINED
/*    14 Not defined					*/ NOT_DEFINED
/*    15 Not defined					*/ NOT_DEFINED
/*    16 Not defined					*/ NOT_DEFINED
/*    17 Not defined					*/ NOT_DEFINED
/*    18 Not defined					*/ NOT_DEFINED
/*    19 Not defined					*/ NOT_DEFINED
/*    20 Not defined					*/ NOT_DEFINED
/*    21 Not defined					*/ NOT_DEFINED
/*    22 Not defined					*/ NOT_DEFINED
/*    23 Not defined					*/ NOT_DEFINED
/*    24 Not defined					*/ NOT_DEFINED
/*    25 Not defined					*/ NOT_DEFINED
/*    26 Not defined					*/ NOT_DEFINED
/*    27 Not defined					*/ NOT_DEFINED
/*    28 Not defined					*/ NOT_DEFINED
/*    29 Not defined					*/ NOT_DEFINED
/*    30 Not defined					*/ NOT_DEFINED
/*    31 Not defined					*/ NOT_DEFINED
/*    32 Not defined					*/ NOT_DEFINED
/*    33 Not defined					*/ NOT_DEFINED
/*    34 Not defined					*/ NOT_DEFINED
/*    35 Acoustic Bass Drum      */ 0x00, 0x00, 0x0d, 0x00, 0xe8, 0xa5, 0xef, 0xff, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
/*    36 Bass Drum 1             */ 0x00, 0x00, 0x0b, 0x00, 0xa8, 0xd6, 0x4c, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
/*    37 Side Stick              */ NOT_DEFINED
/*    38 Acoustic Snare          */ 0x2e, 0x02, 0x0a, 0x1b, 0xff, 0xf6, 0x0f, 0x4a, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, /* snare    */
/*    39 Hand Clap               */ NOT_DEFINED
/*    40 Electric Snare          */ 0x0c, 0xd0, 0x00, 0x00, 0xc7, 0x70, 0xb4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* rksnare  */
/*    41 Low Floor Tom           */ NOT_DEFINED
/*    42 Closed Hi-Hat           */ 0x64, 0x03, 0x02, 0x40, 0xb2, 0x97, 0xa2, 0xd4, 0x02, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, /* cymbal   */
/*    43 High Floor Tom          */ NOT_DEFINED
/*    44 Pedal Hi-Hat            */ NOT_DEFINED
/*    45 Low Tom                 */ 0x01, 0x02, 0x00, 0x00, 0xfa, 0xda, 0xbf, 0xbf, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, /* tom      */
/*    46 Open Hi-Hat             */ NOT_DEFINED
/*    47 Low-Mid Tom             */ 0x02, 0x30, 0x00, 0x00, 0xc8, 0xe0, 0x97, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* tom2     */
/*    48 Hi-Mid Tom              */ NOT_DEFINED
/*    49 Crash Cymbal 1          */ NOT_DEFINED
/*    50 High Tom                */ NOT_DEFINED
/*    51 Ride Cymbal 1           */ 0x64, 0x03, 0x00, 0x40, 0xb2, 0x97, 0x82, 0xd4, 0x02, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, /* bcymbal  */
/*    52 Chinese Cymbal          */ NOT_DEFINED
/*    53 Ride Bell               */ NOT_DEFINED
/*    54 Tambourine              */ NOT_DEFINED
/*    55 Splash Cymbal           */ NOT_DEFINED
/*    56 Cowbell                 */ NOT_DEFINED
/*    57 Crash Cymbal 2          */ NOT_DEFINED
/*    58 Vibrasl						*/ NOT_DEFINED
/*    59 Ride Cymbal					*/ NOT_DEFINED
/*    60 Hi Bon						*/ NOT_DEFINED
/*    61 Low Bon						*/ NOT_DEFINED
/*    62 Mute Hi Con					*/ NOT_DEFINED
/*    63 Open Hi Con					*/ NOT_DEFINED
/*    64 Low Con						*/ NOT_DEFINED
/*    65 High Timba					*/ NOT_DEFINED
/*    66 Low Timba					*/ NOT_DEFINED
/*    67 High Ago						*/ NOT_DEFINED
/*    68 Low Ago						*/ NOT_DEFINED
/*    69 Caba							*/ NOT_DEFINED
/*    70 Marac							*/ NOT_DEFINED
/*    71 Short Whist					*/ NOT_DEFINED
/*    72 Long Whist					*/ NOT_DEFINED
/*    73 Short Gui					*/ NOT_DEFINED
/*    74 Long Gui						*/ NOT_DEFINED
/*    75 Clav							*/ 0x13, 0x08, 0x80, 0x00, 0xfb, 0xe8, 0xff, 0xff, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, /* claves   */
/*    76 Hi Wood Blo					*/ NOT_DEFINED
/*    77 Low Wood Blo				*/ NOT_DEFINED
/*    78 Mute Cui						*/ NOT_DEFINED
/*    79 Open Cui						*/ NOT_DEFINED
/*    80 Mute Triang					*/ NOT_DEFINED
/*    81 Open Triang					*/ 0x26, 0x1e, 0x03, 0x00, 0xe0, 0xff, 0xf0, 0x31, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, /* triangle */
/*    82 Not defined					*/ NOT_DEFINED
/*    83 Not defined					*/ NOT_DEFINED
/*    84 Not defined					*/ NOT_DEFINED
/*    85 Not defined					*/ NOT_DEFINED
/*    86 Not defined					*/ NOT_DEFINED
/*    87 Not defined					*/ NOT_DEFINED
/*    88 Not defined					*/ NOT_DEFINED
/*    89 Not defined					*/ NOT_DEFINED
/*    90 Not defined					*/ NOT_DEFINED
/*    91 Not defined					*/ NOT_DEFINED
/*    92 Not defined					*/ NOT_DEFINED
/*    93 Not defined					*/ NOT_DEFINED
/*    94 Not defined					*/ NOT_DEFINED
/*    95 Not defined					*/ NOT_DEFINED
/*    96 Not defined					*/ NOT_DEFINED
/*    97 Not defined					*/ NOT_DEFINED
/*    98 Not defined					*/ NOT_DEFINED
/*    99 Not defined					*/ NOT_DEFINED
/*   100 Not defined					*/ NOT_DEFINED
/*   101 Not defined					*/ NOT_DEFINED
/*   102 Not defined					*/ NOT_DEFINED
/*   103 Not defined					*/ NOT_DEFINED
/*   104 Not defined					*/ NOT_DEFINED
/*   105 Not defined					*/ NOT_DEFINED
/*   106 Not defined					*/ NOT_DEFINED
/*   107 Not defined					*/ NOT_DEFINED
/*   108 Not defined					*/ NOT_DEFINED
/*   109 Not defined					*/ NOT_DEFINED
/*   110 Not defined					*/ NOT_DEFINED
/*   111 Not defined					*/ NOT_DEFINED
/*   112 Not defined					*/ NOT_DEFINED
/*   113 Not defined					*/ NOT_DEFINED
/*   114 Not defined					*/ NOT_DEFINED
/*   115 Not defined					*/ NOT_DEFINED
/*   116 Not defined					*/ NOT_DEFINED
/*   117 Not defined					*/ NOT_DEFINED
/*   118 Not defined					*/ NOT_DEFINED
/*   119 Not defined					*/ NOT_DEFINED
/*   120 Not defined					*/ NOT_DEFINED
/*   121 Not defined					*/ NOT_DEFINED
/*   122 Not defined					*/ NOT_DEFINED
/*   123 Not defined					*/ NOT_DEFINED
/*   124 Not defined					*/ NOT_DEFINED
/*   125 Not defined					*/ NOT_DEFINED
/*   126 Not defined					*/ NOT_DEFINED
/*   127 Not defined					*/ NOT_DEFINED
/*   128 Not defined					*/ NOT_DEFINED
};


