// 0x800A7A6C QuickStringSet::LoadRes(iResFile (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 0,0; mr 29,5; stw 0,0x8(31); stw 0,0x4(31); mr. 30,4; beq 1f; lwz 3,0x8(30); cmpwi 3,0; beq 1f; lwz 3,0x10(3); li 4,0; cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; mulli 4,4,12; mr 5,29; add 4,3,4; bl _s800A7A6C_0; stw 3,0x8(31); 1:; lwz 9,0x0(31); li 4,0; li 5,1; lha 3,0x100(9); lwz 0,0x104(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 4f; li 0,0; cmpwi 30,0; stw 0,0x8(31); stw 0,0x4(31); beq 3f; lwz 3,0x8(30); cmpwi 3,0; beq 3f; lwz 3,0x10(3); li 4,0; cmpwi 3,0; beq 2f; lwz 4,-4(3); 2:; mulli 4,4,12; mr 5,29; add 4,3,4; bl _s800A7A6C_1; stw 3,0x8(31); 3:; lwz 9,0x0(31); li 4,0; li 5,1; lha 3,0x100(9); lwz 0,0x104(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800A7A6C_0();
extern "C" void _s800A7A6C_1();

struct QuickStringSet {
    void LoadRes_iResFile();
};

void QuickStringSet::LoadRes_iResFile() {
}
