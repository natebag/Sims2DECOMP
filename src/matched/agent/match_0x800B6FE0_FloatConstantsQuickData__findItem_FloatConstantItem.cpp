// 0x800B6FE0 FloatConstantsQuickData::findItem(FloatConstantItem (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 28,5; 0:; subf 0,30,29; srawi. 9,0,3; ble 1f; cmpwi 9,1; bne 2f; lwz 3,0x4(30); mr 4,28; bl _s800B6FE0_0; cmpwi 3,0; mr 3,30; beq 5f; 1:; li 3,0; b 5f; 2:; rlwinm 0,0,1,31,31; mr 3,28; add 0,9,0; rlwinm 0,0,2,0,28; add 31,30,0; lwz 4,0x4(31); bl _s800B6FE0_1; cmpwi 3,0; bne 3f; mr 3,31; b 5f; 3:; ble 4f; addi 30,31,8; b 0b; 4:; mr 29,31; b 0b; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800B6FE0_0();
extern "C" void _s800B6FE0_1();
extern "C" void f_800B6FE0() {}
