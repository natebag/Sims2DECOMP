// 0x80054420 IShrubObject::GetTypeName (12B) const

extern char* g_IShrubObject_TypeName[3];

struct IShrubObject_GTN {
    const char* GetTypeName() const;
};

const char* IShrubObject_GTN::GetTypeName() const {
    return g_IShrubObject_TypeName[0];
}
