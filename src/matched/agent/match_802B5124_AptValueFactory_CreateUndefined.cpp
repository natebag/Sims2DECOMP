// FLAGS: -fno-elide-constructors
// 0x802B5124 AptValueFactory::CreateUndefined(void) (8B)

extern void* g_undefinedValue;

void* AptValueFactory_CreateUndefined() {
    return g_undefinedValue;
}
