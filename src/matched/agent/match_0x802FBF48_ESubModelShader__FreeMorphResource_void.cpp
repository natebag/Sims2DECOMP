// 0x802FBF48 ESubModelShader::FreeMorphResource(void) (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x68(31); cmpwi 0,0; beq 3f; lwz 0,0x6c(31); li 29,0; cmpw 29,0; bge 2f; li 28,0; li 30,0; 0:; lwz 9,0x68(31); add 9,30,9; lwz 4,0x8(9); cmpwi 4,0; beq 1f; mr 3,31; bl _s802FBF48_0; lwz 9,0x68(31); add 9,30,9; stw 28,0x8(9); 1:; lwz 0,0x6c(31); addi 29,29,1; addi 30,30,12; cmpw 29,0; blt 0b; 2:; lwz 4,0x68(31); mr 3,31; bl _s802FBF48_1; li 0,0; stw 0,0x68(31); 3:; li 0,0; stw 0,0x6c(31); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802FBF48_0();
extern "C" void _s802FBF48_1();
extern "C" void f_802FBF48() {}
