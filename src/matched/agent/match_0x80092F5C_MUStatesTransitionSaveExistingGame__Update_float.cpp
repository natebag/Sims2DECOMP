// 0x80092F5C MUStatesTransitionSaveExistingGame::Update(float) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 9,0x8(31); lwz 30,0x90(9); cmpwi 30,0; bne 3f; lwz 0,0x1c(31); cmpwi 0,0; bne 0f; lis 9,-32696; lis 6,171; lwz 3,0x58d8(9); li 4,0; li 5,0; ori 6,6,52719; bl _s80092F5C_0; b 2f; 0:; cmpwi 0,8; bne 1f; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80092F5C_1; stw 30,0x24(3); li 0,1; stw 0,-24656(13); li 9,9; stw 9,0x1c(31); b 7f; 1:; cmpwi 0,9; bne 7f; lfs f0,0x20(31); lis 9,-32706; lfs f13,-32024(9); fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x20(31); bgt 7f; lis 9,-32696; lis 6,171; lwz 3,0x58d8(9); li 4,0; li 5,0; ori 6,6,52719; bl _s80092F5C_2; cmpwi 3,1; beq 2f; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80092F5C_3; li 0,1; li 10,6; stw 0,0x24(3); li 4,10; lwz 9,0x8(31); lwz 11,0x98(9); stw 10,0xac(11); lwz 9,0x8(31); lwz 3,0x98(9); bl _s80092F5C_4; mr 3,31; li 4,14; bl _s80092F5C_5; li 0,7; stw 0,0x1c(31); b 7f; 2:; lwz 3,0x8(31); li 4,2; bl _s80092F5C_6; b 7f; 3:; cmpwi 30,1; beq 7f; cmpwi 30,2; bne 7f; lwz 0,0x1c(31); cmpwi 0,1; beq 6f; cmpwi 0,10; beq 4f; cmpwi 0,2; beq 4f; cmpwi 0,3; beq 4f; cmpwi 0,4; beq 4f; cmpwi 0,5; beq 4f; cmpwi 0,6; beq 4f; cmpwi 0,12; beq 4f; cmpwi 0,7; bne 5f; 4:; lwz 3,0x8(31); li 4,1; bl _s80092F5C_7; b 7f; 5:; cmpwi 0,11; bne 7f; 6:; li 0,0; stw 0,0x1c(31); stw 0,0x90(9); 7:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80092F5C_0();
extern "C" void _s80092F5C_1();
extern "C" void _s80092F5C_2();
extern "C" void _s80092F5C_3();
extern "C" void _s80092F5C_4();
extern "C" void _s80092F5C_5();
extern "C" void _s80092F5C_6();
extern "C" void _s80092F5C_7();
extern "C" void f_80092F5C() {}
