// 0x80118E58 cSamplePatch::cSamplePatch (44b)

struct SndEvtHitPatch;

struct cSamplePatch {
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    float field_14;
    int field_18;

    cSamplePatch(SndEvtHitPatch*, float);
};

struct SndEvtHitPatch {
    int field_00;
    int field_04;
};

cSamplePatch::cSamplePatch(SndEvtHitPatch* patch, float f) {
    field_18 = 0;
    field_04 = 0;
    field_10 = 0;
    field_08 = patch->field_04;
    field_14 = f;
    field_0C = patch->field_00;
}
