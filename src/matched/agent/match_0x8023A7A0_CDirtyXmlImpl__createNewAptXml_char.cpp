// 0x8023A7A0 CDirtyXmlImpl::createNewAptXml(char (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; li 3,36; bl _s8023A7A0_0; lis 11,-32697; lis 9,-32697; mr 31,3; addi 11,11,-25480; addi 9,9,-25160; addi 10,31,32; stw 11,0x20(31); cmpwi 30,0; stw 9,0x0(31); beq 0f; lbz 0,0x0(30); cmpwi 0,0; beq 0f; lha 3,0x118(11); mr 4,30; lwz 0,0x11c(11); add 3,10,3; mtspr 8,0; blrl; b 1f; 0:; li 0,0; stw 0,0x4(31); 1:; cmpwi 31,0; li 3,0; beq 2f; addi 3,31,32; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023A7A0_0();
extern "C" void f_8023A7A0() {}
