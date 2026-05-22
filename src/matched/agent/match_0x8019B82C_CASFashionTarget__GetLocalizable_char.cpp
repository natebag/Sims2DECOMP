// 0x8019B82C CASFashionTarget::GetLocalizable(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8216(1); mfspr 0,8; stmw 30,0x2010(1); stw 0,0x201c(1); lbz 9,0x0(4); li 0,0; sth 0,0x8(1); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 4,4,1; 0:; lis 3,-32705; addi 3,3,-14136; bl _s8019B82C_0; cmpwi 3,0; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14116; addi 3,1,8200; crxor 6,6,6; bl _s8019B82C_1; lwz 9,0x2008(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; addi 3,1,8; bl _s8019B82C_2; b 3f; 2:; li 3,0; b 4f; 3:; addi 3,1,8; bl _s8019B82C_3; addi 3,1,8; bl _s8019B82C_4; addi 3,1,8; bl _s8019B82C_5; addi 3,1,8; bl _s8019B82C_6; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s8019B82C_7; mr 30,3; addi 4,1,8; bl _s8019B82C_8; mr 3,30; 4:; lwz 0,0x201c(1); mtspr 8,0; lmw 30,0x2010(1); addi 1,1,8216"
extern "C" void _s8019B82C_0();
extern "C" void _s8019B82C_1();
extern "C" void _s8019B82C_2();
extern "C" void _s8019B82C_3();
extern "C" void _s8019B82C_4();
extern "C" void _s8019B82C_5();
extern "C" void _s8019B82C_6();
extern "C" void _s8019B82C_7();
extern "C" void _s8019B82C_8();
extern "C" void f_8019B82C() {}
