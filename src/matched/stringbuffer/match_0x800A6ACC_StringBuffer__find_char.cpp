// 0x800A6ACC StringBuffer::find(char (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 25,4; mr 26,3; mr 30,5; mr 3,25; bl _s800A6ACC_0; mr 28,3; mr 3,26; bl _s800A6ACC_1; subf 3,28,3; addi 27,3,1; cmpw 30,27; bge 5f; 0:; li 29,1; li 31,0; b 2f; 1:; addi 31,31,1; 2:; cmpw 31,28; bge 3f; mr 3,26; add 4,30,31; bl _s800A6ACC_2; lbzx 0,25,31; extsb 0,0; cmpw 3,0; beq 1b; li 29,0; 3:; cmpwi 29,0; beq 4f; mr 3,30; b 6f; 4:; addi 30,30,1; cmpw 30,27; blt 0b; 5:; li 3,-1; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800A6ACC_0();
extern "C" void _s800A6ACC_1();
extern "C" void _s800A6ACC_2();

struct StringBuffer {
    void find();
};

void StringBuffer::find() {
}
