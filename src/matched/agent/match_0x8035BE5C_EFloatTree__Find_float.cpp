// 0x8035BE5C EFloatTree::Find(float, (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,0x8(3); lis 9,-32700; addi 9,9,11784; cmpw 3,9; beq 4f; cmpwi 7,4,0; 0:; lfs f0,0x1c(3); fcmpu 0,f1,f0; bne 1f; beqlr cr7; lwz 0,0x18(3); stw 0,0x0(4); blr; 1:; bge 2f; lwz 3,0x0(3); b 3f; 2:; lwz 3,0x4(3); 3:; cmpw 3,9; bne 0b; 4:; li 3,0"
extern "C" void f_8035BE5C() {}
