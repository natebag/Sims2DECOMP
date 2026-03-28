struct Family;

struct FAMTarget {
    Family *GetFamilyInFamilyList(int id);
    int GetLotForFamily(Family *fam);
    int GetLotForFamily(int id);
};

int FAMTarget::GetLotForFamily(int id) {
    Family *fam = GetFamilyInFamilyList(id);
    if (fam == 0) goto not_found;
    return GetLotForFamily(fam);
not_found:
    return 0;
}
