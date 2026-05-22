// 0x80269524 AptAddCustomSavedInput(void (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 0,-27608(13); mr 29,3; mr 31,4; cmpwi 0,0; beq 0f; lis 30,-32694; addi 9,1,8; addi 30,30,-16288; lwz 11,-23012(13); lwz 10,0x18(30); mr 3,9; li 4,8; li 0,7; mtspr 8,10; stw 11,0x8(1); sth 0,0x4(9); sth 31,0x6(9); blrl; lwz 0,0x18(30); mr 3,29; mr 4,31; mtspr 8,0; blrl; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void f_80269524() {}
