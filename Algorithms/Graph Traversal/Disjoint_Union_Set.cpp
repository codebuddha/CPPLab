/*
 * Disjoint_Union_Set.cpp
 * Created on: 28-11-2018
 * Author: Abhirup
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
template<typename T>
struct Node{
    int rank = 0
    T data = NULL;
};
