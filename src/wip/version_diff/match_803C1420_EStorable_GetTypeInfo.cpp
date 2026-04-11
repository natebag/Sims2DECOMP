// EStorable::GetTypeInfo - 0x803C1420 (12 bytes)
// TU: e_instance

void* EStorable_GetTypeInfo(void* self) {
    extern int EStorable_s_typeInfo;
    return &EStorable_s_typeInfo;
}
