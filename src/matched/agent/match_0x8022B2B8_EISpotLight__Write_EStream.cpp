// 0x8022B2B8 EISpotLight::Write(EStream (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,3; mr 30,4; bl _s8022B2B8_0; mr 3,30; addi 4,29,184; bl _s8022B2B8_1; addi 4,29,172; bl _s8022B2B8_2; mr 30,3; addi 4,1,16; lwz 9,0x18(30); li 5,4; lfs f0,0xc4(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x10(1); add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,20; li 5,4; lfs f0,0xc8(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x14(1); add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,24; li 5,4; lfs f0,0xcc(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x18(1); add 3,30,3; blrl; lwz 9,0x18(30); addi 4,1,28; li 5,4; lfs f0,0xd0(29); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; stfs f0,0x1c(1); add 3,30,3; blrl; lwz 0,0xd4(29); li 9,0; cmpwi 0,0; beq 0f; li 9,1; 0:; stb 9,0x8(1); addi 4,1,8; li 5,1; lwz 9,0x18(30); lha 3,0x38(9); lwz 0,0x3c(9); add 3,30,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8022B2B8_0();
extern "C" void _s8022B2B8_1();
extern "C" void _s8022B2B8_2();
extern "C" void f_8022B2B8() {}
