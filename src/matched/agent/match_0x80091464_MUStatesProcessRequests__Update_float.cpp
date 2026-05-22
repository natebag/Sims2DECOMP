// 0x80091464 MUStatesProcessRequests::Update(float) (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x8(31); lwz 0,0x90(9); cmpwi 0,0; bne 0f; stw 0,0x1c(31); b 5f; 0:; cmpwi 0,2; bne 2f; lwz 0,0x1c(31); cmpwi 0,1; bne 1f; li 0,0; stw 0,0x1c(31); b 4f; 1:; li 0,1; b 3f; 2:; cmpwi 0,1; bne 5f; lwz 0,0x1c(31); cmpwi 0,1; beq 4f; li 0,2; 3:; stw 0,-21372(13); 4:; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80091464_0; li 0,0; stw 0,0x24(3); lwz 9,0x8(31); stw 0,0x90(9); b 15f; 5:; lwz 0,-21368(13); cmpwi 0,0; beq 15f; cmpwi 0,8; bgt 15f; lis 9,-32697; li 30,0; lwz 29,0x5c20(9); stw 0,-21364(13); stw 30,-21368(13); cmpwi 29,0; beq 6f; lwz 9,0x8(31); li 0,3; stw 0,-21372(13); lwz 3,0x98(9); bl _s80091464_1; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80091464_2; stw 30,0x24(3); lwz 9,0x8(31); stw 30,0x90(9); stw 30,0x1c(31); b 15f; 6:; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80091464_3; lwz 9,-21364(13); li 0,1; stw 0,0x24(3); cmpwi 9,4; beq 11f; bgt 7f; cmpwi 9,2; beq 9f; bgt 10f; cmpwi 9,1; beq 8f; b 15f; 7:; cmpwi 9,6; beq 15f; blt 12f; cmpwi 9,7; beq 13f; cmpwi 9,8; beq 14f; b 15f; 8:; mr 3,31; li 4,2; bl _s80091464_4; b 15f; 9:; mr 3,31; li 4,3; bl _s80091464_5; b 15f; 10:; mr 3,31; li 4,7; bl _s80091464_6; b 15f; 11:; mr 3,31; li 4,5; bl _s80091464_7; b 15f; 12:; mr 3,31; li 4,8; bl _s80091464_8; b 15f; 13:; lwz 3,-21500(13); lis 4,21321; ori 4,4,19795; bl _s80091464_9; stw 29,0x24(3); li 4,9; mr 3,31; bl _s80091464_10; b 15f; 14:; mr 3,31; li 4,13; bl _s80091464_11; 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80091464_0();
extern "C" void _s80091464_1();
extern "C" void _s80091464_2();
extern "C" void _s80091464_3();
extern "C" void _s80091464_4();
extern "C" void _s80091464_5();
extern "C" void _s80091464_6();
extern "C" void _s80091464_7();
extern "C" void _s80091464_8();
extern "C" void _s80091464_9();
extern "C" void _s80091464_10();
extern "C" void _s80091464_11();
extern "C" void f_80091464() {}
