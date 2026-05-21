// 0x8007302c SimModel::GetGameStateModelID(unsigned int, bool) (100B)
// Static method. Loads gameMode flag from _globals+0x444. If mode!=0, always
// hash id via EChecksum::ComputeSymbol("_LOD", id). If mode==0, hash only when
// id!=0 && !force. Otherwise returns id unchanged.

struct GlobalsGSMID {
    char pad[0x444];
    int m_gameMode;
};
extern "C" GlobalsGSMID _globals;

struct EChecksum {
    static unsigned int ComputeSymbol(const char* str, unsigned int id);
};

struct SimModel {
    static unsigned int GetGameStateModelID(unsigned int id, bool force);
};

unsigned int SimModel::GetGameStateModelID(unsigned int id, bool force) {
    if (_globals.m_gameMode != 0) {
        if (id == 0) goto return_id;
        goto call_hash;
    } else {
        if (id == 0) goto return_id;
        if (force) goto return_id;
    }
call_hash:
    return EChecksum::ComputeSymbol("_LOD", id);
return_id:
    return id;
}
