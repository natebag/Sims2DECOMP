// 0x80325BC0 EResourceManager::GetArchiveFile(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 31,3; lwz 0,0x50(31); cmpwi 0,0; bne 4f; lis 28,-32702; lis 27,-32693; 0:; stw 31,0x8(1); li 4,-1; li 29,0; lwz 9,0x0(31); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x54(31); cmpwi 0,0; beq 1f; li 29,1; 1:; lis 3,-32694; lis 30,-32694; addi 3,3,-10620; bl _s80325BC0_0; cmpwi 3,0; beq 2f; addi 3,30,-10620; bl _s80325BC0_1; cmpwi 3,0; beq 2f; lwz 0,0x54(31); cmpwi 0,0; bne 2f; lwz 4,0x44(31); addi 3,27,6104; bl _s80325BC0_2; cmpwi 3,0; beq 2f; lwz 5,0x44(31); addi 3,30,-10620; mr 8,29; addi 4,31,80; addi 6,28,4072; li 7,0; li 9,0; bl _s80325BC0_3; b 3f; 2:; lwz 5,0x44(31); addi 3,30,-10620; mr 8,29; addi 4,31,80; addi 6,28,4072; lis 7,-32768; li 9,0; bl _s80325BC0_4; 3:; lwz 11,0x8(1); lwz 9,0x0(11); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x50(31); cmpwi 0,0; beq 0b; 4:; lwz 3,0x50(31); lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s80325BC0_0();
extern "C" void _s80325BC0_1();
extern "C" void _s80325BC0_2();
extern "C" void _s80325BC0_3();
extern "C" void _s80325BC0_4();
extern "C" void f_80325BC0() {}
