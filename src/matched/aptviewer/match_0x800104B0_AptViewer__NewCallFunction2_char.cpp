// 0x800104B0 AptViewer::NewCallFunction2(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); mr 3,4; mr 0,7; mr 4,5; cmpwi 0,2; mr 5,6; mr 11,8; beq 3f; bgt 0f; cmpwi 0,0; beq 1f; cmpwi 0,1; beq 2f; b 7f; 0:; cmpwi 0,4; beq 5f; blt 4f; cmpwi 0,5; beq 6f; b 7f; 1:; li 6,0; crxor 6,6,6; bl _s800104B0_0; b 7f; 2:; lwz 7,0x0(11); li 6,1; crxor 6,6,6; bl _s800104B0_1; b 7f; 3:; lwz 8,0x4(11); li 6,2; lwz 7,0x0(11); crxor 6,6,6; bl _s800104B0_2; b 7f; 4:; lwz 9,0x8(11); mr 6,0; lwz 7,0x0(11); lwz 8,0x4(11); crxor 6,6,6; bl _s800104B0_3; b 7f; 5:; lwz 10,0xc(11); li 6,4; lwz 7,0x0(11); lwz 8,0x4(11); lwz 9,0x8(11); crxor 6,6,6; bl _s800104B0_4; b 7f; 6:; lwz 0,0x10(11); li 6,5; lwz 7,0x0(11); lwz 8,0x4(11); lwz 9,0x8(11); lwz 10,0xc(11); stw 0,0x8(1); crxor 6,6,6; bl _s800104B0_5; 7:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"

extern "C" void _s800104B0_0();
extern "C" void _s800104B0_1();
extern "C" void _s800104B0_2();
extern "C" void _s800104B0_3();
extern "C" void _s800104B0_4();
extern "C" void _s800104B0_5();

struct AptViewer {
    void NewCallFunction2();
};

void AptViewer::NewCallFunction2() {
}
