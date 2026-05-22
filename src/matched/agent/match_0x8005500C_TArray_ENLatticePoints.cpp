// 0x8005500C TArray<ENLatticePoints, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8005507C" lines="lwz 31,0x4(28); cmpwi 31,0; beq 1f; 0:; lwz 30,0x1c(31); mr 3,29; mr 4,30; bl _s8005500C_0; lwz 9,0x0(30); mr 4,29; lha 3,0x190(9); lwz 0,0x194(9); add 3,30,3; mtspr 8,0; blrl; lwz 31,0x10(31); cmpwi 31,0; bne 0b; 1:; lwzu 30,0x4(28); mr 31,28"
extern "C" void _s8005500C_0();
extern "C" void f_8005507C();
extern "C" void f_8005500C() {}
