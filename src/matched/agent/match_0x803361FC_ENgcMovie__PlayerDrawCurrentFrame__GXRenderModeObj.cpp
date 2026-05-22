// 0x803361FC ENgcMovie::PlayerDrawCurrentFrame(_GXRenderModeObj (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); lis 9,-32691; mr 29,5; addi 31,9,14656; mr 28,6; lwz 0,0xa0(31); mr 27,7; mr 30,8; li 3,-1; cmpwi 0,0; beq 0f; lbz 0,0xa4(31); cmpwi 0,0; beq 0f; lwz 0,0xf8(31); cmpwi 0,0; beq 0f; mr 3,4; bl _s803361FC_0; lwz 9,0xf8(31); extsh 0,30; lha 8,0x82(31); extsh 10,27; lwz 3,0x0(9); extsh 6,29; lwz 5,0x8(9); extsh 7,28; lwz 4,0x4(9); lha 9,0x86(31); stw 0,0x8(1); bl _s803361FC_1; lwz 11,0xf8(31); lwz 8,0xc0(31); lwz 9,0xc(11); lwz 10,0x50(31); add 9,9,8; divwu 0,9,10; mullw 0,0,10; subf 3,0,9; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s803361FC_0();
extern "C" void _s803361FC_1();
extern "C" void f_803361FC() {}
