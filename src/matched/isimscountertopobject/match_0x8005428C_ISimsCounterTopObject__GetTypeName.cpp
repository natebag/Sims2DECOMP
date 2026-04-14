// 0x8005428C ISimsCounterTopObject::GetTypeName (12B) const

extern char* g_ISimsCounterTopObject_TypeName[3];

struct ISimsCounterTopObject_GTN {
    const char* GetTypeName() const;
};

const char* ISimsCounterTopObject_GTN::GetTypeName() const {
    return g_ISimsCounterTopObject_TypeName[0];
}
