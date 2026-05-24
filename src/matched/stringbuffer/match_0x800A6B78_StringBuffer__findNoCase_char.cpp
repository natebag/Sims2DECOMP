// 0x800A6B78 StringBuffer::findNoCase(char (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,4; mr 26,3; mr 30,5; mr 3,25; bl _s800A6B78_0; mr 29,3; mr 3,26; bl _s800A6B78_1; subf 3,29,3; addi 27,3,1; cmpw 30,27; bge 7f; 0:; li 28,1; li 31,0; b 2f; 1:; addi 31,31,1; 2:; cmpw 31,29; bge 5f; mr 3,26; add 4,30,31; bl _s800A6B78_2; mr 11,3; lbzx 9,25,31; addi 0,11,-65; rlwinm 0,0,0,24,31; extsb 3,9; cmplwi 0,25; bgt 3f; addi 0,11,32; extsb 11,0; 3:; addi 0,3,-65; cmplwi 0,25; bgt 4f; addi 0,3,32; extsb 3,0; 4:; cmpw 11,3; beq 1b; li 28,0; 5:; cmpwi 28,0; beq 6f; mr 3,30; b 8f; 6:; addi 30,30,1; cmpw 30,27; blt 0b; 7:; li 3,-1; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800A6B78_0();
extern "C" void _s800A6B78_1();
extern "C" void _s800A6B78_2();

struct StringBuffer {
    void findNoCase();
};

void StringBuffer::findNoCase() {
}
