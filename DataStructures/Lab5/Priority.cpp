#include "Heap.h"
#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr) {
    for (int num : arr) std::cout << num << " ";
    std::cout << std::endl;
}

int main(){
  int Choice;
  std::vector<int> QueueMax = {5, 19, 2};
  std::vector<int> QueueMin = {5, 19, 2};
  while (true){
  std::cout << "МЕНЮ\n" <<
  "1. Вставити\n"  <<
  "2. Прочитати максимум\\мінімум\n" <<
  "3. Збільшити\\зменшити ключ\n" <<
  "4. Виключити з черги\n" <<
  "Ваш вибір: ";
  std::cin >> Choice;
  switch (Choice) {
    case 1:{
             int ChoiceMode, key;
             std::cout << "До якої черги (мінімальної або максимальної) добавити елемент?\n"<<
             "1. Максимальна\n" <<
             "2. Мінімальна\n";
             std::cin >> ChoiceMode;
             std::cout << "Введіть ключ: ";
             std::cin >> key;            
             if(ChoiceMode==1){
               Insert(QueueMax, key, true);
               printArray(QueueMax);
             }
             else{
               Insert(QueueMin, key, false);
               printArray(QueueMin);
             }
             break;
            }
    case 2:{
             std::cout << "QueueMax: " << Maximum(QueueMax)<< std::endl
             << "QueueMin: " << Minimum(QueueMin) <<std::endl;
             break;
            }
    case 3:{
            int ChoiceMode, index, key;
            std::cout << "До якої черги (мінімальної або максимальної) добавити елемент?\n"<<
            "1. Максимальна\n" <<
            "2. Мінімальна\n";
            std::cin >> ChoiceMode;
            std::cout << "Введіть індекс для заміни: ";
            std::cin >> key;
            std::cout << "Введіть ключ який замінить індексний елемент";
            if (ChoiceMode == 1) {
              HeapIncreaseKey(QueueMax, index, key);
              printArray(QueueMax);
            }
            else{
              HeapDecreaseKey(QueueMin, index, key);
              printArray(QueueMin);
            }
            break;
           }
    case 4:{
            int ChoiceMode;
            std::cout << "До якої черги (мінімальної або максимальної) добавити елемент?\n"<<
            "1. Максимальна\n" <<
            "2. Мінімальна\n";
            std::cin >> ChoiceMode;
            if(ChoiceMode==1){
              ExtractMax(QueueMax);
              printArray(QueueMax);
            }
            else{
              ExtractMin(QueueMin);
              printArray(QueueMin);
            }
            break;
           }
    default:
           std::cout << "Помилка\n";
      break;
  }
  }
}
