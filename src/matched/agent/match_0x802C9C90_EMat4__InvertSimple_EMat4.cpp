// 0x802C9C90 EMat4::InvertSimple(EMat4 (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 6,4,48; addi 7,3,48; addi 8,3,16; addi 5,3,32; li 11,0; 0:; rlwinm 0,11,2,0,29; rlwinm 9,11,4,0,27; addi 10,11,1; add 9,9,4; add 11,0,3; li 0,3; mtspr 9,0; 1:; lfs f0,0x0(9); addi 9,9,4; stfs f0,0x0(11); addi 11,11,16; bdnz 1b; mr 11,10; cmpwi 11,2; ble 0b; li 0,3; mr 11,6; mtspr 9,0; mr 10,5; li 9,0; 2:; lfsx f0,9,8; lfs f12,0x4(11); lfsx f10,9,3; lfs f13,0x30(4); fmuls f12,f12,f0; lfsx f11,9,10; lfs f0,0x8(11); fmadds f13,f13,f10,f12; fnmadds f0,f0,f11,f13; stfsx f0,9,7; addi 9,9,4; bdnz 2b; lis 9,-32702; lfs f0,-7488(9); stfs f0,0x3c(3)"
extern "C" void f_802C9C90() {}
