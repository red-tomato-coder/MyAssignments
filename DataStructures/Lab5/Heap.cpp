#include <iostream>

int Parent(int i){
  return i >> 1;
}

int Left(int i){
  return i << 1;
}

int Right(int i){
  return (i << 1) + 1;
}
