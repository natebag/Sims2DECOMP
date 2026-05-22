// 0x8035A8CC EConfig::GetBool(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,5; li 5,0; bl _s8035A8CC_0; mr. 31,3; beq 1f; lis 4,-32702; mr 3,31; addi 4,4,11456; li 30,0; bl _s8035A8CC_1; cmpwi 3,0; beq 0f; lis 4,-32702; mr 3,31; addi 4,4,11464; bl _s8035A8CC_2; cmpwi 3,0; bne 1f; 0:; li 30,1; 1:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035A8CC_0();
extern "C" void _s8035A8CC_1();
extern "C" void _s8035A8CC_2();
extern "C" void f_8035A8CC() {}
