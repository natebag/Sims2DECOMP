// 0x80176584 UI2D::UnInstallEntry(char*) (68B)

extern "C" {
typedef void* LLNode;
typedef void* LLList;
LLNode LLGrabNode(LLList list);
void LLDestroyNode(LLList list, LLNode node);

int UnInstallEntry(LLList list)
{
    LLNode node = LLGrabNode(list);
    if (node == 0) {
        return 0;
    }
    LLDestroyNode(list, node);
    return 1;
}
}
