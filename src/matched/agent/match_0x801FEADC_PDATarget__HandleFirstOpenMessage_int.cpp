// 0x801FEADC PDATarget::HandleFirstOpenMessage(int) (872 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 26,0x38(1); stw 0,0x54(1); mr 27,4; mr 31,3; li 26,0; li 28,0; cmpwi 27,2; bne 0f; li 27,0; 0:; rlwinm 0,27,2,0,29; addi 9,13,-28524; lwzx 29,9,0; lis 11,-32700; addi 11,11,-25120; lis 9,-32697; lbzx 0,11,29; lwz 10,0x5c70(9); cmpwi 0,0; beq 1f; addi 9,11,14; lbzx 0,9,29; cmpwi 0,0; bne 22f; cmpwi 10,0; beq 22f; 1:; cmpwi 29,6; beq 10f; bgt 3f; cmpwi 29,2; beq 6f; bgt 2f; cmpwi 29,0; beq 17f; cmpwi 29,1; beq 5f; b 17f; 2:; cmpwi 29,4; beq 8f; bgt 9f; b 7f; 3:; cmpwi 29,9; beq 13f; bgt 4f; cmpwi 29,7; beq 11f; cmpwi 29,8; beq 12f; b 17f; 4:; cmpwi 29,11; beq 17f; blt 14f; b 17f; 5:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19952; addi 3,1,8; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_0; lwz 9,0x8(1); b 15f; 6:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19928; addi 3,1,12; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_1; lwz 9,0xc(1); b 15f; 7:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19904; addi 3,1,16; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_2; lwz 9,0x10(1); b 15f; 8:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19880; addi 3,1,20; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_3; lwz 9,0x14(1); b 15f; 9:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19856; addi 3,1,24; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_4; lwz 9,0x18(1); b 15f; 10:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19832; addi 3,1,28; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_5; lwz 9,0x1c(1); b 15f; 11:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19808; addi 3,1,32; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_6; lwz 9,0x20(1); b 15f; 12:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19784; addi 3,1,36; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_7; lwz 9,0x24(1); b 15f; 13:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19760; addi 3,1,40; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_8; lwz 9,0x28(1); b 15f; 14:; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-19736; addi 3,1,44; addi 30,31,172; crxor 6,6,6; bl _s801FEADC_9; lwz 9,0x2c(1); 15:; li 4,0; cmpwi 9,0; beq 16f; lwz 4,0x0(9); 16:; mr 3,30; bl _s801FEADC_10; b 18f; 17:; li 26,1; 18:; cmpwi 26,0; bne 22f; lis 30,-32704; addi 3,31,176; addi 4,30,-30460; addi 28,31,180; bl _s801FEADC_11; lis 4,-32697; lis 5,-32704; addi 4,4,24012; addi 5,5,-28492; addi 3,1,48; crxor 6,6,6; bl _s801FEADC_12; lwz 9,0x30(1); li 4,0; cmpwi 9,0; beq 19f; lwz 4,0x0(9); 19:; mr 3,28; bl _s801FEADC_13; addi 4,30,-30460; addi 3,31,184; bl _s801FEADC_14; addi 4,30,-30460; addi 3,31,188; bl _s801FEADC_15; li 9,1; li 0,3; stw 26,0x90(31); cmpwi 27,0; stw 0,0x8c(31); stw 9,0x84(31); stw 26,0x88(31); stw 9,0x94(31); stw 9,0x98(31); bne 20f; stw 9,0xd0(31); b 21f; 20:; li 0,2; stw 0,0xd0(31); 21:; lis 9,-32700; li 11,1; addi 9,9,-25120; li 0,0; stw 0,0xa8(31); addi 10,9,14; stw 11,0x168(31); li 28,1; stbx 11,10,29; stbx 11,9,29; 22:; mr 3,28; lwz 0,0x54(1); mtspr 8,0; lmw 26,0x38(1); addi 1,1,80"
extern "C" void _s801FEADC_0();
extern "C" void _s801FEADC_1();
extern "C" void _s801FEADC_2();
extern "C" void _s801FEADC_3();
extern "C" void _s801FEADC_4();
extern "C" void _s801FEADC_5();
extern "C" void _s801FEADC_6();
extern "C" void _s801FEADC_7();
extern "C" void _s801FEADC_8();
extern "C" void _s801FEADC_9();
extern "C" void _s801FEADC_10();
extern "C" void _s801FEADC_11();
extern "C" void _s801FEADC_12();
extern "C" void _s801FEADC_13();
extern "C" void _s801FEADC_14();
extern "C" void _s801FEADC_15();
extern "C" void f_801FEADC() {}
