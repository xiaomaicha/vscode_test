//
// Created by wuqi on 19-6-8.
//

#include <vector>
#include <iostream>

void fun_old() {
    const int NUM = 1000;
    std::vector<int *> vec(NUM, nullptr);
    for (auto &e : vec) {
        e = new int(42);
    }
    std::cout << "origin capacity: " << vec.capacity() << std::endl;
    std::cout << "first elem addr is " << vec[0] << std::endl;
    for (auto it = vec.begin() + 2; it != vec.end(); it++) {
        delete *it;
        *it = nullptr;
    }
    vec.erase(vec.begin() + 2, vec.end());
    std::vector<int *>(vec).swap(vec);
    std::cout << "capacity after erase: " << vec.capacity() << std::endl;
    std::cout << "first elem addr is " << vec[0] << std::endl;
    for (auto e : vec) {
        delete e;
    }
}

void fun_new() {
    const int NUM = 1000;
    std::vector<int *> vec(NUM, nullptr);
    for (auto &e : vec) {
        e = new int(42);
    }
    std::cout << "origin capacity: " << vec.capacity() << std::endl;
    std::cout << "first elem addr is " << vec[0] << std::endl;
    for (auto it = vec.begin() + 2; it != vec.end(); it++) {
        delete *it;
        *it = nullptr;
    }
    vec.erase(vec.begin() + 2, vec.end());
    vec.shrink_to_fit();
    std::cout << "capacity after erase: " << vec.capacity() << std::endl;
    std::cout << "first elem addr is " << vec[0] << std::endl;
    for (auto e : vec) {
        delete e;
    }
}

int main() {
    fun_old();
    std::cout<<std::endl;
    fun_new();
}