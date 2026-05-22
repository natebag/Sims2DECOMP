// 0x80267624 __AICallbackStackSwitch (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; lis 5,-32688; addi 5,5,-308; stw 1,0x0(5); lis 5,-32688; addi 5,5,-312; lwz 1,0x0(5); addi 1,1,-8; mtspr 8,31; blrl; lis 5,-32688; addi 5,5,-308; lwz 1,0x0(5); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void f_80267624() {}
