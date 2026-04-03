struct ERTexture {
    ~ERTexture();
    static void Destruct(ERTexture* obj);
};

void ERTexture::Destruct(ERTexture* obj) {
    obj->~ERTexture();
}
