// 0x8013E008 SeqResFile::Delete(StringBuffer (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 31,3; li 23,0; addi 10,31,208; mr 26,4; lwzx 0,10,23; li 9,-250; li 27,0; cmpwi 0,0; beq 4f; lis 9,-32698; lis 11,-32698; addi 24,9,-2920; addi 25,11,-2896; li 28,0; li 29,0; 0:; lwzx 0,10,29; li 3,0; cmpwi 0,2; beq 1f; cmpwi 0,3; beq 2f; b 3f; 1:; li 3,336; bl _s8013E008_0; bl _s8013E008_1; b 3f; 2:; li 3,336; bl _s8013E008_2; mr 30,3; bl _s8013E008_3; stw 24,0x134(30); mr 3,30; stw 25,0xc(30); 3:; mr 4,3; mr 6,27; mr 3,31; mr 5,26; bl _s8013E008_4; addi 28,28,20; addi 10,31,208; mr 9,3; lwzx 0,10,28; addi 29,29,20; addi 27,27,1; cmpwi 0,0; bne 0b; 4:; cmpwi 23,0; li 3,0; bne 5f; mr 3,9; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s8013E008_0();
extern "C" void _s8013E008_1();
extern "C" void _s8013E008_2();
extern "C" void _s8013E008_3();
extern "C" void _s8013E008_4();

struct SeqResFile {
    void Delete_StringBuffer();
};

void SeqResFile::Delete_StringBuffer() {
}
