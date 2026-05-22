// 0x801B690C G2DTarget::UnloadDialog(void) (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x134(31); cmpwi 0,6; bne 6f; lwz 0,0xc4(31); li 9,0; stw 9,0x134(31); cmpwi 0,0; bne 0f; stw 9,0x118(31); 0:; lwz 4,0x14c(31); lis 3,-32705; stw 9,0x88(31); addi 3,3,2780; stw 9,0x84(31); bl _s801B690C_0; mr 3,31; bl _s801B690C_1; li 4,0; li 5,-1; addi 3,31,252; bl _s801B690C_2; li 4,0; li 5,-1; addi 3,31,256; bl _s801B690C_3; li 4,0; li 5,-1; addi 3,31,260; bl _s801B690C_4; li 4,0; li 5,-1; addi 3,31,264; bl _s801B690C_5; li 4,0; addi 3,31,268; li 5,-1; bl _s801B690C_6; lwz 0,0x0(31); lis 9,-32705; addi 4,9,3620; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801B690C_7; 1:; lwz 3,0xcc(31); cmpwi 3,0; beq 2f; bl _s801B690C_8; li 0,0; stw 0,0xcc(31); 2:; lwz 0,0x0(31); cmpwi 0,0; beq 5f; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x58(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x10(31); bl _s801B690C_9; 5:; li 3,0; bl _s801B690C_10; 6:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801B690C_0();
extern "C" void _s801B690C_1();
extern "C" void _s801B690C_2();
extern "C" void _s801B690C_3();
extern "C" void _s801B690C_4();
extern "C" void _s801B690C_5();
extern "C" void _s801B690C_6();
extern "C" void _s801B690C_7();
extern "C" void _s801B690C_8();
extern "C" void _s801B690C_9();
extern "C" void _s801B690C_10();
extern "C" void f_801B690C() {}
