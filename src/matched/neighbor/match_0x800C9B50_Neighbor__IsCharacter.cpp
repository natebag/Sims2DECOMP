// 0x800C9B50 Neighbor::IsCharacter(void) (88B)

struct ObjSelector {
    void* GetSimDescription() const;
};

class Neighbor {
    char pad[0x0C];
    ObjSelector* m_pObjSelector;
public:
    bool IsCharacter() const;
};

bool Neighbor::IsCharacter() const {
    bool found = false;
    if (m_pObjSelector != 0) {
        bool desc = m_pObjSelector->GetSimDescription() != 0;
        if (desc)
            found = true;
    }
    return found;
}
