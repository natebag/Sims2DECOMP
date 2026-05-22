// 0x800A7A00 QuickStringSet::SetLocInfo(iResFile (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 1f; li 0,0; stw 0,0x8(31); stw 0,0x4(31); lwz 3,0x8(4); cmpwi 3,0; beq 1f; lwz 3,0x14(3); li 4,0; cmpwi 3,0; beq 0f; lwz 4,-4(3); 0:; mulli 4,4,12; add 4,3,4; bl _s800A7A00_0; stw 3,0x4(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s800A7A00_0();
extern "C" void f_800A7A00() {}
