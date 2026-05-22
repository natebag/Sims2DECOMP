// 0x8007D808 timeGetTime(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,-24664(13); cmpwi 0,0; beq 0f; lwz 11,-26532(13); lis 4,-32696; addi 4,4,22528; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lis 9,-32707; lfs f0,0x68c0(9); fmuls f1,f1,f0; fctiwz f13,f1; stfd f13,0x8(1); lwz 3,0xc(1); b 1f; 0:; lwz 11,-26532(13); lis 4,-32696; addi 4,4,22528; lwz 9,0x0(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; li 3,0; stw 0,-24664(13); 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void f_8007D808() {}
