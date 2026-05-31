// COMPILER: mwcc
// 0x8025BF9C DVDGetFSTLocation (12B) — Dolphin SDK dvd/dvdfs.c
//
// Returns the FST location word from the disc boot-info (BB2) block. The BB2
// pointer is SDA-resident; FSTLocation is at offset 0x38. MWCC GC-1.2.5n.

struct DVDBB2 { char _pad[0x38]; unsigned int FSTLocation; };
extern DVDBB2* __DVDBB2;

extern "C" unsigned int DVDGetFSTLocation(void) {
    return __DVDBB2->FSTLocation;
}
