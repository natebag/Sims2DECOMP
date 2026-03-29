// ISimsObjectModel::GetTypeInfo - 0x80053CE0 (12 bytes)
// TU: iobject

void* ISimsObjectModel_GetTypeInfo(void* self) {
    extern int ISimsObjectModel_s_typeInfo;
    return &ISimsObjectModel_s_typeInfo;
}
