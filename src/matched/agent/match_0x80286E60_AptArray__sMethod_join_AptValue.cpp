// 0x80286E60 AptArray::sMethod_join(AptValue (500 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; li 11,0; lwz 9,0x0(30); rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 10f; lis 9,-32700; cmpwi 4,0; lhz 11,-6476(9); addi 0,9,-6476; stw 0,0x10(1); addi 31,1,8; addi 11,11,2; stw 0,0x8(1); sth 11,-6476(9); ble 1f; lis 9,-32694; addi 4,1,16; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); bl _s80286E60_0; lwz 5,0x10(1); mr 3,30; mr 4,31; addi 5,5,8; bl _s80286E60_1; b 2f; 1:; lis 5,-32704; mr 3,30; mr 4,31; addi 5,5,16276; bl _s80286E60_2; 2:; lwz 31,-26892(13); cmpwi 31,0; beq 5f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 4:; addi 30,31,12; mr 3,30; bl _s80286E60_3; cmpwi 3,0; bne 6f; mr 3,30; li 4,0; bl _s80286E60_4; b 6f; 5:; lwz 3,-23020(13); li 4,20; bl _s80286E60_5; bl _s80286E60_6; mr 31,3; 6:; lwz 11,0x8(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0xc(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286E60_7; 7:; lwz 0,0x8(1); stw 0,0xc(31); lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 8f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286E60_8; 8:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 9f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80286E60_9; 9:; mr 3,31; b 11f; 10:; lwz 3,-22936(13); 11:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80286E60_0();
extern "C" void _s80286E60_1();
extern "C" void _s80286E60_2();
extern "C" void _s80286E60_3();
extern "C" void _s80286E60_4();
extern "C" void _s80286E60_5();
extern "C" void _s80286E60_6();
extern "C" void _s80286E60_7();
extern "C" void _s80286E60_8();
extern "C" void _s80286E60_9();
extern "C" void f_80286E60() {}
