// 0x80200A28 RELTarget::GetVariable(char (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; li 3,128; bl _s80200A28_0; mr 29,3; li 0,0; stb 0,0x0(29); lbz 9,0x0(31); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-18372; bl _s80200A28_1; cmpwi 3,0; bne 1f; lis 9,-32704; addi 11,9,-30832; lwz 10,-30832(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 9f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-18360; bl _s80200A28_2; cmpwi 3,0; bne 2f; lis 4,-32704; lwz 5,0x88(30); b 5f; 2:; lis 3,-32704; mr 4,31; addi 3,3,-18344; li 5,14; bl _s80200A28_3; cmpwi 3,0; bne 3f; addi 3,31,14; bl _s80200A28_4; lwz 0,0x8c(30); mulli 0,0,6; add 4,3,0; mr 3,30; bl _s80200A28_5; b 4f; 3:; lis 3,-32704; mr 4,31; addi 3,3,-18328; li 5,15; bl _s80200A28_6; cmpwi 3,0; bne 6f; addi 3,31,15; bl _s80200A28_7; lwz 0,0x8c(30); mulli 0,0,6; add 4,3,0; mr 3,30; bl _s80200A28_8; 4:; lis 4,-32704; mr 5,3; 5:; addi 4,4,-30836; mr 3,29; crxor 6,6,6; bl _s80200A28_9; b 9f; 6:; lis 3,-32704; mr 4,31; addi 3,3,-18312; li 5,14; bl _s80200A28_10; cmpwi 3,0; bne 9f; addi 3,31,14; bl _s80200A28_11; lwz 0,0x8c(30); mulli 0,0,6; add 4,3,0; mr 3,30; bl _s80200A28_12; cmpwi 3,0; li 0,1; bne 7f; li 0,0; 7:; cmpwi 0,0; li 5,0; beq 8f; li 5,1; 8:; lis 4,-32704; mr 3,29; addi 4,4,-30836; crxor 6,6,6; bl _s80200A28_13; 9:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80200A28_0();
extern "C" void _s80200A28_1();
extern "C" void _s80200A28_2();
extern "C" void _s80200A28_3();
extern "C" void _s80200A28_4();
extern "C" void _s80200A28_5();
extern "C" void _s80200A28_6();
extern "C" void _s80200A28_7();
extern "C" void _s80200A28_8();
extern "C" void _s80200A28_9();
extern "C" void _s80200A28_10();
extern "C" void _s80200A28_11();
extern "C" void _s80200A28_12();
extern "C" void _s80200A28_13();

struct RELTarget {
    void GetVariable();
};

void RELTarget::GetVariable() {
}
