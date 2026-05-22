// 0x80188E08 TArray<ENLatticePoints, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 4,30; bl _s80188E08_0; cmpwi 3,0; beq 0f; li 29,1; 0:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mulli 4,4,180; addi 4,4,1856; add 3,3,4; bl _s80188E08_1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80188E08_0();
extern "C" void _s80188E08_1();
extern "C" void f_80188E08() {}
