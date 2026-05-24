// 0x800F4AB0 ObjectModuleImpl::ConstructObject(ObjSelector (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lwz 9,0x38(31); mr 29,5; lha 0,0x14(9); cmpwi 0,0; bne 3f; lha 0,0x12(9); cmpwi 0,7; bgt 0f; cmpwi 0,3; bge 1f; cmpwi 0,1; beq 1f; cmpwi 0,2; beq 2f; b 1f; 0:; cmpwi 0,9; li 3,0; ble 8f; 1:; li 3,344; bl _s800F4AB0_0; mr 5,31; mr 6,30; li 4,1; bl _s800F4AB0_1; b 8f; 2:; li 3,1716; bl _s800F4AB0_2; mr 5,31; mr 6,30; li 4,1; bl _s800F4AB0_3; b 6f; 3:; lha 0,0x12(9); cmpwi 0,8; bne 5f; li 3,424; bl _s800F4AB0_4; mr 5,31; mr 6,29; mr 7,30; li 4,1; bl _s800F4AB0_5; mr. 3,3; beq 4f; lwz 9,0x0(3); lwz 3,0x0(9); b 8f; 4:; li 3,0; b 8f; 5:; li 3,392; bl _s800F4AB0_6; mr 5,31; mr 6,29; mr 7,30; li 4,1; bl _s800F4AB0_7; 6:; mr. 3,3; li 0,0; beq 7f; lwz 0,0x0(3); 7:; mr 3,0; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800F4AB0_0();
extern "C" void _s800F4AB0_1();
extern "C" void _s800F4AB0_2();
extern "C" void _s800F4AB0_3();
extern "C" void _s800F4AB0_4();
extern "C" void _s800F4AB0_5();
extern "C" void _s800F4AB0_6();
extern "C" void _s800F4AB0_7();

struct ObjectModuleImpl {
    void ConstructObject_ObjSelector();
};

void ObjectModuleImpl::ConstructObject_ObjSelector() {
}
