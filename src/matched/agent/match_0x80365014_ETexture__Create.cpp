struct ETextureDef {
    unsigned int a, b, c, d, e, f, g, h;
};

struct ETexture {
    ETextureDef m_def;
    int Create(ETextureDef &def);
};

int ETexture::Create(ETextureDef &def) {
    m_def = def;
    return 1;
}
