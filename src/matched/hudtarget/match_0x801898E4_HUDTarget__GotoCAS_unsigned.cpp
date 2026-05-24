// 0x801898E4 HUDTarget::GotoCAS(unsigned (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); mr 31,3; li 0,3; lbz 9,0xe8(31); mr 30,4; mr 29,5; mr 28,6; mr 27,7; stb 0,0x100(31); cmpwi 9,2; beq 0f; bl _s801898E4_0; mr 3,31; li 4,0; bl _s801898E4_1; mr 3,31; li 4,1; bl _s801898E4_2; mr 3,31; li 4,0; bl _s801898E4_3; mr 3,31; li 4,1; bl _s801898E4_4; mr 3,31; bl _s801898E4_5; 0:; lis 3,-32705; mr 4,30; addi 3,3,-19408; bl _s801898E4_6; lis 3,-32705; mr 4,29; addi 3,3,-19396; bl _s801898E4_7; lis 3,-32705; mr 4,28; addi 3,3,-19380; bl _s801898E4_8; lis 3,-32705; mr 4,27; addi 3,3,-19364; bl _s801898E4_9; lis 4,-32705; mr 5,30; addi 4,4,-19956; addi 3,1,8; crxor 6,6,6; bl _s801898E4_10; lis 4,-32705; lwz 3,-25136(13); addi 4,4,-19348; li 5,0; li 6,0; li 7,1; addi 8,1,8; crxor 6,6,6; bl _s801898E4_11; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s801898E4_0();
extern "C" void _s801898E4_1();
extern "C" void _s801898E4_2();
extern "C" void _s801898E4_3();
extern "C" void _s801898E4_4();
extern "C" void _s801898E4_5();
extern "C" void _s801898E4_6();
extern "C" void _s801898E4_7();
extern "C" void _s801898E4_8();
extern "C" void _s801898E4_9();
extern "C" void _s801898E4_10();
extern "C" void _s801898E4_11();

struct HUDTarget {
    void GotoCAS();
};

void HUDTarget::GotoCAS() {
}
