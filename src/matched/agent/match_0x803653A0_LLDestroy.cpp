// 0x803653A0 LLDestroy (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); bl _s803653A0_0; lwz 9,0x0(31); lwz 0,0x88(9); stw 0,0x90(9); lwz 11,0x0(31); lwz 4,0x90(11); cmpwi 4,0; beq 1f; 0:; lwz 11,0x0(31); lwz 9,0x90(11); lwz 0,0x0(9); stw 0,0x90(11); lwz 3,0x0(31); bl _s803653A0_1; lwz 9,0x0(31); lwz 4,0x90(9); cmpwi 4,0; bne 0b; 1:; lwz 3,0x0(31); bl _s803653A0_2; lwz 3,-25848(13); lwz 4,0x0(31); bl _s803653A0_3; li 0,0; stw 0,0x0(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s803653A0_0();
extern "C" void _s803653A0_1();
extern "C" void _s803653A0_2();
extern "C" void _s803653A0_3();
extern "C" void f_803653A0() {}
