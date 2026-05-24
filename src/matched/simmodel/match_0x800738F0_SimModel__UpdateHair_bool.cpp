// 0x800738F0 SimModel::UpdateHair(bool, (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,5; mr 30,6; cmpwi 4,0; beq 8f; lwz 9,0x13c(31); lwz 0,0x94(9); cmpwi 0,0; beq 0f; li 4,2; bl _s800738F0_0; li 5,0; li 6,0; li 4,3; mr 3,31; bl _s800738F0_1; mr 3,31; li 4,4; bl _s800738F0_2; mr 3,31; li 4,5; bl _s800738F0_3; b 5f; 0:; mr 3,31; li 4,3; bl _s800738F0_4; lwz 9,0x13c(31); lwz 0,0x90(9); cmpwi 0,1; beq 3f; bgt 1f; cmpwi 0,0; beq 2f; b 7f; 1:; cmpwi 0,2; beq 4f; cmpwi 0,3; beq 6f; b 7f; 2:; li 5,0; li 6,0; li 4,2; mr 3,31; bl _s800738F0_5; mr 3,31; li 4,4; bl _s800738F0_6; mr 3,31; li 4,5; bl _s800738F0_7; b 5f; 3:; mr 3,31; li 4,2; bl _s800738F0_8; li 4,4; li 5,0; li 6,0; mr 3,31; bl _s800738F0_9; mr 3,31; li 4,5; bl _s800738F0_10; b 5f; 4:; mr 3,31; li 4,2; bl _s800738F0_11; mr 3,31; li 4,4; bl _s800738F0_12; li 4,5; mr 3,31; li 5,0; li 6,0; bl _s800738F0_13; 5:; mr 3,31; li 4,6; bl _s800738F0_14; b 7f; 6:; mr 3,31; li 4,2; bl _s800738F0_15; mr 3,31; li 4,4; bl _s800738F0_16; mr 3,31; li 4,5; bl _s800738F0_17; mr 3,31; li 4,6; li 5,0; li 6,0; bl _s800738F0_18; 7:; cmpwi 30,0; beq 8f; addi 4,31,104; addi 3,1,8; bl _s800738F0_19; lwz 9,0x13c(31); addi 3,1,8; lfs f1,0x104(9); bl _s800738F0_20; addi 3,1,8; li 4,2; bl _s800738F0_21; 8:; cmpwi 29,0; beq 9f; lis 9,-32696; mr 3,31; lbz 4,0x56ad(9); bl _s800738F0_22; 9:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800738F0_0();
extern "C" void _s800738F0_1();
extern "C" void _s800738F0_2();
extern "C" void _s800738F0_3();
extern "C" void _s800738F0_4();
extern "C" void _s800738F0_5();
extern "C" void _s800738F0_6();
extern "C" void _s800738F0_7();
extern "C" void _s800738F0_8();
extern "C" void _s800738F0_9();
extern "C" void _s800738F0_10();
extern "C" void _s800738F0_11();
extern "C" void _s800738F0_12();
extern "C" void _s800738F0_13();
extern "C" void _s800738F0_14();
extern "C" void _s800738F0_15();
extern "C" void _s800738F0_16();
extern "C" void _s800738F0_17();
extern "C" void _s800738F0_18();
extern "C" void _s800738F0_19();
extern "C" void _s800738F0_20();
extern "C" void _s800738F0_21();
extern "C" void _s800738F0_22();

struct SimModel {
    void UpdateHair();
};

void SimModel::UpdateHair() {
}
