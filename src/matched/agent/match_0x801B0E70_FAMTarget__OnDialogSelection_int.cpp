// 0x801B0E70 FAMTarget::OnDialogSelection(int) (520 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; lwz 0,0x88(28); cmpwi 7,0,1; bne cr7,0f; cmpwi 4,0; bne 6f; lwz 0,0x160(28); cmpwi 0,0; beq 6f; cmpwi 0,1; bne 6f; bl _s801B0E70_0; b 6f; 0:; cmpwi 0,3; bne 4f; lwz 0,0x15c(28); cmpwi 0,1; bne 6f; cmpwi 4,1; bne 6f; lwz 4,0x150(28); mr 3,28; bl _s801B0E70_1; mr. 31,3; beq 3f; b 2f; 1:; lwz 9,0x0(31); li 4,0; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); lwz 29,0x0(3); lwz 0,0x24(9); lha 3,0x20(9); mr 4,29; mtspr 8,0; add 3,31,3; blrl; lwz 30,-21476(13); mr 4,29; lwz 9,0x0(30); lha 3,0xc0(9); addi 29,9,368; lwz 11,0xc4(9); add 3,30,3; lha 0,0x170(9); mtspr 8,11; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; 2:; lwz 9,0x0(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bgt 1b; lwz 11,-21476(13); mr 4,31; lwz 9,0x0(11); lwz 0,0x144(9); lha 3,0x140(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); lwz 4,-32056(13); lwz 9,0x0(11); lwz 5,-32040(13); lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; 3:; mr 3,28; bl _s801B0E70_2; b 6f; 4:; beq cr7,6f; cmpwi 0,2; bne 6f; lwz 0,0x164(28); cmpwi 0,1; bne 6f; cmpwi 4,0; bne 6f; lwz 4,0x14c(28); mr 3,28; bl _s801B0E70_3; lwz 0,-31536(13); mr 31,3; cmpwi 0,0; bne 5f; li 3,120; bl _s801B0E70_4; bl _s801B0E70_5; stw 3,-31536(13); 5:; lwz 3,-31536(13); lis 4,-24537; ori 4,4,46451; bl _s801B0E70_6; addi 3,31,-1; bl _s801B0E70_7; 6:; mr 3,28; bl _s801B0E70_8; mr 3,28; bl _s801B0E70_9; lis 3,-32705; li 4,0; addi 3,3,1684; li 5,0; li 6,0; li 7,0; bl _s801B0E70_10; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801B0E70_0();
extern "C" void _s801B0E70_1();
extern "C" void _s801B0E70_2();
extern "C" void _s801B0E70_3();
extern "C" void _s801B0E70_4();
extern "C" void _s801B0E70_5();
extern "C" void _s801B0E70_6();
extern "C" void _s801B0E70_7();
extern "C" void _s801B0E70_8();
extern "C" void _s801B0E70_9();
extern "C" void _s801B0E70_10();
extern "C" void f_801B0E70() {}
