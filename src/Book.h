#ifndef BOOK_H
#define BOOK_H

#include <iosfwd>
#include <string>
#include <string_view>

// Book.h
// 数据模型声明：全组共享的图书实体契约。
class Book {
public:
    Book() = default;  // 默认构造函数，方便某些场景使用

    Book(std::string_view bookId,
         std::string_view title,
         std::string_view author,
         std::string_view categoryId,
         std::string_view publisher,
         std::string_view publishTime,
         double price);

    std::string_view getLoginId() const;
    std::string_view getTitle() const;
    std::string_view getAuthor() const;
    std::string_view getCategoryId() const;
    std::string_view getPublisher() const;
    std::string_view getPublishTime() const;
    double getPrice() const;

    void setLoginId(std::string_view bookId);
    void setTitle(std::string_view title);
    void setAuthor(std::string_view author);
    void setCategoryId(std::string_view categoryId);
    void setPublisher(std::string_view publisher);
    void setPublishTime(std::string_view publishTime);
    void setPrice(double price);

    // 流操作符：简化文件I/O（同学A会用到）
    friend std::ostream& operator<<(std::ostream& os, const Book& b);
    friend std::istream& operator>>(std::istream& is, Book& b);

private:
    std::string bookId_;
    std::string title_;
    std::string author_;
    std::string categoryId_;
    std::string publisher_;
    std::string publishTime_;
    double price_ = 0.0;
};

#endif
