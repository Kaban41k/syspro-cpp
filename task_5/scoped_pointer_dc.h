template<typename T>
class ScopedPointerDC {
private:
  T* pointer;

public:
  ScopedPointerDC(T* raw) : pointer(raw) {}

  ScopedPointerDC(const ScopedPointerDC& other) : pointer(new T(*other.pointer)) {};
  
  ScopedPointerDC& operator=(const ScopedPointerDC& other) {
    pointer = new T(*other.pointer);
    return *this;
  }

  ScopedPointerDC(ScopedPointerDC&& other) { 
    pointer = other.pointer;
    other.pointer = nullptr;
  }

  ScopedPointerDC& operator=(ScopedPointerDC&& other) {
    pointer = other.pointer;
    other.pointer = nullptr;
    return *this;
  }

  T& get() { return *pointer; }
  const T& get() const { return *pointer; }
  
  ~ScopedPointerDC() { delete pointer; }
};