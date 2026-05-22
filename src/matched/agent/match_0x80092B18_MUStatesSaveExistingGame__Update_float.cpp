// 0x80092B18 MUStatesSaveExistingGame::Update(float) (556 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x8(31); lwz 30,0x90(3); cmpwi 30,0; bne 7f; lwz 0,0x1c(31); cmpwi 0,0; bne 2f; lis 9,-32696; stw 30,0x8(1); addi 11,9,22744; addi 4,1,8; lwz 3,0x8(11); stw 30,0x4(11); stw 3,0x58d8(9); bl _s80092B18_0; cmpwi 3,1; beq 0f; lwz 9,0x8(31); stw 30,0x1c(31); stw 30,0x90(9); b 13f; 0:; lwz 0,0x8(1); cmpwi 0,0; beq 1f; lwz 11,0x8(31); li 0,9; li 4,24; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092B18_1; mr 3,31; li 4,14; bl _s80092B18_2; li 0,11; stw 0,0x1c(31); b 13f; 1:; li 0,8; stw 0,0x1c(31); b 13f; 2:; cmpwi 0,8; bne 5f; lis 9,-32696; lis 6,171; lwz 3,0x58d8(9); li 4,0; stw 30,-24648(13); li 5,0; ori 6,6,52719; bl _s80092B18_3; li 0,1; cmpwi 3,1; stw 0,-24656(13); bne 3f; stw 3,-24648(13); 3:; lwz 0,-24648(13); cmpwi 0,0; bne 4f; lwz 11,0x8(31); li 0,6; li 4,10; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80092B18_4; mr 3,31; li 4,14; bl _s80092B18_5; li 0,7; stw 0,0x1c(31); b 13f; 4:; lis 9,-32706; stw 30,-24656(13); lfs f0,-32032(9); li 0,9; stw 0,0x1c(31); stfs f0,0x20(31); b 13f; 5:; cmpwi 0,9; bne 6f; lfs f0,0x20(31); lis 9,-32706; lfs f13,-32028(9); fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x20(31); bgt 13f; 6:; lwz 3,0x8(31); li 4,2; bl _s80092B18_6; b 13f; 7:; cmpwi 30,1; bne 8f; lwz 0,0x1c(31); cmpwi 0,1; bne 13f; b 10f; 8:; cmpwi 30,2; bne 13f; lwz 0,0x1c(31); cmpwi 0,1; beq 12f; cmpwi 0,2; beq 9f; cmpwi 0,10; beq 9f; cmpwi 0,3; beq 9f; cmpwi 0,4; beq 9f; cmpwi 0,5; beq 9f; cmpwi 0,6; beq 9f; cmpwi 0,12; beq 9f; cmpwi 0,7; bne 11f; 9:; lwz 3,0x8(31); 10:; li 4,1; bl _s80092B18_7; b 13f; 11:; cmpwi 0,11; bne 13f; 12:; li 0,0; stw 0,0x1c(31); stw 0,0x90(3); 13:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80092B18_0();
extern "C" void _s80092B18_1();
extern "C" void _s80092B18_2();
extern "C" void _s80092B18_3();
extern "C" void _s80092B18_4();
extern "C" void _s80092B18_5();
extern "C" void _s80092B18_6();
extern "C" void _s80092B18_7();
extern "C" void f_80092B18() {}
