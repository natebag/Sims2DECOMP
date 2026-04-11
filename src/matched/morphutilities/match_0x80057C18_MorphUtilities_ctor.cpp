// 0x80057C18 MorphUtilities::MorphUtilities (8b)

class EIStaticModel;

struct MorphUtilities {
    EIStaticModel** field_0;
    MorphUtilities(EIStaticModel**);
};

MorphUtilities::MorphUtilities(EIStaticModel** p2) {
    field_0 = p2;
}
