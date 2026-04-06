// 0x800B63D8 FamilyImpl::GetName (60b)

struct StringBuffer {
    void* m_data;
};

struct FamilyImpl {
    int field0;
    StringBuffer m_name;
    
    void GetName(StringBuffer* ret);
};

void FamilyImpl_GetName(FamilyImpl* this_, StringBuffer* ret) {
    this_->GetName(ret);
}
