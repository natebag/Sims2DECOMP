// 0x80080BA8 MUWrapper::ResetSlotSelection(bool) (984 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-256(1); mfspr 0,8; mfcr 12; stfd f31,0xf8(1); stmw 17,0xbc(1); stw 0,0x104(1); stw 12,0xb8(1); lis 9,-32707; mr 31,3; lwz 0,0x6d28(9); lis 10,-32707; addi 9,9,27944; lwz 3,0x6d34(10); lhz 6,0x8(9); addi 8,1,8; lwz 5,0x4(9); addi 7,10,27956; stw 0,0x8(1); addi 11,1,40; sth 6,0x8(8); lis 9,-32696; stw 5,0x4(8); addi 6,31,212; lis 8,-32707; mr 17,11; lwz 10,0x8(7); addi 18,9,22744; lwz 0,0x4(7); cmpwi 4,4,0; stw 3,0x28(1); li 29,0; lfs f31,0x6d48(8); lis 19,-32707; lfs f11,0xd4(31); addi 21,1,164; stw 0,0x4(11); lis 26,-32697; stw 10,0x8(11); lis 27,-32707; stfs f11,0x48(1); addi 23,1,88; addi 24,1,120; addi 28,1,160; lfs f12,0x4(6); addi 25,1,152; lfs f0,0xdc(31); lis 20,-32707; lfs f13,0xe0(31); stfs f12,0x4c(1); fsubs f0,f0,f11; lfs f12,0x4(6); stfs f0,0x50(1); fsubs f13,f13,f12; stfs f13,0x54(1); 0:; beq cr4,1f; lwz 6,0xa4(31); li 4,1; lwz 3,0xa8(31); mr 5,29; bl _s80080BA8_0; lfs f1,0x6d44(20); li 4,1; lwz 3,0xa8(31); mr 5,29; bl _s80080BA8_1; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_2; stw 29,0x8(3); bl _s80080BA8_3; 1:; addi 4,1,8; mr 3,23; bl _s80080BA8_4; addi 30,29,1; mr 4,17; mr 3,24; bl _s80080BA8_5; mr 22,30; mr 5,30; addi 4,19,27968; mr 3,28; crxor 6,6,6; bl _s80080BA8_6; mr 4,28; mr 3,23; bl _s80080BA8_7; mr 4,28; mr 3,24; bl _s80080BA8_8; mr 3,21; addi 4,26,24012; addi 5,27,27740; crxor 6,6,6; bl _s80080BA8_9; lwz 9,0xa4(1); li 6,0; cmpwi 9,0; beq 2f; lwz 6,0x0(9); 2:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_10; lwz 0,0xac(31); cmpwi 0,7; beq 3f; cmpwi 0,14; bne 9f; 3:; lwz 9,0xcc(31); cmplw 29,9; blt 9f; addi 0,9,2; cmplw 29,0; bge 9f; li 0,0; mr 3,29; stw 0,0xa8(1); addi 4,1,168; bl _s80080BA8_11; lwz 0,0xa8(1); cmpwi 0,0; bne 7f; lwz 0,0xb0(31); cmpwi 0,15; bne 4f; lwz 0,0x8(18); cmpw 0,29; beq 6f; 4:; addi 3,1,172; addi 4,26,24012; addi 5,27,27740; crxor 6,6,6; bl _s80080BA8_12; lwz 9,0xac(1); li 6,0; cmpwi 9,0; beq 5f; lwz 6,0x0(9); 5:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_13; 6:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_14; li 4,7; bl _s80080BA8_15; b 8f; 7:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_16; li 4,1; bl _s80080BA8_17; 8:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_18; lwz 0,0x4(3); li 4,1; mr 5,29; ori 0,0,1; stw 0,0x4(3); lwz 3,0xa8(31); bl _s80080BA8_19; lwz 9,0x1c(3); addi 4,1,72; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lfs f0,0x48(1); lfs f13,0x4c(1); lfs f12,0x50(1); lfs f11,0x54(1); fadds f0,f0,f12; fadds f13,f13,f11; stfs f0,0x48(1); stfs f13,0x4c(1); b 10f; 9:; lwz 3,0xa8(31); li 4,1; mr 5,29; bl _s80080BA8_20; lwz 0,0x4(3); li 4,1; mr 5,29; rlwinm 0,0,0,0,30; stw 0,0x4(3); stfs f31,0x98(1); lwz 3,0xa8(31); stfs f31,0x4(25); bl _s80080BA8_21; lwz 9,0x1c(3); mr 4,25; lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; 10:; beq cr4,14f; cmpwi 29,0; bne 12f; addi 3,1,176; addi 4,26,24012; addi 5,27,27740; crxor 6,6,6; bl _s80080BA8_22; lwz 9,0xb0(1); li 6,0; cmpwi 9,0; beq 11f; lwz 6,0x0(9); 11:; lwz 3,0xa8(31); li 4,1; li 5,0; bl _s80080BA8_23; b 14f; 12:; addi 3,1,180; addi 4,26,24012; addi 5,27,27740; crxor 6,6,6; bl _s80080BA8_24; lwz 9,0xb4(1); li 6,0; cmpwi 9,0; beq 13f; lwz 6,0x0(9); 13:; lwz 3,0xa8(31); mr 5,29; li 4,1; bl _s80080BA8_25; 14:; mr 29,22; cmpwi 29,1; ble 0b; lwz 0,0x104(1); lwz 12,0xb8(1); mtspr 8,0; lmw 17,0xbc(1); lfd f31,0xf8(1); mtcrf 8,12; addi 1,1,256"
extern "C" void _s80080BA8_0();
extern "C" void _s80080BA8_1();
extern "C" void _s80080BA8_2();
extern "C" void _s80080BA8_3();
extern "C" void _s80080BA8_4();
extern "C" void _s80080BA8_5();
extern "C" void _s80080BA8_6();
extern "C" void _s80080BA8_7();
extern "C" void _s80080BA8_8();
extern "C" void _s80080BA8_9();
extern "C" void _s80080BA8_10();
extern "C" void _s80080BA8_11();
extern "C" void _s80080BA8_12();
extern "C" void _s80080BA8_13();
extern "C" void _s80080BA8_14();
extern "C" void _s80080BA8_15();
extern "C" void _s80080BA8_16();
extern "C" void _s80080BA8_17();
extern "C" void _s80080BA8_18();
extern "C" void _s80080BA8_19();
extern "C" void _s80080BA8_20();
extern "C" void _s80080BA8_21();
extern "C" void _s80080BA8_22();
extern "C" void _s80080BA8_23();
extern "C" void _s80080BA8_24();
extern "C" void _s80080BA8_25();
extern "C" void f_80080BA8() {}
