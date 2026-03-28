// ResourceBehaviorTree::operator delete(void *)
// Address: 0x80226FE0 | Size: 44 bytes
// Static init: calls internal with (1, 0xFFFF)

extern void ResourceBehaviorTree_static_init(int a, unsigned int b);

void ResourceBehaviorTree_op_delete_init() {
    ResourceBehaviorTree_static_init(1, 0xFFFF);
}
