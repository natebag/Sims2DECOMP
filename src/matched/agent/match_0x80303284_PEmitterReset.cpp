// 0x80303284 PEmitterReset (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x54(30); lwz 0,0x88(9); stw 0,0x90(9); lwz 11,0x54(30); lwz 31,0x90(11); cmpwi 31,0; beq 1f; 0:; lwz 11,0x54(30); mr 4,31; lwz 9,0x90(11); lwz 0,0x0(9); stw 0,0x90(11); lwz 3,0x54(30); bl _s80303284_0; lwz 3,-22684(13); mr 4,31; bl _s80303284_1; lwz 9,0x54(30); lwz 31,0x90(9); cmpwi 31,0; bne 0b; 1:; lwz 0,0x50(30); lis 9,-32702; lfs f0,-1948(9); ori 0,0,6; stw 0,0x50(30); stfs f0,0x84(30); stfs f0,0x58(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80303284_0();
extern "C" void _s80303284_1();
extern "C" void f_80303284() {}
