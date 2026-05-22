// 0x80140560 cSimulatorImpl::DoStream(ReconBuffer (696 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); lis 9,-32706; mr 31,3; lfs f0,-10688(9); li 25,1; mr 30,4; mr 26,5; stw 25,0x98(31); mr 3,30; lha 27,0x36(31); addi 4,31,20; lha 28,0x62(31); li 5,48; lha 29,0x46(31); stfs f0,0xa8(31); bl _s80140560_0; lwz 0,0xc(30); cmpwi 0,0; bne 0f; rlwinm 0,27,0,30,30; sth 28,0x62(31); ori 0,0,1; sth 0,0x36(31); 0:; sth 29,0x46(31); lis 9,-32697; lwz 0,0x61c8(9); cmpwi 0,0; beq 1f; ori 0,29,4; sth 0,0x46(31); 1:; li 0,255; lis 9,-32692; sth 0,0x68(31); li 11,4; mr 3,30; addi 4,31,124; lwz 0,-17472(9); li 5,1; sth 11,0x2c(31); sth 0,0x32(31); bl _s80140560_1; lwz 0,0xc(30); cmpwi 0,0; bne 2f; stw 25,0x7c(31); 2:; lha 0,0x17a(31); cmpwi 26,91; addi 4,1,8; mfcr 27; sth 0,0x8(1); mr 3,30; li 5,1; addi 29,31,180; bl _s80140560_2; li 28,5; lha 0,0x8(1); li 5,0; lwz 9,0x0(31); stw 0,0x178(31); lwz 4,0x74(31); lwz 0,0xd4(9); lha 3,0xd0(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; addi 4,31,116; li 5,1; bl _s80140560_3; addi 4,31,144; li 5,1; mr 3,30; bl _s80140560_4; bl _s80140560_5; stw 3,0xc(1); addi 4,1,12; li 5,1; mr 3,30; bl _s80140560_6; lwz 3,0xc(1); bl _s80140560_7; mr 3,30; addi 4,31,120; li 5,1; bl _s80140560_8; mr 3,30; addi 4,31,132; li 5,1; bl _s80140560_9; mr 3,30; addi 4,31,136; li 5,1; bl _s80140560_10; mr 3,30; addi 4,31,140; li 5,1; bl _s80140560_11; lwz 11,0x8c(31); lis 0,26843; lwz 10,0x88(31); ori 0,0,35757; mulhw 9,11,0; srawi 8,11,31; srawi 6,10,31; mulhw 0,10,0; addi 3,31,340; mr 4,30; srawi 9,9,12; subf 9,8,9; srawi 0,0,12; mulli 7,9,10000; subf 0,6,0; sth 9,0x5c(31); mulli 8,0,10000; sth 0,0x58(31); subf 11,7,11; sth 11,0x5a(31); subf 10,8,10; sth 10,0x56(31); bl _s80140560_12; 3:; mr 3,29; mr 4,30; bl _s80140560_13; addi 29,29,32; addic. 28,28,-1; bne 3b; lwz 0,0xc(30); cmpwi 0,0; bne 6f; cmpwi 26,63; ble 4f; lha 9,0x38(31); addi 9,9,3; cmplwi 9,3; ble 5f; 4:; sth 0,0x34(31); sth 0,0x38(31); 5:; lwz 9,0x0(31); lha 4,0x38(31); lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; lha 4,0x22(31); lha 3,0x24(31); bl _s80140560_14; sth 3,0x4e(31); bl _s80140560_15; sth 3,0x50(31); 6:; mtcrf 128,27; ble 7f; lwz 3,0x174(31); cmpwi 3,0; beq 7f; mr 4,30; mr 5,26; bl _s80140560_16; 7:; lis 9,-32706; li 0,0; lfs f0,-10688(9); mr 3,31; stw 0,0x98(31); stfs f0,0xb0(31); stfs f0,0xac(31); bl _s80140560_17; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s80140560_0();
extern "C" void _s80140560_1();
extern "C" void _s80140560_2();
extern "C" void _s80140560_3();
extern "C" void _s80140560_4();
extern "C" void _s80140560_5();
extern "C" void _s80140560_6();
extern "C" void _s80140560_7();
extern "C" void _s80140560_8();
extern "C" void _s80140560_9();
extern "C" void _s80140560_10();
extern "C" void _s80140560_11();
extern "C" void _s80140560_12();
extern "C" void _s80140560_13();
extern "C" void _s80140560_14();
extern "C" void _s80140560_15();
extern "C" void _s80140560_16();
extern "C" void _s80140560_17();
extern "C" void f_80140560() {}
