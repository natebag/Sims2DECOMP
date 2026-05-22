// 0x80143560 SlotDescriptor::DoStream(ReconBuffer (692 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,5; mr 31,3; mr 30,4; cmpwi 29,2; bgt 3f; mr 3,30; addi 4,31,4; li 5,1; bl _s80143560_0; mr 3,30; addi 4,31,8; li 5,1; bl _s80143560_1; cmpwi 29,0; ble 0f; mr 3,30; addi 4,31,12; li 5,1; bl _s80143560_2; b 1f; 0:; lfs f0,0xc(31); mr 3,30; addi 4,1,8; li 5,1; fctiwz f13,f0; stfd f13,0x18(1); lwz 9,0x1c(1); sth 9,0x8(1); bl _s80143560_3; lha 0,0x8(1); lis 10,17200; lis 11,-32706; xoris 0,0,32768; lfd f13,-10432(11); stw 0,0x1c(1); stw 10,0x18(1); lfd f0,0x18(1); fsub f0,f0,f13; frsp f0,f0; stfs f0,0xc(31); 1:; mr 3,30; mr 4,31; li 5,1; bl _s80143560_4; cmpwi 29,1; ble 2f; li 0,0; mr 3,30; sth 0,0xa(1); addi 4,1,10; li 5,1; bl _s80143560_5; 2:; lwz 0,0xc(30); cmpwi 0,0; bne 6f; stw 0,0x28(31); stw 0,0x1c(31); stw 0,0x20(31); stw 0,0x24(31); b 6f; 3:; mr 3,30; mr 4,31; li 5,1; bl _s80143560_6; mr 3,30; addi 4,31,4; li 5,1; bl _s80143560_7; mr 3,30; addi 4,31,8; li 5,1; bl _s80143560_8; mr 3,30; addi 4,31,12; li 5,1; bl _s80143560_9; mr 3,30; addi 4,31,28; li 5,3; bl _s80143560_10; mr 3,30; addi 4,31,40; li 5,1; bl _s80143560_11; cmpwi 29,3; ble 4f; mr 3,30; addi 4,31,44; li 5,1; bl _s80143560_12; 4:; cmpwi 29,4; ble 5f; mr 3,30; addi 4,31,48; li 5,1; bl _s80143560_13; mr 3,30; addi 4,31,52; li 5,1; bl _s80143560_14; mr 3,30; addi 4,31,56; li 5,1; bl _s80143560_15; mr 3,30; addi 4,31,16; li 5,1; bl _s80143560_16; mr 3,30; addi 4,31,20; li 5,1; bl _s80143560_17; 5:; cmpwi 29,6; ble 6f; mr 3,30; addi 4,31,60; li 5,1; bl _s80143560_18; 6:; cmpwi 29,7; ble 7f; mr 3,30; addi 4,31,24; li 5,1; bl _s80143560_19; 7:; cmpwi 29,8; ble 8f; mr 3,30; addi 4,31,64; li 5,1; bl _s80143560_20; b 11f; 8:; lwz 9,0x28(31); andi. 0,9,512; beq 9f; li 0,-3; rlwinm 9,9,0,23,21; b 10f; 9:; andi. 0,9,1024; beq 11f; li 0,-1; rlwinm 9,9,0,22,20; 10:; stw 0,0x40(31); stw 9,0x28(31); 11:; cmpwi 29,9; ble 12f; mr 3,30; addi 4,31,68; li 5,1; bl _s80143560_21; b 13f; 12:; lis 9,-32706; lwz 0,0x34(31); lfs f13,-10424(9); lwz 11,0x30(31); rlwinm 0,0,4,0,27; lwz 9,0x38(31); lfs f0,0x3c(31); rlwinm 11,11,4,0,27; rlwinm 9,9,4,0,27; stw 0,0x34(31); fmuls f0,f0,f13; stw 11,0x30(31); stfs f0,0x3c(31); stw 9,0x38(31); 13:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s80143560_0();
extern "C" void _s80143560_1();
extern "C" void _s80143560_2();
extern "C" void _s80143560_3();
extern "C" void _s80143560_4();
extern "C" void _s80143560_5();
extern "C" void _s80143560_6();
extern "C" void _s80143560_7();
extern "C" void _s80143560_8();
extern "C" void _s80143560_9();
extern "C" void _s80143560_10();
extern "C" void _s80143560_11();
extern "C" void _s80143560_12();
extern "C" void _s80143560_13();
extern "C" void _s80143560_14();
extern "C" void _s80143560_15();
extern "C" void _s80143560_16();
extern "C" void _s80143560_17();
extern "C" void _s80143560_18();
extern "C" void _s80143560_19();
extern "C" void _s80143560_20();
extern "C" void _s80143560_21();
extern "C" void f_80143560() {}
