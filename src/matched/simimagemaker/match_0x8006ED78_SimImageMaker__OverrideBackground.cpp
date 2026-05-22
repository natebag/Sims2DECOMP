// 0x8006ED78 SimImageMaker::OverrideBackground(unsigned int) (104B)

class EResource {
public:
    void DelRef();
};

class EFile;

class EResourceManager {
public:
    EResource* AddRef(unsigned int id, EFile* f, int flag);
};

extern char _textureman[16];  // 0x804BE33C, Tech #17 HA/LO

class SimImageMaker {
public:
    char pad_000[540];
    EResource* m_bg;
    void OverrideBackground(unsigned int id);
};

void SimImageMaker::OverrideBackground(unsigned int id) {
    EResource* bg = m_bg;
    if (bg != 0) {
        bg->DelRef();
        m_bg = 0;
    }
    if (id != 0) {
        m_bg = ((EResourceManager*)_textureman)->AddRef(id, 0, 0);
    }
}
