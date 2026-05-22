// 0x802A10BC AptSharedPtrDelete(AptLinkerThingy (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,3; beq 1f; lwz 3,0x4(31); cmpwi 3,0; beq 0f; bl _s802A10BC_0; cmpwi 3,0; bne 0f; lwz 3,0x4(31); bl _s802A10BC_1; 0:; lwz 3,-23020(13); mr 4,31; li 5,16; bl _s802A10BC_2; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802A10BC_0();
extern "C" void _s802A10BC_1();
extern "C" void _s802A10BC_2();
extern "C" void f_802A10BC() {}
