// 0x80050F14 ISimsObjectModel::OrentSubObject(void) (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-168(1); mfspr 0,8; stfd f28,0x88(1); stfd f29,0x90(1); stfd f30,0x98(1); stfd f31,0xa0(1); stmw 27,0x74(1); stw 0,0xac(1); mr 31,3; li 4,1; lwz 11,0x328(31); addi 30,1,72; addi 28,1,8; lis 29,17200; lwz 9,0x4(11); mr 27,30; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,11,3; blrl; xoris 3,3,32768; lwz 10,0x328(31); lis 8,-32707; stw 3,0x6c(1); lis 7,-32707; lwz 11,0x4(10); lis 6,-32707; stw 29,0x68(1); mr 3,30; lfd f30,0x3270(8); lwz 0,0x35c(11); lfd f31,0x68(1); lha 4,0x358(11); mtspr 8,0; lfs f13,0x3278(7); fsub f31,f31,f30; add 4,10,4; lfs f0,0x327c(6); lwz 9,0x3c8(31); frsp f31,f31; fmuls f31,f31,f13; fmuls f31,f31,f0; lfs f28,0x50(9); lfs f29,0x4c(9); blrl; addi 3,1,8; bl _s80050F14_0; fmr f1,f31; addi 3,1,8; bl _s80050F14_1; mr 3,30; bl _s80050F14_2; xoris 3,3,32768; stw 3,0x6c(1); mr 3,30; stw 29,0x68(1); lfd f31,0x68(1); fsub f31,f31,f30; frsp f31,f31; fadds f31,f31,f29; bl _s80050F14_3; xoris 3,3,32768; stw 3,0x6c(1); lis 9,-32707; lfs f13,0x3280(9); addi 10,1,80; stw 29,0x68(1); mr 4,10; stfs f31,0x50(1); mr 3,28; lfd f0,0x68(1); fsub f0,f0,f30; frsp f0,f0; fadds f0,f0,f28; stfs f0,0x54(1); stfs f13,0x8(10); bl _s80050F14_4; li 0,4; mtspr 9,0; 0:; lfs f0,0x0(28); lfs f13,0x4(28); stfs f0,0x4(28); stfs f13,0x0(28); addi 28,28,16; bdnz 0b; lwz 9,0x0(31); addi 4,1,8; lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; mr 3,27; li 4,2; bl _s80050F14_5; lwz 0,0xac(1); mtspr 8,0; lmw 27,0x74(1); lfd f28,0x88(1); lfd f29,0x90(1); lfd f30,0x98(1); lfd f31,0xa0(1); addi 1,1,168"

extern "C" void _s80050F14_0();
extern "C" void _s80050F14_1();
extern "C" void _s80050F14_2();
extern "C" void _s80050F14_3();
extern "C" void _s80050F14_4();
extern "C" void _s80050F14_5();

struct ISimsObjectModel {
    void OrentSubObject();
};

void ISimsObjectModel::OrentSubObject() {
}
