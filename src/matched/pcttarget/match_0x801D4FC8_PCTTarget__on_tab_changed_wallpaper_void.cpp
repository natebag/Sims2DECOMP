// 0x801D4FC8 PCTTarget::on_tab_changed_wallpaper(void) (388 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; mr 29,3; lwz 27,0x5ea4(9); li 0,0; stw 0,0xc0(29); lwz 31,0x0(27); b 2f; 0:; lwz 3,0x0(31); bl _s801D4FC8_0; cmpwi 3,0; beq 1f; lwz 9,0xc0(29); addi 9,9,1; stw 9,0xc0(29); 1:; addi 31,31,4; 2:; lwz 0,0x0(27); li 11,0; mr 9,0; cmpwi 0,0; beq 3f; lwz 11,-4(9); 3:; rlwinm 0,11,2,0,29; add 0,9,0; cmpw 31,0; bne 0b; lwz 31,0xc0(29); cmpwi 31,0; li 3,1; beq 14f; mulli 3,31,24; addi 30,31,-1; bl _s801D4FC8_1; mr 28,3; cmpwi 31,0; mr 31,28; beq 5f; 4:; mr 3,31; bl _s801D4FC8_2; addi 31,31,24; cmpwi 30,0; addi 30,30,-1; bne 4b; 5:; stw 28,0xbc(29); li 30,0; li 28,0; lwz 31,0x0(27); b 8f; 6:; lwz 3,0x0(31); bl _s801D4FC8_3; cmpwi 3,0; beq 7f; lwz 3,0xbc(29); mr 4,28; lwz 5,0x0(31); addi 28,28,1; add 3,3,30; bl _s801D4FC8_4; addi 30,30,24; 7:; addi 31,31,4; 8:; lwz 0,0x0(27); li 11,0; mr 9,0; cmpwi 0,0; beq 9f; lwz 11,-4(9); 9:; rlwinm 0,11,2,0,29; add 0,9,0; cmpw 31,0; bne 6b; lwz 0,0x9c(29); li 6,0; cmpwi 0,1; beq 10f; cmpwi 0,2; beq 11f; b 12f; 10:; lis 9,-32739; addi 6,9,7436; b 12f; 11:; lis 9,-32739; addi 6,9,7232; 12:; cmpwi 6,0; beq 13f; lwz 4,0xc0(29); li 5,24; lwz 3,0xbc(29); bl _s801D4FC8_5; 13:; li 3,1; 14:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801D4FC8_0();
extern "C" void _s801D4FC8_1();
extern "C" void _s801D4FC8_2();
extern "C" void _s801D4FC8_3();
extern "C" void _s801D4FC8_4();
extern "C" void _s801D4FC8_5();

struct PCTTarget {
    void on_tab_changed_wallpaper();
};

void PCTTarget::on_tab_changed_wallpaper() {
}
