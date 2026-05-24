// 0x8030F5E8 EREdithTreeSet::Load(EFile (892 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 27,0x3c(1); stw 0,0x54(1); mr 31,3; mr 30,4; bl _s8030F5E8_0; addi 3,1,8; bl _s8030F5E8_1; lis 5,17732; addi 3,1,8; mr 4,30; ori 5,5,21576; li 6,3; li 7,3; bl _s8030F5E8_2; cmpwi 3,0; beq 0f; addi 3,1,8; bl _s8030F5E8_3; lwz 9,0x18(1); lis 3,-32693; lwz 0,0x10(31); li 5,8; mr 4,9; addi 3,3,27900; rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s8030F5E8_4; mr 4,3; lwz 5,0x18(1); stw 4,0x14(31); lwz 9,0x28(30); lha 3,0x18(9); lwz 0,0x1c(9); add 3,30,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,0x28(30); addi 4,1,32; li 5,20; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x20(1); lis 0,8262; ori 0,0,17993; cmpw 9,0; beq 1f; bl _s8030F5E8_5; lwz 4,0x30(1); li 5,0; bl _s8030F5E8_6; lwz 9,0x28(30); mr 28,3; lwz 5,0x30(1); mr 4,28; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; mr 3,28; bl _s8030F5E8_7; lwz 29,0x30(1); addi 30,3,1; lwz 0,0x10(31); lis 3,-32693; subf 29,30,29; li 5,8; rlwimi 0,29,8,0,23; add 30,28,30; stw 0,0x10(31); mr 4,29; addi 3,3,27900; bl _s8030F5E8_8; mr 0,3; mr 4,30; mr 5,29; stw 0,0x14(31); bl _s8030F5E8_9; stw 29,0x18(1); bl _s8030F5E8_10; mr 4,28; bl _s8030F5E8_11; 1:; lwz 29,0x18(1); li 0,0; lwz 30,0x14(31); addi 29,29,-64; stw 0,0x18(31); addi 30,30,64; cmpwi 29,75; ble 4f; lis 28,-32702; 2:; lbz 0,0x0(30); addi 8,30,12; addi 7,30,76; addi 3,1,32; stb 0,0x20(1); addi 4,28,828; li 5,4; lbz 0,0x1(30); stb 0,0x21(1); lbz 9,0x2(30); stb 9,0x22(1); lbz 0,0x3(30); stb 0,0x23(1); lbz 9,0x4(30); lbz 0,0x5(30); lbz 11,0x6(30); rlwinm 9,9,24,0,7; rlwinm 0,0,16,0,15; lbz 10,0x7(30); or 9,9,0; rlwinm 11,11,8,0,23; or 9,9,11; or 9,9,10; stw 9,0x24(1); lbz 0,0x8(30); lbz 9,0x9(30); rlwinm 0,0,8,0,23; stw 8,0x2c(1); or 9,9,0; stw 7,0x30(1); sth 9,0x28(1); bl _s8030F5E8_12; cmpwi 3,0; bne 3f; lwz 9,0x18(31); addi 9,9,1; stw 9,0x18(31); 3:; lwz 0,0x24(1); subf 29,0,29; add 30,30,0; cmpwi 29,75; bgt 2b; 4:; lwz 4,0x18(31); cmpwi 4,0; beq 8f; mulli 4,4,12; lis 3,-32693; addi 3,3,27900; li 5,8; bl _s8030F5E8_13; lwz 29,0x18(1); lwz 30,0x14(31); addi 29,29,-64; stw 3,0x1c(31); addi 30,30,64; cmpwi 29,75; ble 7f; lis 27,-32702; li 28,0; 5:; lbz 0,0x0(30); addi 8,30,12; addi 7,30,76; addi 3,1,32; stb 0,0x20(1); addi 4,27,828; li 5,4; lbz 0,0x1(30); stb 0,0x21(1); lbz 9,0x2(30); stb 9,0x22(1); lbz 0,0x3(30); stb 0,0x23(1); lbz 9,0x4(30); lbz 0,0x5(30); lbz 11,0x6(30); rlwinm 9,9,24,0,7; rlwinm 0,0,16,0,15; lbz 10,0x7(30); or 9,9,0; rlwinm 11,11,8,0,23; or 9,9,11; or 9,9,10; stw 9,0x24(1); lbz 0,0x8(30); lbz 9,0x9(30); rlwinm 0,0,8,0,23; stw 8,0x2c(1); or 9,9,0; stw 7,0x30(1); sth 9,0x28(1); bl _s8030F5E8_14; cmpwi 3,0; bne 6f; lwz 9,0x1c(31); lhz 0,0x28(1); stwx 0,28,9; lwz 3,0x2c(1); bl _s8030F5E8_15; lwz 9,0x1c(31); lwz 0,0x2c(1); add 9,28,9; stw 0,0x4(9); lwz 11,0x1c(31); lwz 0,0x30(1); add 11,28,11; stw 0,0x8(11); addi 28,28,12; 6:; lwz 0,0x24(1); subf 29,0,29; add 30,30,0; cmpwi 29,75; bgt 5b; 7:; lis 6,-32719; lwz 4,0x18(31); lwz 3,0x1c(31); addi 6,6,-3132; li 5,12; bl _s8030F5E8_16; 8:; addi 3,1,8; li 4,2; bl _s8030F5E8_17; lwz 0,0x54(1); mtspr 8,0; lmw 27,0x3c(1); addi 1,1,80"

extern "C" void _s8030F5E8_0();
extern "C" void _s8030F5E8_1();
extern "C" void _s8030F5E8_2();
extern "C" void _s8030F5E8_3();
extern "C" void _s8030F5E8_4();
extern "C" void _s8030F5E8_5();
extern "C" void _s8030F5E8_6();
extern "C" void _s8030F5E8_7();
extern "C" void _s8030F5E8_8();
extern "C" void _s8030F5E8_9();
extern "C" void _s8030F5E8_10();
extern "C" void _s8030F5E8_11();
extern "C" void _s8030F5E8_12();
extern "C" void _s8030F5E8_13();
extern "C" void _s8030F5E8_14();
extern "C" void _s8030F5E8_15();
extern "C" void _s8030F5E8_16();
extern "C" void _s8030F5E8_17();

struct EREdithTreeSet {
    void Load_EFile();
};

void EREdithTreeSet::Load_EFile() {
}
