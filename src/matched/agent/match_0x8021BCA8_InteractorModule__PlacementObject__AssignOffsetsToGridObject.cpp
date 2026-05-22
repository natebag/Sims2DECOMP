// 0x8021BCA8 InteractorModule::PlacementObject::AssignOffsetsToGridObject(cXMTObjectImpl (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,5; mr. 30,4; beq 6f; cmpwi 31,0; beq 6f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; lwz 9,0x4(31); li 4,8; lwz 3,0x0(9); bl _s8021BCA8_0; mr 31,3; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; 0:; cmpwi 31,0; beq 1f; lwz 0,0x1c(31); stw 0,0x1c(30); lwz 9,0x20(31); stw 9,0x20(30); lwz 0,0x24(31); stw 0,0x24(30); 1:; lwz 3,0x8(31); cmpwi 3,0; beq 2f; lwz 11,0x4(3); li 4,8; lwz 9,0x0(11); lwz 3,0x0(9); bl _s8021BCA8_1; mr 31,3; b 3f; 2:; li 31,0; 3:; lwz 3,0x8(30); cmpwi 3,0; beq 4f; lwz 11,0x4(3); li 4,8; lwz 9,0x0(11); lwz 3,0x0(9); bl _s8021BCA8_2; mr 30,3; b 5f; 4:; li 30,0; 5:; cmpwi 30,0; bne 0b; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021BCA8_0();
extern "C" void _s8021BCA8_1();
extern "C" void _s8021BCA8_2();
extern "C" void f_8021BCA8() {}
