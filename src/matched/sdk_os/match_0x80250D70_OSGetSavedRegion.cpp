// COMPILER: mwcc
// 0x80250D70 OSGetSavedRegion (28B) — Dolphin SDK os/OSReset.c
//
// Copies the saved region/size words out of the reboot-params block (extern
// array at 0x80499F10; region at +0xC, size at +0x10). The base is materialised
// once (lis/addi) and reused for both loads. MWCC GC-1.2.5n.

extern unsigned int __OSRebootParams[];

extern "C" void OSGetSavedRegion(unsigned int* region, unsigned int* size) {
    *region = __OSRebootParams[3];
    *size = __OSRebootParams[4];
}
