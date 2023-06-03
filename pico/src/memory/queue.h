#include <queue>
#include <vector>
#include "pico/stdlib.h"

#include "mem.h"

#define MAX_QUEUE_SIZE 16

struct segment_t {
    uint start; // TODO: can these be smaller?
    uint size;
    uint complete_size;
    std::vector<block_t> blocks;
};

struct mem_op_t {
    storage_ptr_t data;
    segment_t* seg;
};

class MemQueue {
    std::queue<mem_op_t> operations;
    Memory mem;

public:
    //MemQueue();
    void push(mem_op_t op);
    void pop();
    bool full();
    bool empty();
    void clear();
};