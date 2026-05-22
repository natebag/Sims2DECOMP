// 0x801A055C CASRoommateTarget::GetButtonStateString(char (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 4,4; beqlr; lwz 9,0x84(3); li 0,4; mtspr 9,0; li 10,0; lwz 3,0x1c(9); li 11,0; 0:; mr 0,11; cmpwi 11,0; bge 1f; addi 0,11,3; 1:; rlwinm 0,0,0,0,29; lwz 9,0x1348(3); subf 0,0,11; srw 9,9,0; andi. 0,9,1; beq 2f; addi 10,10,1; 2:; addi 11,11,1; bdnz 0b; cmpwi 10,3; li 0,48; bgt 3f; li 0,49; 3:; stb 0,0x0(4); cmpwi 10,0; li 0,48; ble 4f; li 0,49; 4:; stb 0,0x1(4); li 0,48; ble 5f; li 0,49; 5:; stb 0,0x2(4); li 0,48; ble 6f; li 0,49; 6:; stb 0,0x3(4); li 0,0; stb 0,0x4(4)"
extern "C" void f_801A055C() {}
