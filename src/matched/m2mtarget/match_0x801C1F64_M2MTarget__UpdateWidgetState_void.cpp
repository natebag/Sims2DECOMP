// 0x801C1F64 M2MTarget::UpdateWidgetState(void) (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; lwz 0,0x168(29); cmpwi 0,2; beq 0f; bgt 5f; cmpwi 0,0; beq 5f; cmpwi 0,1; bne 5f; bl _s801C1F64_0; b 5f; 0:; addi 3,29,132; addi 30,29,288; bl _s801C1F64_1; li 31,0; mr 3,30; mr 27,30; bl _s801C1F64_2; lis 4,-32705; li 5,0; addi 4,4,9056; mr 3,30; bl _s801C1F64_3; li 4,1; mr 3,30; bl _s801C1F64_4; lis 4,-32705; li 5,0; addi 4,4,9060; mr 3,30; bl _s801C1F64_5; li 4,1; mr 3,30; bl _s801C1F64_6; lis 4,-32705; li 5,0; addi 4,4,9072; mr 3,30; bl _s801C1F64_7; mr 3,30; li 4,1; bl _s801C1F64_8; mr 3,30; bl _s801C1F64_9; lwz 0,0x188(29); cmpw 31,0; bge 2f; lis 9,-32700; addi 28,9,-26116; 1:; addi 0,31,48; mr 3,30; stb 0,0x8(28); addi 31,31,1; bl _s801C1F64_10; li 5,0; mr 3,30; mr 4,28; bl _s801C1F64_11; mr 3,30; li 4,1; bl _s801C1F64_12; mr 3,30; bl _s801C1F64_13; lwz 0,0x188(29); cmpw 31,0; blt 1b; 2:; lwz 31,0x188(29); cmpwi 31,7; bgt 4f; lis 9,-32700; mr 30,27; addi 28,9,-26116; 3:; addi 0,31,48; mr 3,30; stb 0,0x8(28); addi 31,31,1; bl _s801C1F64_14; li 5,0; mr 3,30; mr 4,28; bl _s801C1F64_15; mr 3,30; li 4,0; bl _s801C1F64_16; mr 3,30; bl _s801C1F64_17; cmpwi 31,7; ble 3b; 4:; mr 3,29; bl _s801C1F64_18; 5:; lwz 0,0x168(29); mr 3,29; mr 4,0; stw 0,0x16c(29); bl _s801C1F64_19; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s801C1F64_0();
extern "C" void _s801C1F64_1();
extern "C" void _s801C1F64_2();
extern "C" void _s801C1F64_3();
extern "C" void _s801C1F64_4();
extern "C" void _s801C1F64_5();
extern "C" void _s801C1F64_6();
extern "C" void _s801C1F64_7();
extern "C" void _s801C1F64_8();
extern "C" void _s801C1F64_9();
extern "C" void _s801C1F64_10();
extern "C" void _s801C1F64_11();
extern "C" void _s801C1F64_12();
extern "C" void _s801C1F64_13();
extern "C" void _s801C1F64_14();
extern "C" void _s801C1F64_15();
extern "C" void _s801C1F64_16();
extern "C" void _s801C1F64_17();
extern "C" void _s801C1F64_18();
extern "C" void _s801C1F64_19();

struct M2MTarget {
    void UpdateWidgetState();
};

void M2MTarget::UpdateWidgetState() {
}
