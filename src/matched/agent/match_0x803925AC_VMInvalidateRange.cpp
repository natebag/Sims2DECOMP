// 0x803925AC VMInvalidateRange (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); mr 31,3; stw 30,0x8(1); add 30,3,4; b 2f; 0:; mr 3,31; bl _s803925AC_0; cmpwi 3,0; beq 1f; mr 3,31; bl _s803925AC_1; lwz 0,-21892(13); mr 4,3; mr 3,31; subf 0,0,4; rlwinm 4,0,20,12,31; bl _s803925AC_2; 1:; addi 31,31,4096; 2:; cmplw 31,30; blt 0b; lwz 0,0x14(1); lwz 31,0xc(1); lwz 30,0x8(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s803925AC_0();
extern "C" void _s803925AC_1();
extern "C" void _s803925AC_2();
extern "C" void f_803925AC() {}
