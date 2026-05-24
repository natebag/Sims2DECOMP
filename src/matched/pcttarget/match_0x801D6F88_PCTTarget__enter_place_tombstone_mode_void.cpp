// 0x801D6F88 PCTTarget::enter_place_tombstone_mode(void) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 23,0x4c(1); stw 0,0x74(1); mr 28,3; li 27,1; stw 27,0xe8(28); addi 30,1,8; li 4,0; bl _s801D6F88_0; li 25,0; lis 9,-32698; lwz 10,0x84(28); addi 26,9,29032; li 0,0; lis 9,-32739; lis 11,-13071; stw 0,0x14(30); addi 9,9,7792; stb 0,0x18(30); ori 11,11,24704; stw 0,0x1c(30); li 24,6; sth 0,0x20(30); mr 23,30; stw 26,0x10(30); stw 27,0x24(30); stw 10,0xc(1); stw 9,0x14(1); stw 11,0x1c(1); stw 0,0x2c(1); stw 24,0x8(1); stw 28,0x10(1); stb 25,0x20(1); bl _s801D6F88_1; lwz 30,0x4(30); mr 29,3; mr 4,30; bl _s801D6F88_2; cmpwi 3,0; beq 1f; slw 0,27,30; lbz 9,0x3c(29); rlwinm 0,0,0,24,31; and. 31,9,0; bne 1f; or 0,0,9; li 3,40; stb 0,0x3c(29); bl _s801D6F88_3; stb 25,0x18(3); rlwinm 4,30,3,0,28; sth 31,0x20(3); mr 11,3; stw 27,0x24(3); mr 10,23; stw 24,0x0(3); li 9,24; stw 26,0x30(1); stw 26,0x10(3); stw 31,0x14(3); stw 31,0x1c(3); 0:; lwz 0,0x0(10); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); lwz 0,0x10(10); stw 0,0x10(11); lwz 0,0x14(10); addi 10,10,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(10); lwz 9,0x30(1); stw 0,0x0(11); lwz 0,0x4(10); stw 0,0x4(11); lwz 0,0x8(10); stw 0,0x8(11); lwz 0,0xc(10); stw 0,0xc(11); stw 9,0x10(3); lwz 0,0x0(3); lwz 9,0x2c(29); stw 0,0x40(1); stw 3,0x44(1); add 11,9,4; stw 0,0x38(1); stw 3,0x3c(1); stwx 0,9,4; stw 3,0x4(11); 1:; mr 3,28; li 4,0; bl _s801D6F88_4; lwz 3,0x214(28); cmpwi 3,0; beq 2f; li 4,0; bl _s801D6F88_5; 2:; lis 9,-32698; li 3,1; addi 9,9,-10560; stw 9,0x10(23); lwz 0,0x74(1); mtspr 8,0; lmw 23,0x4c(1); addi 1,1,112"

extern "C" void _s801D6F88_0();
extern "C" void _s801D6F88_1();
extern "C" void _s801D6F88_2();
extern "C" void _s801D6F88_3();
extern "C" void _s801D6F88_4();
extern "C" void _s801D6F88_5();

struct PCTTarget {
    void enter_place_tombstone_mode();
};

void PCTTarget::enter_place_tombstone_mode() {
}
