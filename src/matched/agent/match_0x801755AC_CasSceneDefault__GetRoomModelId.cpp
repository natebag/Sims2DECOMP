// 0x801755AC CasSceneDefault::GetRoomModelId (24B)

struct CasSceneDefault {
    unsigned int GetRoomModelId(int param);
};

unsigned int CasSceneDefault::GetRoomModelId(int param) {
    if (param == 0) {
        return 0x94A667AF;
    }
    return 0;
}
