// 0x801B0DB4 FAMTarget::GetNumberOfFamilyMembers(Family*) (68B)
// TRIAGE

class Family {
public:
    virtual int Method0();
    virtual int Method1();
    virtual int Method2();
    virtual int Method3();
    virtual int Method4();
    virtual int GetMemberCount();  // slot 6 (offset 48 = 6*8)
};

class FAMTarget {
public:
    int GetNumberOfFamilyMembers(Family* f);
};

int FAMTarget::GetNumberOfFamilyMembers(Family* f) {
    int r;
    if (f == 0) goto fail;
    r = f->GetMemberCount();
    goto end;
fail:
    r = 0;
end:
    return r;
}
