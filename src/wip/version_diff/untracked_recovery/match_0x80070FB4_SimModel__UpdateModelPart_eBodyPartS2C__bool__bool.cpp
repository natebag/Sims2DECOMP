// 0x80070FB4 (128B) SimModel::UpdateModelPart(eBodyPartS2C, bool, bool)
// 4-call forwarding wrapper through CasSimDescriptionS2C / CasSimPartsS2C.

enum eBodyPartS2C { /* ... */ };

struct SimPartsS2CParam { int data[4]; };
struct CasSimDescriptionS2C;
struct CasSimPartsS2C;

struct SimModel {
    char pad[0x138];
    CasSimPartsS2C* m_parts;
    CasSimDescriptionS2C* m_desc;
    
    void ChangeModelPart(eBodyPartS2C part, unsigned int modelId, bool a, bool b);
    void UpdateModelPart(eBodyPartS2C part, bool a, bool b);
};

struct CasSimDescriptionS2C {
    void GetBodyPartParam(SimPartsS2CParam* out, eBodyPartS2C part);
    unsigned int GetBodyPartIndex(eBodyPartS2C part) const;
};

struct CasSimPartsS2C {
    unsigned int GetModelID(eBodyPartS2C part, unsigned int index, SimPartsS2CParam& param) const;
};

void SimModel::UpdateModelPart(eBodyPartS2C part, bool a, bool b) {
    SimPartsS2CParam param;
    m_desc->GetBodyPartParam(&param, part);
    unsigned int index = m_desc->GetBodyPartIndex(part);
    unsigned int modelId = m_parts->GetModelID(part, index, param);
    ChangeModelPart(part, modelId, a, b);
}
