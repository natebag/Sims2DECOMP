// 0x8003531C (20 bytes)
/* ESim::GetModelPart(int) */

struct ESim_ModelObj {
    char pad[0x68];
    void *parts[4];
};

struct ESim_GetModelPart {
    char pad_00[0x63C];
    ESim_ModelObj *m_model; /* ptr at offset 0x63C */

    void *GetModelPart(int idx);
};

void *ESim_GetModelPart::GetModelPart(int idx) {
    ESim_ModelObj *model = m_model;
    return model->parts[idx];
}
