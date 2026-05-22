// 0x80385A34 GetInitVal (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80385A34_0; stw 3,-25328(13); lis 3,16838; addi 0,3,20077; lwz 4,-25328(13); lis 5,32749; addi 3,5,-32768; mullw 4,4,0; addi 0,4,12345; stw 0,-25328(13); lwz 0,-25328(13); rlwinm 0,0,16,17,31; or 3,3,0; lwz 0,0xc(1); rlwinm 3,3,0,0,19; addi 1,1,8; mtspr 8,0"
extern "C" void _s80385A34_0();
extern "C" void f_80385A34() {}
