#include "BookManager.h"

#include <iostream>
#include <string_view>

// BookManager_Search.cpp
// Module C: 信息查询（同学C负责）

// 按书名查询：模糊匹配
void BookManager::searchByTitle(std::string_view title) const {
    bool found = false;

    std::cout << "\n===== 查询结果 =====\n";
    for (const auto& b : books) {
        if (b.getTitle().find(title) != std::string_view::npos) {
            std::cout << "登录号: " << b.getLoginId()
                      << "  书名: " << b.getTitle()
                      << "  作者: " << b.getAuthor()
                      << "  分类号: " << b.getCategoryId()
                      << "  出版社: " << b.getPublisher()
                      << "  出版时间: " << b.getPublishTime()
                      << "  价格: " << b.getPrice() << '\n';
            found = true;
        }
    }

    if (!found) {
        std::cout << "没有找到书名包含「" << title << "」的图书。\n";
    }
}

// 按作者查询：模糊匹配
void BookManager::searchByAuthor(std::string_view author) const {
    bool found = false;

    std::cout << "\n===== 查询结果 =====\n";
    for (const auto& b : books) {
        if (b.getAuthor().find(author) != std::string_view::npos) {
            std::cout << "登录号: " << b.getLoginId()
                      << "  书名: " << b.getTitle()
                      << "  作者: " << b.getAuthor()
                      << "  分类号: " << b.getCategoryId()
                      << "  出版社: " << b.getPublisher()
                      << "  出版时间: " << b.getPublishTime()
                      << "  价格: " << b.getPrice() << '\n';
            found = true;
        }
    }

    if (!found) {
        std::cout << "没有找到作者包含「" << author << "」的图书。\n";
    }
}
