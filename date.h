#include <iostream>
class Date {
 public:
  Date(int month, int day, int year) : month_(month), day_(day),
                                       year_(year) {}
  Date(const Date& other): month_(other.Month()), day_(other.Day()), 
                           year_(other.Year()) { }
  Date() : Date(1, 1, 1970) {}
  int Month() const { return month_; }
  void SetMonth(int month) { month_ = month; }
  int Day() const { return day_; }
  void SetDay(int day) { day_ = day; }
  int Year() const { return year_; }
  void SetYear(int year) { year_ = year; }

  std::string ToString() const {
    return std::to_string(month_) + "/" + std::to_string(day_) + 
           "/" + std::to_string(year_);
  }

private:
 int month_;
 int day_;
 int year_;
};