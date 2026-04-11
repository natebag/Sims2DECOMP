// 0x8030FC90 EResourceLoader::EResourceLoader (20b)

extern int EResourceLoader_vtable[];

struct EResourceLoader {
    int* m_vt;
    EResourceLoader();
};

EResourceLoader::EResourceLoader() {
    *(int**)this = EResourceLoader_vtable;
}
