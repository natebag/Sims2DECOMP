// 0x801BBE20 INGTarget::get_mix_ing_name(unsigned (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 29,0x12c(1); stw 0,0x13c(1); mr 31,3; mr. 29,5; beq 0f; cmplwi 4,3; bgt 0f; rlwinm 9,4,3,0,28; addi 30,9,480; add 0,31,30; cmpwi 0,0; beq 0f; lwzx 9,31,30; cmpwi 9,0; bne 1f; 0:; li 3,0; b 4f; 1:; lwz 9,0x10(9); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,29; bl _s801BBE20_0; lwzx 9,31,30; addi 4,1,8; li 5,1; lha 3,0x2(9); bl _s801BBE20_1; lis 4,-32705; mr 3,29; addi 4,4,6544; bl _s801BBE20_2; addi 4,1,8; mr 3,29; bl _s801BBE20_3; mr 3,31; bl _s801BBE20_4; cmpwi 3,0; beq 3f; addi 30,1,264; lwz 3,0x454(31); mr 4,30; bl _s801BBE20_5; lis 4,-32705; mr 3,29; addi 4,4,6568; bl _s801BBE20_6; mr 3,29; mr 4,30; bl _s801BBE20_7; 3:; li 3,1; 4:; lwz 0,0x13c(1); mtspr 8,0; lmw 29,0x12c(1); addi 1,1,312"

extern "C" void _s801BBE20_0();
extern "C" void _s801BBE20_1();
extern "C" void _s801BBE20_2();
extern "C" void _s801BBE20_3();
extern "C" void _s801BBE20_4();
extern "C" void _s801BBE20_5();
extern "C" void _s801BBE20_6();
extern "C" void _s801BBE20_7();

struct INGTarget {
    void get_mix_ing_name();
};

void INGTarget::get_mix_ing_name() {
}
