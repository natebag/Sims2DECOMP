// COMPILER: mwcc
// 0x8024FE60 OSSetStringTable (12B) — Dolphin SDK os/OSError.c
//
// Stores the symbol string-table pointer into the global at 0x800030D0.
// Absolute lis/stw, no relocation. MWCC GC-1.2.5n.

extern "C" void OSSetStringTable(const void* stringTable) {
    *(const void**)0x800030D0 = stringTable;
}
