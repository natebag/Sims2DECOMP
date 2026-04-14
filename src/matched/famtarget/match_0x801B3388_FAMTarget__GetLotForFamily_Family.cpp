// 0x801b3388 FAMTarget::GetLotForFamily (68B)

struct FamilyBase {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
};

struct Family : FamilyBase {
    virtual int GetLot(void);
};

struct FAMTarget {
    int GetLotForFamily(Family* fam);
};

int FAMTarget::GetLotForFamily(Family* fam) {
    if (!fam) return 0;
    return fam->GetLot();
}
