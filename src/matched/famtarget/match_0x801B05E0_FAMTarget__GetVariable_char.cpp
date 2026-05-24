// 0x801B05E0 FAMTarget::GetVariable(char (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801B05E0_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801B05E0_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,-672; mr 4,31; bl _s801B05E0_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x84(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 4f; 1:; lis 4,-32705; mr 3,31; addi 4,4,1644; li 5,25; bl _s801B05E0_3; cmpwi 3,0; bne 3f; lbz 0,0x19(31); addi 3,1,8; stb 0,0x8(1); bl _s801B05E0_4; mr 4,3; mr 3,29; bl _s801B05E0_5; cmpwi 3,0; bne 2f; lis 9,-32705; lhz 0,-5284(9); sth 0,0x0(30); b 4f; 2:; lis 9,-32705; lhz 0,-5288(9); sth 0,0x0(30); b 4f; 3:; lwz 3,-30404(13); mr 4,31; bl _s801B05E0_6; cmpwi 3,0; bne 4f; lis 4,-32705; lwz 5,0x88(29); addi 4,4,-8800; mr 3,30; crxor 6,6,6; bl _s801B05E0_7; 4:; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s801B05E0_0();
extern "C" void _s801B05E0_1();
extern "C" void _s801B05E0_2();
extern "C" void _s801B05E0_3();
extern "C" void _s801B05E0_4();
extern "C" void _s801B05E0_5();
extern "C" void _s801B05E0_6();
extern "C" void _s801B05E0_7();

struct FAMTarget {
    void GetVariable();
};

void FAMTarget::GetVariable() {
}
