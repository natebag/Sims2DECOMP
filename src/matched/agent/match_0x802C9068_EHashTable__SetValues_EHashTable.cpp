// 0x802C9068 EHashTable::SetValues(EHashTable (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x0(4); mr 30,3; b 1f; 0:; lwz 4,0xc(31); lwz 5,0x10(31); bl _s802C9068_0; lwz 31,0x4(31); 1:; mr 3,30; li 0,1; cmpwi 31,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C9068_0();
extern "C" void f_802C9068() {}
