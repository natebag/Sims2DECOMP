class Family;

class FAMTarget {
public:
    Family *GetFamilyInFamilyList(int index);
    int GetLotForFamily(Family *family);
    int GetLotForFamily(int familyIndex);
};

int FAMTarget::GetLotForFamily(int familyIndex) {
    Family *fam = GetFamilyInFamilyList(familyIndex);
    if (fam == 0) return 0;
    return GetLotForFamily(fam);
}
