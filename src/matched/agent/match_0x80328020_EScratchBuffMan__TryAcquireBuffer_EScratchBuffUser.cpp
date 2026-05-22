// 0x80328020 EScratchBuffMan::TryAcquireBuffer(EScratchBuffUser (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x8(30); mr 29,5; mr 28,6; cmpw 31,0; bne 0f; lwz 9,0x0(31); li 5,0; lwz 4,0xc(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x8(30); cmpwi 0,0; beq 1f; lwz 9,0x0(31); li 4,0; li 5,2; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 1:; stw 29,0x0(30); li 5,1; stw 28,0x4(30); stw 31,0x8(30); lwz 4,0xc(30); lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void f_80328020() {}
