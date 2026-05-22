// 0x802D75A4 efwrite (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x28(6); mullw 5,4,5; mr 4,3; lha 3,0x20(9); lwz 0,0x24(9); add 3,6,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_802D75A4() {}
