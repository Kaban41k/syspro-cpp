#ifndef SQUARE_MATRICE
#define SQUARE_MATRICE

#include <vector>

class SMatrice {
private:
  double* data_;
  size_t size_ = 0;
public:
  class Array {
  private:
    double* data_;
    size_t size_ = 0;

  public:
    Array(double* data, size_t size) : data_(data), size_(size) {};
    double& operator[](size_t index);
  };
  
  SMatrice(size_t size) : data_(new double[size * size]{}), size_(size) {};
  SMatrice(std::vector<double> vec);

  SMatrice(const SMatrice& other);
  SMatrice& operator=(const SMatrice& other);
  
  ~SMatrice();
  SMatrice(SMatrice&& other);
  SMatrice& operator=(SMatrice&& other);

  explicit operator double() const;

  friend SMatrice operator+(const SMatrice&, double);
  friend SMatrice operator*(const SMatrice&, double);
  
  SMatrice& operator+=(double scalar);
  SMatrice& operator*=(double scalar);
  SMatrice& operator+=(const SMatrice& other);
  SMatrice& operator*=(const SMatrice& other);

  friend SMatrice operator+(const SMatrice&, const SMatrice&);
  friend SMatrice operator*(const SMatrice&, const SMatrice&);
  friend bool operator==(const SMatrice&, const SMatrice&);
  friend bool operator!=(const SMatrice&, const SMatrice&);  

  Array operator[](size_t index);

  double size() {
    return size_;
  }
};

#endif
