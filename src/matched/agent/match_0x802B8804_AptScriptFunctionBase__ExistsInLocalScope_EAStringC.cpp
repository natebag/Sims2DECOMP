// 0x802B8804 AptScriptFunctionBase::ExistsInLocalScope(EAStringC (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-26960(13); cmpwi 9,0; bne 0f; lwz 3,0x2c(3); cmpwi 3,0; addi 3,3,12; bne 1f; li 3,0; b 2f; 0:; addi 3,9,12; 1:; bl _s802B8804_0; cmpwi 3,0; li 3,1; bne 2f; li 3,0; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802B8804_0();
extern "C" void f_802B8804() {}
