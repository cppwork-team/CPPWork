#include "BookManager.h"

#include <algorithm>
#include <iostream>

// BookManager_Sort.cpp
// Module E: 排序控制（同学E负责）

void BookManager::sortBooks() {
    if (books.empty()) {
        std::cout << "目前没有图书，无需排序。\n";
        return;
    }

    std::cout << "\n请选择排序方式：\n"
              << "1. 按价格升序（从低到高）\n"
              << "2. 按价格降序（从高到低）\n"
              << "3. 按书名字母顺序\n"
              << "4. 按登录号顺序\n"
              << "5. 按作者字母顺序\n"
              << "请输入选项: ";

    int choice = 0;
    std::cin >> choice;

    switch (choice) {
    case 1:  // 按价格升序
        std::sort(books.begin(), books.end(),
                  [](const Book& a, const Book& b) {
                      return a.getPrice() < b.getPrice();
                  });
        std::cout << "已按价格升序排序。\n";
        break;

    case 2:  // 按价格降序
        std::sort(books.begin(), books.end(),
                  [](const Book& a, const Book& b) {
                      return a.getPrice() > b.getPrice();
                  });
        std::cout << "已按价格降序排序。\n";
        break;

    case 3:  // 按书名字母顺序
        std::sort(books.begin(), books.end(),
                  [](const Book& a, const Book& b) {
                      return a.getTitle() < b.getTitle();
                  });
        std::cout << "已按书名字母顺序排序。\n";
        break;

    case 4:  // 按登录号顺序
        std::sort(books.begin(), books.end(),
                  [](const Book& a, const Book& b) {
                      return a.getLoginId() < b.getLoginId();
                  });
        std::cout << "已按登录号顺序排序。\n";
        break;

    case 5:  // 按作者字母顺序
        std::sort(books.begin(), books.end(),
                  [](const Book& a, const Book& b) {
                      return a.getAuthor() < b.getAuthor();
                  });
        std::cout << "已按作者字母顺序排序。\n";
        break;

    default:
        std::cout << "无效选项，排序取消。\n";
        break;
    }
}
