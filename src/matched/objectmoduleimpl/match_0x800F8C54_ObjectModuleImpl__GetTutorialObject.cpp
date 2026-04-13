// 0x800F8C54 ObjectModuleImpl::GetTutorialObject (24B)

struct TutorialData {
    int field_0;
    void* m_object;
};

struct ObjectModuleImpl_GTO {
    char pad[0x2088];
    TutorialData* m_tutorial;
    void* GetTutorialObject();
};

void* ObjectModuleImpl_GTO::GetTutorialObject() {
    void* r = 0;
    if (m_tutorial != 0) r = m_tutorial->m_object;
    return r;
}
