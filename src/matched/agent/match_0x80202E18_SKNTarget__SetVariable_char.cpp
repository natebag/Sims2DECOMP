// 0x80202E18 SKNTarget::SetVariable(char (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 9,0x0(31); mr 29,5; addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 31,31,1; 0:; lis 3,-32704; mr 4,31; addi 3,3,-17172; bl _s80202E18_0; cmpwi 3,0; bne 1f; mr 3,29; bl _s80202E18_1; mr 0,3; mulli 4,0,12; mr 3,30; stw 0,0x84(30); bl _s80202E18_2; b 2f; 1:; lis 3,-32704; mr 4,31; addi 3,3,-17160; bl _s80202E18_3; cmpwi 3,0; bne 2f; mr 3,29; bl _s80202E18_4; lwz 0,0x84(30); mr 4,3; stw 4,0x88(30); mr 3,30; mulli 0,0,12; add 4,0,4; bl _s80202E18_5; mr 5,3; lis 9,-32697; lwz 3,0x5bc4(9); cmpwi 3,0; beq 2f; lwz 4,0x90(30); bl _s80202E18_6; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80202E18_0();
extern "C" void _s80202E18_1();
extern "C" void _s80202E18_2();
extern "C" void _s80202E18_3();
extern "C" void _s80202E18_4();
extern "C" void _s80202E18_5();
extern "C" void _s80202E18_6();
extern "C" void f_80202E18() {}
