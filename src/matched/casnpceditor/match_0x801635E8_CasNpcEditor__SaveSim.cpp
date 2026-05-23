// 0x801635E8 CasNpcEditor::SaveSim (96b)

struct CasNpcEditor {
    char pad[8];
    int editType;
};

extern int SaveNpcType1(CasNpcEditor*);
extern int SaveNpcType2(CasNpcEditor*);
extern int SaveNpcType3(CasNpcEditor*);

int CasNpcEditor_SaveSim(CasNpcEditor* self) {
    switch (self->editType) {
    case 1: return SaveNpcType1(self);
    case 2: return SaveNpcType2(self);
    case 3: return SaveNpcType3(self);
    default: return 0;
    }
}
