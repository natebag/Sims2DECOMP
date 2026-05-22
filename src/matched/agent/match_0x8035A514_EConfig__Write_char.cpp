// 0x8035A514 EConfig::Write(char (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-4136(1); mfspr 0,8; stmw 26,0x1010(1); stw 0,0x102c(1); mr 28,3; addi 4,1,4104; lis 3,-32694; lwz 5,0x4(28); lis 6,-32702; mr 26,4; addi 3,3,-10620; addi 6,6,11428; lis 7,-32768; lis 8,-32768; li 9,0; bl _s8035A514_0; cmpwi 3,0; bne 0f; li 3,0; b 3f; 0:; lwz 31,0x8(28); cmpwi 31,0; beq 2f; lis 27,-32702; 1:; lwz 30,0x0(31); lwz 3,0x0(30); bl _s8035A514_1; mr 29,3; lwz 5,0x0(30); addi 4,27,11432; addi 3,1,8; crxor 6,6,6; bl _s8035A514_2; lwz 11,0x1008(1); addi 5,29,2; addi 4,1,8; lwz 9,0x28(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 2:; lis 3,-32694; mr 4,26; addi 3,3,-10620; bl _s8035A514_3; li 0,0; li 3,1; stw 0,0x0(28); 3:; lwz 0,0x102c(1); mtspr 8,0; lmw 26,0x1010(1); addi 1,1,4136"
extern "C" void _s8035A514_0();
extern "C" void _s8035A514_1();
extern "C" void _s8035A514_2();
extern "C" void _s8035A514_3();
extern "C" void f_8035A514() {}
