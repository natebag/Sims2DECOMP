// 0x80239A60 EmitterSpr3dProcessCB(void (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0xb4(3); cmpwi 0,0; bne 0f; lwz 11,-28384(13); lwz 4,-28388(13); lwz 9,0x70(11); lwz 0,0x294(9); lha 3,0x290(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-28384(13); li 4,1; li 5,2; li 6,0; lwz 9,0x70(11); li 7,0; lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 10,-28384(13); lis 11,-32704; lwz 4,-26704(13); li 5,0; lwz 9,0x70(10); addi 4,4,160; lfs f1,-1868(11); lha 3,0xf8(9); lwz 0,0xfc(9); add 3,10,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80239A60() {}
