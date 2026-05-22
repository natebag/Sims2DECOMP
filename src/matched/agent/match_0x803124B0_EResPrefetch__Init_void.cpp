// 0x803124B0 EResPrefetch::Init(void) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32692; mr 30,3; lwz 0,-17448(9); lwz 11,-26824(13); stw 0,0x3fc(30); lwz 9,0x338(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0x3f8(30); cmpwi 3,0; beq 0f; lwz 0,0x3fc(30); divwu 0,0,3; b 1f; 0:; li 0,0; 1:; stw 0,0x400(30); addi 3,30,908; li 4,2048; bl _s803124B0_0; cmpwi 3,0; beq 2f; lis 9,-32702; addi 31,30,8; addi 9,9,1256; mr 3,31; stw 9,0x32c(31); li 4,23; li 5,8192; li 6,0; bl _s803124B0_1; cmpwi 3,0; beq 2f; mr 3,31; bl _s803124B0_2; li 0,1; li 3,1; stw 0,0x3d8(30); b 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803124B0_0();
extern "C" void _s803124B0_1();
extern "C" void _s803124B0_2();
extern "C" void f_803124B0() {}
