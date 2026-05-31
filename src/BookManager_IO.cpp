#include "BookManager.h"

#include <fstream>
#include <iostream>

// BookManager_IO.cpp
// Module A: 文件持久化（同学A负责）

// 从文件加载图书：使用流操作符简化读取
bool BookManager::loadFromFile(std::string_view filename) {
    std::ifstream in{std::string(filename)};
    if (!in) {
        std::cout << "无法打开文件：" << filename << "\n";
        return false;
    }

    books.clear();  // 清空现有数据
    Book b;
    while (in >> b) {
        books.push_back(b);
    }

    std::cout << "已从 " << filename << " 加载 " << books.size() << " 条记录。\n";
    return true;
}

// 保存图书到文件：使用流操作符简化写入
bool BookManager::saveToFile(std::string_view filename) const {
    std::ofstream out{std::string(filename)};
    if (!out) {
        std::cout << "无法打开文件：" << filename << "\n";
        return false;
    }

    for (const auto& b : books) {
        out << b << '\n';
    }

    std::cout << "已保存 " << books.size() << " 条记录到 " << filename << "\n";
    return true;
}
