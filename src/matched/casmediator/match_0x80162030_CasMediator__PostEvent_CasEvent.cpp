// 0x80162030 CasMediator::PostEvent(CasEvent (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); li 0,0; mr 31,4; stw 0,0x8(1); mr 30,3; lwz 9,0x4(31); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(30); lwz 0,0x8(9); stw 0,0x8(1); b 1f; 0:; lwz 3,0x10(9); lwz 9,0x4(3); lha 0,0x10(9); lwz 9,0x14(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x8(1); bl _s80162030_0; stw 3,0x8(1); 1:; lwz 9,0x8(1); mr 4,31; lwz 0,0x4(30); li 11,1; cmpw 9,0; bne 2f; li 11,0; 2:; cmpwi 11,0; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80162030_0();

struct CasMediator {
    void PostEvent_CasEvent();
};

void CasMediator::PostEvent_CasEvent() {
}
