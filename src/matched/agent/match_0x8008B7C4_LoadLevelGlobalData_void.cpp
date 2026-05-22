// 0x8008B7C4 LoadLevelGlobalData(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); bl _s8008B7C4_0; lis 29,-32693; lis 9,-32702; lis 28,-32692; addi 31,9,16044; lis 27,-32693; addi 30,31,248; lis 26,-32692; 0:; lwz 4,0x0(31); addi 3,29,11064; li 5,0; li 6,0; addi 31,31,4; bl _s8008B7C4_1; cmpw 31,30; ble 0b; lis 9,-32702; addi 31,9,16296; addi 30,31,92; 1:; lwz 4,0x0(31); addi 3,28,-27556; li 5,0; li 6,0; addi 31,31,4; bl _s8008B7C4_2; cmpw 31,30; ble 1b; addi 31,13,-32184; mr 30,31; 2:; lwz 4,0x0(31); addi 3,27,21144; li 5,0; li 6,0; addi 31,31,4; bl _s8008B7C4_3; cmpw 31,30; ble 2b; lis 9,-32702; addi 31,9,16392; addi 30,31,16; 3:; lwz 4,0x0(31); addi 3,26,-17444; li 5,0; li 6,0; addi 31,31,4; bl _s8008B7C4_4; cmpw 31,30; ble 3b; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8008B7C4_0();
extern "C" void _s8008B7C4_1();
extern "C" void _s8008B7C4_2();
extern "C" void _s8008B7C4_3();
extern "C" void _s8008B7C4_4();
extern "C" void f_8008B7C4() {}
