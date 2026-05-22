// 0x80076E74 Timer_Init(EClock (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 11,-26532(13); mr 4,3; stw 3,-32196(13); lwz 9,0x0(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26532(13); lwz 4,-32196(13); lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32707; stfs f1,-24908(13); lfs f13,0x5cec(9); li 3,1; fmuls f1,f1,f13; fctiwz f0,f1; stfd f0,0x8(1); lwz 9,0xc(1); stw 9,-24896(13); lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void f_80076E74() {}
