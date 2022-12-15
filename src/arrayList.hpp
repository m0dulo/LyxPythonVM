#ifndef ARRAY_LIST_HPP_
#define ARRAY_LIST_HPP_

template <typename T> class ArrayList {
private:
  int _length;
  T *_array;
  int _size;

  void expand();

public:
  ArrayList(int n = 8);

  void add(T t);
  void insert(int index, T t);
  T get(int index) const;
  void set(int index, T t);
  int size() const;
  int length() const;
  T pop();
}

#endif // ARRAY_LIST_HPP_