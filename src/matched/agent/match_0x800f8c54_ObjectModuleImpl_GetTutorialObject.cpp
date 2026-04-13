// 0x800f8c54 ObjectModuleImpl::GetTutorialObject (24b)

struct cXObject {
    char pad[4];
    cXObject* m_next;
};

struct ObjectModuleImpl {
    char pad[0x2088];
    cXObject* m_tutorialObject;
    cXObject* GetTutorialObject();
};

cXObject* ObjectModuleImpl::GetTutorialObject() {
    cXObject* r = 0;
    if (m_tutorialObject) r = m_tutorialObject->m_next;
    return r;
}
