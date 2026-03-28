/* ISimsObjectModel::InsertSubModelsInHouse(ERLevel *) at 0x8004C91C (80B) */

struct EInstance;

struct ERLevel {
    void InsertInstance(EInstance *inst, EInstance *parent);
};

struct SubModelNode {
    EInstance *m_instance;
    char pad_04[4];
    SubModelNode *m_next;
};

struct ISimsObjectModel {
    char pad_00[0x450];
    SubModelNode *m_subModels;

    void InsertSubModelsInHouse(ERLevel *level);
};

void ISimsObjectModel::InsertSubModelsInHouse(ERLevel *level) {
    SubModelNode *node = m_subModels;
    while (node != 0) {
        level->InsertInstance(node->m_instance, 0);
        node = node->m_next;
    }
}
