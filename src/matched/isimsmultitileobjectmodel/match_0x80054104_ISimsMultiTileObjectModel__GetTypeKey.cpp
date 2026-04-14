// 0x80054104 ISimsMultiTileObjectModel::GetTypeKey (12B) const

extern int g_ISimsMultiTileObjectModel_TypeKey[3];

struct ISimsMultiTileObjectModel_GTK {
    int GetTypeKey() const;
};

int ISimsMultiTileObjectModel_GTK::GetTypeKey() const {
    return g_ISimsMultiTileObjectModel_TypeKey[0];
}
