class EFile;

class REffectsSequencer {
public:
    void Deallocate();
    int Load(EFile* file);
    void Refresh(EFile* file);
};

void REffectsSequencer::Refresh(EFile* file)
{
    if (file != 0) {
        Deallocate();
        Load(file);
    }
}
