// 0x802B79D4 AptScriptFunctionBase::PopStaticData(void (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lwz 0,-26968(13); li 30,0; mr 29,3; cmpw 30,0; bge 1f; lis 27,-32703; lis 28,-32703; li 31,0; 0:; lwz 9,-26972(13); addi 4,27,26664; lwz 0,-22936(13); addi 5,28,26724; lwzx 11,31,9; li 6,206; stwx 0,31,9; addi 30,30,1; addi 31,31,4; lwz 9,0x8(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-26968(13); cmpw 30,0; blt 0b; 1:; lwz 0,-26972(13); stw 29,-26972(13); subf 0,29,0; srawi 0,0,2; stw 0,-26968(13); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_802B79D4() {}
