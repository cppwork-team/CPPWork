#include "BookManager.h"

#include <iostream>
#include <limits>
#include <string>

// BookManager_Edit.cpp
// Module D: 修改与删除（同学D负责）

// 删除图书：返回 bool 表示是否成功
bool BookManager::deleteBook(std::string_view bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getLoginId() == bookId) {
            std::cout << "找到图书：" << it->getTitle() << "，确认删除？(y/n): ";
            char confirm;
            std::cin >> confirm;

            if (confirm == 'y' || confirm == 'Y') {
                books.erase(it);
                std::cout << "已删除登录号为「" << bookId << "」的图书。\n";
                return true;
            } else {
                std::cout << "已取消删除。\n";
                return false;
            }
        }
    }

    std::cout << "未找到登录号为「" << bookId << "」的图书。\n";
    return false;
}

// 修改图书：返回 bool 表示是否成功，使用 getline 支持带空格的输入
bool BookManager::modifyBook(std::string_view bookId) {
    for (auto& b : books) {
        if (b.getLoginId() == bookId) {
            std::cout << "找到图书：" << b.getTitle() << "\n";
            std::cout << "请输入新的信息（登录号不可修改）：\n";

            std::string newTitle, newAuthor, newCategoryId;
            std::string newPublisher, newPublishTime;
            double newPrice = 0;

            // 清除之前可能残留的换行符
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "新书名: ";
            std::getline(std::cin, newTitle);
            std::cout << "新作者: ";
            std::getline(std::cin, newAuthor);
            std::cout << "新分类号: ";
            std::getline(std::cin, newCategoryId);
            std::cout << "新出版社: ";
            std::getline(std::cin, newPublisher);
            std::cout << "新出版时间: ";
            std::getline(std::cin, newPublishTime);

            std::cout << "新价格: ";
            while (!(std::cin >> newPrice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "价格格式不正确，请重新输入: ";
            }

            b.setTitle(newTitle);
            b.setAuthor(newAuthor);
            b.setCategoryId(newCategoryId);
            b.setPublisher(newPublisher);
            b.setPublishTime(newPublishTime);
            b.setPrice(newPrice);

            std::cout << "修改成功！\n";
            return true;
        }
    }

    std::cout << "未找到登录号为「" << bookId << "」的图书。\n";
    return false;
}
