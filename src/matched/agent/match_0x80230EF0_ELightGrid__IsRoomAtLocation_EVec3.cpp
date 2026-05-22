// 0x80230EF0 ELightGrid::IsRoomAtLocation(EVec3 (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32704; lfs f0,0x0(4); lfs f10,-3444(9); lfs f13,0x4(4); fadds f0,f0,f10; mr 11,9; fctiwz f12,f0; stfd f12,0x8(1); fadds f13,f13,f10; lwz 9,0xc(1); fctiwz f11,f13; stfd f11,0x8(1); cmplwi 9,62; lwz 0,0xc(1); bgt 2f; cmpwi 0,0; blt 2f; cmpwi 0,62; bgt 2f; mulli 9,9,2268; li 10,4; mtspr 9,10; li 11,0; mulli 0,0,36; addi 9,9,27972; add 9,3,9; add 3,9,0; 0:; lbzx 0,3,11; extsb 0,0; cmpw 0,5; bne 1f; li 3,1; b 3f; 1:; addi 11,11,1; bdnz 0b; 2:; li 3,0; 3:; addi 1,1,16"
extern "C" void f_80230EF0() {}
