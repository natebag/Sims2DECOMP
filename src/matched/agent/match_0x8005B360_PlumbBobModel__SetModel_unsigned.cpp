// 0x8005B360 PlumbBobModel::SetModel(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 3,0x28(30); li 29,0; cmpwi 3,0; beq 0f; lwz 29,0x8(3); 0:; cmpw cr7,31,29; beq cr7,2f; beq 1f; bl _s8005B360_0; li 0,0; stw 0,0x28(30); 1:; cmpwi 31,0; beq 2f; lis 3,-32692; mr 4,31; addi 3,3,-27556; li 5,0; li 6,0; bl _s8005B360_1; stw 3,0x28(30); 2:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8005B360_0();
extern "C" void _s8005B360_1();
extern "C" void f_8005B360() {}
