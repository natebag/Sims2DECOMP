// 0x8033B304 ENgcRC::SpriteList(int, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,9; mr. 11,4; beq 0f; lwz 9,0x0(3); mr 4,11; lis 3,-32691; lwz 0,0x54(9); addi 3,3,21688; add 0,0,11; stw 0,0x54(9); mr 9,10; bl _s8033B304_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8033B304_0();
extern "C" void f_8033B304() {}
