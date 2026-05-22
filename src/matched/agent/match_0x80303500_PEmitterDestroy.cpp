// 0x80303500 PEmitterDestroy (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; lwz 30,0x0(28); lwz 0,0x8c(30); cmpwi 0,0; beq 0f; lwz 3,0xb8(30); mr 4,30; bl _s80303500_0; 0:; lwz 9,0x54(30); addi 29,30,84; addi 27,30,96; lwz 0,0x88(9); stw 0,0x90(9); lwz 11,0x54(30); lwz 31,0x90(11); cmpwi 31,0; beq 2f; 1:; lwz 11,0x54(30); mr 4,31; lwz 9,0x90(11); lwz 0,0x0(9); stw 0,0x90(11); lwz 3,0x54(30); bl _s80303500_1; lwz 3,-22684(13); mr 4,31; bl _s80303500_2; lwz 9,0x54(30); lwz 31,0x90(9); cmpwi 31,0; bne 1b; 2:; mr 3,29; bl _s80303500_3; lis 9,-32702; lwz 3,-22688(13); lwz 11,-1920(9); mr 4,30; addi 9,9,-1920; lwz 0,0x4(9); stw 11,0x60(30); stw 0,0x4(27); bl _s80303500_4; li 0,0; stw 0,0x0(28); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80303500_0();
extern "C" void _s80303500_1();
extern "C" void _s80303500_2();
extern "C" void _s80303500_3();
extern "C" void _s80303500_4();
extern "C" void f_80303500() {}
