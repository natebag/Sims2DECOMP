// 0x8030FF7C EResLoaderMsgQueue::Send(unsigned (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; cmpwi 5,0; li 4,0; beq 0f; li 4,-1; 0:; mr 3,31; bl _s8030FF7C_0; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; lwz 9,0x4c(31); addi 30,31,76; li 4,-1; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x30(31); lwz 10,0x3c(31); rlwinm 9,9,2,0,29; stwx 29,9,10; lwz 11,0x30(31); lwz 10,0x38(31); addi 11,11,1; lwz 9,0x44(31); divw 0,11,10; lwz 8,0x4c(31); addi 9,9,1; stw 9,0x44(31); mullw 0,0,10; subf 11,0,11; stw 11,0x30(31); lwz 0,0x1c(8); lha 3,0x18(8); mtspr 8,0; add 3,30,3; blrl; mr 3,31; bl _s8030FF7C_1; lwz 0,0x48(31); cmplw 3,0; ble 2f; mr 3,31; bl _s8030FF7C_2; stw 3,0x48(31); 2:; addi 3,31,24; bl _s8030FF7C_3; li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8030FF7C_0();
extern "C" void _s8030FF7C_1();
extern "C" void _s8030FF7C_2();
extern "C" void _s8030FF7C_3();
extern "C" void f_8030FF7C() {}
