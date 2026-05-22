// 0x8008B8A8 UnloadLevelGlobalData(void) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32702; lis 29,-32693; addi 31,9,16044; lis 28,-32692; addi 30,31,248; lis 27,-32693; lis 26,-32692; 0:; lwz 4,0x0(31); addi 3,29,11064; li 5,1; addi 31,31,4; bl _s8008B8A8_0; cmpw 31,30; ble 0b; lis 9,-32702; addi 31,9,16296; addi 30,31,92; 1:; lwz 4,0x0(31); addi 3,28,-27556; li 5,1; addi 31,31,4; bl _s8008B8A8_1; cmpw 31,30; ble 1b; addi 31,13,-32184; mr 30,31; 2:; lwz 4,0x0(31); addi 3,27,21144; li 5,1; addi 31,31,4; bl _s8008B8A8_2; cmpw 31,30; ble 2b; lis 9,-32702; addi 31,9,16392; addi 30,31,16; 3:; lwz 4,0x0(31); addi 3,26,-17444; li 5,1; addi 31,31,4; bl _s8008B8A8_3; cmpw 31,30; ble 3b; bl _s8008B8A8_4; bl _s8008B8A8_5; lwz 31,-21488(13); cmpwi 31,0; beq 4f; lwz 9,0x0(31); lwz 0,0x134(9); lha 3,0x130(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); li 4,8; li 5,8; li 6,0; lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8008B8A8_0();
extern "C" void _s8008B8A8_1();
extern "C" void _s8008B8A8_2();
extern "C" void _s8008B8A8_3();
extern "C" void _s8008B8A8_4();
extern "C" void _s8008B8A8_5();
extern "C" void f_8008B8A8() {}
