// 0x801DE32C RCPTarget::GetLocalizable(char (392 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8224(1); mfspr 0,8; stmw 29,0x2014(1); stw 0,0x2024(1); addi 29,1,8; mr 30,4; mr 31,3; li 4,0; li 5,8192; mr 3,29; crxor 6,6,6; bl _s801DE32C_0; lis 4,-32705; mr 3,30; addi 4,4,21108; li 5,13; bl _s801DE32C_1; cmpwi 3,0; bne 2f; addi 3,30,13; bl _s801DE32C_2; cmplwi 3,2; bgt 0f; lwz 0,0x134(31); lwz 9,0x128(31); add 3,0,3; cmplw 3,9; blt 1f; 0:; li 3,0; b 6f; 1:; addi 3,3,1; mr 4,29; bl _s801DE32C_3; b 5f; 2:; lis 4,-32705; mr 3,30; addi 4,4,21124; li 5,14; bl _s801DE32C_4; cmpwi 3,0; bne 3f; addi 3,30,14; bl _s801DE32C_5; cmplwi 3,2; bgt 0b; lwz 0,0x134(31); lwz 9,0x128(31); add 0,0,3; cmplw 0,9; bge 0b; mulli 0,0,20; lwz 3,0x124(31); add 3,3,0; bl _s801DE32C_6; mr. 4,3; li 3,0; beq 6f; b 4f; 3:; lis 3,-32705; mr 4,30; addi 3,3,20876; bl _s801DE32C_7; cmpwi 3,0; bne 0b; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,21140; addi 3,1,8200; crxor 6,6,6; bl _s801DE32C_8; lwz 9,0x2008(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,29; bl _s801DE32C_9; 5:; addi 3,1,8; bl _s801DE32C_10; addi 3,1,8; bl _s801DE32C_11; addi 3,1,8; bl _s801DE32C_12; addi 3,1,8; bl _s801DE32C_13; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801DE32C_14; mr 30,3; addi 4,1,8; bl _s801DE32C_15; mr 3,30; 6:; lwz 0,0x2024(1); mtspr 8,0; lmw 29,0x2014(1); addi 1,1,8224"

extern "C" void _s801DE32C_0();
extern "C" void _s801DE32C_1();
extern "C" void _s801DE32C_2();
extern "C" void _s801DE32C_3();
extern "C" void _s801DE32C_4();
extern "C" void _s801DE32C_5();
extern "C" void _s801DE32C_6();
extern "C" void _s801DE32C_7();
extern "C" void _s801DE32C_8();
extern "C" void _s801DE32C_9();
extern "C" void _s801DE32C_10();
extern "C" void _s801DE32C_11();
extern "C" void _s801DE32C_12();
extern "C" void _s801DE32C_13();
extern "C" void _s801DE32C_14();
extern "C" void _s801DE32C_15();

struct RCPTarget {
    void GetLocalizable();
};

void RCPTarget::GetLocalizable() {
}
