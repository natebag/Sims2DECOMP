// 0x8029BA20 AptDisplayList::AddToDisplayList(AptNativeHash (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,6; mr 29,5; lwz 11,0x4c(30); mr 28,3; lwz 10,0x0(29); mr 31,4; lwz 9,0x8(11); mr 4,30; lwz 5,0xc(10); lwz 3,0x4(9); addi 3,3,8; bl _s8029BA20_0; mr 4,29; mr 5,30; mr 3,28; bl _s8029BA20_1; mr 30,3; lis 9,-32700; lwz 0,0xc(30); addi 9,9,-6476; addi 4,30,12; cmpw 0,9; beq 0f; mr 3,31; mr 5,30; bl _s8029BA20_2; 0:; lwz 8,-23008(13); lis 4,-32704; lis 5,-32704; addi 4,4,30224; lwz 11,0x4(8); addi 5,5,29796; lwz 10,0x0(8); li 6,1628; rlwinm 11,11,2,0,29; stwx 30,11,10; lwz 9,0x4(8); lwz 10,0x0(8); rlwinm 9,9,2,0,29; lwzx 8,9,10; lwz 11,0x8(8); lha 3,0x8(11); lwz 0,0xc(11); add 3,8,3; mtspr 8,0; blrl; lwz 11,-23008(13); mr 3,30; lwz 9,0x4(11); addi 9,9,1; stw 9,0x4(11); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8029BA20_0();
extern "C" void _s8029BA20_1();
extern "C" void _s8029BA20_2();

struct AptDisplayList {
    void AddToDisplayList_AptNativeHash();
};

void AptDisplayList::AddToDisplayList_AptNativeHash() {
}
