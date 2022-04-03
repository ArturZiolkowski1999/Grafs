#include <iostream>
#include "gtest/gtest.h"
#include "Graph.h"
#include "Timer.h"


// TEST (sorting, quicksort) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.quick_sort();
//     for (int i = 0; i < 4; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (sorting, mergesort) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.merge_sort();
//     for (int i = 0; i < 4; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (sorting, insertionsort) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.insertion_sort();
//     for (int i = 0; i < 4; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (sorting, heapsors) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.heap_sort();
//     for (int i = 0; i < 4; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (reshufle, proc_100) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.heap_sort();

//     srt_list.reshuffle(100);
//     for (int i = 0; i < 4; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }


// TEST (reshufle, proc_80) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.heap_sort();

//     srt_list.reshuffle(80);
//     for (int i = 0; i < 3; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (reshufle, proc_60) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.heap_sort();

//     srt_list.reshuffle(60);
//     for (int i = 0; i < 2; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }

// TEST (reshufle, proc_40) {
//     std::array<int, 5> tst_array = {4,2,5,1,3};
//     SortableList<int, 5> srt_list;
//     srt_list.set_array(tst_array);
//     srt_list.heap_sort();

//     srt_list.reshuffle(40);
//     for (int i = 0; i < 1; ++i){
//         EXPECT_TRUE(srt_list[i] < srt_list[i+1]);
//     }
// }