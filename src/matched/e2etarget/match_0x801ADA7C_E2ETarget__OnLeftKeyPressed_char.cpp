// 0x801ADA7C E2ETarget::OnLeftKeyPressed(char (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stmw 30,0x108(1); stw 0,0x114(1); mr 31,3; mr 30,4; lwz 0,0xa8(31); cmpwi 0,2; bne 0f; bl _s801ADA7C_0; lis 9,-32705; lis 4,-32705; lfs f0,-1736(9); addi 4,4,-2240; addi 3,1,8; fsubs f1,f1,f0; creqv 6,6,6; bl _s801ADA7C_1; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_2; b 6f; 0:; cmpwi 0,3; bne 1f; bl _s801ADA7C_3; lis 9,-32705; lis 4,-32705; lfs f0,-1732(9); addi 4,4,-2240; addi 3,1,8; fsubs f1,f1,f0; creqv 6,6,6; bl _s801ADA7C_4; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_5; b 6f; 1:; cmpwi 0,4; bne 2f; bl _s801ADA7C_6; lis 9,-32705; lis 4,-32705; lfs f0,-1732(9); addi 4,4,-2240; addi 3,1,8; fsubs f1,f1,f0; creqv 6,6,6; bl _s801ADA7C_7; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_8; b 6f; 2:; cmpwi 0,5; bne 3f; bl _s801ADA7C_9; lis 9,-32705; lis 4,-32705; lfs f0,-1732(9); addi 4,4,-2240; addi 3,1,8; fsubs f1,f1,f0; creqv 6,6,6; bl _s801ADA7C_10; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_11; b 6f; 3:; cmpwi 0,6; bne 4f; lwz 5,0xbc(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,-1; crxor 6,6,6; bl _s801ADA7C_12; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_13; b 6f; 4:; cmpwi 0,7; bne 5f; lwz 5,0xc4(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,-1; crxor 6,6,6; bl _s801ADA7C_14; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_15; b 6f; 5:; cmpwi 0,8; bne 6f; lwz 5,0xc0(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,-1; crxor 6,6,6; bl _s801ADA7C_16; mr 3,31; mr 4,30; addi 5,1,8; bl _s801ADA7C_17; 6:; lwz 0,0x114(1); mtspr 8,0; lmw 30,0x108(1); addi 1,1,272"

extern "C" void _s801ADA7C_0();
extern "C" void _s801ADA7C_1();
extern "C" void _s801ADA7C_2();
extern "C" void _s801ADA7C_3();
extern "C" void _s801ADA7C_4();
extern "C" void _s801ADA7C_5();
extern "C" void _s801ADA7C_6();
extern "C" void _s801ADA7C_7();
extern "C" void _s801ADA7C_8();
extern "C" void _s801ADA7C_9();
extern "C" void _s801ADA7C_10();
extern "C" void _s801ADA7C_11();
extern "C" void _s801ADA7C_12();
extern "C" void _s801ADA7C_13();
extern "C" void _s801ADA7C_14();
extern "C" void _s801ADA7C_15();
extern "C" void _s801ADA7C_16();
extern "C" void _s801ADA7C_17();

struct E2ETarget {
    void OnLeftKeyPressed();
};

void E2ETarget::OnLeftKeyPressed() {
}
