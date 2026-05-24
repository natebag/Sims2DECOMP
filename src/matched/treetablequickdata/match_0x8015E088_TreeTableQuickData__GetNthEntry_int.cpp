// 0x8015E088 TreeTableQuickData::GetNthEntry(int) (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lwz 11,0x4(30); cmpwi 11,0; beq 0f; cmpwi 4,0; blt 0f; lwz 0,0xc(30); lwz 9,0x8(30); subf 0,9,0; srawi 0,0,2; cmpw 4,0; blt 1f; 0:; li 3,0; b 5f; 1:; rlwinm 29,4,2,0,29; lwzx 0,9,29; mr 3,0; cmpwi 0,0; bne 5f; mr 3,11; bl _s8015E088_0; mr. 31,3; li 3,0; beq 5f; li 3,28; bl _s8015E088_1; mr 4,31; bl _s8015E088_2; lwz 30,0x8(30); mr 31,3; lwzx 0,30,29; cmpw 31,0; beq 4f; cmpwi 31,0; beq 2f; lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwzx 11,30,29; cmpwi 11,0; beq 3f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 3:; stwx 31,30,29; 4:; mr 3,31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8015E088_0();
extern "C" void _s8015E088_1();
extern "C" void _s8015E088_2();

struct TreeTableQuickData {
    void GetNthEntry();
};

void TreeTableQuickData::GetNthEntry() {
}
