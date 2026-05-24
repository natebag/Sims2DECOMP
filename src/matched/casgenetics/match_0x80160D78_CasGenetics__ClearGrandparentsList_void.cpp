// 0x80160D78 CasGenetics::ClearGrandparentsList(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); mr 29,3; li 11,0; addi 25,1,8; li 26,0; 0:; rlwinm 9,11,4,0,27; addi 27,11,1; add 11,9,29; lwzx 31,9,29; lwz 0,0x4(11); mr 28,9; cmpw 31,0; beq 3f; mr 30,11; 1:; lwz 0,0x0(31); li 4,3; addi 31,31,4; mr 3,0; cmpwi 0,0; beq 2f; bl _s80160D78_0; 2:; lwz 0,0x4(30); cmpw 31,0; bne 1b; 3:; add 3,28,29; lwzx 9,28,29; lwz 4,0x4(3); stw 26,0x8(1); subf 0,9,4; srawi 0,0,2; cmplw 26,0; bge 4f; stw 9,0x4(3); b 5f; 4:; neg 5,0; mr 6,25; bl _s80160D78_1; 5:; mr 11,27; cmplwi 11,1; ble 0b; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"

extern "C" void _s80160D78_0();
extern "C" void _s80160D78_1();

struct CasGenetics {
    void ClearGrandparentsList();
};

void CasGenetics::ClearGrandparentsList() {
}
