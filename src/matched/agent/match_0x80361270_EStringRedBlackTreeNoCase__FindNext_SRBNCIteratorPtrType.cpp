// 0x80361270 EStringRedBlackTreeNoCase::FindNext(SRBNCIteratorPtrType (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x10(4); mr 30,5; cmpwi 31,0; beq 1f; lwz 4,0x1c(4); addi 3,31,28; bl _s80361270_0; cmpwi 3,0; bne 1f; cmpwi 30,0; beq 0f; lwz 0,0x18(31); stw 0,0x0(30); 0:; mr 3,31; b 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80361270_0();
extern "C" void f_80361270() {}
