// 0x8021146C InteractorModule::DestroyObject(cXObject (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; bl _s8021146C_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x4(31); lwz 29,-21484(13); lha 3,0x328(9); lwz 9,0x32c(9); lwz 30,0x0(29); add 3,31,3; mtspr 8,9; lha 0,0x58(30); addi 30,30,88; add 29,29,0; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 11,-21424(13); lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21508(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; li 3,1; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8021146C_0();
extern "C" void f_8021146C() {}
