// 0x802C8BA8 EHashTable::InsertNew(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 28,4; mr 30,5; mr 29,6; li 3,20; bl _s802C8BA8_0; mr. 10,3; bne 0f; li 3,0; b 3f; 0:; stw 30,0xc(10); rlwinm 11,28,2,0,29; stw 29,0x10(10); lwz 9,0x8(31); lwzx 0,9,11; stw 0,0x8(10); stwx 10,9,11; lwz 9,0x4(31); stw 9,0x0(10); cmpwi 9,0; beq 1f; stw 10,0x4(9); b 2f; 1:; stw 10,0x0(31); 2:; li 0,0; mr 3,10; stw 0,0x4(10); stw 10,0x4(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802C8BA8_0();
extern "C" void f_802C8BA8() {}
