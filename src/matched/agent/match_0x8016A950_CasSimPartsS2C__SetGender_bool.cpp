// 0x8016A950 CasSimPartsS2C::SetGender(bool) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 30,4; addi 3,1,8; mr 29,3; bl _s8016A950_0; cmpwi 30,0; beq 0f; lis 4,-32706; mr 3,29; addi 4,4,1756; bl _s8016A950_1; li 0,1; stw 0,0x8(31); b 1f; 0:; lis 4,-32706; mr 3,29; addi 4,4,1764; bl _s8016A950_2; stw 30,0x8(31); 1:; lis 4,-32706; lwz 3,0x0(31); addi 4,4,1772; addi 30,31,4; bl _s8016A950_3; mr 4,3; lwz 5,0x8(1); lwz 3,0x0(31); bl _s8016A950_4; cmpwi 30,0; beq 2f; stw 3,0x4(31); 2:; lwz 4,0x8(1); mr 3,29; bl _s8016A950_5; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8016A950_0();
extern "C" void _s8016A950_1();
extern "C" void _s8016A950_2();
extern "C" void _s8016A950_3();
extern "C" void _s8016A950_4();
extern "C" void _s8016A950_5();
extern "C" void f_8016A950() {}
