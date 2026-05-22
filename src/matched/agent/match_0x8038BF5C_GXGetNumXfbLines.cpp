// 0x8038BF5C GXGetNumXfbLines (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); mr 31,3; lfs f0,-17680(13); fdivs f1,f0,f1; bl _s8038BF5C_0; rlwinm 5,31,0,16,31; addi 0,5,-1; rlwinm 4,3,0,23,31; rlwinm 0,0,8,0,23; divwu 3,0,4; cmplwi 4,128; addi 3,3,1; ble 2f; cmplwi 4,256; bge 2f; b 1f; 0:; rlwinm 4,4,31,1,31; 1:; rlwinm. 0,4,0,31,31; beq 0b; divwu 0,5,4; mullw 0,0,4; subf. 0,0,5; bne 2f; addi 3,3,1; 2:; cmplwi 3,1024; ble 3f; li 3,1024; 3:; lwz 0,0x24(1); rlwinm 3,3,0,16,31; lwz 31,0x1c(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8038BF5C_0();
extern "C" void f_8038BF5C() {}
