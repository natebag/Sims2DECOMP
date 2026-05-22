// 0x802C95F4 EMat4::Transpose(EMat4 (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 8,3; li 11,0; mr 3,4; 0:; rlwinm 0,11,4,0,27; rlwinm 9,11,2,0,29; addi 10,11,1; add 9,9,3; add 11,0,8; li 0,4; mtspr 9,0; 1:; lfs f0,0x0(9); addi 9,9,16; stfs f0,0x0(11); addi 11,11,4; bdnz 1b; mr 11,10; cmpwi 11,3; ble 0b"
extern "C" void f_802C95F4() {}
