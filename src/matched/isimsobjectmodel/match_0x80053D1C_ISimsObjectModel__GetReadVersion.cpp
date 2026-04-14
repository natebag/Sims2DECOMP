// 0x80053D1C ISimsObjectModel::GetReadVersion (12B)

struct ReadVersionBlock { unsigned short ver[256]; };
extern ReadVersionBlock g_sObjReadVersion[3];

struct ISOM_GRV {
    unsigned short GetReadVersion();
};

unsigned short ISOM_GRV::GetReadVersion() {
    return g_sObjReadVersion[0].ver[0];
}
