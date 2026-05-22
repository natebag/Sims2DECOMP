// 0x8005898C OptionsRecon::DoStream(ReconBuffer (624 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,4; mr 31,3; mr 3,30; mr 4,31; bl _s8005898C_0; mr 3,30; addi 4,31,4; bl _s8005898C_1; mr 3,30; addi 4,31,8; bl _s8005898C_2; mr 3,30; addi 4,31,12; bl _s8005898C_3; mr 3,30; addi 4,31,16; bl _s8005898C_4; mr 3,30; addi 4,31,28; li 5,1; bl _s8005898C_5; lwz 9,0xc(30); cmpwi 9,0; bne 1f; lbz 0,0x1c(31); andi. 11,0,128; beq 0f; stb 9,0x1c(31); 0:; lbz 0,0x1c(31); extsb 0,0; cmpwi 0,10; ble 1f; li 0,10; stb 0,0x1c(31); 1:; mr 3,30; addi 4,31,29; li 5,1; bl _s8005898C_6; lwz 9,0xc(30); cmpwi 9,0; bne 3f; lbz 0,0x1d(31); andi. 11,0,128; beq 2f; stb 9,0x1d(31); 2:; lbz 0,0x1d(31); extsb 0,0; cmpwi 0,10; ble 3f; li 0,10; stb 0,0x1d(31); 3:; mr 3,30; addi 4,31,30; li 5,1; bl _s8005898C_7; lwz 9,0xc(30); cmpwi 9,0; bne 5f; lbz 0,0x1e(31); andi. 11,0,128; beq 4f; stb 9,0x1e(31); 4:; lbz 0,0x1e(31); extsb 0,0; cmpwi 0,10; ble 5f; li 0,10; stb 0,0x1e(31); 5:; mr 3,30; addi 4,31,31; li 5,1; bl _s8005898C_8; mr 3,30; addi 4,31,32; li 5,1; bl _s8005898C_9; lwz 0,0xc(30); cmpwi 0,0; bne 6f; mr 3,30; addi 4,1,8; li 5,1; bl _s8005898C_10; b 7f; 6:; mr 3,30; addi 4,31,84; li 5,1; bl _s8005898C_11; 7:; mr 3,30; addi 4,31,88; bl _s8005898C_12; mr 3,30; addi 4,31,160; bl _s8005898C_13; li 5,1; mr 3,30; addi 4,31,232; bl _s8005898C_14; mr 3,30; addi 4,31,236; bl _s8005898C_15; mr 3,30; addi 4,31,240; bl _s8005898C_16; mr 3,30; addi 4,31,20; bl _s8005898C_17; mr 3,30; addi 4,31,24; bl _s8005898C_18; mr 3,30; addi 4,31,40; li 5,1; bl _s8005898C_19; lwz 9,0xc(30); cmpwi 9,0; bne 9f; lbz 0,0x28(31); andi. 11,0,128; beq 8f; stb 9,0x28(31); 8:; lbz 0,0x28(31); extsb 0,0; cmpwi 0,10; ble 9f; li 0,10; stb 0,0x28(31); 9:; mr 3,30; addi 4,31,41; li 5,1; bl _s8005898C_20; lwz 9,0xc(30); cmpwi 9,0; bne 11f; lbz 0,0x29(31); andi. 11,0,128; beq 10f; stb 9,0x29(31); 10:; lbz 0,0x29(31); extsb 0,0; cmpwi 0,10; ble 11f; li 0,10; stb 0,0x29(31); 11:; mr 3,30; addi 4,31,36; bl _s8005898C_21; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8005898C_0();
extern "C" void _s8005898C_1();
extern "C" void _s8005898C_2();
extern "C" void _s8005898C_3();
extern "C" void _s8005898C_4();
extern "C" void _s8005898C_5();
extern "C" void _s8005898C_6();
extern "C" void _s8005898C_7();
extern "C" void _s8005898C_8();
extern "C" void _s8005898C_9();
extern "C" void _s8005898C_10();
extern "C" void _s8005898C_11();
extern "C" void _s8005898C_12();
extern "C" void _s8005898C_13();
extern "C" void _s8005898C_14();
extern "C" void _s8005898C_15();
extern "C" void _s8005898C_16();
extern "C" void _s8005898C_17();
extern "C" void _s8005898C_18();
extern "C" void _s8005898C_19();
extern "C" void _s8005898C_20();
extern "C" void _s8005898C_21();
extern "C" void f_8005898C() {}
