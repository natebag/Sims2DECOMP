// 0x8022BBB4 EIStaticModel::Setup(EInstance (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 30,3; lis 7,-32704; lwz 9,0x80(30); lwz 10,0x84(30); addi 8,30,128; addi 31,30,192; mr 26,4; stw 9,0xc0(30); stw 10,0xc4(30); mr 25,5; lwz 9,0x8(8); lwz 10,0xc(8); stw 9,0x8(31); stw 10,0xc(31); lwz 11,0x10(8); lwz 12,0x14(8); stw 11,0x10(31); stw 12,0x14(31); lwz 9,0x18(8); lwz 10,0x1c(8); stw 9,0x18(31); stw 10,0x1c(31); lwz 11,0x20(8); lwz 12,0x24(8); stw 11,0x20(31); stw 12,0x24(31); lwz 9,0x28(8); lwz 10,0x2c(8); stw 9,0x28(31); stw 10,0x2c(31); lwz 11,0x30(8); lwz 12,0x34(8); stw 11,0x30(31); stw 12,0x34(31); lwz 9,0x38(8); lwz 10,0x3c(8); stw 9,0x38(31); stw 10,0x3c(31); lfs f13,-4612(7); lfs f0,0xc0(30); fcmpu 0,f0,f13; bne 0f; lfs f0,0x4(31); fcmpu 0,f0,f13; bne 0f; lfs f0,0x8(31); fcmpu 0,f0,f13; beq 1f; 0:; mr 3,31; mr 4,31; bl _s8022BBB4_0; 1:; lis 9,-32704; lis 11,-32704; lfs f0,-4608(9); addi 29,30,208; lfs f13,-4612(11); mr 28,29; stfs f0,0xc(31); stfs f13,0xcc(30); lfs f0,0xd0(30); fcmpu 0,f0,f13; bne 2f; lfs f0,0x4(28); fcmpu 0,f0,f13; bne 2f; lfs f0,0x8(28); fcmpu 0,f0,f13; beq 3f; 2:; mr 3,29; mr 4,29; bl _s8022BBB4_1; 3:; lis 9,-32704; lis 11,-32704; lfs f0,-4608(9); addi 31,30,224; lfs f13,-4612(11); mr 27,31; stfs f0,0xc(29); stfs f13,0xc(28); lfs f0,0xe0(30); fcmpu 0,f0,f13; bne 4f; lfs f0,0x4(27); fcmpu 0,f0,f13; bne 4f; lfs f0,0x8(27); fcmpu 0,f0,f13; beq 5f; 4:; mr 3,31; mr 4,31; bl _s8022BBB4_2; 5:; lis 9,-32704; lis 11,-32704; lfs f0,-4608(9); mr 3,30; lfs f13,-4612(11); mr 4,26; stfs f0,0xc(31); mr 5,25; stfs f13,0xc(27); bl _s8022BBB4_3; mr 3,30; bl _s8022BBB4_4; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8022BBB4_0();
extern "C" void _s8022BBB4_1();
extern "C" void _s8022BBB4_2();
extern "C" void _s8022BBB4_3();
extern "C" void _s8022BBB4_4();

struct EIStaticModel {
    void Setup_EInstance();
};

void EIStaticModel::Setup_EInstance() {
}
