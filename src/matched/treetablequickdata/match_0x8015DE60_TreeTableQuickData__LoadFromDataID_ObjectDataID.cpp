// 0x8015DE60 TreeTableQuickData::LoadFromDataID(ObjectDataID (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 22,0x10(1); stw 0,0x3c(1); lwz 9,-21508(13); mr 27,3; mr 24,4; lwz 11,0x0(9); lwz 4,0x0(24); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; mr. 3,3; beq 0f; lwz 3,0x8(3); cmpwi 3,0; bne 1f; 0:; li 3,0; b 13f; 1:; lwz 3,0x24(3); li 4,0; cmpwi 3,0; beq 2f; lwz 4,-4(3); 2:; mulli 4,4,12; lhz 5,0x4(24); add 4,3,4; bl _s8015DE60_0; mr. 25,3; beq 0b; addi 28,27,8; stw 25,0x4(27); lwz 29,0x8(27); mr 26,28; addi 23,1,8; addi 22,27,24; lwz 30,0x4(28); mr 31,29; cmpw 29,30; beq 5f; 3:; lwz 11,0x0(31); cmpwi 11,0; beq 4f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; addi 31,31,4; cmpw 31,30; bne 3b; 5:; stw 29,0x4(28); li 5,0; lwz 3,0x0(25); cmpwi 3,0; beq 6f; lwz 5,-4(3); 6:; lwz 3,0x8(27); li 9,0; lwz 4,0x4(26); stw 9,0x8(1); subf 0,3,4; srawi 0,0,2; cmplw 5,0; bge 10f; rlwinm 0,5,2,0,29; add 29,0,3; lwz 30,0x4(26); mr 31,29; cmpw 29,30; beq 9f; 7:; lwz 11,0x0(31); cmpwi 11,0; beq 8f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 8:; addi 31,31,4; cmpw 31,30; bne 7b; 9:; stw 29,0x4(26); b 11f; 10:; subf 5,0,5; mr 3,26; mr 6,23; bl _s8015DE60_1; 11:; lwz 11,0x8(1); cmpwi 11,0; beq 12f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 12:; mr 3,22; mr 4,24; bl _s8015DE60_2; li 3,1; 13:; lwz 0,0x3c(1); mtspr 8,0; lmw 22,0x10(1); addi 1,1,56"

extern "C" void _s8015DE60_0();
extern "C" void _s8015DE60_1();
extern "C" void _s8015DE60_2();

struct TreeTableQuickData {
    void LoadFromDataID_ObjectDataID();
};

void TreeTableQuickData::LoadFromDataID_ObjectDataID() {
}
