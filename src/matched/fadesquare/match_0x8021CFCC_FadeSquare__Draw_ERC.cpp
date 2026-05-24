// 0x8021CFCC FadeSquare::Draw(ERC (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-368(1); mfspr 0,8; stmw 24,0x150(1); stw 0,0x174(1); mr 31,3; mr 29,4; lwz 0,0xc(31); mr 30,5; cmpwi 0,0; beq 8f; li 0,4; addi 26,1,36; mtspr 9,0; addi 28,1,256; addi 25,1,24; addi 24,1,8; addi 27,1,272; 0:; bdnz 0b; li 0,4; mtspr 9,0; 1:; bdnz 1b; li 0,1; li 9,0; lis 3,-32697; stw 0,0xf8(1); stw 9,0xfc(1); addi 3,3,24012; bl _s8021CFCC_0; lfs f11,0x418(3); addi 9,3,1084; lfs f13,0x43c(3); lis 10,-32704; addi 3,3,1048; lfs f12,0x8(9); fsubs f13,f13,f11; lfs f0,0x4(9); lfs f10,0x8(3); lfs f11,0x4(3); stfs f13,0x100(1); fsubs f12,f12,f10; fsubs f0,f0,f11; stfs f12,0x108(1); stfs f0,0x104(1); lwz 9,0x100(1); lwz 11,0x4(28); lwz 0,0x8(28); stw 9,0x24(1); stw 0,0x8(26); stw 11,0x4(26); lfs f12,-9124(10); lfs f0,0x28(1); lfs f13,0x24(1); fneg f0,f0; stfs f13,0x28(1); fcmpu 0,f0,f12; stfs f0,0x24(1); bne 2f; fcmpu 0,f13,f12; bne 2f; lfs f0,0x2c(1); fcmpu 0,f0,f12; beq 3f; 2:; addi 3,1,36; mr 4,3; bl _s8021CFCC_1; 3:; lis 9,-32696; lwz 11,0x0(30); lfs f11,0x55c4(9); mr 3,27; lwz 9,0x4(30); lwz 0,0x8(30); lfs f13,0x0(30); stw 11,0x18(1); fmuls f13,f13,f11; lfs f12,0x8(30); lfs f0,0x4(30); stw 0,0x8(25); fmuls f12,f12,f11; stw 9,0x4(25); fmuls f0,f0,f11; stfs f13,0x100(1); stfs f0,0x104(1); stfs f12,0x108(1); lwz 0,0x100(1); lwz 9,0x8(28); lwz 11,0x4(28); stw 0,0x8(1); stw 9,0x8(24); stw 11,0x4(24); bl _s8021CFCC_2; mr 3,27; mr 4,31; bl _s8021CFCC_3; lwz 0,0x18(31); cmpwi 0,0; beq 4f; lwz 10,0xc(31); lis 9,-32704; lis 11,-32704; lfs f12,-9120(9); lfs f13,-9116(11); mr 3,27; lfs f1,0x10(31); lfs f0,0x88(10); fmadds f1,f1,f12,f13; fmuls f1,f0,f1; bl _s8021CFCC_4; b 5f; 4:; lwz 11,0xc(31); lis 9,-32704; lfs f13,-9112(9); mr 3,27; lfs f1,0x10(31); lfs f0,0x88(11); fadds f1,f1,f13; fmuls f1,f0,f1; bl _s8021CFCC_5; 5:; lwz 9,0x70(29); addi 4,1,8; lwz 0,0x16c(9); lha 3,0x168(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x70(29); addi 4,1,272; li 5,1; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x18(31); cmpwi 0,0; beq 6f; lwz 11,0x70(29); lis 9,-32704; lfs f0,-9112(9); lha 3,0x258(11); lfs f1,0x10(31); lwz 0,0x25c(11); add 3,29,3; fsubs f1,f0,f1; mtspr 8,0; blrl; b 7f; 6:; lwz 9,0x70(29); lfs f1,0x10(31); lha 3,0x258(9); lwz 0,0x25c(9); add 3,29,3; mtspr 8,0; blrl; 7:; lwz 3,0xc(31); mr 4,29; bl _s8021CFCC_6; 8:; lwz 0,0x174(1); mtspr 8,0; lmw 24,0x150(1); addi 1,1,368"

extern "C" void _s8021CFCC_0();
extern "C" void _s8021CFCC_1();
extern "C" void _s8021CFCC_2();
extern "C" void _s8021CFCC_3();
extern "C" void _s8021CFCC_4();
extern "C" void _s8021CFCC_5();
extern "C" void _s8021CFCC_6();

struct FadeSquare {
    void Draw();
};

void FadeSquare::Draw() {
}
