#include "date.h"
#include <iostream>
#include <map>

class Refrigerator {
 public:
  Refrigerator(const Date &last_checkup_date, int max_contents,
               const std::map<std::string, int> &contents)
      : last_checkup_date_(last_checkup_date),
        max_contents_(max_contents),
        contents_(contents) { }
  Refrigerator() : max_contents_(10), last_checkup_date_(10, 7, 2022) {}

  int MaxContents() const { return max_contents_; }
  const std::map<std::string, int>& Contents() const { 
    return contents_; 
  }
  const Date& LastCheckupDate() { return last_checkup_date_; }

  bool Fill(const std::string &name, int quantity) {
    if (contents_.size() + quantity > max_contents_) {
      return false;
    } else {
      if (contents_.count(name) == 0) {
        contents_.insert({name, quantity});
      } else {
        contents_.at(name) += quantity;
      }
      return true;
    }
  }

  bool ConductCheckup(const Date &checkup_date) {
    int last_date_as_num = (last_checkup_date_.Year() * 100 +
                           last_checkup_date_.Month()) * 100 +
                           last_checkup_date_.Day();
    int curr_date_as_num = (checkup_date.Year() * 100 +
                            checkup_date.Month()) * 100 +
                            checkup_date.Day();
    if (last_date_as_num < curr_date_as_num) {
      last_checkup_date_ = checkup_date;
      return true;
    } else {
      return false;
    }
  }

  void DisplayInfo() const {
    std::cout << "Max contents: " << max_contents_ << "\n"
              << "Current contents: " << contents_.size() << "\n";
    std::cout << "Last check-up: ";
    std::cout << last_checkup_date_.ToString() << "\n";

  }

private:
 Date last_checkup_date_;
 int max_contents_;
 std::map<std::string, int> contents_;
};
