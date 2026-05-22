// 0x80078B74 CUnlockDisplay::SetDirectLight(float, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); cmpwi 4,3; bgt 1f; lwz 0,0x440(3); addi 9,4,1; cmpw 9,0; ble 0f; stw 9,0x440(3); 0:; stfs f1,0x8(1); addi 9,1,8; mulli 11,4,24; stfs f2,0x4(9); stfs f3,0x8(9); lwz 7,0x4(9); lwz 8,0x8(1); lwz 0,0x8(9); add 11,11,3; addi 10,11,864; stw 8,0x360(11); stw 0,0x8(10); stw 7,0x4(10); 1:; addi 1,1,24"
extern "C" void f_80078B74() {}
