// 0x802ACD2C AptString::sMethod_fromCharCode(AptValue (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 29,4; addi 3,1,8; rlwinm 4,29,1,0,30; li 30,0; bl _s802ACD2C_0; cmpw 30,29; bge 2f; lis 27,-32694; lis 28,-32700; addi 25,27,-16032; addi 26,28,-6476; addi 31,1,16; 0:; lwz 9,-16032(27); lwz 0,0x8(25); subf 9,30,9; rlwinm 9,9,2,0,29; add 9,9,0; lwz 3,-4(9); bl _s802ACD2C_1; lhz 9,-6476(28); mr 4,3; stw 26,0x10(1); mr 3,31; addi 9,9,1; sth 9,-6476(28); bl _s802ACD2C_2; mr 4,31; addi 3,1,8; bl _s802ACD2C_3; lwz 4,0x10(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACD2C_4; 1:; addi 30,30,1; cmpw 30,29; blt 0b; 2:; lwz 31,-26892(13); cmpwi 31,0; beq 5f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 3f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 4f; 3:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 4:; addi 30,31,12; mr 3,30; bl _s802ACD2C_5; cmpwi 3,0; bne 6f; mr 3,30; li 4,0; bl _s802ACD2C_6; b 6f; 5:; lwz 3,-23020(13); li 4,20; bl _s802ACD2C_7; bl _s802ACD2C_8; mr 31,3; 6:; addi 4,1,8; addi 3,31,12; bl _s802ACD2C_9; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 7f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802ACD2C_10; 7:; mr 3,31; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s802ACD2C_0();
extern "C" void _s802ACD2C_1();
extern "C" void _s802ACD2C_2();
extern "C" void _s802ACD2C_3();
extern "C" void _s802ACD2C_4();
extern "C" void _s802ACD2C_5();
extern "C" void _s802ACD2C_6();
extern "C" void _s802ACD2C_7();
extern "C" void _s802ACD2C_8();
extern "C" void _s802ACD2C_9();
extern "C" void _s802ACD2C_10();
extern "C" void f_802ACD2C() {}
