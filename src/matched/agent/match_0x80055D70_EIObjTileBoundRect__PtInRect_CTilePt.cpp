// 0x80055D70 EIObjTileBoundRect::PtInRect(CTilePt (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stfd f30,0x28(1); stfd f31,0x30(1); stmw 29,0x1c(1); stw 0,0x3c(1); mr 30,4; mr 31,3; mr 3,30; lis 29,17200; bl _s80055D70_0; xoris 3,3,32768; stw 3,0x14(1); lis 9,-32707; lfd f31,0x35b8(9); mr 3,30; stw 29,0x10(1); lfd f0,0x10(1); fsub f0,f0,f31; frsp f30,f0; bl _s80055D70_1; xoris 3,3,32768; stw 3,0x14(1); lfs f13,0x0(31); li 3,0; stw 29,0x10(1); fcmpu 0,f30,f13; lfd f0,0x10(1); fsub f0,f0,f31; frsp f13,f0; ble 0f; lfs f0,0x4(31); fcmpu 0,f30,f0; bge 0f; lfs f0,0x8(31); fcmpu 0,f13,f0; ble 0f; lfs f0,0xc(31); fcmpu 0,f13,f0; bge 0f; li 3,1; 0:; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x1c(1); lfd f30,0x28(1); lfd f31,0x30(1); addi 1,1,56"
extern "C" void _s80055D70_0();
extern "C" void _s80055D70_1();
extern "C" void f_80055D70() {}
