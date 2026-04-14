// 0x80054110 ISimsMultiTileObjectModel::GetTypeVersion (12B) const

struct VerBlock_ISimsMultiTileObjectModel { unsigned short ver[256]; };
extern VerBlock_ISimsMultiTileObjectModel g_ISimsMultiTileObjectModel_TypeVersion[3];

struct ISimsMultiTileObjectModel_GTV {
    unsigned short GetTypeVersion() const;
};

unsigned short ISimsMultiTileObjectModel_GTV::GetTypeVersion() const {
    return g_ISimsMultiTileObjectModel_TypeVersion[0].ver[0];
}
