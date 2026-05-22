// 0x8002EAB8 ERoom::UpdateWallFade(int) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; lwz 0,0x5c44(9); mr 29,4; cmpwi 0,0; beq 1f; lis 9,-32697; addi 9,9,24012; lwz 11,0xc8(9); cmpwi 11,0; beq 1f; lwz 0,0x24(11); cmpwi 0,1; bne 0f; lwz 0,0xd0(9); cmpwi 0,0; beq 1f; lwz 9,-32644(13); lwz 0,0x0(9); cmpwi 0,0; beq 0f; lis 30,-32693; addi 4,31,4; addi 3,30,3548; bl _s8002EAB8_0; addi 3,30,3548; addi 4,31,16; bl _s8002EAB8_1; addi 3,30,3548; addi 4,31,28; bl _s8002EAB8_2; addi 3,30,3548; addi 4,31,40; bl _s8002EAB8_3; addi 3,30,3548; addi 4,31,52; bl _s8002EAB8_4; addi 3,30,3548; addi 4,31,64; bl _s8002EAB8_5; addi 3,30,3548; addi 4,31,76; bl _s8002EAB8_6; addi 3,30,3548; addi 4,31,88; bl _s8002EAB8_7; 0:; mr 3,31; mr 4,29; bl _s8002EAB8_8; mr 3,31; mr 4,29; bl _s8002EAB8_9; mr 3,31; mr 4,29; bl _s8002EAB8_10; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8002EAB8_0();
extern "C" void _s8002EAB8_1();
extern "C" void _s8002EAB8_2();
extern "C" void _s8002EAB8_3();
extern "C" void _s8002EAB8_4();
extern "C" void _s8002EAB8_5();
extern "C" void _s8002EAB8_6();
extern "C" void _s8002EAB8_7();
extern "C" void _s8002EAB8_8();
extern "C" void _s8002EAB8_9();
extern "C" void _s8002EAB8_10();
extern "C" void f_8002EAB8() {}
