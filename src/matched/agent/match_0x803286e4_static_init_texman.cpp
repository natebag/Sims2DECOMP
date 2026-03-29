void EResourceManager_ctor(void *);
void EResourceManager_dtor(void *, int);
extern char ETextureManager_instance[];
extern int ETextureManager_vtable[];

void __static_init_and_dest_texman(int init, unsigned int mask) {
    if (mask == 0xFFFF) {
        if (init != 0) {
            char *inst = ETextureManager_instance;
            EResourceManager_ctor(inst);
            *(int **)(inst + 0xd1c) = ETextureManager_vtable;
        } else {
            EResourceManager_dtor(ETextureManager_instance, 2);
        }
    }
}
