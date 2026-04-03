void EResourceManager_dtor_base(void*);

struct ETextureManager {
    void dtor_base();
};

void ETextureManager::dtor_base() {
    EResourceManager_dtor_base(this);
}
