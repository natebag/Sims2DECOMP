// 0x8003FC60 EGlobal::GetHouseGrassShaderId(char (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; beq 0f; lwz 3,0xe8(3); lis 4,-32707; addi 4,4,10132; bl _s8003FC60_0; mr 4,3; lis 9,-32697; lwz 3,0x5eb4(9); mr 5,31; bl _s8003FC60_1; mr. 3,3; beq 0f; lwz 3,0x28(3); b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8003FC60_0();
extern "C" void _s8003FC60_1();
extern "C" void f_8003FC60() {}
