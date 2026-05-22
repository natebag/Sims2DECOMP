// 0x80197CFC CASGeneticsTarget::GetLocalizableSubnav(int, (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,5; cmpwi 4,4; beq 1f; ble 0f; cmpwi 4,5; beq 2f; cmpwi 4,6; beq 3f; b 6f; 0:; cmpwi 4,0; blt 6f; lis 4,-32705; mr 3,31; addi 4,4,-17308; li 5,32; bl _s80197CFC_0; b 6f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14956; addi 3,1,8; crxor 6,6,6; bl _s80197CFC_1; lwz 9,0x8(1); b 4f; 2:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14936; addi 3,1,12; crxor 6,6,6; bl _s80197CFC_2; lwz 9,0xc(1); b 4f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-14912; addi 3,1,16; crxor 6,6,6; bl _s80197CFC_3; lwz 9,0x10(1); 4:; li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,31; li 5,32; bl _s80197CFC_4; li 0,0; sth 0,0x3e(31); 6:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s80197CFC_0();
extern "C" void _s80197CFC_1();
extern "C" void _s80197CFC_2();
extern "C" void _s80197CFC_3();
extern "C" void _s80197CFC_4();
extern "C" void f_80197CFC() {}
