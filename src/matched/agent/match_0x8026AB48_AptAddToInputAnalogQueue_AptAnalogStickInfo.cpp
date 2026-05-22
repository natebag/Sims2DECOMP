// 0x8026AB48 AptAddToInputAnalogQueue(AptAnalogStickInfo) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 0,0x1c(1); lwz 0,-22988(13); mr 7,3; cmpwi 0,0; beq 0f; lis 9,-32694; lwz 0,-16052(9); cmpwi 0,0; bne 0f; lwz 3,-23008(13); cmpwi 3,0; beq 0f; lwz 10,0x0(7); addi 9,1,8; lwz 8,0xc(7); mr 4,9; lwz 11,0x4(7); lwz 0,0x8(7); stw 10,0x8(1); stw 11,0x4(9); stw 0,0x8(9); stw 8,0xc(9); bl _s8026AB48_0; 0:; lwz 0,0x1c(1); mtspr 8,0; addi 1,1,24"
extern "C" void _s8026AB48_0();
extern "C" void f_8026AB48() {}
