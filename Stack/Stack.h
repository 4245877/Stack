#pragma once
template <typename T>
class Stack{
private:
	T* stack = nullptr;
	int top = -1;
public:
	Stack() = default;
	Stack(const Stack& other) {
		if (other.stack == nullptr) {
			return;
		}
		stack = new int[other.Size()];
		for (size_t i = 0; i < other.Size(); i++)
		{
			stack[i] = other.stack[i];
		}
		top = other.top;
	}
	~Stack() {
		delete[] stack;
		stack = nullptr;
		top = -1;
	}

	Stack& operator=(const Stack& other) {
		if (this != &other)
		{
			delete[] stack;

			top = other.top; // навіть ящко там пустота

			if (other.Size() != 0)
			{
				stack = new int[other.Size()];

				for (size_t i = 0; i < other.Size(); i++)
				{
					stack[i] = other.stack[i];
				}
			}
		}

		return *this;
	}
	void Push(const T& value) { // НЕ ЗРУЧНО
		if (IsEmpty()){
			stack = new T[1];
			top++;
			stack[top] = value;
		}
		else{
			T* newStack = new T[Size() + 1];

			for (size_t i = 0; i < Size(); i++){
				newStack[i] = stack[i];
			}
			top++;
			newStack[top] = value;

			delete[] stack;
			stack = newStack;
		}
	}
	void Pop() {
		if (!IsEmpty()) {
			if (Size() == 1) {
				delete[] stack;
				stack = nullptr;
				top--;
			}
			else {
				T* newStack = new T[Size() - 1];
				for (size_t i = 0; i < Size() - 1; i++) {
					newStack[i] = stack[i];  // Исправлен индекс
				}
				top--;
				delete[] stack;
				stack = newStack;
			}
		}
	}
	T& Top(){
		return stack[top];
	}
	size_t Size() const{
		return top + 1;
	}
	bool IsEmpty() const{
		return top == -1;
	}
};
