// 0x8031BD8C ERQuickdata::findRow(void (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,5; lwz 9,0x14(31); mr 30,4; li 4,0; lwz 5,0x8(9); mr 6,30; addi 5,5,-1; bl _s8031BD8C_0; mr. 3,3; li 7,0; blt 1f; mulli 8,3,20; lwz 3,0x14(31); addi 9,3,40; lwzx 11,9,8; cmpwi 11,0; bne 0f; li 11,1; 0:; addi 9,3,28; lwzx 0,9,8; subf 0,0,30; divwu 10,0,11; mullw 9,10,11; cmpw 0,9; bne 1f; addi 0,8,24; stw 10,0x0(29); add 7,3,0; 1:; mr 3,7; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8031BD8C_0();
extern "C" void f_8031BD8C() {}
