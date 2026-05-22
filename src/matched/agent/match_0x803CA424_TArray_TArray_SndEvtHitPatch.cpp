// 0x803CA424 TArray<TArray<SndEvtHitPatch, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr 30,4; addi 31,5,-1; cmpwi 5,0; beq 1f; 0:; mr 3,29; mr 4,30; bl _s803CA424_0; addi 29,29,12; cmpwi 31,0; addi 30,30,12; addi 31,31,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803CA424_0();
extern "C" void f_803CA424() {}
