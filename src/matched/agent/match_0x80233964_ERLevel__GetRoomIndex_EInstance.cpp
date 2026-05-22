// 0x80233964 ERLevel::GetRoomIndex(EInstance (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); lwz 0,0x1c(4); mr 31,3; addi 5,1,8; addi 6,1,10; cmpwi 0,0; beq 0f; lwz 3,0x28(4); mtspr 8,0; li 4,0; blrl; b 1f; 0:; sth 0,0x8(1); sth 0,0xa(1); 1:; lha 3,0xa(1); addis 9,31,3; cmpwi 3,0; blt 2f; lwz 0,-23884(9); cmpw 3,0; blt 3f; 2:; lwz 3,-23884(9); 3:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void f_80233964() {}
