// 0x80133AE4 ReconBuffer::ReconString(BString (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; lwz 0,0x14(29); cmpwi 0,0; beq 2f; lwz 9,0x20(29); lwz 0,0xc(29); addi 31,9,1; stw 31,0x20(29); cmpwi 0,2; beq 6f; cmpwi 0,1; bne 0f; lwz 29,0x1c(29); mr 3,28; lwz 30,0x0(29); lha 0,0x98(30); addi 30,30,152; add 29,29,0; bl _s80133AE4_0; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,31; li 6,-1; mtspr 8,0; blrl; b 6f; 0:; lwz 3,0x1c(29); mr 4,31; li 5,-1; lwz 9,0x0(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; mr. 4,3; bne 1f; lis 9,-32706; addi 4,9,-12184; 1:; mr 3,28; bl _s80133AE4_1; b 6f; 2:; lwz 0,0x18(29); cmpwi 0,0; beq 3f; mr 3,29; bl _s80133AE4_2; 3:; lwz 0,0xc(29); cmpwi 0,2; beq 5f; cmpwi 0,0; bne 4f; lwz 0,0x0(29); mr 3,28; lwz 4,0x8(29); add 4,0,4; bl _s80133AE4_3; b 5f; 4:; cmpwi 0,1; bne 5f; lwz 30,0x0(29); mr 3,28; lwz 0,0x8(29); add 30,30,0; bl _s80133AE4_4; mr 4,3; mr 3,30; bl _s80133AE4_5; 5:; mr 3,28; bl _s80133AE4_6; lwz 9,0x8(29); addi 9,9,1; add 9,9,3; stw 9,0x8(29); andi. 0,9,1; beq 6f; addi 0,9,1; stw 0,0x8(29); 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80133AE4_0();
extern "C" void _s80133AE4_1();
extern "C" void _s80133AE4_2();
extern "C" void _s80133AE4_3();
extern "C" void _s80133AE4_4();
extern "C" void _s80133AE4_5();
extern "C" void _s80133AE4_6();

struct ReconBuffer {
    void ReconString_BString();
};

void ReconBuffer::ReconString_BString() {
}
