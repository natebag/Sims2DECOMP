// 0x801D6560 PCTTarget::enter_tool_mode(PCTTarget::ePCTType, (708 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); mr 30,3; mr 29,4; lwz 3,0x214(30); mr 28,5; cmpwi 3,0; beq 0f; li 4,0; bl _s801D6560_0; lwz 3,0x214(30); li 4,0; bl _s801D6560_1; 0:; lis 3,26334; ori 3,3,56946; bl _s801D6560_2; cmpwi 29,2; beq 7f; bgt 1f; cmpwi 29,0; beq 10f; cmpwi 29,1; beq 2f; b 10f; 1:; cmpwi 29,3; beq 8f; cmpwi 29,4; beq 9f; b 10f; 2:; lwz 3,0x214(30); cmpwi 3,0; beq 3f; li 4,1; bl _s801D6560_3; 3:; addi 31,1,36; mr 3,30; bl _s801D6560_4; lis 9,-32705; lis 11,-32698; lfs f0,0x47f0(9); addi 10,1,8; addi 11,11,29056; li 0,2; stw 11,0x10(10); li 8,0; stfs f0,0x8(31); li 11,0; stfs f0,0x4(31); lis 9,-32739; stfs f0,0x24(1); addi 9,9,7744; stw 0,0x8(1); mr 27,10; lwz 0,0x84(30); cmpwi 28,0; sth 8,0x14(10); stw 11,0x18(10); stw 0,0xc(1); stw 9,0x14(1); stw 30,0x10(1); beq 4f; bl _s801D6560_5; lwz 4,0x84(30); li 5,6; bl _s801D6560_6; mr. 3,3; beq 4f; stw 29,0x20(1); addi 9,3,8; lwz 0,0x8(3); lwz 11,0x8(9); lwz 10,0x4(9); stw 0,0x24(1); stw 11,0x8(31); stw 10,0x4(31); 4:; bl _s801D6560_7; lwz 31,0x4(27); mr 29,3; mr 4,31; bl _s801D6560_8; cmpwi 3,0; beq 6f; li 0,1; lbz 9,0x3c(29); slw 0,0,31; rlwinm 0,0,0,24,31; and. 28,9,0; bne 6f; or 0,0,9; li 3,40; stb 0,0x3c(29); bl _s801D6560_9; lis 11,-32705; lis 9,-32698; lfs f0,0x47f0(11); addi 9,9,29056; stw 9,0x10(3); addi 11,3,28; stfs f0,0x4(11); li 9,2; stfs f0,0x8(11); rlwinm 4,31,3,0,28; stfs f0,0x1c(3); mr 11,3; lwz 0,0x10(3); mr 10,27; stw 9,0x0(3); li 8,24; stw 28,0x18(3); stw 0,0x30(1); sth 28,0x14(3); 5:; lwz 0,0x0(10); addic. 8,8,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 5b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(29); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 6:; mr 3,30; li 4,0; bl _s801D6560_10; lis 9,-32698; li 3,1; addi 9,9,-10560; stw 9,0x10(27); b 11f; 7:; mr 3,30; li 4,0; li 5,0; bl _s801D6560_11; b 11f; 8:; mr 3,30; li 4,0; li 5,0; bl _s801D6560_12; b 11f; 9:; mr 3,30; li 4,0; li 5,0; bl _s801D6560_13; b 11f; 10:; li 3,0; 11:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s801D6560_0();
extern "C" void _s801D6560_1();
extern "C" void _s801D6560_2();
extern "C" void _s801D6560_3();
extern "C" void _s801D6560_4();
extern "C" void _s801D6560_5();
extern "C" void _s801D6560_6();
extern "C" void _s801D6560_7();
extern "C" void _s801D6560_8();
extern "C" void _s801D6560_9();
extern "C" void _s801D6560_10();
extern "C" void _s801D6560_11();
extern "C" void _s801D6560_12();
extern "C" void _s801D6560_13();

struct PCTTarget {
    void enter_tool_mode_PCTTarget__ePCTType();
};

void PCTTarget::enter_tool_mode_PCTTarget__ePCTType() {
}
