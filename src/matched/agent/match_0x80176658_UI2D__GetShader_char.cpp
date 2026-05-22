// 0x80176658 UI2D::GetShader(char (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s80176658_0; mr. 31,3; beq 6f; lwz 0,0x1c(31); cmpwi 0,0; bne 0f; lwz 0,0x18(31); cmpwi 0,0; bne 2f; 0:; lis 3,-32692; lwz 4,0xc(31); addi 3,3,-17444; bl _s80176658_1; stw 3,0x18(31); cmpwi 3,0; beq 6f; lwz 0,0x3c(3); cmpwi 0,2; bne 1f; lbz 4,0x13(31); bl _s80176658_2; li 0,1; stw 3,0x28(31); stw 0,0x20(31); 1:; li 0,0; stw 0,0x1c(31); 2:; lwz 0,0x20(31); cmpwi 0,0; beq 4f; lwz 0,0x28(31); cmpwi 0,0; bne 3f; lwz 3,0x18(31); lbz 4,0x13(31); bl _s80176658_3; stw 3,0x28(31); b 6f; 3:; lwz 11,0x18(31); lis 9,-32706; lfs f1,0x231c(9); li 4,0; lwz 9,0x0(11); li 5,0; li 6,0; lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x18(31); lwz 0,0x58(3); rlwinm 0,0,30,31,31; cmpwi 0,0; stw 0,0x20(31); bne 6f; lbz 4,0x13(31); bl _s80176658_4; mr 4,3; stw 4,0x24(31); cmpwi 4,0; beq 4f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s80176658_5; 4:; lwz 3,0x18(31); lwz 0,0x3c(3); cmpwi 0,2; bne 5f; lbz 4,0x13(31); bl _s80176658_6; cmpwi 3,0; beq 6f; lwz 11,0x18(31); lis 9,-32706; lfs f1,0x231c(9); li 4,0; lwz 9,0x0(11); li 5,0; li 6,0; lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x18(31); lwz 11,0x10(31); lbz 0,0x50(9); cmpw 0,11; li 3,0; bne 7f; 5:; lwz 3,0x18(31); b 7f; 6:; li 3,0; 7:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80176658_0();
extern "C" void _s80176658_1();
extern "C" void _s80176658_2();
extern "C" void _s80176658_3();
extern "C" void _s80176658_4();
extern "C" void _s80176658_5();
extern "C" void _s80176658_6();
extern "C" void f_80176658() {}
