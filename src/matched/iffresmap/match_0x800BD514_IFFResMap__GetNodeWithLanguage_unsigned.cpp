// 0x800BD514 IFFResMap::GetNodeWithLanguage(unsigned (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 27,5; mr 29,6; mr 28,7; li 5,0; bl _s800BD514_0; lwz 0,0x4(30); mr 31,3; cmpw 31,0; bne 1f; b 8f; 0:; mr 3,30; b 9f; 1:; cmpwi 28,0; beq 2f; stw 28,0x14(31); 2:; cmpwi 29,0; lwz 9,0x4(31); beq 5f; lwz 30,0x0(31); cmpw 30,9; beq 5f; 3:; lwz 0,0x4(30); cmpw 0,27; bne 4f; lha 3,0x8(30); bl _s800BD514_1; cmpw 3,29; beq 0b; 4:; lwz 0,0x4(31); addi 30,30,88; mr 9,0; cmpw 30,0; bne 3b; 5:; lwz 30,0x0(31); cmpw 30,9; beq 8f; 6:; lwz 0,0x4(30); cmpw 0,27; bne 7f; lha 3,0x8(30); bl _s800BD514_2; cmpwi 3,0; beq 0b; 7:; lwz 0,0x4(31); addi 30,30,88; cmpw 30,0; bne 6b; 8:; li 3,0; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800BD514_0();
extern "C" void _s800BD514_1();
extern "C" void _s800BD514_2();

struct IFFResMap {
    void GetNodeWithLanguage();
};

void IFFResMap::GetNodeWithLanguage() {
}
