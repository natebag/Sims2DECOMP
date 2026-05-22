// 0x8035A86C EConfig::SetBool(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-144(1); mfspr 0,8; stmw 30,0x88(1); stw 0,0x94(1); cmpwi 5,0; mr 31,3; mr 30,4; li 5,48; beq 0f; li 5,49; 0:; lis 4,-32702; addi 3,1,8; addi 4,4,11452; crxor 6,6,6; bl _s8035A86C_0; mr 3,31; mr 4,30; addi 5,1,8; bl _s8035A86C_1; lwz 0,0x94(1); mtspr 8,0; lmw 30,0x88(1); addi 1,1,144"
extern "C" void _s8035A86C_0();
extern "C" void _s8035A86C_1();
extern "C" void f_8035A86C() {}
