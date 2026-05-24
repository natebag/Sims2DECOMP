// 0x800D70A4 NghResFile::WriteToFileInMemoryBlocks(char (1100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-320(1); mfspr 0,8; stmw 24,0x120(1); stw 0,0x144(1); addi 30,1,8; mr 27,3; mr 29,4; li 5,260; addi 4,30,8; mr 3,30; bl _s800D70A4_0; addi 28,1,280; mr 4,29; mr 5,30; mr 3,27; bl _s800D70A4_1; mr 24,28; li 0,0; mr 3,30; stw 0,0x118(1); bl _s800D70A4_2; mr 5,3; lis 6,-32706; lis 3,-32694; addi 6,6,-21636; addi 3,3,-10620; mr 4,28; li 7,2; lis 8,-32768; li 9,0; bl _s800D70A4_3; cmpwi 3,0; beq 10f; lis 9,-32696; addi 30,9,25388; lwz 9,0x4(30); lwz 28,0x3c(9); lwz 0,0x54(9); cmplw 0,28; ble 0f; mr 28,0; 0:; lwz 0,0x6c(9); cmplw 0,28; ble 1f; mr 28,0; 1:; lwz 0,0x7c(9); cmplw 0,28; ble 2f; mr 28,0; 2:; bl _s800D70A4_4; mr 4,28; li 5,0; bl _s800D70A4_5; mr 29,3; li 4,0; mr 5,28; bl _s800D70A4_6; mr 3,27; mr 4,29; bl _s800D70A4_7; cmpwi 3,1; bne 11f; lwz 10,0x118(1); li 5,0; lwz 9,0x4(30); lwz 11,0x28(10); lwz 4,0x38(9); lwz 0,0x2c(11); lha 3,0x28(11); mtspr 8,0; add 3,10,3; blrl; lwz 10,0x118(1); mr 4,29; lwz 9,0x4(30); lwz 11,0x28(10); lwz 5,0x3c(9); lha 3,0x20(11); lwz 0,0x24(11); add 3,10,3; mtspr 8,0; blrl; li 4,0; mr 5,28; mr 3,29; bl _s800D70A4_8; mr 3,27; mr 4,29; bl _s800D70A4_9; cmpwi 3,1; bne 11f; lwz 10,0x118(1); li 5,0; lwz 9,0x4(30); lwz 11,0x28(10); lwz 4,0x50(9); lwz 0,0x2c(11); lha 3,0x28(11); mtspr 8,0; add 3,10,3; blrl; lwz 10,0x118(1); mr 4,29; lwz 9,0x4(30); lwz 11,0x28(10); lwz 5,0x54(9); lha 3,0x20(11); lwz 0,0x24(11); add 3,10,3; mtspr 8,0; blrl; li 4,0; mr 5,28; mr 3,29; bl _s800D70A4_10; mr 3,27; mr 4,29; bl _s800D70A4_11; cmpwi 3,1; bne 11f; lwz 10,0x118(1); li 5,0; lwz 11,0x4(30); mr 26,30; lwz 9,0x28(10); li 31,0; lwz 4,0x68(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,10,3; blrl; lwz 10,0x118(1); mr 4,29; lwz 9,0x4(30); lwz 11,0x28(10); lwz 5,0x6c(9); lha 3,0x20(11); lwz 0,0x24(11); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x24(27); addi 25,9,1; 3:; addi 30,31,1; mr 3,27; mr 4,30; li 5,0; li 6,0; bl _s800D70A4_12; cmpwi 3,1; bne 11f; li 4,0; mr 5,28; mr 3,29; bl _s800D70A4_13; mr 3,27; mr 4,30; mr 5,29; bl _s800D70A4_14; cmpwi 3,1; bne 11f; lwz 9,0x4(26); li 5,0; lwz 10,0x118(1); addi 9,9,120; lwz 4,0x4(9); lwz 11,0x28(10); mullw 4,31,4; lwz 0,0x8(9); lwz 9,0x2c(11); lha 3,0x28(11); mtspr 8,9; add 4,0,4; add 3,10,3; blrl; lwz 10,0x118(1); mr 4,29; lwz 9,0x4(26); lwz 11,0x28(10); lwz 5,0x7c(9); lha 3,0x20(11); lwz 0,0x24(11); add 3,10,3; mtspr 8,0; blrl; cmpw 30,25; beq 4f; mr 3,27; mr 4,30; bl _s800D70A4_15; 4:; mr 31,30; cmpwi 31,15; ble 3b; lis 30,-32694; mr 4,24; addi 3,30,-10620; bl _s800D70A4_16; addi 3,1,8; bl _s800D70A4_17; mr 5,3; lis 6,-32706; addi 3,30,-10620; addi 6,6,-21632; mr 4,24; li 7,2; lis 8,-32768; li 9,0; bl _s800D70A4_18; cmpwi 3,0; beq 9f; li 4,0; mr 5,28; mr 3,29; bl _s800D70A4_19; lwz 11,0x118(1); li 4,0; li 5,2; lwz 9,0x28(11); lwz 0,0x2c(9); lha 3,0x28(9); mtspr 8,0; add 3,11,3; blrl; bl _s800D70A4_20; lwz 9,0x118(1); lwz 0,0x14(9); subf. 30,0,3; ble 8f; 5:; cmpw 30,28; ble 6f; lwz 3,0x118(1); mr 4,29; mr 5,28; subf 30,28,30; lwz 9,0x28(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; b 7f; 6:; lwz 3,0x118(1); mr 5,30; mr 4,29; li 30,0; lwz 9,0x28(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; 7:; cmpwi 30,0; bgt 5b; 8:; lis 3,-32694; mr 4,24; addi 3,3,-10620; bl _s800D70A4_21; 9:; bl _s800D70A4_22; mr 4,29; bl _s800D70A4_23; b 12f; 10:; li 3,-42; b 13f; 11:; bl _s800D70A4_24; mr 4,29; bl _s800D70A4_25; li 3,-50; b 13f; 12:; li 3,0; 13:; lwz 0,0x144(1); mtspr 8,0; lmw 24,0x120(1); addi 1,1,320"

extern "C" void _s800D70A4_0();
extern "C" void _s800D70A4_1();
extern "C" void _s800D70A4_2();
extern "C" void _s800D70A4_3();
extern "C" void _s800D70A4_4();
extern "C" void _s800D70A4_5();
extern "C" void _s800D70A4_6();
extern "C" void _s800D70A4_7();
extern "C" void _s800D70A4_8();
extern "C" void _s800D70A4_9();
extern "C" void _s800D70A4_10();
extern "C" void _s800D70A4_11();
extern "C" void _s800D70A4_12();
extern "C" void _s800D70A4_13();
extern "C" void _s800D70A4_14();
extern "C" void _s800D70A4_15();
extern "C" void _s800D70A4_16();
extern "C" void _s800D70A4_17();
extern "C" void _s800D70A4_18();
extern "C" void _s800D70A4_19();
extern "C" void _s800D70A4_20();
extern "C" void _s800D70A4_21();
extern "C" void _s800D70A4_22();
extern "C" void _s800D70A4_23();
extern "C" void _s800D70A4_24();
extern "C" void _s800D70A4_25();

struct NghResFile {
    void WriteToFileInMemoryBlocks();
};

void NghResFile::WriteToFileInMemoryBlocks() {
}
