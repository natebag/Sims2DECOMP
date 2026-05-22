// 0x8030D77C TGAWriter::WriteFile(char (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,6; mr 28,5; li 0,0; addi 30,1,8; mr 5,4; lis 27,-32694; lis 6,-32702; stw 0,0x8(1); addi 6,6,500; addi 3,27,-10620; mr 4,30; li 7,2; lis 8,-32768; li 9,0; bl _s8030D77C_0; li 31,0; cmpwi 3,0; beq 0f; lwz 3,0x8(1); mr 4,28; mr 5,29; lwz 9,0x28(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; xor 31,3,29; subfic 0,31,0; adde 31,0,31; mr 4,30; addi 3,27,-10620; bl _s8030D77C_1; 0:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s8030D77C_0();
extern "C" void _s8030D77C_1();
extern "C" void f_8030D77C() {}
