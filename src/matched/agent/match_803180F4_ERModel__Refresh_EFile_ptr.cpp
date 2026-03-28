class EFile;

class ERModel {
public:
    void Refresh(EFile*);
    void DoRefresh(EFile*);
};

void ERModel::Refresh(EFile* f) {
    if (f) {
        DoRefresh(f);
    }
}
