// 0x801A2BA4 ACTTarget::ReOrderActionQueue(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lwz 10,0xe4(3); li 7,0; cmpwi 10,0; beq 3f; addi 8,3,136; 0:; lwz 0,0x8(10); cmpwi 0,0; bne 2f; lwz 0,0xc(10); cmpw 0,7; beq 1f; stw 7,0xc(10); mr 11,9; lfs f0,-4(8); fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); stw 9,0x10(10); lfs f0,0x0(8); fctiwz f12,f0; stfd f12,0x8(1); lwz 11,0xc(1); stw 11,0x14(10); 1:; addi 7,7,1; addi 8,8,8; cmpwi 7,8; ble 2f; addi 8,3,200; li 7,8; 2:; lwz 10,0x44(10); cmpwi 10,0; bne 0b; 3:; addi 1,1,16"
extern "C" void f_801A2BA4() {}
