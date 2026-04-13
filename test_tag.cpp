struct cXObjectImpl {
    int m_graphicsTagged;
    bool HaveGraphicsBeenTagged();
    void TagGraphicsField();
    const char* GetName() const;
};

bool cXObjectImpl::HaveGraphicsBeenTagged() {
    if (this->m_graphicsTagged) {
        this->m_graphicsTagged = 0;
        return 1;
    }
    return 0;
}

void cXObjectImpl::TagGraphicsField() {
    this->m_graphicsTagged = 1;
}

const char* cXObjectImpl::GetName() const {
    return *(const char**)((char*)this + 0x8c + 0x14);
}
