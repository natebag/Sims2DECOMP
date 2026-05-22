// 0x8035A828 EConfig::GetInt(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; li 5,0; bl _s8035A828_0; mr. 0,3; mr 3,30; beq 0f; mr 3,0; bl _s8035A828_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035A828_0();
extern "C" void _s8035A828_1();
extern "C" void f_8035A828() {}
