// 0x80011B4C AptViewer::PopAptButtonFilter(int, (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 28,3; mr 30,4; lwz 0,0x3a8(28); cmpwi 0,0; beq 1f; cmplwi 30,1; ble 0f; li 30,0; 0:; rlwinm 23,30,2,0,29; addi 24,28,1104; lwzx 31,24,23; cmplwi 31,9; bgt 1f; mulli 25,30,80; rlwinm 9,31,3,0,28; addi 27,28,944; add 29,9,25; lwzx 0,27,29; cmpwi 0,0; beq 1f; mr 3,28; mr 4,30; bl _s80011B4C_0; mr. 3,3; beq 1f; lwzx 26,27,29; addi 28,28,948; mr 4,26; bl _s80011B4C_1; lis 3,-32707; lwzx 6,28,29; mr 5,31; addi 3,3,-9568; mr 4,30; mr 7,26; crxor 6,6,6; bl _s80011B4C_2; li 0,0; addic. 31,31,-1; stwx 0,27,29; stwx 0,28,29; blt 1f; stwx 31,24,23; rlwinm 0,31,3,0,28; add 0,0,25; lis 3,-32707; lwzx 6,28,0; addi 3,3,-9504; mr 4,30; mr 5,31; mr 7,26; crxor 6,6,6; bl _s80011B4C_3; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s80011B4C_0();
extern "C" void _s80011B4C_1();
extern "C" void _s80011B4C_2();
extern "C" void _s80011B4C_3();

struct AptViewer {
    void PopAptButtonFilter();
};

void AptViewer::PopAptButtonFilter() {
}
