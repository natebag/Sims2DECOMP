// 0x80230E28 ELightGrid::GetLightsAtLocation(EVec3 (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32704; lfs f0,0x0(4); lfs f10,-3448(9); mr 10,3; lfs f13,0x4(4); fadds f0,f0,f10; mr 11,9; fctiwz f12,f0; stfd f12,0x8(1); fadds f13,f13,f10; lwz 9,0xc(1); fctiwz f11,f13; stfd f11,0x8(1); cmpwi 9,0; lwz 0,0xc(1); blt 0f; cmpwi 9,62; ble 1f; li 9,62; b 1f; 0:; li 9,0; 1:; cmpwi 0,0; blt 3f; cmpwi 0,62; ble 4f; li 0,62; b 4f; 2:; rlwinm 3,3,3,0,28; addi 3,3,4; add 3,9,3; b 6f; 3:; li 0,0; 4:; mulli 9,9,2268; li 11,4; mtspr 9,11; li 3,0; mulli 0,0,36; addi 9,9,27972; add 9,10,9; add 9,9,0; 5:; lbzx 0,9,3; extsb 0,0; cmpw 0,5; beq 2b; addi 3,3,1; bdnz 5b; addi 3,13,-23772; 6:; addi 1,1,16"
extern "C" void f_80230E28() {}
