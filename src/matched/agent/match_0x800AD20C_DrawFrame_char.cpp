// 0x800AD20C DrawFrame(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 11,-25912(13); lwz 8,-26524(13); lwz 9,0x340(11); mr 10,11; addi 9,9,2; 0:; lwz 0,0x340(10); cmpw 0,9; blt 0b; lwz 9,0x20(8); lha 3,0x10(9); lwz 0,0x14(9); add 3,8,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800AD20C() {}
