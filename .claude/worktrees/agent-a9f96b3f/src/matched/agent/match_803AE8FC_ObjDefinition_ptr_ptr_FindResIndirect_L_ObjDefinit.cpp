// 0x803AE8FC (104 bytes)
// ObjDefinition * * FindResIndirect<ObjDefinition *>(ObjDefinition * *, ObjDefinition * *, int)

__attribute__((naked))
void ObjDefinition * * FindResIndirect<ObjDefinition *>(ObjDefinition * *, ObjDefinition * *, int) {
    asm volatile(".long 0x7C6A1B78\n.long 0x7C0A2050\n.long 0x7C091671\n.long 0x40810020\n.long 0x2C090001\n.long 0x40820020\n.long 0x812A0000\n.long 0x7D435378\n.long 0xA80900BC\n.long 0x7C002800\n.long 0x4D820020\n.long 0x38600000\n.long 0x4E800020\n.long 0x54000FFE\n.long 0x7C090214\n.long 0x5400083A\n.long 0x7D2A002E\n.long 0x7C6A0214\n.long 0xA96900BC\n.long 0x7C0B2851\n.long 0x4D820020\n.long 0x4081000C\n.long 0x39430004\n.long 0x4BFFFFA8\n.long 0x7C641B78\n.long 0x4BFFFFA0");
}
