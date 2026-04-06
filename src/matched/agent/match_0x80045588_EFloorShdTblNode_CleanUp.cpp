// 0x80045588 EFloorShdTblNode::CleanUp (72b)

class ENodeList;
class EResource;

struct EFloorShdTblNode {
    EResource* m_resource;
    char pad[4];
    ENodeList* m_list;
    
    void CleanUp();
};

extern "C" void ENodeList_RemoveAll(ENodeList* list);
extern "C" void EResource_DelRef(EResource* res);

void EFloorShdTblNode::CleanUp() {
    m_list->RemoveAll();
    if (m_resource) {
        m_resource->DelRef();
        m_resource = 0;
    }
}
