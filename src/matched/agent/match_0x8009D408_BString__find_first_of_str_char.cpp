// 0x8009D408 BString::find_first_of_str(char (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; mr 28,6; mr 30,5; b 5f; 0:; li 31,0; b 2f; 1:; addi 31,31,1; 2:; cmplw 31,28; bge 4f; mr 3,29; bl _s8009D408_0; lbzx 9,3,30; li 11,1; lbzx 0,27,31; cmpw 9,0; bne 3f; li 11,0; 3:; cmpwi 11,0; bne 1b; 4:; cmpw 31,28; bne 6f; addi 30,30,1; 5:; mr 3,29; bl _s8009D408_1; cmplw 30,3; blt 0b; 6:; mr 3,29; li 31,-1; bl _s8009D408_2; cmplw 30,3; bge 7f; mr 31,30; 7:; li 3,-1; cmplw 3,31; ble 8f; mr 3,31; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s8009D408_0();
extern "C" void _s8009D408_1();
extern "C" void _s8009D408_2();
extern "C" void f_8009D408() {}
