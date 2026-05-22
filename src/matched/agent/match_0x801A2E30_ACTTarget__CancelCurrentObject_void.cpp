// 0x801A2E30 ACTTarget::CancelCurrentObject(void) (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x648(31); cmpwi 9,0; beq 6f; lwz 0,0x8(9); cmpwi 0,0; bne 6f; lwz 4,0x38(9); bl _s801A2E30_0; lwz 9,0x648(31); stw 3,0x3c(9); lwz 11,0x648(31); lwz 3,0x3c(11); cmpwi 3,0; beq 6f; bl _s801A2E30_1; lwz 30,0x648(31); mr 11,3; lwz 9,0x3c(30); lwz 0,0x3c(9); rlwinm 29,0,24,31,31; cmpwi 29,0; bne 4f; lwz 9,0x4(11); lwz 4,0x38(30); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-31536(13); cmpwi 0,0; bne 0f; li 3,120; bl _s801A2E30_2; bl _s801A2E30_3; stw 3,-31536(13); 0:; lwz 3,-31536(13); lis 4,14155; ori 4,4,56554; bl _s801A2E30_4; lwz 0,0x644(31); cmpwi 0,0; beq 6f; cmpwi 7,30,0; beq cr7,3f; lwz 9,0x44(30); cmpwi 9,0; beq 1f; lwz 0,0x0(9); cmpwi 0,8; bgt 1f; stw 29,0x64c(31); mr 3,31; lwz 0,0x44(30); b 2f; 1:; beq cr7,3f; lwz 0,0x48(30); cmpwi 0,0; beq 3f; li 9,0; mr 3,31; stw 9,0x64c(31); lwz 0,0x48(30); 2:; stw 0,0x648(31); bl _s801A2E30_5; b 6f; 3:; mr 3,31; bl _s801A2E30_6; b 6f; 4:; lwz 0,-31536(13); cmpwi 0,0; bne 5f; li 3,120; bl _s801A2E30_7; bl _s801A2E30_8; stw 3,-31536(13); 5:; lis 4,10927; lwz 3,-31536(13); ori 4,4,62296; bl _s801A2E30_9; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801A2E30_0();
extern "C" void _s801A2E30_1();
extern "C" void _s801A2E30_2();
extern "C" void _s801A2E30_3();
extern "C" void _s801A2E30_4();
extern "C" void _s801A2E30_5();
extern "C" void _s801A2E30_6();
extern "C" void _s801A2E30_7();
extern "C" void _s801A2E30_8();
extern "C" void _s801A2E30_9();
extern "C" void f_801A2E30() {}
