class ERTexture {
public:
    void Load(unsigned char*);
    void LoadData(unsigned char*);
};

void ERTexture::Load(unsigned char* data) {
    LoadData(data + 4);
}
