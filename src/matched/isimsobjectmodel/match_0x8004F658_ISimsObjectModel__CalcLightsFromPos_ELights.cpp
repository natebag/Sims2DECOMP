// 0x8004F658 ISimsObjectModel::CalcLightsFromPos(ELights (640 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-344(1); mfspr 0,8; stfd f31,0x150(1); stmw 20,0x120(1); stw 0,0x15c(1); li 0,4; mr 27,3; mtspr 9,0; mr 24,4; mr 20,5; 0:; bdnz 0b; li 0,4; lwz 9,0x120(27); mtspr 9,0; 1:; bdnz 1b; lwz 22,0x140(9); li 28,0; addi 25,9,324; li 21,1; cmpw 28,22; bge 8f; addi 30,27,192; 2:; mulli 9,28,12; lfs f6,0x10(30); lfs f8,0x18(30); addi 5,1,8; lfs f11,0x14(30); mr 3,27; lfs f5,0xc0(27); addi 4,1,256; .long 0x7D29CC6E; mr 6,20; lfs f10,0x8(30); mr 26,5; lfs f13,0x4(9); addi 23,28,1; lfs f3,0x4(30); fmuls f8,f13,f8; lfs f0,0x8(9); fmuls f6,f13,f6; lfs f12,0x20(30); fmuls f13,f13,f11; lfs f4,0x24(30); lfs f11,0x28(30); fmadds f10,f9,f10,f8; fmadds f5,f9,f5,f6; lfs f7,0x30(30); fmadds f9,f9,f3,f13; lfs f8,0x34(30); lfs f13,0x38(30); fmadds f11,f0,f11,f10; fmadds f12,f0,f12,f5; fmadds f0,f0,f4,f9; fadds f12,f12,f7; fadds f0,f0,f8; stfs f12,0x100(1); fadds f11,f11,f13; stfs f0,0x104(1); stfs f11,0x108(1); bl _s8004F658_0; cmpwi 21,0; beq 4f; mr 11,26; mr 9,24; li 10,240; 3:; lwz 0,0x0(11); addic. 10,10,-24; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); lwz 0,0x8(11); stw 0,0x8(9); lwz 0,0xc(11); stw 0,0xc(9); lwz 0,0x10(11); stw 0,0x10(9); lwz 0,0x14(11); addi 11,11,24; stw 0,0x14(9); addi 9,9,24; bne 3b; lwz 0,0x0(11); li 21,0; stw 0,0x0(9); lwz 0,0x4(11); stw 0,0x4(9); 4:; lfs f12,0x100(1); addi 3,1,272; lfs f11,0x78(1); li 29,0; lfs f13,0x7c(1); fsubs f11,f11,f12; lfs f10,0x104(1); lfs f0,0x80(1); lfs f12,0x108(1); fsubs f13,f13,f10; stfs f11,0x110(1); fsubs f0,f0,f12; stfs f13,0x114(1); stfs f0,0x118(1); bl _s8004F658_1; rlwinm 0,28,5,0,26; fmr f31,f1; add 28,0,24; 5:; rlwinm 31,29,5,0,26; lfs f10,0x100(1); add 9,31,26; lfs f9,0x104(1); lfsu f12,0x70(9); addi 3,1,272; lfs f11,0x108(1); lfs f13,0x8(9); fsubs f12,f12,f10; lfs f0,0x4(9); fsubs f13,f13,f11; stfs f12,0x110(1); fsubs f0,f0,f9; stfs f13,0x118(1); stfs f0,0x114(1); bl _s8004F658_2; addi 8,29,1; fcmpu 0,f1,f31; cror 3,2,0; bns 7f; add 9,31,26; addi 11,28,112; addi 9,9,112; li 10,24; 6:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 6b; lwz 0,0x0(9); stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); 7:; mr 29,8; cmpwi 29,3; ble 5b; mr 28,23; cmpw 28,22; blt 2b; 8:; lwz 0,0x15c(1); mtspr 8,0; lmw 20,0x120(1); lfd f31,0x150(1); addi 1,1,344"

extern "C" void _s8004F658_0();
extern "C" void _s8004F658_1();
extern "C" void _s8004F658_2();

struct ISimsObjectModel {
    void CalcLightsFromPos_ELights();
};

void ISimsObjectModel::CalcLightsFromPos_ELights() {
}
