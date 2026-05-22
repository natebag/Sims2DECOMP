// 0x80060C20 SAnimator2::advanceAlongNode(float (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lwz 12,0xc(3); lwz 9,0x14(3); lwz 10,0x0(12); rlwinm 7,9,3,0,28; add 11,10,7; addi 9,9,-1; rlwinm 9,9,3,0,28; lwz 6,0x4(11); add 8,10,9; lwzx 11,10,9; lwz 0,0x4(8); lwzx 9,10,7; subf 0,0,6; subf 9,11,9; mullw 0,0,0; mullw 9,9,9; add 0,0,9; cmpwi 0,3; ble 0f; xoris 0,6,32768; stw 0,0x14(1); lis 8,17200; lis 10,-32707; mr 11,9; stw 8,0x10(1); addi 5,1,8; lfd f13,0x47c0(10); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0x8(1); lwz 9,0x0(12); lwzx 0,9,7; xoris 0,0,32768; stw 0,0x14(1); stw 8,0x10(1); lfd f0,0x10(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0xc(1); bl _s80060C20_0; 0:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80060C20_0();
extern "C" void f_80060C20() {}
