// 0x80054414 IShrubObject::GetTypeInfo (12B) const

struct TypeInfo_IShrubObject { char data[256]; };
extern TypeInfo_IShrubObject g_IShrubObject_TypeInfo[3];

struct IShrubObject_GTI {
    TypeInfo_IShrubObject* GetTypeInfo() const;
};

TypeInfo_IShrubObject* IShrubObject_GTI::GetTypeInfo() const {
    return &g_IShrubObject_TypeInfo[0];
}
