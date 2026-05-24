// 0x800BFDD4 IFFResFile2::LoadNode(IFFResNode (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 27,0x64(1); stw 0,0x7c(1); mr 30,4; mr 28,3; lwz 0,0xc(30); mr 27,5; mr 31,6; cmpwi 0,0; bne 9f; lwz 5,0x0(30); addi 4,1,8; bl _s800BFDD4_0; mr. 29,3; bne 4f; lwz 9,0xc(1); lis 0,16384; addi 9,9,-76; cmplw 9,0; stw 9,0x58(1); bgt 0f; lwz 0,0x8(1); cmpw 0,31; beq 1f; 0:; li 3,-1; b 10f; 1:; bl _s800BFDD4_1; li 4,12; li 5,0; bl _s800BFDD4_2; lwz 0,0x58(1); mr 31,3; cmpwi 0,0; stw 0,0x0(31); beq 2f; bl _s800BFDD4_3; lwz 4,0x58(1); li 5,0; bl _s800BFDD4_4; stw 3,0x4(31); b 3f; 2:; stw 29,0x4(31); 3:; li 0,1; cmpwi 31,0; stw 0,0x8(31); stw 31,0xc(30); beq 9f; lwz 4,0x0(30); addi 28,28,16; mr 3,28; addi 4,4,76; bl _s800BFDD4_5; mr. 29,3; beq 5f; 4:; mr 3,29; b 10f; 5:; lwz 9,0xc(30); lwz 31,0x4(9); cmpwi 31,0; li 3,0; beq 10f; mr 3,28; mr 4,31; addi 5,1,88; bl _s800BFDD4_6; mr. 29,3; beq 8f; lwz 31,0xc(30); cmpwi 31,0; beq 7f; lwz 0,0x8(31); cmpwi 0,0; beq 6f; bl _s800BFDD4_7; lwz 4,0x4(31); bl _s800BFDD4_8; 6:; bl _s800BFDD4_9; mr 4,31; bl _s800BFDD4_10; 7:; li 0,0; mr 3,29; stw 0,0xc(30); b 10f; 8:; lhz 0,0xa(30); andi. 9,0,16; beq 9f; cmpwi 27,0; beq 9f; mr 3,31; lwz 4,0x58(1); mtspr 8,27; blrl; lhz 0,0x8(30); rlwinm 0,0,0,28,26; sth 0,0x8(30); 9:; li 3,0; 10:; lwz 0,0x7c(1); mtspr 8,0; lmw 27,0x64(1); addi 1,1,120"

extern "C" void _s800BFDD4_0();
extern "C" void _s800BFDD4_1();
extern "C" void _s800BFDD4_2();
extern "C" void _s800BFDD4_3();
extern "C" void _s800BFDD4_4();
extern "C" void _s800BFDD4_5();
extern "C" void _s800BFDD4_6();
extern "C" void _s800BFDD4_7();
extern "C" void _s800BFDD4_8();
extern "C" void _s800BFDD4_9();
extern "C" void _s800BFDD4_10();

struct IFFResFile2 {
    void LoadNode_IFFResNode();
};

void IFFResFile2::LoadNode_IFFResNode() {
}
