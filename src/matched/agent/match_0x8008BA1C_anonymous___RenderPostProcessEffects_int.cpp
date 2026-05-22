// 0x8008BA1C {anonymous}::RenderPostProcessEffects(int, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; rlwinm 3,3,2,0,29; addi 9,9,24012; mr 29,4; addi 9,9,280; lwzx 3,9,3; bl _s8008BA1C_0; mr. 31,3; beq 1f; mr 3,31; bl _s8008BA1C_1; mr 30,3; mr 3,31; bl _s8008BA1C_2; mr 31,3; cmpwi 30,0; beq 0f; lfs f1,-26800(13); mr 3,30; mr 4,29; bl _s8008BA1C_3; 0:; cmpwi 31,0; beq 1f; lfs f1,-26800(13); mr 3,31; mr 4,29; bl _s8008BA1C_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8008BA1C_0();
extern "C" void _s8008BA1C_1();
extern "C" void _s8008BA1C_2();
extern "C" void _s8008BA1C_3();
extern "C" void _s8008BA1C_4();
extern "C" void f_8008BA1C() {}
