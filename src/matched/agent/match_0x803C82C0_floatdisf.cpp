// 0x803C82C0 __floatdisf (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x18(31); addi 4,1,12; stw 3,0xc(1); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; lwz 30,0x0(30); b 1f; 0:; lwz 9,0x18(31); addi 4,1,16; li 5,4; lwz 0,0xc(30); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; stw 0,0x10(1); mtspr 8,9; blrl; lwz 9,0x18(31); addi 4,1,20; li 5,4; lwz 0,0x10(30); lha 3,0x38(9); lwz 9,0x3c(9); add 3,31,3; stw 0,0x14(1); mtspr 8,9; blrl; lwz 30,0x4(30); 1:; li 0,1; cmpwi 30,0; bne 2f; li 0,0; 2:; cmpwi 0,0; bne 0b; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void f_803C82C0() {}
