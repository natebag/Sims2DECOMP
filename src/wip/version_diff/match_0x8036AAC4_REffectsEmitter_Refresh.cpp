class EFile;

class REffectsEmitter {
public:
    char pad[0x20];
    int m_loaded;

    void Deallocate();
    int Load(EFile* file);
    void Refresh(EFile* file);
};

void REffectsEmitter::Refresh(EFile* file)
{
    if (file != 0) {
        Deallocate();
        Load(file);
        m_loaded = 1;
    }
}
