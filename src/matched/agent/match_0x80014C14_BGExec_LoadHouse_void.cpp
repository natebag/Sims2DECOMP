// 0x80014C14 BGExec_LoadHouse(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 8,-21476(13); lis 9,-32697; addi 9,9,24012; lwz 4,-32056(13); lwz 11,0x0(8); lwz 10,0xc8(9); lwz 0,0x44(11); lha 3,0x40(11); mtspr 8,0; lwz 5,0x54(10); add 3,8,3; lwz 6,0x158(9); blrl; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80014C14() {}
