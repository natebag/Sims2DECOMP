// 0x80242540 scalbnf (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); fmr f2,f1; fmr f0,f2; stfs f0,0x8(1); lwz 0,0x8(1); mr 11,0; rlwinm 9,11,9,24,31; cmpwi 9,0; bne 0f; rlwinm. 0,11,0,1,31; beq 7f; lfs f0,-28008(13); fmuls f2,f2,f0; fmr f0,f2; stfs f0,0x8(1); lwz 0,0x8(1); mr 11,0; rlwinm 9,11,9,24,31; lis 0,-1; addi 9,9,-25; ori 0,0,15536; cmpw 3,0; bge 0f; lfs f1,-28004(13); b 6f; 0:; cmpwi 9,255; bne 1f; fadds f1,f2,f2; b 7f; 1:; add 9,9,3; cmpwi 9,254; bgt 3f; cmpwi 9,0; ble 2f; rlwinm 9,9,23,0,8; rlwinm 0,11,0,9,0; or 0,0,9; stw 0,0x8(1); lfs f2,0x8(1); fmr f1,f2; b 7f; 2:; cmpwi 9,-25; bgt 5f; li 0,0; ori 0,0,50000; cmpw 3,0; ble 4f; 3:; lfs f1,-28000(13); bl _s80242540_0; lfs f0,-28000(13); fmuls f1,f1,f0; b 7f; 4:; lfs f1,-28004(13); bl _s80242540_1; lfs f0,-28004(13); fmuls f1,f1,f0; b 7f; 5:; addi 9,9,25; rlwinm 0,11,0,9,0; rlwinm 9,9,23,0,8; or 0,0,9; stw 0,0x8(1); lfs f2,0x8(1); lfs f1,-27996(13); 6:; fmuls f1,f2,f1; 7:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80242540_0();
extern "C" void _s80242540_1();
extern "C" void f_80242540() {}
