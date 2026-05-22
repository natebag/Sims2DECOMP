// 0x80371C80 OSUTF16to32 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lhz 5,0x0(3); cmplwi 5,0; beq 0f; addi 3,3,2; 0:; cmplwi 5,55296; blt 1f; cmplwi 5,57343; ble 2f; 1:; mr 6,5; b 5f; 2:; cmplwi 5,56319; bgt 4f; lhz 0,0x0(3); addi 3,3,2; cmplwi 0,56320; blt 3f; cmplwi 0,57343; bgt 3f; rlwinm 0,0,0,22,31; mr 6,0; rlwimi 6,5,10,12,21; addis 6,6,1; b 5f; 3:; li 3,0; blr; 4:; li 3,0; blr; 5:; stw 6,0x0(4)"
extern "C" void f_80371C80() {}
