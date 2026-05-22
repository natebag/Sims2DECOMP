// 0x801A0048 CASRoommateTarget::~CASRoommateTarget(void) (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 11,-32698; lwz 3,0x94(31); lis 9,-32698; addi 11,11,27176; addi 9,9,27272; mr 30,4; stw 11,0x88(31); stw 9,0x80(31); cmpwi 3,0; beq 0f; li 4,3; bl _s801A0048_0; 0:; lwz 9,0x0(31); li 0,0; stw 0,0x94(31); cmpwi 9,0; beq 10f; lwz 3,0x4(31); addi 4,31,40; bl _s801A0048_1; lwz 3,0x8(31); addi 4,31,56; bl _s801A0048_2; lwz 3,0xc(31); addi 4,31,72; bl _s801A0048_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 1f; lwz 0,0x58(31); cmpwi 0,0; beq 2f; 1:; li 11,1; 2:; cmpwi 11,0; beq 3f; lwz 3,0x10(31); bl _s801A0048_4; 3:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x68(31); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x14(31); bl _s801A0048_5; 6:; lwz 3,0x18(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801A0048_6; 7:; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801A0048_7; 8:; lwz 3,0x20(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801A0048_8; 9:; lwz 3,0x24(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801A0048_9; 10:; lis 9,-32698; lis 11,-32698; addi 9,9,24424; addi 11,11,-12328; stw 9,0x88(31); andi. 0,30,1; stw 11,0x80(31); beq 11f; mr 3,31; bl _s801A0048_10; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801A0048_0();
extern "C" void _s801A0048_1();
extern "C" void _s801A0048_2();
extern "C" void _s801A0048_3();
extern "C" void _s801A0048_4();
extern "C" void _s801A0048_5();
extern "C" void _s801A0048_6();
extern "C" void _s801A0048_7();
extern "C" void _s801A0048_8();
extern "C" void _s801A0048_9();
extern "C" void _s801A0048_10();
extern "C" void f_801A0048() {}
