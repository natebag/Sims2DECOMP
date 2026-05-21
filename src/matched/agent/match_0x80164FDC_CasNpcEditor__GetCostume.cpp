// 0x80164FDC CasNpcEditor::GetCostume(unsigned int) (80B)

class CasCostumes {
public:
    int GetSimDescription(bool flag, unsigned int idx);
};

extern char g_CasMgr_8047625C[16];

class CasNpcEditor {
public:
    int GetCostume(unsigned int idx);
};

int CasNpcEditor::GetCostume(unsigned int idx) {
    if (idx > 0xA1) goto fail;
    {
        unsigned int adjusted = idx;
        bool flag = true;
        if (adjusted > 0x50) {
            adjusted -= 81;
            flag = false;
        }
        CasCostumes* mgr = (CasCostumes*)(*(void**)g_CasMgr_8047625C);
        return mgr->GetSimDescription(flag, adjusted);
    }
fail:
    return 0;
}
