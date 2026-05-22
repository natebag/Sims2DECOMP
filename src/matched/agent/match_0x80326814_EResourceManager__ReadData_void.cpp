// 0x80326814 EResourceManager::ReadData(void (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 10,-22652(13); mr 0,4; mr 11,5; mr 4,3; lwz 9,0x0(10); mr 5,0; mr 7,6; li 8,1; lha 3,0x78(9); mr 6,11; lwz 0,0x7c(9); add 3,10,3; li 9,0; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80326814() {}
