// 0x80306A08 pow2(int) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32702; mr. 3,3; lfs f1,-1384(9); neg 0,3; ble 0f; mr 0,3; 0:; mcrf cr7,cr0; cmpwi 0,0; ble 2f; mtspr 9,0; 1:; fadds f1,f1,f1; bdnz 1b; 2:; bgelr cr7; lis 9,-32702; lfs f0,-1384(9); fdivs f1,f0,f1"
extern "C" float f_80306A08() {}
