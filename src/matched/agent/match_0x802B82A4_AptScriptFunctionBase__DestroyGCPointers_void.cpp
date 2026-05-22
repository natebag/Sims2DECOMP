// 0x802B82A4 AptScriptFunctionBase::DestroyGCPointers(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lwz 11,0x2c(31); cmpwi 11,0; beq 0f; lwz 9,0x8(11); lis 4,-32703; lis 5,-32703; addi 4,4,27080; lha 3,0x10(9); addi 5,5,26724; lwz 0,0x14(9); li 6,574; add 3,11,3; mtspr 8,0; blrl; 0:; li 30,0; lwz 11,0x24(31); stw 30,0x2c(31); lis 29,-32703; lis 28,-32703; addi 4,29,27080; lwz 9,0x8(11); addi 5,28,26724; li 6,576; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 3,0x28(31); stw 30,0x24(31); bl _s802B82A4_0; lwz 11,0x28(31); addi 4,29,27080; addi 5,28,26724; li 6,590; lwz 9,0x8(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x28(31); mr 3,31; bl _s802B82A4_1; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802B82A4_0();
extern "C" void _s802B82A4_1();
extern "C" void f_802B82A4() {}
