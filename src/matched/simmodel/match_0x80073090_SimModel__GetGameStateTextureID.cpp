// 0x80073090 SimModel::GetGameStateTextureID(unsigned int, bool) (100B)
// Static method. Identical logic to GetGameStateModelID but hashes with "_GAME"
// string instead of "_LOD".

struct GlobalsGSTID {
    char pad[0x444];
    int m_gameMode;
};
extern "C" GlobalsGSTID _globals;

struct EChecksum {
    static unsigned int ComputeSymbol(const char* str, unsigned int id);
};

struct SimModel {
    static unsigned int GetGameStateTextureID(unsigned int id, bool force);
};

unsigned int SimModel::GetGameStateTextureID(unsigned int id, bool force) {
    if (_globals.m_gameMode != 0) {
        if (id == 0) goto return_id;
        goto call_hash;
    } else {
        if (id == 0) goto return_id;
        if (force) goto return_id;
    }
call_hash:
    return EChecksum::ComputeSymbol("_GAME", id);
return_id:
    return id;
}
