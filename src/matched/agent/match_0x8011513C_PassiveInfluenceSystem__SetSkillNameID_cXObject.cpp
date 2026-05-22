// 0x8011513C PassiveInfluenceSystem::SetSkillNameID(cXObject (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); lwz 9,0x4(3); lwz 0,0x0(9); mr 10,9; b 1f; 0:; stw 11,0x18(1); lwz 0,0x0(11); stw 11,0x10(1); 1:; stw 0,0x8(1); lwz 11,0x8(1); li 0,1; stw 10,0x10(1); cmpw cr7,11,10; bne cr7,2f; li 0,0; 2:; cmpwi 0,0; beq 3f; lwz 9,0x8(11); lwz 0,0x4(9); cmpw 0,4; bne 0b; 3:; mfcr 0; rlwinm 0,0,31,31,31; stw 10,0x10(1); cmpwi 0,0; bne 4f; lwz 9,0x8(11); li 3,1; stw 5,0x1c(9); b 5f; 4:; li 3,0; 5:; addi 1,1,32"
extern "C" void f_8011513C() {}
