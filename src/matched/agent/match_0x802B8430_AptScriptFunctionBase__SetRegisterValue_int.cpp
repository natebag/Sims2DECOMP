// 0x802B8430 AptScriptFunctionBase::SetRegisterValue(int, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 0,-26968(13); addi 11,3,1; mr 10,4; cmpw 11,0; ble 0f; stw 11,-26968(13); 0:; lwz 11,-26972(13); rlwinm 9,3,2,0,29; lis 30,-32703; lis 29,-32703; lwzx 28,9,11; addi 4,30,27204; stwx 10,9,11; addi 5,29,26724; li 6,729; lwz 9,0x8(10); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x8(28); addi 4,30,27204; addi 5,29,26724; li 6,730; lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_802B8430() {}
