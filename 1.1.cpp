/*  Реализуйте класс double_vector -  массив вещественных чисел переменного размера.
30 баллов*/
#include <iostream>

using namespace std;

class double_vector
{
private:
 double *arr;
 unsigned int size;
 unsigned int capacity;

public:
 double_vector()//конструктор без аргументов (создает вектор размера 1, с одним элементом равным нулю): double_vector()
 {
  arr = new double[1];
  size = 0;
  capacity = 1;
  arr[0] = 0;
 }

 double_vector(unsigned int n)//конструктор с одним аргументом - длинной массива (создает вектор нужного размера заполненный нулями):double_vector(unsigned int N)
 {
  arr = new double[n];
  size = 0;
  capacity = n;
  for (int i = 0; i < n; i++)
   arr[i] = 0;
 }
 
 ~double_vector()//деструктор: ~double_vector()
 {
  delete[]arr;
  cout « " +";
 }

 double_vector(const double_vector& a)//конструктор копий: double_vector(const double_vector& A)

 {
  double* T = new double[a.capacity];
  for (int i = 0; i < a.capacity; i++)
   T[i] = 0;
  for (int i = 0; i < a.size; i++)
   T[i] = a.arr[i];
  size = a.size;
  capacity = a.capacity;
  arr = T;
  cout « " Copy";
 }

 const double_vector& operator= (const double_vector& a)//оператор присвоения:const double_vector& operator=(const double_vector& A)
 {
  double* T = new double[a.capacity];
  for (int i = 0; i < a.capacity; i++) {
   T[i] = 0;
  }

  for (int i = 0; i < a.size; i++)
   T[i] = a.arr[i];

  size = a.size;
  capacity = a.capacity;
  delete[] arr;
  arr = T;
  cout « "wow.its working";
  return *this;
 }
  double operator[] (unsigned int n)//оператор обращения по индексу:double operator[] (unsigned int n)
 {
  cout « " operator [] is working ;";
  return arr[n - 1];
 }

  void push_back(double x)
 {
  if (size >= capacity) {
   capacity *= 2;
   double* temp = new double[capacity];
   for (int i = 0; i < capacity; i++) {
    temp[i] = 0;
   }
   for (int i = 0; i < size; i++) {
    temp[i] = arr[i];
   }
   delete[]arr;
   arr = temp;
  }
  arr[size] = x;
  size++;
  cout « "  ;";
 }

 double pop_back()
 {
  double a;
  a = arr[size];
  arr[size] = 0;
  size--;
  cout « " ;";
  return a;
 }
//б
 double pop_front()
 {
  double a;
  a = arr[0];
  for (int i = 0; i < size - 1; i++)
   arr[i] = arr[i -1];

  size--;
  cout « "+";
  return a;
 }
unsigned int get_size(){ 
unsigned int a = size; 
cout « " size is working ;"; 
return a; 
} 
unsigned int get_capacity(){ 
unsigned int a = capacity; 
cout « " capacity is working
};