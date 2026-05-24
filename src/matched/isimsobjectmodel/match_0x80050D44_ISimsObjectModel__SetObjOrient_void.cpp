// 0x80050D44 ISimsObjectModel::SetObjOrient(void) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stfd f27,0x48(1); stfd f28,0x50(1); stfd f29,0x58(1); stfd f30,0x60(1); stfd f31,0x68(1); stmw 28,0x38(1); stw 0,0x74(1); mr 29,3; lis 28,17200; lwz 30,0x328(29); addi 3,1,8; lwz 11,0x3c8(29); lwz 9,0x4(30); lfs f27,0x50(11); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; lfs f28,0x4c(11); add 4,30,4; blrl; lwz 9,0x4(30); li 4,1; lwz 0,0x264(9); lha 3,0x260(9); mtspr 8,0; add 3,30,3; blrl; xoris 3,3,32768; stw 3,0x34(1); lis 9,-32707; lfd f29,0x3258(9); lis 10,-32707; stw 28,0x30(1); lis 9,-32707; lfs f13,0x3260(10); addi 3,1,8; lfd f31,0x30(1); lfs f0,0x3264(9); fsub f31,f31,f29; frsp f31,f31; fmuls f31,f31,f13; fmuls f31,f31,f0; stfs f31,0x3f0(29); bl _s80050D44_0; xoris 3,3,32768; stw 3,0x34(1); addi 3,1,8; stw 28,0x30(1); lfd f30,0x30(1); fsub f30,f30,f29; frsp f30,f30; fadds f30,f30,f28; bl _s80050D44_1; xoris 3,3,32768; stw 3,0x34(1); lis 11,-32707; lfs f12,0x3268(11); lis 8,-32707; stw 28,0x30(1); addi 10,1,16; stfs f30,0x10(1); addi 11,1,32; lfd f0,0x30(1); mr 3,29; lfs f13,0x326c(8); mr 4,10; fsub f0,f0,f29; mr 5,11; frsp f0,f0; fadds f0,f0,f27; stfs f0,0x14(1); fmr f1,f31; stfs f12,0x8(10); stfs f13,0x8(11); stfs f13,0x4(11); stfs f13,0x20(1); bl _s80050D44_2; addi 3,1,8; li 4,2; bl _s80050D44_3; lwz 0,0x74(1); mtspr 8,0; lmw 28,0x38(1); lfd f27,0x48(1); lfd f28,0x50(1); lfd f29,0x58(1); lfd f30,0x60(1); lfd f31,0x68(1); addi 1,1,112"

extern "C" void _s80050D44_0();
extern "C" void _s80050D44_1();
extern "C" void _s80050D44_2();
extern "C" void _s80050D44_3();

struct ISimsObjectModel {
    void SetObjOrient();
};

void ISimsObjectModel::SetObjOrient() {
}
