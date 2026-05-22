// 0x8019C67C ObjectModuleImpl::RelationshipAccessed(Neighbor (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8019C72C" lines="addi 5,5,-13680; addi 3,1,96; crxor 6,6,6; bl _s8019C67C_0; lwz 9,0x60(1); b 0f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-13664; addi 3,1,100; crxor 6,6,6; bl _s8019C67C_1; lwz 9,0x64(1); b 0f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15084; addi 3,1,104; crxor 6,6,6; bl _s8019C67C_2; lwz 9,0x68(1); 0:; li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,31; bl _s8019C67C_3"
extern "C" void _s8019C67C_0();
extern "C" void _s8019C67C_1();
extern "C" void _s8019C67C_2();
extern "C" void _s8019C67C_3();
extern "C" void f_8019C72C();
extern "C" void f_8019C67C() {}
