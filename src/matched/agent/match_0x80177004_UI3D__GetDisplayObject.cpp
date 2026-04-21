// 0x80177004 UI3D::GetDisplayObject(char*) (52B)
// DOL: bl FindEntry(name); if (!r) return 0; return r->field28;

struct UI3DEntry {
    char pad[28];
    void* m_displayObject;
};

struct UI3D {
    static void* GetDisplayObject(char* name);
    static UI3DEntry* FindEntry(char* name);
};

void* UI3D::GetDisplayObject(char* name) {
    UI3DEntry* e = FindEntry(name);
    if (e != 0) return e->m_displayObject;
    return 0;
}
