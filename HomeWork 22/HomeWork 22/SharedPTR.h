#pragma once

template<class T>
class SharedPTR
{
private:
	T* _ptr = nullptr;
	int* _count = nullptr;

public:
	SharedPTR() : _ptr(), _count(new int(0)) {}

	SharedPTR(T* ptr) : _ptr(ptr), _count(new int(1)) {}

	SharedPTR(const SharedPTR& obj) { // Copy Constructor
		_ptr = obj._ptr;
		_count = obj._count;
		if (obj._ptr)
			(*_count)++;
	}

	SharedPTR& operator=(const SharedPTR& obj) { // Copy Assignment
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}

		_ptr = obj._ptr;
		_count = obj._count;
		if (nullptr != obj._ptr)
			(*_count)++;
	}

	SharedPTR& operator=(SharedPTR&& dyingObj) { // Move Assignment
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}

		_ptr = dyingObj._ptr;
		_count = dyingObj._count;

		dyingObj._ptr = nullptr;
		dyingObj._count = nullptr;
	}

	int getCount() const { return *_count; }

	T* get() const { return _ptr; }

	T* operator->() const { return _ptr; }

	T& operator*() const { return _ptr; }

	~SharedPTR()
	{
		(*_count)--;
		if (*_count == 0)
		{
			if (nullptr != _ptr)
				delete _ptr;
			delete _count;
		}
	}
};
