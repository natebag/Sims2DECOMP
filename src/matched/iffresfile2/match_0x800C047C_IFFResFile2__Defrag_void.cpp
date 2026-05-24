// 0x800C047C IFFResFile2::Defrag(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 27,0x5c(1); stw 0,0x74(1); mr 31,3; li 3,0; ori 3,3,51200; bl _s800C047C_0; mr. 27,3; bne 0f; li 3,-200; b 7f; 0:; lis 28,29299; li 29,64; li 30,0; ori 28,28,28016; b 5f; 1:; lhz 0,0x12(1); andi. 9,0,4; bne 2f; lwz 0,0x8(1); cmpw 0,28; bne 3f; 2:; lwz 0,0xc(1); add 30,30,0; b 4f; 3:; lwz 6,0xc(1); mr 3,31; mr 4,29; mr 5,30; mr 7,27; bl _s800C047C_1; mr. 3,3; bne 7f; lwz 3,0x138(31); mr 4,29; mr 5,30; bl _s800C047C_2; 4:; lwz 0,0xc(1); add 29,29,0; 5:; mr 3,31; addi 4,1,8; mr 5,29; bl _s800C047C_3; cmpwi 3,0; beq 1b; cmpwi 27,0; beq 6f; mr 3,27; bl _s800C047C_4; 6:; subf 4,30,29; addi 3,31,16; bl _s800C047C_5; lwz 9,0x138(31); li 0,-1; stw 0,0x13c(31); li 11,0; stw 11,0x10(9); li 3,0; 7:; lwz 0,0x74(1); mtspr 8,0; lmw 27,0x5c(1); addi 1,1,112"

extern "C" void _s800C047C_0();
extern "C" void _s800C047C_1();
extern "C" void _s800C047C_2();
extern "C" void _s800C047C_3();
extern "C" void _s800C047C_4();
extern "C" void _s800C047C_5();

struct IFFResFile2 {
    void Defrag();
};

void IFFResFile2::Defrag() {
}
