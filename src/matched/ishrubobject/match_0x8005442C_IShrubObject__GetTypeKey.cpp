// 0x8005442C IShrubObject::GetTypeKey (12B) const

extern int g_IShrubObject_TypeKey[3];

struct IShrubObject_GTK {
    int GetTypeKey() const;
};

int IShrubObject_GTK::GetTypeKey() const {
    return g_IShrubObject_TypeKey[0];
}
