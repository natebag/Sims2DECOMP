// 0x80053D04 ISimsObjectModel::GetTypeVersion (12B) const

struct VersionBlock { unsigned short ver[256]; };
extern VersionBlock g_sObjTypeVersion[3];

struct ISOM_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short ISOM_GTV::GetTypeVersion() const {
    return g_sObjTypeVersion[0].ver[0];
}
