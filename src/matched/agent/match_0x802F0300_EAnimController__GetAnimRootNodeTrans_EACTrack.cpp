// 0x802F0300 EAnimController::GetAnimRootNodeTrans(EACTrack (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x24(4); mr 31,3; cmpwi 9,0; li 0,0; beq 0f; lwz 0,0x18(9); 0:; cmpwi 0,0; beq 2f; lwz 10,0x7c(5); lwz 9,0x34(10); lwz 11,0xc(9); cmpwi 11,0; beq 2f; ble 1f; lwz 9,0x44(10); rlwinm 11,11,2,0,29; lfsx f13,9,11; add 9,9,11; stfs f13,0x0(31); lfs f0,0x4(9); stfs f0,0x4(31); lfs f13,0x8(9); stfs f13,0x8(31); b 3f; 1:; lwz 9,0x98(5); mr 3,31; lfs f1,0x40(5); lwz 4,0x4(9); bl _s802F0300_0; b 3f; 2:; lis 9,-32702; lfs f0,-4300(9); stfs f0,0x0(31); stfs f0,0x8(31); stfs f0,0x4(31); 3:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802F0300_0();
extern "C" void f_802F0300() {}
