// 0x803616C4 EStringTableNoCase::ClearTable(void) (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x8(3); cmpwi 0,0; beq 0f; lwz 5,0xc(3); li 4,0; mr 3,0; rlwinm 5,5,2,0,29; bl _s803616C4_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803616C4_0();
extern "C" void f_803616C4() {}
