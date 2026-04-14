// 0x80054298 ISimsCounterTopObject::GetTypeKey (12B) const

extern int g_ISimsCounterTopObject_TypeKey[3];

struct ISimsCounterTopObject_GTK {
    int GetTypeKey() const;
};

int ISimsCounterTopObject_GTK::GetTypeKey() const {
    return g_ISimsCounterTopObject_TypeKey[0];
}
