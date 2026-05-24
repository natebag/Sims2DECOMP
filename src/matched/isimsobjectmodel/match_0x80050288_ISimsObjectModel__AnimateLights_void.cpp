// 0x80050288 ISimsObjectModel::AnimateLights(void) (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; stmw 23,0x5c(1); stw 0,0x84(1); mr 27,3; lwz 0,0x468(27); lwz 28,0x340(27); cmpwi 0,0; ble 6f; lis 9,-32763; mr 26,0; addi 23,9,-6384; li 25,0; li 24,0; 0:; lwz 9,0x120(27); lwz 10,0x464(27); lwz 11,0x90(9); lwzx 29,10,24; lhax 0,11,25; add 11,11,25; lwz 31,0x4(11); cmpwi 0,0; beq 1f; cmpwi 0,1; beq 2f; mulli 4,31,68; b 3f; 1:; mulli 30,31,68; mr 3,29; add 31,28,30; addi 4,31,20; bl _s80050288_0; lwzx 0,28,30; mr 4,30; andi. 9,0,128; beq 3f; lfs f13,0x3c(31); stfs f13,0xc4(29); lfs f0,0x3c(31); fadds f0,f0,f0; stfs f0,0xc8(29); b 3f; 2:; addi 5,1,8; addi 3,27,820; mr 4,31; addi 30,29,172; bl _s80050288_1; lfs f13,0xac(29); li 4,2; addi 3,1,8; addi 5,1,72; stfs f13,0x48(1); lfs f0,0x4(30); stfs f0,0x4c(1); lfs f13,0x8(30); stfs f13,0x50(1); bl _s80050288_2; lwz 9,0x48(1); mulli 4,31,68; lwz 11,0x4c(1); lwz 0,0x50(1); stw 9,0xac(29); stw 0,0x8(30); stw 11,0x4(30); 3:; lwzx 0,4,28; add 7,4,28; andi. 9,0,32; beq 4f; lwz 8,0x2c(7); addi 9,7,44; lwz 10,0x8(9); addi 11,29,144; lwz 0,0x4(9); stw 8,0x90(29); stw 10,0x8(11); stw 0,0x4(11); 4:; lwzx 0,4,28; andi. 9,0,64; beq 5f; lfs f0,0x38(7); stfs f0,0x8c(29); 5:; mr 3,27; addi 25,25,28; bl _s80050288_3; addi 24,24,4; stw 3,0x28(29); stw 23,0x1c(29); lwz 9,0x0(29); lha 3,0x50(9); lwz 0,0x54(9); add 3,29,3; mtspr 8,0; blrl; addic. 26,26,-1; bne 0b; 6:; lwz 0,0x84(1); mtspr 8,0; lmw 23,0x5c(1); addi 1,1,128"

extern "C" void _s80050288_0();
extern "C" void _s80050288_1();
extern "C" void _s80050288_2();
extern "C" void _s80050288_3();

struct ISimsObjectModel {
    void AnimateLights();
};

void ISimsObjectModel::AnimateLights() {
}
