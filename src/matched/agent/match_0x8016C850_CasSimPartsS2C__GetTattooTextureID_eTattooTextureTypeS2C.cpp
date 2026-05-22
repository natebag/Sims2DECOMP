// 0x8016C850 CasSimPartsS2C::GetTattooTextureID(eTattooTextureTypeS2C, (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-624(1); mfspr 0,8; stmw 29,0x264(1); stw 0,0x274(1); mr 30,3; mr 31,4; lwz 0,0x4(30); mr 29,5; li 3,0; cmpwi 0,0; beq 1f; mr 3,30; bl _s8016C850_0; cmplw 29,3; bge 0f; cmpwi 31,2; bgt 0f; cmpwi 31,0; blt 0f; mr 4,31; addi 5,1,8; mr 3,30; bl _s8016C850_1; addi 11,1,8; lwz 10,0x4(30); lbzx 9,11,29; mr 3,30; lwz 11,0x4(10); mulli 9,9,20; lwzx 4,11,9; bl _s8016C850_2; b 1f; 0:; li 3,0; 1:; lwz 0,0x274(1); mtspr 8,0; lmw 29,0x264(1); addi 1,1,624"
extern "C" void _s8016C850_0();
extern "C" void _s8016C850_1();
extern "C" void _s8016C850_2();
extern "C" void f_8016C850() {}
