// 0x8004B1E0 BBI::InventoryItems::GetItemCategoryFromObjDefinition(ObjDefinition (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr. 3,3; bne 0f; li 3,0; blr; 0:; lha 0,0x50(3); cmpwi 0,512; bne 1f; li 3,3; blr; 1:; lha 3,0x12(3); cmpwi 3,7; bgt 2f; cmpwi 3,5; bge 6f; cmpwi 3,0; blt 6f; cmpwi 3,3; ble 6f; b 4f; 2:; cmpwi 3,14; bgt 3f; cmpwi 3,9; bge 6f; b 5f; 3:; cmpwi 3,15; bne 6f; 4:; li 3,1; blr; 5:; li 3,2; blr; 6:; li 3,0"
extern "C" int f_8004B1E0() {}
