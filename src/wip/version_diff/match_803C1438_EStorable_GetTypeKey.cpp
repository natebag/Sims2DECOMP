// EStorable::GetTypeKey - 0x803C1438 (12 bytes)
// TU: e_instance

unsigned int EStorable_GetTypeKey(void* self) {
    extern unsigned int EStorable_s_typeInfo_key;
    return EStorable_s_typeInfo_key;
}
