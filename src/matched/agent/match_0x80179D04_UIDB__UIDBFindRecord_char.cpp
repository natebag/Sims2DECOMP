// 0x80179D04 UIDB::UIDBFindRecord(char (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32696; mr 26,3; addi 31,9,31252; mr 27,4; addi 25,31,900; li 29,0; mr 30,31; 0:; lwz 0,0x4(31); mr 28,30; cmpw 0,27; bne 1f; lwz 3,0x0(31); mr 4,26; bl _s80179D04_0; cmpwi 3,0; bne 1f; li 29,1; 1:; cmpwi 7,29,0; bne cr7,2f; addi 31,31,12; addi 30,30,12; cmpw 31,25; ble 0b; 2:; mr 3,28; bne cr7,3f; li 3,0; 3:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s80179D04_0();
extern "C" void f_80179D04() {}
