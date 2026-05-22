// 0x80011CA8 AptViewer::RemoveCmdFromAptButtonFilter(int, (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0x3a8(3); mr 30,5; mr 31,6; cmpwi 0,0; beq 1f; cmplwi 4,1; ble 0f; li 4,0; 0:; cmpwi 31,49; bgt 1f; bl _s80011CA8_0; mr. 3,3; beq 1f; mr 4,30; mr 5,31; bl _s80011CA8_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80011CA8_0();
extern "C" void _s80011CA8_1();
extern "C" void f_80011CA8() {}
