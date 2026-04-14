// 0x80053CF8 ISimsObjectModel::GetTypeKey (12B) const

extern int g_sObjTypeKey[3];

struct ISOM_GTK {
    int GetTypeKey() const;
};

int ISOM_GTK::GetTypeKey() const {
    return g_sObjTypeKey[0];
}
