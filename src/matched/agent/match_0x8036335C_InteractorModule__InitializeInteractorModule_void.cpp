// 0x8036335C InteractorModule::InitializeInteractorModule(void) (516 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 4,2; addi 3,3,-6992; bl _s8036335C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x48(3); blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8036335C_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8036335C_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,24; bl _s8036335C_3; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); addi 3,3,24; bl _s8036335C_4; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; lwz 3,0x54(3); blr; stwu 1,-16(1); lwz 0,0x58(3); lis 7,17200; lwz 9,0x5c(3); xoris 0,0,32768; mr 10,11; stw 0,0xc(1); xoris 9,9,32768; lis 8,-32702; stw 7,0x8(1); lfd f13,0x2fb0(8); lfd f0,0x8(1); stw 9,0xc(1); fsub f0,f0,f13; stw 7,0x8(1); frsp f0,f0; lfd f1,0x8(1); fsub f1,f1,f13; frsp f1,f1; fdivs f1,f0,f1; addi 1,1,16; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,1; ori 4,4,65535; bl _s8036335C_5; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 4,0; li 3,0; ori 4,4,65535; bl _s8036335C_6; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8036335C_7; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; addi 4,1,8; bl _s8036335C_8; lwz 0,0x8(1); mr 3,30; stw 0,0x0(29); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32; blr; stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; addi 4,1,8; bl _s8036335C_9; lwz 0,0x8(1); mr 3,30; stw 0,0x0(29); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8036335C_0();
extern "C" void _s8036335C_1();
extern "C" void _s8036335C_2();
extern "C" void _s8036335C_3();
extern "C" void _s8036335C_4();
extern "C" void _s8036335C_5();
extern "C" void _s8036335C_6();
extern "C" void _s8036335C_7();
extern "C" void _s8036335C_8();
extern "C" void _s8036335C_9();
extern "C" void f_8036335C() {}
