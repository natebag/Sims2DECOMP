// 0x800D4614 NghResFile::FlushSection(unsigned (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 31,4; bl _s800D4614_0; cmpwi 3,0; beq 6f; lwz 9,0x24(29); cmpwi 31,1; addi 27,9,1; beq 2f; cmplwi 31,1; blt 0f; cmpwi 31,2; beq 3f; cmpwi 31,3; beq 5f; b 6f; 0:; lis 4,21569; mr 3,29; ori 4,4,21588; li 28,0; bl _s800D4614_1; mr 31,3; lwz 3,0x0(31); bl _s800D4614_2; li 0,0; li 30,0; stw 0,0x0(31); 1:; addi 30,30,1; mr 3,29; mr 4,30; bl _s800D4614_3; lis 4,21321; mr 3,29; ori 4,4,19785; bl _s800D4614_4; mr 31,3; lwz 3,0x0(31); bl _s800D4614_5; stw 28,0x0(31); lis 4,18511; ori 4,4,21843; mr 3,29; bl _s800D4614_6; mr 31,3; lwz 3,0x0(31); bl _s800D4614_7; stw 28,0x0(31); cmpwi 30,15; ble 1b; mr 3,29; mr 4,27; bl _s800D4614_8; b 6f; 2:; lis 4,20039; mr 3,29; ori 4,4,16968; li 30,0; bl _s800D4614_9; mr 31,3; lwz 3,0x0(31); bl _s800D4614_10; stw 30,0x0(31); lis 4,20034; ori 4,4,21075; mr 3,29; bl _s800D4614_11; mr 31,3; lwz 3,0x0(31); bl _s800D4614_12; stw 30,0x0(31); lis 4,17985; ori 4,4,19785; mr 3,29; bl _s800D4614_13; mr 31,3; lwz 3,0x0(31); bl _s800D4614_14; stw 30,0x0(31); lis 4,21875; ori 4,4,25970; mr 3,29; bl _s800D4614_15; mr 31,3; lwz 3,0x0(31); bl _s800D4614_16; stw 30,0x0(31); b 6f; 3:; lis 4,29800; mr 3,29; ori 4,4,28002; bl _s800D4614_17; mr 31,3; lwz 3,0x0(31); bl _s800D4614_18; li 0,0; li 9,0; stw 0,0x0(31); addi 3,29,544; li 0,36; mtspr 9,0; 4:; stw 9,0x0(3); addi 3,3,-4; bdnz 4b; b 6f; 5:; mr 3,29; mr 4,27; bl _s800D4614_19; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800D4614_0();
extern "C" void _s800D4614_1();
extern "C" void _s800D4614_2();
extern "C" void _s800D4614_3();
extern "C" void _s800D4614_4();
extern "C" void _s800D4614_5();
extern "C" void _s800D4614_6();
extern "C" void _s800D4614_7();
extern "C" void _s800D4614_8();
extern "C" void _s800D4614_9();
extern "C" void _s800D4614_10();
extern "C" void _s800D4614_11();
extern "C" void _s800D4614_12();
extern "C" void _s800D4614_13();
extern "C" void _s800D4614_14();
extern "C" void _s800D4614_15();
extern "C" void _s800D4614_16();
extern "C" void _s800D4614_17();
extern "C" void _s800D4614_18();
extern "C" void _s800D4614_19();

struct NghResFile {
    void FlushSection();
};

void NghResFile::FlushSection() {
}
