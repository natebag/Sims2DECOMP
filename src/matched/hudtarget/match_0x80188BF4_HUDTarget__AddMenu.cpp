// 0x80188BF4 HUDTarget::AddMenu(int, cXObject*, BString2&, unsigned int, ERShader*) (96B)

class cXObject;
class BString2;
class ERShader;

class ActionMenu {
public:
    void AddMenu(cXObject* obj, BString2& name, unsigned int flags, ERShader* shader);
};

class HUDTarget {
public:
    char pad_000[1856];
    ActionMenu m_menus[1];   // 180 bytes per menu
    void AddMenu(int idx, cXObject* obj, BString2& name, unsigned int flags, ERShader* shader);
    int IsMenuAvailable(int) const;
};

void HUDTarget::AddMenu(int idx, cXObject* obj, BString2& name, unsigned int flags, ERShader* shader) {
    IsMenuAvailable(idx);
    ActionMenu* m = (ActionMenu*)((char*)m_menus + idx * 180);
    m->AddMenu(obj, name, flags, shader);
}
