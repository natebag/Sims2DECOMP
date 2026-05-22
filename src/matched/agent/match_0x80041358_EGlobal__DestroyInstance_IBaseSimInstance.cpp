// 0x80041358 EGlobal::DestroyInstance(IBaseSimInstance (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,4; mr 29,3; lwz 11,0x0(26); cmpwi 11,0; beq 4f; lwz 9,0x0(11); li 27,0; addi 31,29,188; addi 28,29,196; lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; 0:; mr 3,30; bl _s80041358_0; lwz 9,0x0(31); cmpwi 9,0; beq 1f; lwz 0,0x0(9); cmpw 0,3; beq 2f; b 3f; 1:; cmpwi 3,0; bne 3f; 2:; stw 27,0x0(31); 3:; addi 31,31,4; cmpw 31,28; ble 0b; lwz 9,0xc8(29); mr 4,30; lwz 3,0x1c(9); bl _s80041358_1; lwz 11,0x0(30); lwz 9,0xc8(29); lwz 0,0x1ac(11); lha 3,0x1a8(11); lwz 4,0x1c(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x0(30); lwz 9,0xc8(29); lha 3,0x190(11); lwz 0,0x194(11); lwz 4,0x1c(9); add 3,30,3; mtspr 8,0; blrl; lwz 9,0xc8(29); mr 4,30; lwz 3,0x4(9); bl _s80041358_2; 4:; li 0,0; stw 0,0x0(26); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80041358_0();
extern "C" void _s80041358_1();
extern "C" void _s80041358_2();
extern "C" void f_80041358() {}
