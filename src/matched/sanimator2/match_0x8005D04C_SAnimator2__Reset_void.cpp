// 0x8005D04C SAnimator2::Reset(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; bl _s8005D04C_0; mr 3,31; bl _s8005D04C_1; mr 3,31; bl _s8005D04C_2; mr 3,31; bl _s8005D04C_3; mr 3,31; bl _s8005D04C_4; lis 9,-32707; lwz 0,0x61c(31); lfs f0,0x45b0(9); li 11,0; lwz 4,0x28(31); rlwinm 0,0,0,31,31; lwz 9,0xdc(31); cmpwi 4,0; stw 11,0xec(31); stw 9,0xe0(31); stw 0,0x61c(31); stfs f0,0xb8(31); stw 30,0xc8(31); stw 30,0xcc(31); stw 30,0xd4(31); stw 30,0xd8(31); stfs f0,0x30(31); stw 30,0x130(31); beq 0f; lis 3,-32693; addi 3,3,11064; bl _s8005D04C_5; lis 3,-32707; lwz 4,0x28(31); addi 3,3,17800; crxor 6,6,6; bl _s8005D04C_6; lwz 9,-32344(13); stw 30,0x28(31); addi 9,9,-1; stw 9,-32344(13); 0:; addi 3,31,1568; bl _s8005D04C_7; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8005D04C_0();
extern "C" void _s8005D04C_1();
extern "C" void _s8005D04C_2();
extern "C" void _s8005D04C_3();
extern "C" void _s8005D04C_4();
extern "C" void _s8005D04C_5();
extern "C" void _s8005D04C_6();
extern "C" void _s8005D04C_7();

struct SAnimator2 {
    void Reset();
};

void SAnimator2::Reset() {
}
