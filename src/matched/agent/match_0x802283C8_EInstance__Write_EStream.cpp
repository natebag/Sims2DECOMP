// 0x802283C8 EInstance::Write(EStream (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 29,3; lwz 9,0x18(30); addi 4,1,8; li 5,4; lwz 0,0x58(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x8(1); mtspr 8,9; blrl; lwz 4,0x4(29); mr 3,30; bl _s802283C8_0; lwz 4,0x38(29); bl _s802283C8_1; mr 30,3; addi 4,1,12; lwz 9,0x18(30); li 5,4; lwz 0,0x5c(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0xc(1); mtspr 8,9; blrl; mr 3,30; addi 4,29,60; bl _s802283C8_2; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802283C8_0();
extern "C" void _s802283C8_1();
extern "C" void _s802283C8_2();
extern "C" void f_802283C8() {}
