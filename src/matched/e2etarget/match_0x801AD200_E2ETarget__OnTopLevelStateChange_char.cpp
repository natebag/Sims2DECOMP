// 0x801AD200 E2ETarget::OnTopLevelStateChange(char (376 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; addi 3,1,8; bl _s801AD200_0; addi 3,1,8; bl _s801AD200_1; lwz 0,0xd8(31); cmpwi 0,1; bne 0f; li 4,0; mr 3,31; li 5,0; bl _s801AD200_2; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-1824; bl _s801AD200_3; addi 3,1,8; li 4,0; bl _s801AD200_4; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-1800; bl _s801AD200_5; addi 3,1,8; li 4,1; bl _s801AD200_6; bl _s801AD200_7; li 0,-1; li 3,-1; stw 0,0xc4(31); bl _s801AD200_8; b 2f; 0:; cmpwi 0,2; bne 1f; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-1824; bl _s801AD200_9; addi 3,1,8; li 4,1; bl _s801AD200_10; lis 4,-32705; addi 3,1,8; addi 4,4,-1800; li 5,0; bl _s801AD200_11; addi 3,1,8; li 4,0; bl _s801AD200_12; bl _s801AD200_13; b 2f; 1:; cmpwi 0,0; bne 2f; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-1824; bl _s801AD200_14; li 30,-1; addi 3,1,8; li 4,0; bl _s801AD200_15; lis 4,-32705; addi 3,1,8; li 5,0; addi 4,4,-1800; bl _s801AD200_16; li 4,0; addi 3,1,8; bl _s801AD200_17; bl _s801AD200_18; stw 30,0xc4(31); li 3,-1; bl _s801AD200_19; stw 30,0xbc(31); li 3,-1; bl _s801AD200_20; 2:; addi 3,1,8; bl _s801AD200_21; addi 3,1,8; li 4,2; bl _s801AD200_22; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s801AD200_0();
extern "C" void _s801AD200_1();
extern "C" void _s801AD200_2();
extern "C" void _s801AD200_3();
extern "C" void _s801AD200_4();
extern "C" void _s801AD200_5();
extern "C" void _s801AD200_6();
extern "C" void _s801AD200_7();
extern "C" void _s801AD200_8();
extern "C" void _s801AD200_9();
extern "C" void _s801AD200_10();
extern "C" void _s801AD200_11();
extern "C" void _s801AD200_12();
extern "C" void _s801AD200_13();
extern "C" void _s801AD200_14();
extern "C" void _s801AD200_15();
extern "C" void _s801AD200_16();
extern "C" void _s801AD200_17();
extern "C" void _s801AD200_18();
extern "C" void _s801AD200_19();
extern "C" void _s801AD200_20();
extern "C" void _s801AD200_21();
extern "C" void _s801AD200_22();

struct E2ETarget {
    void OnTopLevelStateChange();
};

void E2ETarget::OnTopLevelStateChange() {
}
