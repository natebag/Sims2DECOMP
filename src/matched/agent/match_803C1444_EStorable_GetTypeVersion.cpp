// EStorable::GetTypeVersion - 0x803C1444 (12 bytes)
// TU: e_instance

unsigned int EStorable_GetTypeVersion(void* self) {
    extern unsigned int EStorable_s_typeInfo_version;
    return EStorable_s_typeInfo_version;
}
