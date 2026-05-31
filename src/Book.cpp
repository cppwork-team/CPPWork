#include "Book.h"

#include <iomanip>
#include <istream>
#include <ostream>

// Book.cpp
// 数据模型基础实现：Book 类的构造函数、Getter/Setter 和流操作符。

Book::Book(std::string_view bookId,
           std::string_view title,
           std::string_view author,
           std::string_view categoryId,
           std::string_view publisher,
           std::string_view publishTime,
           double price)
    : bookId_(bookId),
      title_(title),
      author_(author),
      categoryId_(categoryId),
      publisher_(publisher),
      publishTime_(publishTime),
      price_(price) {
}

std::string_view Book::getLoginId() const {
    return bookId_;
}

std::string_view Book::getTitle() const {
    return title_;
}

std::string_view Book::getAuthor() const {
    return author_;
}

std::string_view Book::getCategoryId() const {
    return categoryId_;
}

std::string_view Book::getPublisher() const {
    return publisher_;
}

std::string_view Book::getPublishTime() const {
    return publishTime_;
}

double Book::getPrice() const {
    return price_;
}

void Book::setLoginId(std::string_view bookId) {
    bookId_ = bookId;
}

void Book::setTitle(std::string_view title) {
    title_ = title;
}

void Book::setAuthor(std::string_view author) {
    author_ = author;
}

void Book::setCategoryId(std::string_view categoryId) {
    categoryId_ = categoryId;
}

void Book::setPublisher(std::string_view publisher) {
    publisher_ = publisher;
}

void Book::setPublishTime(std::string_view publishTime) {
    publishTime_ = publishTime;
}

void Book::setPrice(double price) {
    price_ = price;
}

// 流输出操作符：用 std::quoted 处理可能包含空格的字段
std::ostream& operator<<(std::ostream& os, const Book& b) {
    os << std::quoted(std::string(b.bookId_))     << ' '
       << std::quoted(std::string(b.title_))      << ' '
       << std::quoted(std::string(b.author_))     << ' '
       << std::quoted(std::string(b.categoryId_)) << ' '
       << std::quoted(std::string(b.publisher_))  << ' '
       << std::quoted(std::string(b.publishTime_)) << ' '
       << b.price_;
    return os;
}

// 流输入操作符：用 std::quoted 读取带引号的字段
std::istream& operator>>(std::istream& is, Book& b) {
    is >> std::quoted(b.bookId_)
       >> std::quoted(b.title_)
       >> std::quoted(b.author_)
       >> std::quoted(b.categoryId_)
       >> std::quoted(b.publisher_)
       >> std::quoted(b.publishTime_)
       >> b.price_;
    return is;
}
