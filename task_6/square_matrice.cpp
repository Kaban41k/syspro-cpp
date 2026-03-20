#include "square_matrice.h"

double& SMatrice::Array::operator[](size_t index) {
  return data_[index];
}

SMatrice::SMatrice(std::vector<double> vec) : data_(new double[vec.size() * vec.size()]{}), size_(vec.size()) { 
  for (size_t i = 0; i < size_; i++) {
    data_[i + i * size_] = vec[i]; 
  }
}

SMatrice::SMatrice(const SMatrice& other) : data_(new double[other.size_ * other.size_]), size_(other.size_) {
  std::memcpy(data_, other.data_, sizeof(double) * size_ * size_);
}

SMatrice& SMatrice::operator=(const SMatrice& other) {
  size_ = other.size_;
  data_ = new double[size_ * size_];
  std::memcpy(data_, other.data_, sizeof(double) * size_ * size_);

  return *this;
}

SMatrice::~SMatrice() {
  delete[] data_;
}

SMatrice::SMatrice(SMatrice&& other) : data_(other.data_), size_(other.size_) {
  other.data_ = nullptr;
  other.size_ = 0;
}

SMatrice& SMatrice::operator=(SMatrice&& other) {
  data_ = other.data_;
  size_ = other.size_;
  other.data_ = nullptr;
  size_ = 0;

  return *this;
}

SMatrice::operator double() const {
  double s = 0;

  for (size_t i = 0; i < size_ * size_; i++) {
    s += data_[i];
  }

  return s;
}

SMatrice operator+(const SMatrice& matrice, double scalar) {
  SMatrice m(matrice.size_);
  
  for (size_t i = 0; i < m.size_ * m.size_; i++) {
    m.data_[i] = matrice.data_[i] + scalar;
  }

  return m;
}

SMatrice operator*(const SMatrice& matrice, double scalar) {
  SMatrice m(matrice.size_);
  
  for (size_t i = 0; i < m.size_ * m.size_; i++) {
    m.data_[i] = matrice.data_[i] * scalar;
  }

  return m;
}

SMatrice& SMatrice::operator+=(double scalar) {
  for (size_t i = 0; i < size_ * size_; i++) {
    data_[i] += scalar;
  }

  return *this;
}

SMatrice& SMatrice::operator*=(double scalar) {
  for (size_t i = 0; i < size_ * size_; i++) {
    data_[i] *= scalar;
  }

  return *this;
}

SMatrice& SMatrice::operator+=(const SMatrice& other) {
  for (size_t i = 0; i < size_ * size_; i++) {
    data_[i] += other.data_[i];
  }

  return *this;
}

SMatrice& SMatrice::operator*=(const SMatrice& other) {
  for (size_t i = 0; i < size_ * size_; i++) {
    data_[i] *= other.data_[i];
  }

  return *this;
}

SMatrice operator+(const SMatrice& lmatrice, const SMatrice& rmatrice) {
  SMatrice m(lmatrice.size_);
  
  for (size_t i = 0; i < m.size_ * m.size_; i++) {
    m.data_[i] = lmatrice.data_[i] + rmatrice.data_[i];
  }

  return m;
}

SMatrice operator*(const SMatrice& lmatrice, const SMatrice& rmatrice) {
  SMatrice m(lmatrice.size_);
  
  for (size_t i = 0; i < m.size_ * m.size_; i++) {
    m.data_[i] = lmatrice.data_[i] * rmatrice.data_[i];
  }

  return m;
}

bool operator==(const SMatrice& lmatrice, const SMatrice& rmatrice) {
  if (lmatrice.size_ != rmatrice.size_) { 
    return false; 
  }

  for (size_t i = 0; i < lmatrice.size_ * rmatrice.size_; i++) {
    if (lmatrice.data_[i] != rmatrice.data_[i]) {
      return false;
    }
  }

  return true;
}

bool operator!=(const SMatrice& lmatrice, const SMatrice& rmatrice) {
  return !(lmatrice == rmatrice);
}

SMatrice::Array SMatrice::operator[](size_t index) {
  return Array(data_ + index * size_, size_);
}
