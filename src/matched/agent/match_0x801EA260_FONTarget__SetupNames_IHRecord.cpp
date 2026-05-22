// 0x801EA260 FONTarget::SetupNames(IHRecord (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-128(1); mfspr 0,8; mfcr 12; stmw 20,0x50(1); stw 0,0x84(1); stw 12,0x4c(1); mr 26,5; mr 23,3; mr 31,4; cmpwi 26,9; ble 0f; li 26,9; 0:; li 0,0; cmpwi 31,0; beq 1f; lwz 0,0x8(31); subfic 9,0,0; adde 0,9,0; 1:; addi 28,1,8; lis 24,-32704; addi 25,24,-30484; mr 29,28; cmpwi 4,0,0; li 30,0; lis 20,-32704; addi 27,1,40; lis 21,-32704; lis 22,-32704; 2:; lwz 10,-30484(24); mr 5,30; lbz 0,0xa(25); addi 4,20,-30472; lwz 11,0x4(25); mr 3,27; lhz 9,0x8(25); stw 10,0x8(1); stb 0,0xa(29); stw 11,0x4(29); sth 9,0x8(29); crxor 6,6,6; bl _s801EA260_0; mr 4,27; mr 3,29; bl _s801EA260_1; lwz 0,0x9c(23); addi 4,21,-30464; mr 3,28; cmpwi 0,1; bne 3f; bl _s801EA260_2; 3:; addi 3,1,8; addi 4,22,-30460; cmpwi 31,0; cmpw cr7,30,26; beq 5f; bge cr7,5f; addi 3,31,20; bl _s801EA260_3; mr 4,3; mr 3,28; bl _s801EA260_4; beq cr4,4f; lwz 31,0x4(31); b 6f; 4:; lwz 31,0xc(31); b 6f; 5:; bl _s801EA260_5; 6:; addi 30,30,1; cmpwi 30,8; ble 2b; lwz 0,0x84(1); lwz 12,0x4c(1); mtspr 8,0; lmw 20,0x50(1); mtcrf 8,12; addi 1,1,128"
extern "C" void _s801EA260_0();
extern "C" void _s801EA260_1();
extern "C" void _s801EA260_2();
extern "C" void _s801EA260_3();
extern "C" void _s801EA260_4();
extern "C" void _s801EA260_5();
extern "C" void f_801EA260() {}
