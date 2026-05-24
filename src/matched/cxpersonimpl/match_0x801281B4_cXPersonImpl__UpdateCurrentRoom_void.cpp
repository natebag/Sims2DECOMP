// 0x801281B4 cXPersonImpl::UpdateCurrentRoom(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; lwz 9,0x0(30); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x30c(11); lha 3,0x308(11); mtspr 8,0; add 3,10,3; blrl; lhz 0,0x41c(30); mr 31,3; cmpw 31,0; beq 3f; bl _s801281B4_0; li 28,0; lhz 4,0x41c(30); li 0,0; ori 0,0,65530; mr 29,3; li 27,0; cmplw 4,0; bgt 0f; bl _s801281B4_1; mr 28,3; 0:; li 0,0; ori 0,0,65530; cmplw 31,0; bgt 1f; mr 3,29; mr 4,31; bl _s801281B4_2; mr 27,3; 1:; sth 31,0x41c(30); cmpwi 28,0; beq 2f; mr 3,28; bl _s801281B4_3; cmpwi 3,0; bne 2f; mr 3,28; li 4,0; bl _s801281B4_4; 2:; cmpwi 27,0; beq 3f; mr 3,27; li 4,1; bl _s801281B4_5; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801281B4_0();
extern "C" void _s801281B4_1();
extern "C" void _s801281B4_2();
extern "C" void _s801281B4_3();
extern "C" void _s801281B4_4();
extern "C" void _s801281B4_5();

struct cXPersonImpl {
    void UpdateCurrentRoom();
};

void cXPersonImpl::UpdateCurrentRoom() {
}
