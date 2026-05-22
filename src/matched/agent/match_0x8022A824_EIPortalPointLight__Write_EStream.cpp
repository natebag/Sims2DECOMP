// 0x8022A824 EIPortalPointLight::Write(EStream (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,3; mr 29,4; bl _s8022A824_0; lwz 9,0x0(30); addi 4,1,8; lwz 0,0x174(9); lha 3,0x170(9); mtspr 8,0; add 3,30,3; blrl; addi 4,1,8; mr 3,29; bl _s8022A824_1; mr 29,3; addi 4,1,32; lwz 9,0x18(29); li 5,4; lfs f0,0xc4(30); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x20(1); add 3,29,3; blrl; lwz 9,0x18(29); addi 4,1,36; li 5,4; lfs f0,0xc8(30); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x24(1); add 3,29,3; blrl; lwz 0,0xcc(30); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; stb 9,0x18(1); addi 4,1,24; li 5,1; lwz 9,0x18(29); lha 3,0x38(9); lwz 0,0x3c(9); add 3,29,3; mtspr 8,0; blrl; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s8022A824_0();
extern "C" void _s8022A824_1();
extern "C" void f_8022A824() {}
