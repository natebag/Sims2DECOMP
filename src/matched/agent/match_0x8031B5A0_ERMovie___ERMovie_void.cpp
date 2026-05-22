// 0x8031B5A0 ERMovie::~ERMovie(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 0,0x24(31); addi 9,9,-19112; mr 30,4; stw 9,0x0(31); cmpwi 0,0; beq 0f; lwz 11,-26392(13); mr 4,0; lwz 9,0x0(11); lwz 0,0xf4(9); lha 3,0xf0(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x24(31); 0:; mr 3,31; li 4,0; bl _s8031B5A0_0; andi. 0,30,1; beq 1f; bl _s8031B5A0_1; mr 4,31; bl _s8031B5A0_2; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8031B5A0_0();
extern "C" void _s8031B5A0_1();
extern "C" void _s8031B5A0_2();
extern "C" void f_8031B5A0() {}
