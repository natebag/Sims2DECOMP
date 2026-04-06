// 0x800C9B50 Neighbor::IsCharacter (88b)

struct ObjSelector;
struct Neighbor {
    ObjSelector* m_selector;  // offset 12
};

extern void* ObjSelector_GetSimDescription(ObjSelector* this);

int Neighbor_IsCharacter(Neighbor* this) {
    if (!this->m_selector) {
        return 0;
    }
    
    void* simDesc = ObjSelector_GetSimDescription(this->m_selector);
    return simDesc ? 1 : 0;
}
