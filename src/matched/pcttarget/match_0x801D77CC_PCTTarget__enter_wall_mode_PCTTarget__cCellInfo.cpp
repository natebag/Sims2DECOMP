// 0x801D77CC PCTTarget::enter_wall_mode(PCTTarget::cCellInfo (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 27,0x4c(1); stw 0,0x64(1); lis 9,-32698; addi 11,1,8; addi 9,9,28984; li 0,3; stw 9,0x10(11); mr 29,3; stw 0,0x8(1); li 8,0; lwz 0,0x84(29); lis 10,-32739; stw 8,0x14(11); addi 10,10,7840; stw 8,0x18(11); lis 9,-32698; stw 8,0x24(11); mr 27,11; addi 9,9,-10560; mr 28,5; stw 0,0xc(1); mr. 31,4; stw 10,0x14(1); stw 29,0x10(1); beq 0f; lwz 10,0x4(31); cmpwi 10,-1; bne 1f; 0:; li 0,1; stw 8,0x24(1); stw 0,0x28(1); stw 8,0x1c(1); b 4f; 1:; lwz 0,0x0(31); cmpwi 0,2; bne 2f; lwz 11,0x14(31); cmpwi 11,0; bne 3f; 2:; stw 9,0x10(27); li 3,0; b 14f; 3:; li 0,1; stw 10,0x28(1); stw 0,0x1c(1); stw 11,0x24(1); 4:; lis 9,-32697; li 0,0; lwz 11,0x6188(9); stw 0,0x2c(1); cmpwi 11,0; beq 5f; lwz 0,-21088(13); b 7f; 5:; cmpwi 31,0; beq 8f; li 3,0; bl _s801D77CC_0; mr 30,3; mr 3,31; bl _s801D77CC_1; mr. 3,3; beq 6f; divw 0,30,3; b 7f; 6:; lis 0,32767; ori 0,0,65535; 7:; stw 0,0x2c(1); 8:; cmpwi 7,28,0; li 0,1; beq cr7,9f; li 0,0; 9:; stw 0,0x20(1); lwz 3,0x214(29); cmpwi 3,0; beq 11f; beq cr7,10f; li 4,2; bl _s801D77CC_2; b 11f; 10:; li 4,5; bl _s801D77CC_3; 11:; mr 3,29; li 4,0; bl _s801D77CC_4; bl _s801D77CC_5; lwz 31,0x4(27); mr 29,3; mr 4,31; bl _s801D77CC_6; cmpwi 3,0; beq 13f; li 0,1; lbz 9,0x3c(29); slw 0,0,31; rlwinm 0,0,0,24,31; and. 30,9,0; bne 13f; or 0,0,9; li 3,40; stb 0,0x3c(29); bl _s801D77CC_7; lis 9,-32698; li 0,3; addi 9,9,28984; stw 0,0x0(3); stw 30,0x24(3); rlwinm 4,31,3,0,28; stw 9,0x30(1); mr 11,3; stw 9,0x10(3); mr 10,27; stw 30,0x14(3); li 9,24; stw 30,0x18(3); 12:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 12b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(29); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 13:; lis 9,-32698; li 3,1; addi 9,9,-10560; stw 9,0x10(27); 14:; lwz 0,0x64(1); mtspr 8,0; lmw 27,0x4c(1); addi 1,1,96"

extern "C" void _s801D77CC_0();
extern "C" void _s801D77CC_1();
extern "C" void _s801D77CC_2();
extern "C" void _s801D77CC_3();
extern "C" void _s801D77CC_4();
extern "C" void _s801D77CC_5();
extern "C" void _s801D77CC_6();
extern "C" void _s801D77CC_7();

struct PCTTarget {
    void enter_wall_mode_PCTTarget__cCellInfo();
};

void PCTTarget::enter_wall_mode_PCTTarget__cCellInfo() {
}
