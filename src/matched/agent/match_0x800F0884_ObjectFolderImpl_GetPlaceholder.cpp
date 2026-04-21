// 0x800F0884 (60B) ObjectFolderImpl::GetPlaceholder(void)

struct ObjectFolderImpl_Base {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void* GetObjectByID(int guid) = 0;
};

struct ObjectFolderImpl : public ObjectFolderImpl_Base {
    void* GetPlaceholder();
};

void* ObjectFolderImpl::GetPlaceholder() {
    return GetObjectByID(0x7FD96B54);
}
