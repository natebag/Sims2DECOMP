// COMPILER: mwcc
// 0x8025FCF0 DVDGetCurrentDiskID (8B) — Dolphin SDK dvd/dvd.c
//
// Returns the current disc ID, which lives at the very start of low memory
// (0x80000000). The constant address folds to a single lis. MWCC GC-1.2.5n.

extern "C" void* DVDGetCurrentDiskID(void) {
    return (void*)0x80000000;
}
