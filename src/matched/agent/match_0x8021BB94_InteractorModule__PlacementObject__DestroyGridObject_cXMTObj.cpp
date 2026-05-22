// 0x8021BB94 InteractorModule::PlacementObject::DestroyGridObject(cXMTObjectImpl (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,4; mr 31,3; lwz 9,0x0(28); cmpwi 9,0; beq 2f; lwz 9,0x0(9); lwz 29,-21484(13); lwz 11,0x4(9); lwz 30,0x0(29); lwz 9,0x4(11); lha 0,0x58(30); lha 3,0x328(9); addi 30,30,88; lwz 9,0x32c(9); add 29,29,0; add 3,11,3; mtspr 8,9; blrl; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; lwz 11,0x14(31); addi 3,31,20; lwz 0,0x4(3); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,6; cmpw 9,0; bne 0b; 1:; stw 11,0x4(3); li 0,0; stw 0,0x0(28); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_8021BB94() {}
