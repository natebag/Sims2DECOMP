// 0x803ADF68 (96 bytes)
// SndInfo * FindRes<SndInfo>(SndInfo *, SndInfo *, int)

__attribute__((naked))
void SndInfo * FindRes<SndInfo>(SndInfo *, SndInfo *, int) {
    asm volatile(".long 0x7C6B1B78\n.long 0x7C0B2050\n.long 0x7C091E71\n.long 0x4081001C\n.long 0x2C090001\n.long 0x4082001C\n.long 0x800B0000\n.long 0x7D635B78\n.long 0x7C002800\n.long 0x4D820020\n.long 0x38600000\n.long 0x4E800020\n.long 0x54000FFE\n.long 0x7C090214\n.long 0x54001038\n.long 0x7D2B002E\n.long 0x7C6B0214\n.long 0x7C092851\n.long 0x4D820020\n.long 0x4081000C\n.long 0x39630008\n.long 0x4BFFFFB0\n.long 0x7C641B78\n.long 0x4BFFFFA8");
}
