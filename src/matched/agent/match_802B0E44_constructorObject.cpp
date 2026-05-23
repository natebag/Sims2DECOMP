// FLAGS: -fno-elide-constructors
// 0x802B0E44 _constructorObject(AptValue*) (8B)

extern void* g_constructorObject;

void* constructorObject() {
    return g_constructorObject;
}
