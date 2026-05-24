// 0x80070CC4 SimModel::SetAllModels(void) (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 6,0; li 4,1; li 5,0; bl _s80070CC4_0; mr 3,30; li 4,0; li 5,0; bl _s80070CC4_1; mr 3,30; li 4,1; li 5,0; li 6,0; li 7,0; bl _s80070CC4_2; li 5,0; li 6,0; li 7,0; mr 3,30; li 4,1; bl _s80070CC4_3; mr 3,30; li 4,0; bl _s80070CC4_4; mr 3,30; li 4,1; li 5,0; li 6,0; li 7,0; bl _s80070CC4_5; li 7,0; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_6; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_7; li 6,0; mr 3,30; li 4,1; li 5,0; bl _s80070CC4_8; mr 3,30; li 4,1; li 5,0; bl _s80070CC4_9; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_10; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_11; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_12; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_13; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_14; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_15; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_16; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_17; mr 3,30; li 4,1; li 5,0; li 6,0; bl _s80070CC4_18; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80070CC4_0();
extern "C" void _s80070CC4_1();
extern "C" void _s80070CC4_2();
extern "C" void _s80070CC4_3();
extern "C" void _s80070CC4_4();
extern "C" void _s80070CC4_5();
extern "C" void _s80070CC4_6();
extern "C" void _s80070CC4_7();
extern "C" void _s80070CC4_8();
extern "C" void _s80070CC4_9();
extern "C" void _s80070CC4_10();
extern "C" void _s80070CC4_11();
extern "C" void _s80070CC4_12();
extern "C" void _s80070CC4_13();
extern "C" void _s80070CC4_14();
extern "C" void _s80070CC4_15();
extern "C" void _s80070CC4_16();
extern "C" void _s80070CC4_17();
extern "C" void _s80070CC4_18();

struct SimModel {
    void SetAllModels();
};

void SimModel::SetAllModels() {
}
