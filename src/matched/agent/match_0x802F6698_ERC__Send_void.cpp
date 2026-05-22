// 0x802F6698 ERC::Send(void) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,0; beq 0f; lwz 29,0x10(31); cmpwi 29,0; bne 0f; lwz 9,0x70(31); addi 30,1,8; lwz 0,0x2a4(9); lha 3,0x2a0(9); mtspr 8,0; add 3,31,3; blrl; addi 3,1,8; li 4,4096; bl _s802F6698_0; lwz 4,0x0(31); addi 3,1,8; bl _s802F6698_1; lwz 11,-26392(13); li 5,1; lwz 4,0x0(31); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x70(31); li 4,0; stw 29,0x0(31); lwz 0,0x29c(9); lha 3,0x298(9); mtspr 8,0; add 3,31,3; blrl; lwz 3,0x0(31); addi 4,1,8; bl _s802F6698_2; li 4,4096; li 5,32; mr 3,31; bl _s802F6698_3; lwz 9,0x0(31); mr 0,3; mr 3,30; stw 0,0x48(9); stw 0,0x8(31); bl _s802F6698_4; mr 3,30; bl _s802F6698_5; 0:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s802F6698_0();
extern "C" void _s802F6698_1();
extern "C" void _s802F6698_2();
extern "C" void _s802F6698_3();
extern "C" void _s802F6698_4();
extern "C" void _s802F6698_5();
extern "C" void f_802F6698() {}
