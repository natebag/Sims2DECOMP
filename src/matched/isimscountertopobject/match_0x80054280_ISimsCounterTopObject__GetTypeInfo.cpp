// 0x80054280 ISimsCounterTopObject::GetTypeInfo (12B) const

struct TypeInfo_ISimsCounterTopObject { char data[256]; };
extern TypeInfo_ISimsCounterTopObject g_ISimsCounterTopObject_TypeInfo[3];

struct ISimsCounterTopObject_GTI {
    TypeInfo_ISimsCounterTopObject* GetTypeInfo() const;
};

TypeInfo_ISimsCounterTopObject* ISimsCounterTopObject_GTI::GetTypeInfo() const {
    return &g_ISimsCounterTopObject_TypeInfo[0];
}
