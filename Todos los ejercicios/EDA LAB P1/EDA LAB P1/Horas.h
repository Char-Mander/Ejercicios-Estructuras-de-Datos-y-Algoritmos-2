#pragma once
#include <cstddef>    // size_t
#include <stdexcept>  // std::domain_error
#include <utility>

template <class Horas>
	class hora {
	public:
		set(int horas, int minutos, int segundos); // constructor
		void insert(T e);
		bool contains(T e) const;
		void erase(T e);
		bool empty() const;
		size_t size() const;
	private:
		int horas;
		int minutos;
		int segundos;
		
		void amplia();
	};

	template <class T>

	hora<T>::set(int h, int m, int s) : horas(h), minutos(m), segundos(s) {}

	template <class T>
	void set<T>::insert(T e) {
		if (!contains(e)) {
			if (contador == capacidad)
				amplia();
			datos[contador] = e;
			++contador;
		}
	}