// 0x8035C850 EMsgQueue::iSend(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8035C850_0; cmpwi 3,0; beq 0f; lwz 11,0x30(31); addi 3,31,24; lwz 10,0x3c(31); rlwinm 11,11,2,0,29; stwx 30,11,10; lwz 9,0x30(31); lwz 11,0x38(31); addi 9,9,1; divw 0,9,11; mullw 0,0,11; subf 9,0,9; stw 9,0x30(31); bl _s8035C850_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035C850_0();
extern "C" void _s8035C850_1();
extern "C" void f_8035C850() {}
