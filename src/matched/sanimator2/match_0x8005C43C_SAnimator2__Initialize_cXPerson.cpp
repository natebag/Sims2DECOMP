// 0x8005C43C SAnimator2::Initialize(cXPerson (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 30,4; lwz 0,0x61c(31); li 29,0; stw 30,0x4(31); li 27,2; rlwinm 0,0,0,0,30; stw 0,0x61c(31); lwz 9,0x0(30); lwz 11,0x0(9); lwz 0,0x14(11); stw 0,0x8(31); lwz 9,0x4(30); lwz 0,0x184(9); lha 3,0x180(9); mtspr 8,0; add 3,30,3; blrl; lis 10,-32707; lis 11,-32707; lis 9,-32707; lfs f12,0x4564(11); lfs f13,0x4560(9); li 4,0; lfs f0,0x455c(10); stw 3,0xc(31); stfs f0,0x608(31); stfs f12,0x104(31); stfs f13,0x114(31); stfs f13,0x30(31); stfs f12,0xfc(31); stfs f13,0x110(31); lwz 9,0x0(31); stw 27,0x118(31); stw 29,0x11c(31); lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; sth 29,0x164(31); stb 0,0x5fa(31); stw 29,0x178(31); stw 29,0x5e8(31); stw 29,0x5ec(31); stw 29,0x5f0(31); stb 0,0x5f9(31); stw 29,0x24(31); stw 29,0x28(31); lwz 9,0x4(30); lha 3,0x1d8(9); lwz 0,0x1dc(9); add 3,30,3; mtspr 8,0; blrl; mr. 28,3; beq 0f; stw 27,0x60c(31); addi 9,31,1548; li 0,23; li 11,6; stw 29,0xc(9); b 1f; 0:; lwz 9,0x4(30); lha 3,0x1e0(9); lwz 0,0x1e4(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; stw 27,0x60c(31); addi 9,31,1548; li 0,23; li 11,6; stw 28,0xc(9); 1:; stw 0,0x4(9); stw 11,0x8(9); b 5f; 2:; lwz 9,0x4(30); lha 3,0x1e8(9); lwz 0,0x1ec(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; li 0,23; addi 9,31,1548; stw 0,0x60c(31); li 11,16; li 0,14; b 4f; 3:; li 0,53; addi 9,31,1548; stw 0,0x60c(31); li 11,16; li 0,12; 4:; stw 11,0x4(9); stw 0,0xc(9); stw 27,0x8(9); 5:; lwz 5,0x8(31); addi 3,31,1568; mr 4,31; addi 5,5,820; bl _s8005C43C_0; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8005C43C_0();

struct SAnimator2 {
    void Initialize();
};

void SAnimator2::Initialize() {
}
