// 0x80248914 _fwalk (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,4; li 28,0; addic. 29,3,472; beq 4f; 0:; lwz 31,0x4(29); lwz 30,0x8(29); addic. 31,31,-1; blt 3f; 1:; lha 0,0xc(30); cmpwi 0,0; beq 2f; mr 3,30; mtspr 8,27; crxor 6,6,6; blrl; or 28,28,3; 2:; addi 30,30,96; addic. 31,31,-1; bge 1b; 3:; lwz 29,0x0(29); cmpwi 29,0; bne 0b; 4:; mr 3,28; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void f_80248914() {}
