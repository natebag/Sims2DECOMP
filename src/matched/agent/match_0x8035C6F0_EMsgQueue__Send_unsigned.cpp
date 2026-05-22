// 0x8035C6F0 EMsgQueue::Send(unsigned (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; cmpwi 5,0; li 4,0; beq 0f; li 4,-1; 0:; mr 3,31; bl _s8035C6F0_0; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; bl _s8035C6F0_1; lwz 9,0x30(31); lwz 10,0x3c(31); rlwinm 9,9,2,0,29; stwx 30,9,10; lwz 11,0x30(31); lwz 10,0x38(31); addi 11,11,1; lwz 9,0x44(31); divw 0,11,10; addi 9,9,1; stw 9,0x44(31); mullw 0,0,10; subf 11,0,11; stw 11,0x30(31); bl _s8035C6F0_2; addi 3,31,24; bl _s8035C6F0_3; mr 3,31; bl _s8035C6F0_4; lwz 0,0x48(31); cmplw 3,0; ble 2f; mr 3,31; bl _s8035C6F0_5; stw 3,0x48(31); 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035C6F0_0();
extern "C" void _s8035C6F0_1();
extern "C" void _s8035C6F0_2();
extern "C" void _s8035C6F0_3();
extern "C" void _s8035C6F0_4();
extern "C" void _s8035C6F0_5();
extern "C" void f_8035C6F0() {}
