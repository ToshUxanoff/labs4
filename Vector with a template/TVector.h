#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include "iostream"

class out_of_range : public std::exception
{
};
template <typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;
private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
	{
		Count = 0;
		InternalCapacity = capacity;
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
			delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (size < InternalCapacity)
		{
			return;
		}
		value_type* buf = new value_type[size];
		memcpy(buf, Ptr, Count*sizeof(value_type));
		delete[]Ptr;
		InternalCapacity = size;
		Ptr = buf;
		buf = nullptr;
	}

	TVector(const TVector& rhs)
	{
		reserve (rhs.InternalCapacity);
		InternalCapacity = rhs.InternalCapacity;
		Count = rhs.Count;
		memcpy(Ptr, rhs.Ptr, InternalCapacity*sizeof(value_type));
	}

	TVector& operator=(const TVector& rhs)
	{
		reserve(rhs.InternalCapacity);
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;
		memcpy(Ptr, rhs.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void push_back(const value_type& value)
	{	
		if (InternalCapacity == 0)
		{
			reserve(1);
		}
		if (Count >= InternalCapacity)
		{
			InternalCapacity++;
			reserve(InternalCapacity);
		}
			Ptr[Count] = value;
			Count++;
	}

	reference at(size_type index)
	{
		if (index > InternalCapacity||index < 0)
		{
			throw out_of_range();
		}
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index > InternalCapacity || index < 0)
		{
			throw out_of_range();
		}
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		return Ptr[index];
	}

	reference front()
	{
		return Ptr[0];
	}

	const_reference front() const
	{
		return Ptr[0];
	}

	reference back()
	{
		return Ptr[Count-1];
	}

	const_reference back() const
	{
		return Ptr[Count - 1];
	}

	void clear()
	{
		delete[] Ptr;
		Count = 0;
		InternalCapacity = 0;
	}

	void pop_back()
	{
		Count--;
	}

	void swap(TVector& other) throw()
	{
		std::swap(Ptr, other.Ptr);
		std::swap(InternalCapacity, other.InternalCapacity);
		std::swap(Count, other.Count);
	}
	void resize(size_type count, value_type value = value_type())
	{
		if (count > INT_MAX)
		{
			throw std::exception();
		}
		if (count > Count)
		{	
			reserve(count);
			for (int i = Count; i < count; ++i)
			{
				Ptr[i] = value;
			}
		}
		Count = count;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		int position = *pos;
		if (pos > Ptr + Count)
		{
			throw out_of_range();
		}
		Count++;
		reserve(Count);
		for (int i = Count - 1 ; i >= position; i--)
		{
			Ptr[i] = Ptr[i - 1];
		}
		Ptr[position] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		int position = *pos;
		if (pos > Ptr + Count)
		{
			throw out_of_range();
		}
		Count+=count;
		reserve(Count);
		for (int i = Count - 1; i >= position+count; i--)
		{
			Ptr[i] = Ptr[i - count];
		}
		for (int i = 0; i < count; i++)
		{
			Ptr[position+i] = value;
		}
	}

	iterator erase(iterator pos)
	{
		if (pos > Ptr + Count)
		{
			throw out_of_range();
		}
		for (int i = 0; i + pos < Ptr + Count; ++i)
		{

			*(pos + i) = *(pos + i + 1);
		}
		Count--;
		return pos;
	}

	iterator erase(iterator first, iterator last)
	{
		if (last > Ptr + Count || first >= Ptr + Count)
		{
			throw out_of_range();
		}
		for (int i = 0; i + last < Ptr + Count; ++i)
		{
			*(i + first) = *(last + i);
		}
		Count -= (last - first);
		return first;
	}
};


#endif // __TVECTOR_INCLUDED__
