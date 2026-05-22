// 0x802D0F24 EAHeap::FindHeapForAddress(void (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s802D0F24_0; cmpwi 3,0; beq 0f; mr 3,31; b 3f; 0:; lwz 3,0x52c(31); cmpwi 3,0; beq 1f; mr 4,30; bl _s802D0F24_1; mr. 3,3; bne 3f; 1:; lwz 3,0x530(31); cmpwi 3,0; beq 2f; mr 4,30; bl _s802D0F24_2; mr. 3,3; bne 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D0F24_0();
extern "C" void _s802D0F24_1();
extern "C" void _s802D0F24_2();
extern "C" void f_802D0F24() {}
