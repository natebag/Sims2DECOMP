// 0x802C8F80 EHashTable::AutoSizeTable(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802C8F80_0; li 4,1; cmpw 4,3; bge 1f; 0:; add 4,4,4; cmpw 4,3; blt 0b; 1:; cmpwi 4,1; ble 2f; addi 4,4,-1; 2:; mr 3,31; bl _s802C8F80_1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802C8F80_0();
extern "C" void _s802C8F80_1();
extern "C" void f_802C8F80() {}
