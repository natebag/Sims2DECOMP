// 0x80237918 ERLevel::UpdateFloorLighting(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addis 3,3,3; lwz 0,-23932(3); cmpwi 0,0; beq 2f; lwz 0,-23884(3); li 31,0; cmpw 31,0; bge 2f; mr 30,3; li 29,0; 0:; lwz 9,-23932(30); lwzx 11,29,9; cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,-23884(30); addi 31,31,1; addi 29,29,4; cmpw 31,0; blt 0b; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80237918() {}
