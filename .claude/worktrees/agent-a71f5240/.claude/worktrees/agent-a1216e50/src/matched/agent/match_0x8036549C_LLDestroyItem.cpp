extern "C" {

typedef void* LLNode;
typedef void* LLList;

LLNode LLGrabNode(LLList list);
void LLDestroyNode(LLList list, LLNode node);

int LLDestroyItem(LLList list)
{
    LLNode node = LLGrabNode(list);
    if (node == 0) {
        return -1;
    }
    LLDestroyNode(list, node);
    return 0;
}

}
