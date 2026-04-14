/* ESim::GetTypeInfoStatic(void) - 0x80035120 (12 bytes) */

struct TypeInfo;

extern TypeInfo ESim_typeInfo;

struct ESim {
    static const TypeInfo* GetTypeInfoStatic();
};

const TypeInfo* ESim::GetTypeInfoStatic() {
    return &ESim_typeInfo;
}
