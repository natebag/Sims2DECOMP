// 0x800DFA9C cXObjectImpl::Turn(int) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr. 29,4; beq 1f; addi 25,31,40; li 4,23; mr 3,25; bl _s800DFA9C_0; lha 0,0x0(3); cmpwi 0,0; beq 1f; li 4,1; mr 3,25; bl _s800DFA9C_1; lha 26,0x0(3); li 4,1; mr 3,25; bl _s800DFA9C_2; mr 30,3; li 4,23; mr 3,25; bl _s800DFA9C_3; lha 0,0x0(3); li 4,1; lhz 5,0x0(30); mr 3,25; mullw 0,0,29; add 5,5,0; rlwinm 5,5,0,29,31; bl _s800DFA9C_4; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x480(9); lwz 0,0x484(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lis 28,-32702; lis 27,-32702; rlwinm 0,26,2,0,29; addi 28,28,17152; addi 27,27,17188; lwz 4,0x6c(31); lwz 5,0x68(31); lwzx 9,27,0; srawi 4,4,4; lwzx 11,28,0; srawi 5,5,4; lwz 6,0x80(31); add 5,5,9; lwz 3,0x58(31); add 4,4,11; bl _s800DFA9C_5; lwz 30,0x6c(31); li 4,1; lwz 26,0x58(31); mr 3,25; srawi 30,30,4; bl _s800DFA9C_6; lha 0,0x0(3); li 4,1; lwz 29,0x68(31); mr 3,25; rlwinm 0,0,2,0,29; lwzx 9,28,0; srawi 29,29,4; add 30,30,9; bl _s800DFA9C_7; lha 0,0x0(3); mr 4,30; lwz 6,0x80(31); mr 3,26; rlwinm 0,0,2,0,29; lwzx 5,27,0; add 5,29,5; bl _s800DFA9C_8; 0:; mr 3,31; bl _s800DFA9C_9; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800DFA9C_0();
extern "C" void _s800DFA9C_1();
extern "C" void _s800DFA9C_2();
extern "C" void _s800DFA9C_3();
extern "C" void _s800DFA9C_4();
extern "C" void _s800DFA9C_5();
extern "C" void _s800DFA9C_6();
extern "C" void _s800DFA9C_7();
extern "C" void _s800DFA9C_8();
extern "C" void _s800DFA9C_9();

struct cXObjectImpl {
    void Turn();
};

void cXObjectImpl::Turn() {
}
