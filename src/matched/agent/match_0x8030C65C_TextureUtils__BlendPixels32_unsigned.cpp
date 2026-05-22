// 0x8030C65C TextureUtils::BlendPixels32(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 12,4,0,24,31; mr 6,3; cmpwi 12,0; beq 0f; cmpwi 12,255; beq 1f; b 2f; 0:; mr 3,6; blr; 1:; mr 3,4; blr; 2:; subfic 10,12,255; rlwinm 9,6,8,24,31; rlwinm 0,4,8,24,31; mullw 3,10,9; rlwinm 8,4,16,24,31; mullw 5,12,0; rlwinm 7,4,24,24,31; rlwinm 0,6,16,24,31; rlwinm 6,6,24,24,31; lis 9,-32640; ori 9,9,32897; add 11,5,3; mullw 5,12,8; mullw 3,10,0; mulhwu 11,11,9; add 0,5,3; mullw 5,12,7; rlwinm 11,11,17,0,7; mullw 3,10,6; mulhwu 0,0,9; add 3,5,3; mulhwu 3,3,9; rlwinm 0,0,9,8,15; ori 0,0,255; rlwinm 3,3,1,16,23; or 3,3,0; or 3,3,11"
extern "C" int f_8030C65C() {}
