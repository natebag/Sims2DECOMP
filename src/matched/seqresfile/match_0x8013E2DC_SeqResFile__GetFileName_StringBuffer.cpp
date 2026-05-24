// 0x8013E2DC SeqResFile::GetFileName(StringBuffer (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-568(1); mfspr 0,8; stmw 29,0x22c(1); stw 0,0x23c(1); mr 31,3; mr 29,4; lwz 9,0xc(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; addi 30,1,8; li 5,260; addi 4,30,8; mr 3,30; bl _s8013E2DC_0; li 5,260; addi 4,1,288; addi 3,1,280; bl _s8013E2DC_1; li 4,0; mr 3,31; bl _s8013E2DC_2; lwz 9,0xc(3); mr 4,30; lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; mr 4,29; addi 5,1,280; bl _s8013E2DC_3; 0:; lwz 0,0x23c(1); mtspr 8,0; lmw 29,0x22c(1); addi 1,1,568"

extern "C" void _s8013E2DC_0();
extern "C" void _s8013E2DC_1();
extern "C" void _s8013E2DC_2();
extern "C" void _s8013E2DC_3();

struct SeqResFile {
    void GetFileName_StringBuffer();
};

void SeqResFile::GetFileName_StringBuffer() {
}
