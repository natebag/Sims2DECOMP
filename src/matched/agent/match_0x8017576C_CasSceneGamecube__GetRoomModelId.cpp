// 0x8017576C CasSceneGamecube::GetRoomModelId (24B)

struct CasSceneGamecube {
    unsigned int GetRoomModelId(int param);
};

unsigned int CasSceneGamecube::GetRoomModelId(int param) {
    if (param == 0) {
        return 0x94A667AF;
    }
    return 0;
}
