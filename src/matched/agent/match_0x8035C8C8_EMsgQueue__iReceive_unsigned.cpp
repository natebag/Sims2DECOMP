// 0x8035C8C8 EMsgQueue::iReceive(unsigned (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; addi 3,31,24; bl _s8035C8C8_0; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; cmpwi 30,0; beq 1f; lwz 9,0x34(31); lwz 11,0x3c(31); rlwinm 9,9,2,0,29; lwzx 0,9,11; stw 0,0x0(30); 1:; lwz 9,0x34(31); mr 3,31; lwz 11,0x38(31); addi 9,9,1; divw 0,9,11; mullw 0,0,11; subf 9,0,9; stw 9,0x34(31); bl _s8035C8C8_1; li 3,1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035C8C8_0();
extern "C" void _s8035C8C8_1();
extern "C" void f_8035C8C8() {}
