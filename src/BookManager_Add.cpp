#include "BookManager.h"

#include <iostream>
#include <limits>
#include <string>

// BookManager_Add.cpp
// Module B: 信息录入与浏览（同学B负责）

// 添加图书：使用 getline 支持带空格的输入
void BookManager::addBook() {
    std::string id, title, author, categoryId, publisher, publishTime;
    double price = 0;

    // 清除之前可能残留的换行符
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "请输入登录号: ";
    std::getline(std::cin, id);
    std::cout << "请输入书名: ";
    std::getline(std::cin, title);
    std::cout << "请输入作者: ";
    std::getline(std::cin, author);
    std::cout << "请输入分类号: ";
    std::getline(std::cin, categoryId);
    std::cout << "请输入出版社: ";
    std::getline(std::cin, publisher);
    std::cout << "请输入出版时间: ";
    std::getline(std::cin, publishTime);

    std::cout << "请输入价格: ";
    while (!(std::cin >> price)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "价格格式不正确，请重新输入: ";
    }

    books.emplace_back(id, title, author, categoryId, publisher, publishTime, price);
    std::cout << "添加成功！当前共有 " << books.size() << " 本书。\n";
}

// 浏览全部图书：改进的表格输出
void BookManager::displayAll() const {
    if (books.empty()) {
        std::cout << "目前还没有任何图书，请先添加。\n";
        return;
    }

    std::cout << "\n===== 全部图书（共 " << books.size() << " 本）=====\n";
    std::cout << "登录号\t\t书名\t\t\t作者\t\t分类号\t\t出版社\t\t出版时间\t价格\n";
    std::cout << std::string(100, '-') << '\n';

    for (const auto& b : books) {
        std::cout << b.getLoginId()      << "\t\t"
                  << b.getTitle()        << "\t\t"
                  << b.getAuthor()       << "\t\t"
                  << b.getCategoryId()   << "\t\t"
                  << b.getPublisher()    << "\t\t"
                  << b.getPublishTime()  << "\t\t"
                  << b.getPrice()        << '\n';
    }
}
