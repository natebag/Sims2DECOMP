// 0x8038A96C GXSetMisc (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,2; beq 2f; bge 0f; cmpwi 3,0; beqlr; bge 1f; blr; 0:; cmpwi 3,4; bgelr; b 3f; 1:; lwz 5,-17720(13); li 0,1; sth 4,0x4(5); lhz 3,0x4(5); cntlzw 3,3; rlwinm 3,3,27,16,31; sth 3,0x0(5); sth 0,0x2(5); lhz 0,0x4(5); cmplwi 0,0; beqlr; lwz 0,0x5ac(5); ori 0,0,8; stw 0,0x5ac(5); blr; 2:; neg 4,4; lwz 3,-17720(13); addic 0,4,-1; subfe 0,0,4; stb 0,0x5a9(3); blr; 3:; neg 4,4; lwz 3,-17720(13); addic 0,4,-1; subfe 0,0,4; stb 0,0x5aa(3)"
extern "C" void f_8038A96C() {}
