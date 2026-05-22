// 0x80014450 AwarenessManager::getAwarenessSkillID(int, (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 0,4; li 4,0; cmpwi 0,2; stw 4,0x0(6); bne 10f; cmpwi 5,3; beq 4f; bgt 0f; cmpwi 5,0; beq 1f; ble 9f; cmpwi 5,1; beq 2f; cmpwi 5,2; beq 3f; b 9f; 0:; cmpwi 5,5; beq 6f; blt 5f; cmpwi 5,6; beq 7f; cmpwi 5,7; beq 8f; b 9f; 1:; li 4,309; b 9f; 2:; li 4,311; b 9f; 3:; li 4,312; b 9f; 4:; li 4,314; b 9f; 5:; li 4,308; b 9f; 6:; li 4,313; b 9f; 7:; li 4,307; b 9f; 8:; li 4,310; 9:; lwz 3,0x34(3); mr 5,6; bl _s80014450_0; b 21f; 10:; cmpwi 0,3; bne 21f; cmpwi 5,3; beq 15f; bgt 11f; cmpwi 5,0; beq 12f; ble 20f; cmpwi 5,1; beq 13f; cmpwi 5,2; beq 14f; b 20f; 11:; cmpwi 5,5; beq 17f; blt 16f; cmpwi 5,6; beq 18f; cmpwi 5,7; beq 19f; b 20f; 12:; li 4,309; b 20f; 13:; li 4,311; b 20f; 14:; li 4,312; b 20f; 15:; li 4,314; b 20f; 16:; li 4,308; b 20f; 17:; li 4,313; b 20f; 18:; li 4,307; b 20f; 19:; li 4,310; 20:; lwz 3,0x34(3); mr 5,6; bl _s80014450_1; 21:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80014450_0();
extern "C" void _s80014450_1();
extern "C" void f_80014450() {}
