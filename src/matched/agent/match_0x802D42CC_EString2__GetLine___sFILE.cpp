// 0x802D42CC EString2::GetLine(__sFILE (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8240(1); mfspr 0,8; stmw 25,0x2014(1); stw 0,0x2034(1); addi 29,1,8; lis 9,-32702; addi 25,9,-6888; mr 28,3; mr 26,4; li 30,0; addi 27,1,8200; mr 31,29; 0:; mr 3,27; li 4,1; li 5,1; mr 6,26; bl _s802D42CC_0; mr. 3,3; beq 1f; lhz 0,0x2008(1); cmpwi 0,10; bne 2f; 1:; sth 25,0x0(31); addi 30,30,1; b 3f; 2:; sth 0,0x0(31); cmpwi 3,1; addi 31,31,2; addi 30,30,1; beq 0b; 3:; cmpwi 30,1; ble 4f; addi 0,30,-2; add 0,0,0; lhzx 9,29,0; cmpwi 9,13; bne 4f; lis 9,-32702; addi 30,30,-1; addi 9,9,-6888; sthx 9,29,0; 4:; lwz 4,0x0(28); mr 3,28; bl _s802D42CC_1; mr 3,28; addi 4,1,8; bl _s802D42CC_2; addi 3,30,-1; lwz 0,0x2034(1); mtspr 8,0; lmw 25,0x2014(1); addi 1,1,8240"
extern "C" void _s802D42CC_0();
extern "C" void _s802D42CC_1();
extern "C" void _s802D42CC_2();
extern "C" void f_802D42CC() {}
