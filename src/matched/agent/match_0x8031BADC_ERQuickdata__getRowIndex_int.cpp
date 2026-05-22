// 0x8031BADC ERQuickdata::getRowIndex(int, (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,5; mr 27,6; 0:; cmpwi 28,0; beq 4f; cmpwi 27,0; beq 4f; subf. 9,30,29; blt 4f; bne 1f; rlwinm 0,30,2,0,29; mr 3,28; lwzx 4,27,0; bl _s8031BADC_0; cmpwi 3,0; mr 3,30; beq 5f; b 4f; 1:; rlwinm 0,9,1,31,31; mr 3,28; add 0,9,0; srawi 0,0,1; add 31,30,0; rlwinm 9,31,2,0,29; lwzx 4,9,27; bl _s8031BADC_1; cmpwi 3,0; bne 2f; mr 3,31; b 5f; 2:; ble 3f; addi 30,31,1; b 0b; 3:; addi 29,31,-1; b 0b; 4:; li 3,-1; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8031BADC_0();
extern "C" void _s8031BADC_1();
extern "C" void f_8031BADC() {}
