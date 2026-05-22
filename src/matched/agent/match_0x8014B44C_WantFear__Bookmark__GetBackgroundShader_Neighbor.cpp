// 0x8014B44C WantFear::Bookmark::GetBackgroundShader(Neighbor (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); bl _s8014B44C_0; cmpwi 3,3; bgt 0f; cmpwi 3,2; bge 5f; cmpwi 3,0; beq 1f; cmpwi 3,1; beq 2f; b 5f; 0:; cmpwi 3,4; beq 3f; cmpwi 3,128; beq 4f; b 5f; 1:; lis 3,-24359; ori 3,3,32207; b 6f; 2:; lis 3,2171; ori 3,3,13819; b 6f; 3:; lis 3,17252; ori 3,3,61367; b 6f; 4:; lis 3,-29535; ori 3,3,50854; b 6f; 5:; lis 3,-16260; ori 3,3,13636; 6:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8014B44C_0();
extern "C" void f_8014B44C() {}
