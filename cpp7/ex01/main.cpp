/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jainavas <jainavas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:14:22 by jainavas          #+#    #+#             */
/*   Updated: 2025/03/16 18:17:51 by jainavas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void imprimir(const T& elemento) {
    std::cout << elemento << " ";
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    size_t tamanio = sizeof(numeros) / sizeof(numeros[0]);

    std::cout << "Array de enteros: ";
    iter(numeros, tamanio, imprimir<int>);
    std::cout << std::endl;

    char caracteres[] = {'a', 'b', 'c', 'd'};
    size_t tamanioChar = sizeof(caracteres) / sizeof(caracteres[0]);

    std::cout << "Array de caracteres: ";
    iter(caracteres, tamanioChar, imprimir<char>);
    std::cout << std::endl;

    return 0;
}
