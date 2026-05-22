// 0x8029D1EC _pointInTri(float (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,3; li 8,0; mtspr 9,9; li 10,0; li 0,2; mr 11,3; 0:; lfs f13,0x4(11); rlwinm 0,0,3,0,28; add 9,3,0; fcmpu 0,f13,f2; bgt 1f; lfs f0,0x4(9); fmr f10,f0; fcmpu 0,f2,f0; blt 2f; 1:; lfs f0,0x4(9); fmr f10,f0; fcmpu 0,f0,f2; bgt 3f; fcmpu 0,f2,f13; cror 3,2,1; bso 3f; 2:; lfs f11,0x0(11); lfs f12,0x4(11); lfs f0,0x0(9); fsubs f13,f2,f12; fsubs f0,f0,f11; fmuls f0,f0,f13; fsubs f12,f10,f12; fdivs f0,f0,f12; fadds f0,f0,f11; fcmpu 0,f1,f0; cror 3,2,1; bso 3f; xori 8,8,1; 3:; mr 0,10; addi 11,11,8; addi 10,10,1; bdnz 0b; mr 3,8"
extern "C" float f_8029D1EC() {}
