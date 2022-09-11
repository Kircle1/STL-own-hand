#include <ostream>
namespace mtl {
	template <typename T>
	class Vector {
	private:
		T* arr;
		size_t _size{};
		size_t _capacity{};
	public:
		Vector() {
			arr = new T[1];
			_capacity = 1;
		}
		~Vector() {
			delete[] arr;
		}
		Vector(Vector& other) {
			arr = new T[other._capacity];
			for (size_t i = 0; i < other.size; ++i) arr[i] = other.arr[i];
			size = other.size;
			_capacity = other._capacity;
		}
		Vector(Vector&& other) noexcept {
			arr = other.arr;
			size = other.size;
			_capacity = other._capacity;
			other.arr = nullptr;
			other.size = other._capacity = 0;
		}
		Vector& operator=(Vector& other) {
			if (this != &other)
			{
				delete[] arr;
				arr = new T[other._capacity];
				for (size_t i = 0; i < other.size; i++) arr[i] = other.arr[i];
				size = other.size;
				_capacity = other._capacity;
			}
			return *this;
		}
		T& operator[](size_t index) {
			return arr[index];
		}
		const T& operator[](size_t index) const {
			return arr[index];
		}
		bool isEmpty() const {
			return size == 0;
		}
		size_t size() const {
			return size;
		}
		size_t capacity() const {
			return _capacity;
		}
		void addMemory() {
			T* tmp = arr;
			arr = new T[_capacity];
			for (size_t i = 0; i < size; i++) arr[i] = tmp[i];
			delete[] tmp;
		}
		void pushback(const T& value) {
			if (size >= _capacity) addMemory();
			arr[size++] = value;
		}
		void remove(size_t index) {
			for (size_t i = index + 1; i < size; i++)
			{
				arr[i - 1] = arr[i];
			}
			--size;
		}

		T* begin() {
			return &arr[0];
		}
		const T* begin() const {
			return &arr[0];
		}
		T* end() {
			return &arr[size];
		}
		const T* end() const {
			return &arr[size];
		}
	};
	template <typename T>
	inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
		for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << " ";
		return os;
	}
}
