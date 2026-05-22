// 0x8007EA2C ISimsObjectModel::UpdateParticle(ObjAnimDef (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x4(30); mr 3,29; li 4,0; ori 0,0,2; stw 0,0x4(30); bl _s8007EA2C_0; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 29,0xac(3); lwz 30,0x40(29); addi 9,30,32; mr 3,9; stfs f1,0x34(9); bl _s8007EA2C_1; lwz 0,0x4(30); mr 3,29; li 4,0; ori 0,0,2; stw 0,0x4(30); bl _s8007EA2C_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0xac(3); lwz 11,0x40(30); lwz 9,0x1c(11); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; li 4,0; bl _s8007EA2C_3; mr 3,30; li 4,0; bl _s8007EA2C_4; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0xac(3); lwz 11,0x40(30); lwz 9,0x1c(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; li 4,0; bl _s8007EA2C_5; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 30,0xac(3); lwz 11,0x40(30); lwz 9,0x1c(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; li 4,0; bl _s8007EA2C_6; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8007EA2C_0();
extern "C" void _s8007EA2C_1();
extern "C" void _s8007EA2C_2();
extern "C" void _s8007EA2C_3();
extern "C" void _s8007EA2C_4();
extern "C" void _s8007EA2C_5();
extern "C" void _s8007EA2C_6();
extern "C" void f_8007EA2C() {}
