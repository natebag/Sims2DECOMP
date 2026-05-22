// 0x802DCE84 StringWriter8(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,5; mr 30,4; lwz 9,0x4(31); mr 4,3; lwz 11,0x8(31); add 0,9,30; cmplw 0,11; ble 0f; subf 30,9,11; 0:; lwz 3,0x0(31); cmpwi 3,0; beq 1f; add 3,3,9; mr 5,30; crxor 6,6,6; bl _s802DCE84_0; 1:; lwz 0,0x4(31); li 3,1; add 0,0,30; stw 0,0x4(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802DCE84_0();
extern "C" void f_802DCE84() {}
