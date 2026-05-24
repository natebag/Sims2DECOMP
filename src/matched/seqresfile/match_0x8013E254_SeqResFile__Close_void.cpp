// 0x8013E254 SeqResFile::Close(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; bl _s8013E254_0; mr 29,3; b 1f; 0:; li 4,0; mr 3,30; bl _s8013E254_1; mr 31,3; mr 3,30; mr 4,31; bl _s8013E254_2; cmpwi 31,0; beq 1f; lwz 9,0xc(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 1:; mr 3,30; bl _s8013E254_3; cmpwi 3,0; bne 0b; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8013E254_0();
extern "C" void _s8013E254_1();
extern "C" void _s8013E254_2();
extern "C" void _s8013E254_3();

struct SeqResFile {
    void Close();
};

void SeqResFile::Close() {
}
