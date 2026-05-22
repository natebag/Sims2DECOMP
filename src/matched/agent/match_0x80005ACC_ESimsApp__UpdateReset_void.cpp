// 0x80005ACC ESimsApp::UpdateReset(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lwz 3,-26524(13); cmpwi 3,0; beq 1f; lis 9,-32707; li 4,27; addi 9,9,-20448; addi 5,1,8; lwz 11,0x0(9); lwz 12,0x4(9); addi 6,1,16; li 7,0; li 8,0; stw 11,0x10(1); stw 12,0x14(1); li 9,0; stw 11,0x8(1); stw 12,0xc(1); bl _s80005ACC_0; cmpwi 3,0; beq 0f; lfs f0,-32760(13); lis 9,-32707; lfs f13,-26800(13); lfs f12,-19660(9); fadds f0,f0,f13; fcmpu 0,f0,f12; stfs f0,-32760(13); ble 1f; lwz 11,-26512(13); li 4,0; lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26512(13); lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; lis 9,-32707; lfs f0,-19656(9); stfs f0,-32760(13); 1:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s80005ACC_0();
extern "C" void f_80005ACC() {}
