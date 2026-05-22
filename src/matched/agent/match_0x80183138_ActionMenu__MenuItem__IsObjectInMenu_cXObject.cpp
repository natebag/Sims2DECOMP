// 0x80183138 ActionMenu::MenuItem::IsObjectInMenu(cXObject (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x0(31); cmpw 0,30; li 3,1; beq 2f; lwz 3,0x60(31); cmpwi 3,0; beq 0f; mr 4,30; bl _s80183138_0; cmpwi 3,0; li 3,1; bne 2f; 0:; lwz 3,0x5c(31); cmpwi 3,0; beq 1f; mr 4,30; bl _s80183138_1; cmpwi 3,0; li 3,1; bne 2f; 1:; li 3,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80183138_0();
extern "C" void _s80183138_1();
extern "C" void f_80183138() {}
