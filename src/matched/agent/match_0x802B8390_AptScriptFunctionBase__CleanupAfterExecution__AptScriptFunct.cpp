// 0x802B8390 AptScriptFunctionBase::CleanupAfterExecution(_AptScriptFunctionState (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-26960(13); mr 31,3; mr 30,4; cmpwi 11,0; beq 0f; lwz 9,0x8(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x0(3); lis 4,-32703; lwz 11,-26960(13); lis 5,-32703; sth 0,0x30(31); addi 4,4,27128; addi 5,5,26724; li 6,656; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x0(30); stw 0,-26960(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802B8390() {}
