template<typename T>
class ScopedPointerNC {
private:
  T* pointer;

public:
  ScopedPointerNC(T* raw) : pointer(raw) {}

  ScopedPointerNC(const ScopedPointerNC& other) = delete;
  ScopedPointerNC& operator=(const ScopedPointerNC& other) = delete;
  
  
  ScopedPointerNC(ScopedPointerNC&& other) { 
    pointer = other.pointer;
    other.pointer = nullptr;
  }

  ScopedPointerNC& operator=(ScopedPointerNC&& other) {
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }

  T& get() { return *pointer; }
  const T& get() const { return *pointer; }
  
  ~ScopedPointerNC() { delete pointer; }
};