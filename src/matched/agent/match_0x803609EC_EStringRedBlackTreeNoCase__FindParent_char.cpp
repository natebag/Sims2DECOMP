// 0x803609EC EStringRedBlackTreeNoCase::FindParent(char (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,0x8(3); lis 9,-32700; addi 9,9,11816; mr 30,4; li 31,0; cmpw 0,9; beq 3f; mr 29,9; 0:; mr 31,0; mr 4,30; addi 3,31,28; bl _s803609EC_0; cmpwi 3,0; ble 1f; lwz 0,0x0(31); b 2f; 1:; lwz 0,0x4(31); 2:; cmpw 0,29; bne 0b; 3:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803609EC_0();
extern "C" void f_803609EC() {}
