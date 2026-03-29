// EStorable::GetTypeName - 0x803C142C (12 bytes)
// TU: e_instance

char* EStorable_GetTypeName(void* self) {
    extern char* EStorable_s_typeInfo_name;
    return EStorable_s_typeInfo_name;
}
