// 0x800A6880 StringBuffer::compareNoCase(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,5; mr 28,4; bl _s800A6880_0; mr 29,3; mr 3,30; bl _s800A6880_1; mr 6,3; mr 7,6; cmpw 6,31; ble 0f; mr 7,31; 0:; li 8,0; cmpw 8,7; bge 4f; 1:; lbzx 0,29,8; lbzx 11,28,8; extsb 10,0; addi 9,10,-65; extsb 11,11; cmplwi 9,25; bgt 2f; addi 0,10,32; extsb 10,0; 2:; addi 0,11,-65; cmplwi 0,25; bgt 3f; addi 0,11,32; extsb 11,0; 3:; subf. 3,11,10; bne 5f; addi 8,8,1; cmpw 8,7; blt 1b; 4:; subf 3,31,6; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800A6880_0();
extern "C" void _s800A6880_1();

struct StringBuffer {
    void compareNoCase();
};

void StringBuffer::compareNoCase() {
}
