// 0x80011A48 AptViewer::PushAptButtonFilter(int, (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; mr 30,4; lwz 0,0x3a8(29); mr 28,5; cmpwi 0,0; bne 0f; li 3,0; b 5f; 0:; li 23,0; cmplwi 30,1; ble 1f; li 30,0; 1:; rlwinm 24,30,2,0,29; addi 25,29,1104; lwzx 31,25,24; cmpwi 31,9; bgt 3f; mr 3,29; mr 4,30; bl _s80011A48_0; mr. 3,3; beq 4f; mulli 27,30,80; rlwinm 0,31,3,0,28; addi 26,29,944; add 0,0,27; lwzx 9,26,0; cmpwi 9,0; beq 2f; addi 31,31,1; 2:; stwx 31,25,24; li 4,0; mr 5,28; li 6,100; bl _s80011A48_1; rlwinm 0,31,3,0,28; mr 23,3; add 0,0,27; addi 9,29,948; stwx 23,26,0; lis 3,-32707; stwx 28,9,0; addi 3,3,-9696; mr 4,30; mr 5,31; mr 6,28; mr 7,23; crxor 6,6,6; bl _s80011A48_2; b 4f; 3:; lis 3,-32707; mr 4,31; addi 3,3,-9636; crxor 6,6,6; bl _s80011A48_3; 4:; mr 3,23; 5:; lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"

extern "C" void _s80011A48_0();
extern "C" void _s80011A48_1();
extern "C" void _s80011A48_2();
extern "C" void _s80011A48_3();

struct AptViewer {
    void PushAptButtonFilter();
};

void AptViewer::PushAptButtonFilter() {
}
