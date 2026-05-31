// COMPILER: mwcc
// 0x8025BF8C DVDRewindDir (16B) — Dolphin SDK dvd/dvdfs.c
//
// Resets a directory iterator: location = entryStart + 1. dir->entryStart is at
// offset 0, dir->location at offset 4. MWCC GC-1.2.5n.

struct DVDDir { unsigned int entryStart; unsigned int location; };

extern "C" void DVDRewindDir(DVDDir* dir) {
    dir->location = dir->entryStart + 1;
}
