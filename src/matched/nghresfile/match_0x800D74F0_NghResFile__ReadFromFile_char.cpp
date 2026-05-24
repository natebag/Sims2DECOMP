// 0x800D74F0 NghResFile::ReadFromFile(char (704 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-320(1); mfspr 0,8; stmw 25,0x124(1); stw 0,0x144(1); addi 31,1,8; mr 28,3; mr 30,4; li 5,260; addi 4,31,8; mr 3,31; bl _s800D74F0_0; lis 25,-32694; addi 29,1,280; mr 4,30; mr 5,31; mr 3,28; bl _s800D74F0_1; mr 26,29; mr 3,31; bl _s800D74F0_2; mr 5,3; lis 6,-32706; lis 3,-32694; addi 6,6,-21732; addi 3,3,-10620; mr 4,29; lis 7,-32768; lis 8,-32768; li 9,0; bl _s800D74F0_3; lwz 0,0x118(1); cmpwi 0,0; li 3,-1; beq 5f; lwz 3,-21432(13); addi 27,28,40; li 30,0; bl _s800D74F0_4; mr 3,31; bl _s800D74F0_5; mr 4,3; mr 3,27; bl _s800D74F0_6; li 0,1; stb 30,0x134(28); stw 0,0x20(28); li 4,0; mr 3,28; bl _s800D74F0_7; lis 9,-32696; addi 31,9,25388; lwz 11,0x4(31); lwz 30,0x3c(11); mr 3,30; bl _s800D74F0_8; lwz 10,-22652(13); mr 29,3; lwz 9,0x4(31); mr 5,29; lwz 11,0x0(10); mr 7,30; lwz 6,0x38(9); li 8,1; lha 3,0x70(11); li 9,0; lwz 0,0x74(11); add 3,10,3; lwz 4,0x118(1); mtspr 8,0; blrl; cmpw 3,30; bne 3f; mr 3,28; mr 4,29; li 5,0; bl _s800D74F0_9; mr 30,3; cmpwi 29,0; beq 0f; mr 3,29; bl _s800D74F0_10; 0:; cmpwi 30,1; bne 3f; li 4,1; mr 3,28; bl _s800D74F0_11; lwz 9,0x4(31); lwz 30,0x54(9); mr 3,30; bl _s800D74F0_12; lwz 10,-22652(13); mr 29,3; lwz 9,0x4(31); mr 5,29; lwz 11,0x0(10); mr 7,30; lwz 6,0x50(9); li 8,1; lha 3,0x70(11); li 9,0; lwz 0,0x74(11); add 3,10,3; lwz 4,0x118(1); mtspr 8,0; blrl; cmpw 3,30; bne 3f; mr 3,28; mr 4,29; li 5,0; bl _s800D74F0_13; mr 30,3; cmpwi 29,0; beq 1f; mr 3,29; bl _s800D74F0_14; 1:; cmpwi 30,1; bne 3f; li 4,2; mr 3,28; bl _s800D74F0_15; lwz 9,0x4(31); lwz 30,0x6c(9); mr 3,30; bl _s800D74F0_16; lwz 10,-22652(13); mr 29,3; lwz 9,0x4(31); mr 5,29; lwz 11,0x0(10); mr 7,30; lwz 6,0x68(9); li 8,1; lha 3,0x70(11); li 9,0; lwz 0,0x74(11); add 3,10,3; lwz 4,0x118(1); mtspr 8,0; blrl; cmpw 3,30; bne 3f; mr 3,28; mr 4,29; li 5,0; bl _s800D74F0_17; mr 30,3; cmpwi 29,0; beq 2f; mr 3,29; bl _s800D74F0_18; 2:; cmpwi 30,1; beq 4f; 3:; lwz 3,-21432(13); bl _s800D74F0_19; mr 3,27; bl _s800D74F0_20; addi 3,25,-10620; mr 4,26; bl _s800D74F0_21; li 3,-1; b 5f; 4:; mr 3,28; bl _s800D74F0_22; lwz 3,-21432(13); bl _s800D74F0_23; lis 3,-32694; mr 4,26; addi 3,3,-10620; bl _s800D74F0_24; li 3,0; 5:; lwz 0,0x144(1); mtspr 8,0; lmw 25,0x124(1); addi 1,1,320"

extern "C" void _s800D74F0_0();
extern "C" void _s800D74F0_1();
extern "C" void _s800D74F0_2();
extern "C" void _s800D74F0_3();
extern "C" void _s800D74F0_4();
extern "C" void _s800D74F0_5();
extern "C" void _s800D74F0_6();
extern "C" void _s800D74F0_7();
extern "C" void _s800D74F0_8();
extern "C" void _s800D74F0_9();
extern "C" void _s800D74F0_10();
extern "C" void _s800D74F0_11();
extern "C" void _s800D74F0_12();
extern "C" void _s800D74F0_13();
extern "C" void _s800D74F0_14();
extern "C" void _s800D74F0_15();
extern "C" void _s800D74F0_16();
extern "C" void _s800D74F0_17();
extern "C" void _s800D74F0_18();
extern "C" void _s800D74F0_19();
extern "C" void _s800D74F0_20();
extern "C" void _s800D74F0_21();
extern "C" void _s800D74F0_22();
extern "C" void _s800D74F0_23();
extern "C" void _s800D74F0_24();

struct NghResFile {
    void ReadFromFile();
};

void NghResFile::ReadFromFile() {
}
