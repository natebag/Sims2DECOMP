// 0x801D4DDC PCTTarget::on_tab_changed_wall(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; mr 31,3; lwz 27,0x5ea8(9); li 30,0; lwz 9,0x0(27); cmpwi 9,0; beq 0f; lwz 30,-4(9); 0:; addi 0,30,1; mr 29,30; mulli 3,0,24; stw 0,0xc0(31); bl _s801D4DDC_0; mr 28,3; cmpwi 29,-1; mr 30,28; beq 2f; 1:; mr 3,30; bl _s801D4DDC_1; addi 30,30,24; cmpwi 29,0; addi 29,29,-1; bne 1b; 2:; lwz 0,-23856(13); stw 28,0xbc(31); cmpwi 0,0; bne 3f; lis 29,-32696; li 4,0; addi 30,29,32204; li 5,20; mr 3,30; li 28,1; crxor 6,6,6; bl _s801D4DDC_2; lis 0,-8422; lis 4,-32697; ori 0,0,36483; lis 5,-32705; stw 0,0x7dcc(29); addi 4,4,24012; addi 5,5,18264; stw 28,0x4(30); addi 3,30,8; crxor 6,6,6; bl _s801D4DDC_3; li 0,-1; stw 28,-23856(13); sth 0,0x10(30); stw 0,0xc(30); 3:; lwz 3,0xbc(31); lis 5,-32696; addi 5,5,32204; li 4,-1; bl _s801D4DDC_4; li 28,1; lwz 30,0x0(27); li 29,24; b 5f; 4:; lwz 3,0xbc(31); mr 4,28; lwz 5,0x0(30); addi 28,28,1; add 3,3,29; addi 30,30,4; bl _s801D4DDC_5; addi 29,29,24; 5:; lwz 9,0x0(27); li 0,0; mr 11,9; cmpwi 9,0; beq 6f; lwz 0,-4(11); 6:; rlwinm 0,0,2,0,29; add 0,9,0; cmpw 30,0; bne 4b; lwz 0,0x9c(31); li 6,0; cmpwi 0,1; beq 7f; cmpwi 0,2; beq 8f; b 9f; 7:; lis 9,-32739; addi 6,9,7332; b 9f; 8:; lis 9,-32739; addi 6,9,7232; 9:; cmpwi 6,0; beq 10f; lwz 4,0xc0(31); li 5,24; lwz 3,0xbc(31); addi 4,4,-1; addi 3,3,24; bl _s801D4DDC_6; 10:; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801D4DDC_0();
extern "C" void _s801D4DDC_1();
extern "C" void _s801D4DDC_2();
extern "C" void _s801D4DDC_3();
extern "C" void _s801D4DDC_4();
extern "C" void _s801D4DDC_5();
extern "C" void _s801D4DDC_6();

struct PCTTarget {
    void on_tab_changed_wall();
};

void PCTTarget::on_tab_changed_wall() {
}
