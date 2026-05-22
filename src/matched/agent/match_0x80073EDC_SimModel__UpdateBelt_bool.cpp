// 0x80073EDC SimModel::UpdateBelt(bool, (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 24,0x20(1); stw 0,0x44(1); mr 31,3; mr 24,5; mr 25,6; cmpwi 4,0; beq 11f; addi 9,31,104; li 27,1; mr 26,9; lwz 9,0x24(9); cmpwi 9,0; beq 0f; lwz 0,0x120(9); cmpwi 0,0; beq 0f; lwz 4,0x13c(31); addi 3,1,8; li 5,9; bl _s80073EDC_0; lwz 3,0x13c(31); li 4,9; lwz 28,0x138(31); bl _s80073EDC_1; mr 30,3; lwz 29,0xc(1); lwz 3,0x13c(31); li 4,22; bl _s80073EDC_2; mr 6,3; mr 4,30; mr 3,28; mr 5,29; bl _s80073EDC_3; subfic 0,3,0; adde 27,0,3; 0:; cmpwi 27,0; beq 2f; lwz 9,0x30(26); cmpwi 9,0; beq 1f; lwz 0,0x120(9); cmpwi 0,0; beq 1f; lwz 4,0x13c(31); addi 3,1,8; li 5,12; bl _s80073EDC_4; lwz 3,0x13c(31); li 4,12; lwz 28,0x138(31); bl _s80073EDC_5; mr 30,3; lwz 29,0xc(1); lwz 3,0x13c(31); li 4,22; bl _s80073EDC_6; mr 6,3; mr 4,30; mr 3,28; mr 5,29; bl _s80073EDC_7; cmpwi 3,0; beq 1f; li 27,0; 1:; cmpwi 27,0; beq 2f; mr 3,31; li 4,22; li 5,0; li 6,0; bl _s80073EDC_8; b 3f; 2:; mr 3,31; li 4,22; bl _s80073EDC_9; 3:; lwz 9,0x13c(31); lwz 0,0xe4(9); cmpwi 0,0; beq 4f; mr 3,31; li 4,24; li 5,0; li 6,0; bl _s80073EDC_10; b 5f; 4:; mr 3,31; li 4,24; bl _s80073EDC_11; 5:; lwz 11,0x13c(31); lwz 0,0xe0(11); cmpwi 0,0; beq 8f; lwz 9,0x30(26); li 3,1; cmpwi 9,0; beq 6f; lwz 0,0x120(9); cmpwi 0,0; beq 6f; lbz 4,0xb4(11); lwz 3,0x138(31); extsb 4,4; bl _s80073EDC_12; subfic 0,3,0; adde 3,0,3; 6:; cmpwi 3,0; beq 7f; mr 3,31; li 4,23; li 5,0; li 6,0; bl _s80073EDC_13; b 9f; 7:; mr 3,31; li 4,23; bl _s80073EDC_14; b 9f; 8:; mr 3,31; li 4,23; bl _s80073EDC_15; 9:; cmpwi 25,0; beq 11f; addi 30,1,24; mr 4,26; mr 3,30; bl _s80073EDC_16; lwz 9,0x13c(31); lwz 0,0xe4(9); cmpwi 0,0; beq 10f; lfs f1,0x104(9); mr 3,30; bl _s80073EDC_17; 10:; lwz 9,0x13c(31); mr 3,30; li 4,0; lfs f1,0xf8(9); bl _s80073EDC_18; mr 3,30; li 4,2; bl _s80073EDC_19; 11:; cmpwi 24,0; beq 12f; lis 9,-32696; mr 3,31; lbz 4,0x5775(9); bl _s80073EDC_20; 12:; lwz 0,0x44(1); mtspr 8,0; lmw 24,0x20(1); addi 1,1,64"
extern "C" void _s80073EDC_0();
extern "C" void _s80073EDC_1();
extern "C" void _s80073EDC_2();
extern "C" void _s80073EDC_3();
extern "C" void _s80073EDC_4();
extern "C" void _s80073EDC_5();
extern "C" void _s80073EDC_6();
extern "C" void _s80073EDC_7();
extern "C" void _s80073EDC_8();
extern "C" void _s80073EDC_9();
extern "C" void _s80073EDC_10();
extern "C" void _s80073EDC_11();
extern "C" void _s80073EDC_12();
extern "C" void _s80073EDC_13();
extern "C" void _s80073EDC_14();
extern "C" void _s80073EDC_15();
extern "C" void _s80073EDC_16();
extern "C" void _s80073EDC_17();
extern "C" void _s80073EDC_18();
extern "C" void _s80073EDC_19();
extern "C" void _s80073EDC_20();
extern "C" void f_80073EDC() {}
