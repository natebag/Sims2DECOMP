/* ObjectFolderImpl::DeletingInstance(ObjSelector *) at 0x800EFD90 (52B) */

struct ObjSel_DI {
    char m_pad[104];
    int m_refCount;
};

struct ObjectFolderImpl_DI {
    void UnloadData(ObjSel_DI* sel);
    void DeletingInstance(ObjSel_DI* sel);
};

void ObjectFolderImpl_DI::DeletingInstance(ObjSel_DI* sel) {
    sel->m_refCount--;
    if (sel->m_refCount == 0) UnloadData(sel);
}
