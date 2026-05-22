// 0x80012F50 AwarenessManager::GetActiveMemoryCategory(cXObject (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,-1; mr 28,6; mr 30,5; stw 0,0x0(28); mr 29,3; stw 0,0x0(30); mr. 4,4; beq 0f; lwz 3,0x0(4); li 4,2; bl _s80012F50_0; mr 31,3; b 1f; 0:; li 31,0; 1:; cmpwi 31,0; beq 3f; lwz 11,0x34(29); mr 4,31; li 5,6; lwz 9,0x4(11); lha 3,0x390(9); lwz 0,0x394(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,-1; stw 3,0x0(30); bne 2f; lwz 11,0x34(29); mr 4,31; li 5,2; lwz 9,0x4(11); lha 3,0x390(9); lwz 0,0x394(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,-1; stw 3,0x0(30); beq 3f; 2:; lwz 3,0x34(29); mr 4,31; lwz 5,0x0(30); lwz 9,0x4(3); lha 0,0x380(9); lwz 9,0x384(9); add 3,3,0; mtspr 8,9; blrl; stw 3,0x0(28); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80012F50_0();
extern "C" void f_80012F50() {}
