// 0x800EBFFC ConvertToBackslash(StringBuffer (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; li 31,0; bl _s800EBFFC_0; mr 29,3; cmpw 31,29; bge 2f; li 28,92; 0:; mr 3,30; bl _s800EBFFC_1; lbzx 0,3,31; cmpwi 0,47; bne 1f; mr 3,30; bl _s800EBFFC_2; stbx 28,3,31; 1:; addi 31,31,1; cmpw 31,29; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800EBFFC_0();
extern "C" void _s800EBFFC_1();
extern "C" void _s800EBFFC_2();
extern "C" void f_800EBFFC() {}
