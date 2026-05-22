// 0x801F5BA0 INVTarget::GetNumberOfBuildItemsToBuy(BBI::InventoryItem::eItemSubcategory, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); cmpwi 4,3; li 31,1; beq 1f; bgt 0f; cmpwi 4,2; beq 1f; b 2f; 0:; cmpwi 4,4; beq 1f; cmpwi 4,5; bne 2f; 1:; li 31,20; 2:; lwz 3,0x90(3); bl _s801F5BA0_0; mr. 3,3; beq 3f; bl _s801F5BA0_1; b 4f; 3:; li 3,0; 4:; add 0,3,31; mr 9,31; cmpwi 0,99; ble 5f; subfic 9,3,99; 5:; mr 3,9; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s801F5BA0_0();
extern "C" void _s801F5BA0_1();
extern "C" void f_801F5BA0() {}
