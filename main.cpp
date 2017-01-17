#include <iostream>
#include <cstring>
#include "CacheSim.h"
#include "argparse.hpp"
using namespace std;


int main(const int argc, const char * argv[]) {
//    char test_case[100] = "";
//    // 如果没有输入文件，默认是gcc.trace
//    if(argc > 1){
//        strcat(test_case, argv[1]);
//    }else{
//        strcat(test_case, "gcc.trace");
//    }
////    int line_size[] = {8, 16, 32, 64, 128};
//    int line_size[] = {32};
//    int ways[] = {1, 2, 4, 8, 12, 16, 32};
////    int ways[] = {8};
////    int cache_size[] = {0x800,0x1000,0x2000,0x4000,0x8000,0x10000,0x20000,0x40000,0x80000};
//    int cache_size[] = {0x8000,0x10000,0x20000};
//    int i,j,m;
//    CacheSim cache;
//    for (m = 0;m<sizeof(cache_size)/sizeof(int);m++){
//        for (i=0; i<sizeof(line_size)/sizeof(int); i++){
//            for (j=0; j<sizeof(ways)/sizeof(int); j++){
////                for (int k = CACHE_SWAP_FIFO; k < CACHE_SWAP_MAX; ++k) {
//                    printf("\ncache_size: %d Bytes\tline_size: %d\t mapping ways %d \t swap_style %d \n", cache_size[m],line_size[i], ways[j], k);
//                    cache.init(cache_size[m], line_size[i], ways[j]);
////                    cache.set_swap_style(k);
//                    cache.load_trace(test_case);
//                    delete cache;
////                }
//            }
//        }
//    }
    //以下为固定的测试
    ArgumentParser parser;
    // 输入trace的地址
    parser.addArgument("-i", "--input", 1, false);
    parser.addArgument("--l1",1, true);
    parser.addArgument("--l2",1, true);
    parser.addArgument("--line_size", 1, true);
    parser.addArgument("--ways", 1, true);
    parser.parse(argc, argv);


//    int line_size[] = {8, 16, 32, 64, 128};
    _u64 line_size[] = {32,32 };
    _u64 ways[] = {4,4};
    _u64 cache_size[3] = {0x1000,0x8000};
    CacheSim cache;
    cache.init(cache_size, line_size,ways);
    cache.load_trace(parser.retrieve<string>("input").c_str());
    return 0;
}