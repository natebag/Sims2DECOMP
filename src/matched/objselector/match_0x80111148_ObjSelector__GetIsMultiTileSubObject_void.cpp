// 0x80111148 ObjSelector::GetIsMultiTileSubObject(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x38(3); li 3,0; lha 0,0x14(9); cmplwi 0,0; beqlr; lha 0,0x16(9); cmplwi 0,65535; beqlr; li 3,1"

struct ObjSelector {
    void GetIsMultiTileSubObject();
};

void ObjSelector::GetIsMultiTileSubObject() {
}
