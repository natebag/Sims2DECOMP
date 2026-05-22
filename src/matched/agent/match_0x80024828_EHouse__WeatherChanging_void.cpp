// 0x80024828 EHouse::WeatherChanging(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 11,-21496(13); mr 29,3; li 4,0; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); mr 30,3; li 4,5; lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; mulli 30,30,60; li 0,1; stw 0,0x38(29); add 30,30,3; stw 30,0x34(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80024828() {}
