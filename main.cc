#include <iostream>
#include "fridge.h"
#include <map>

int main() {

  // TODO: Follow instructions from README.md

  Refrigerator fridge;
  fridge.DisplayInfo();
  if (fridge.ConductCheckup(Date(10, 10, 2022))) {
    std::cout << "Checkup completed\n";
  } else {
    std::cout << "Checkup cannot be done in the past\n";
  }

  if (fridge.ConductCheckup(Date(9, 1, 2022))) {
    std::cout << "Checkup completed\n";
  } else {
    std::cout << "Checkup cannot be done in the past\n";
  }

  if (fridge.ConductCheckup(Date(10, 1, 2022))) {
    std::cout << "Checkup completed\n";
  } else {
    std::cout << "Checkup cannot be done in the past\n";
  }

  std::map<std::string, int> fridge_contents { 
    {"milk", 3},
    {"apple", 2},
    {"water", 10}
  };
  Refrigerator other_fridge(Date(10, 11, 2022), 20, fridge_contents);
  std::cout << "Last checkup date: " 
            << other_fridge.LastCheckupDate().ToString() << "\n";
  for (std::pair<std::string, int> content: other_fridge.Contents()) {
    std::cout << content.first << " x " << content.second << "\n";
  }
  
  return 0;
}