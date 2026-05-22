// 0x8019DF0C ObjectModuleImpl::GetObject(int) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,0; beq 0f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s8019DF0C_0; 0:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-12516; cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s8019DF0C_1; 1:; lwz 0,0x0(31); lis 9,-32705; addi 4,9,-12496; cmpwi 0,0; beq 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 2f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s8019DF0C_2; 2:; mr 3,31; bl _s8019DF0C_3; addi 3,31,140; li 4,0; li 5,5; bl _s8019DF0C_4; mr 3,31; lwz 0,0x74(1); lwz 12,0x40(1); mtspr 8,0; lmw 21,0x44(1); mtcrf 8,12; addi 1,1,112"
extern "C" void _s8019DF0C_0();
extern "C" void _s8019DF0C_1();
extern "C" void _s8019DF0C_2();
extern "C" void _s8019DF0C_3();
extern "C" void _s8019DF0C_4();
extern "C" int f_8019DF0C() {}
