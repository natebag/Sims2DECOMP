// 0x802F0D1C __static_initialization_and_destruction_0 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; ori 0,0,65535; cmpw 4,0; bnelr; cmpwi 3,0; beqlr; lis 9,-32702; lis 11,-32702; lfs f0,-4276(9); lfs f13,-4272(11); li 9,2; fmuls f0,f0,f13; stfs f0,-22724(13); 0:; addi 0,9,-1; li 9,64; mtspr 9,9; 1:; bdnz 1b; mr 9,0; cmpwi 9,-1; bne 0b"
extern "C" void f_802F0D1C() {}
