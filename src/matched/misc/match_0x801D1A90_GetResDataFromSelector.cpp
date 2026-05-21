// 0x801D1A90 (64B) GetResDataFromSelector(ObjSelector *)

class ObjSelector;
extern "C" ObjSelector* FindSelectorContainingResData(ObjSelector* s);  // 0x801D1A10

unsigned int GetResDataFromSelector(ObjSelector* s) {
    ObjSelector* found = FindSelectorContainingResData(s);
    if (found == 0) return 0;
    void* p = *(void**)((char*)found + 56);
    if (p == 0) return 0;
    return *(unsigned int*)((char*)p + 192);
}
