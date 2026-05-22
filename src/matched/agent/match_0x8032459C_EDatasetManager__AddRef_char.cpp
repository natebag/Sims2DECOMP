// 0x8032459C EDatasetManager::AddRef(char (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8032459C_0; lwz 0,-26632(13); li 3,1; cmpwi 0,0; beq 0f; mr 3,31; mr 4,30; li 5,0; li 6,0; bl _s8032459C_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8032459C_0();
extern "C" void _s8032459C_1();
extern "C" void f_8032459C() {}
