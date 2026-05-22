// 0x800C6E44 cXMTObjectImpl::SetMultiObjectData(int, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 0,0xc(3); mr 29,4; mr 30,5; mr 31,3; cmpwi 0,0; beq 1f; mr 31,0; b 1f; 0:; lwz 10,0x0(31); mr 4,29; extsh 5,30; lwz 11,0x4(10); lwz 9,0x4(11); lha 3,0x1e8(9); lwz 0,0x1ec(9); add 3,11,3; mtspr 8,0; blrl; lwz 31,0x8(31); 1:; cmpwi 31,0; bne 0b; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_800C6E44() {}
