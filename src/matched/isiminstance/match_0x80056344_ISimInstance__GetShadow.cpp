// 0x80056344 ISimInstance::GetShadow (8B) — returns 0 constant

struct ISimInstance_GS {
    void* GetShadow();
};

void* ISimInstance_GS::GetShadow() {
    return 0;
}
